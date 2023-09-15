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
    auto console_sink = CreateRef<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = CreateRef<spdlog::sinks::basic_file_sink_mt>(
        parameters::log_path, false);

    console_sink->set_pattern("[%H:%M:%S.%e] [%^%l%$] [t:%t] [%s:%#] %v");
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%#] %v");

    m_Sinks.emplace_back(console_sink);
    m_Sinks.emplace_back(file_sink);

    m_Logger =
        CreateRef<spdlog::logger>("rs_log", begin(m_Sinks), end(m_Sinks));
    m_Logger->set_level(spdlog::level::trace);
    m_Logger->flush_on(
        spdlog::level::warn);  // Flush automatically when warning appears

    spdlog::register_logger(m_Logger);  // Register Logger
    spdlog::flush_every(std::chrono::seconds(1));
    spdlog::set_default_logger(m_Logger);
    spdlog::set_level(spdlog::level::trace);
  }

 private:
  Ref<spdlog::logger> m_Logger;
  std::vector<spdlog::sink_ptr> m_Sinks{};
};  // Logger

}  // namespace room_sketcher
