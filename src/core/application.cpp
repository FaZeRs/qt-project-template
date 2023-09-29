#include "application.h"

#include <config.h>
#include <qapplication.h>
#include <qbytearray.h>
#include <qlogging.h>
#include <qscopeguard.h>
#include <qstring.h>
#if USE_SENTRY
#include <sentry.h>
#endif
#if USE_SPDLOG
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include "logger.h"
#endif
#include <cstring>

#include "parameters.h"

#if USE_SPDLOG
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
#if USE_SENTRY
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_WARNING, "default", loc.constData()));
#endif
      break;
    case QtCriticalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::err, loc.constData());
#if USE_SENTRY
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_ERROR, "default", loc.constData()));
#endif
      break;
    case QtFatalMsg:
      spdlog::log(
          spdlog::source_loc{context.file, context.line, context.function},
          spdlog::level::critical, loc.constData());
#if USE_SENTRY
      sentry_capture_event(sentry_value_new_message_event(
          SENTRY_LEVEL_FATAL, "default", loc.constData()));
#endif
      break;
  }
}
#endif

namespace room_sketcher {

static Scope<QCoreApplication> createApplication(int& argc, char** argv) {
  QCoreApplication::setApplicationName(config::project_name);
  QCoreApplication::setOrganizationName(config::organization_name);
  QCoreApplication::setApplicationVersion(config::project_version);

  for (int i = 1; i < argc; ++i) {
    // NOLINTNEXTLINE
    if (strcmp(argv[i], "-no-gui") == 0)
      return CreateScope<QCoreApplication>(argc, argv);
  }
  return CreateScope<QApplication>(argc, argv);
}

Application::Application(int& argc, char** argv)
    : m_Application(createApplication(argc, argv)) {
  qSetMessagePattern("[%{time h:mm:ss.zzz}] [%{type}] [t:%{threadid}] "
                     "[%{function}:%{line}] %{message}");
#if USE_SPDLOG
  Logger::instance();
  qInstallMessageHandler(qtLogMessageHandler);
#endif

  qInfo("*** ************* ***");
  qInfo("*** %s ***", config::project_name);
  qInfo("*** v: %s ***", config::project_version);
  qInfo("*** ************* ***\n");


#if USE_SENTRY
  initializeSentry();
  auto sentryClose = qScopeGuard([] { sentry_close(); });
#endif
}

int Application::run() const { return m_Application->exec(); }

void Application::initializeSentry() {
#if USE_SENTRY
  constexpr double sample_rate = 0.2;
  sentry_options_t* options = sentry_options_new();
  sentry_options_set_symbolize_stacktraces(options, true);
  sentry_options_set_dsn(options, parameters::sentry_dsn);
  sentry_options_set_database_path(options, ".sentry-native");
  sentry_options_set_release(options, config::project_version);
  sentry_options_set_traces_sample_rate(options, sample_rate);
  sentry_init(options);
#endif
}

}  // namespace room_sketcher
