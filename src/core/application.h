#pragma once

#include <QCoreApplication>

#include "base.h"
#include "settings.h"

namespace room_sketcher {

class Application {
 public:
  Application(int& argc, char** argv);
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;
  Application(Application&&) = delete;
  Application& operator=(Application&&) = delete;
  ~Application() = default;

  [[nodiscard]] int run() const;

 private:
  static void initializeSentry();

  Scope<QCoreApplication> m_Application;
};

}  // namespace room_sketcher
