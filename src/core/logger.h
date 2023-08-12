#pragma once

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <memory>

#include "base.h"
#include "parameters.h"
#include "singleton.h"

namespace room_sketcher {

class Logger final : public Singleton<Logger> {
 public:
  Logger() { initLogger(); }
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger(Logger&&) = delete;
  Logger& operator=(Logger&&) = delete;
  ~Logger() {
    spdlog::drop_all();  // Release all Loggers
  }

  // Creates SPDLOG logger with multiple sinks (console + file)
  void initLogger() {
    m_ConsoleSink = CreateRef<spdlog::sinks::stdout_color_sink_mt>();
    m_FileSink = CreateRef<spdlog::sinks::basic_file_sink_mt>(
        parameters::log_path, false);

    m_ConsoleSink->set_level(spdlog::level::trace);
    m_FileSink->set_level(spdlog::level::trace);

    m_ConsoleSink->set_pattern("[%H:%M:%S.%e] [%^%l%$] [t:%t] [%s:%#] %v");
    m_FileSink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%#] %v");

    m_Sinks.emplace_back(m_ConsoleSink);
    m_Sinks.emplace_back(m_FileSink);

    m_Logger =
        CreateRef<spdlog::logger>("rs_log", begin(m_Sinks), end(m_Sinks));
    m_Logger->set_level(spdlog::level::trace);
    m_Logger->flush_on(
        spdlog::level::warn);  // Flush automatically when warning appears

    spdlog::register_logger(m_Logger);  // Register Logger
    spdlog::set_default_logger(m_Logger);
  }

 private:
  Ref<spdlog::logger> m_Logger;
  Ref<spdlog::sinks::stdout_color_sink_mt> m_ConsoleSink;
  Ref<spdlog::sinks::basic_file_sink_mt> m_FileSink;
  std::vector<spdlog::sink_ptr> m_Sinks{};
};  // Logger

}  // namespace room_sketcher
