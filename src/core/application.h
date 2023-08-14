#pragma once

#include <qcoreapplication.h>

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
  ~Application();

  [[nodiscard]] int run() const;

  [[nodiscard]] Settings* settings() const;

 private:
  static void initializeSentry();

  Scope<QCoreApplication> m_Application;
  Scope<Settings> m_Settings = CreateScope<Settings>();
};

}  // namespace room_sketcher
