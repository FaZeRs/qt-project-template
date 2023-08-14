#include "application.h"

#include <config.h>
#include <qapplication.h>
#include <qbytearray.h>
#include <qlogging.h>
#include <qscopeguard.h>
#include <qstring.h>
#include <sentry.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>

#include <cstring>

#include "logger.h"
#include "parameters.h"

static void qtLogMessageHandler(QtMsgType type,
                                const QMessageLogContext& context,
                                const QString& msg) {
  QByteArray loc = msg.toUtf8();
  switch (type) {
    case QtDebugMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::debug, loc.constData());
      break;
    case QtInfoMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::info, loc.constData());
      break;
    case QtWarningMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::warn, loc.constData());
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_WARNING, "default", loc.constData()));
      break;
    case QtCriticalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::err, loc.constData());
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_ERROR, "default", loc.constData()));
      break;
    case QtFatalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::critical, loc.constData());
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_FATAL, "default", loc.constData()));
      break;
  }
}

namespace room_sketcher {

static Scope<QCoreApplication> createApplication(int& argc, char** argv) {
  QCoreApplication::setApplicationName(config::project_name);
  QCoreApplication::setOrganizationName(config::organization_name);
  QCoreApplication::setApplicationVersion(config::project_version);

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-no-gui") == 0)
      return CreateScope<QCoreApplication>(argc, argv);
  }
  return CreateScope<QApplication>(argc, argv);
}

Application::Application(int& argc, char** argv)
    : m_Application(createApplication(argc, argv)) {
  Logger::instance();

  SPDLOG_INFO("*** ************* ***");
  SPDLOG_INFO("*** {} ***", config::project_name);
  SPDLOG_INFO("*** v: {} ***", config::project_version);
  SPDLOG_INFO("*** ************* ***\n");

  qInstallMessageHandler(qtLogMessageHandler);

  initializeSentry();
  auto sentryClose = qScopeGuard([] { sentry_close(); });
}

Application::~Application() { m_Settings.reset(); }

int Application::run() const { return m_Application->exec(); }

Settings* Application::settings() const { return m_Settings.get(); }

void Application::initializeSentry() {
  constexpr double sample_rate = 0.2;
  sentry_options_t* options = sentry_options_new();
  sentry_options_set_symbolize_stacktraces(options, true);
  sentry_options_set_dsn(options, parameters::sentry_dsn);
  sentry_options_set_database_path(options, ".sentry-native");
  sentry_options_set_release(options, config::project_version);
  sentry_options_set_traces_sample_rate(options, sample_rate);
  sentry_init(options);
}

}  // namespace room_sketcher
