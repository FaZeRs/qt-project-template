#include "main_window.h"

#include <QtCore/qobjectdefs.h>
#include <config.h>
#include <qaction.h>
#include <qapplication.h>
#include <qcoreapplication.h>
#include <qdatetime.h>
#include <qkeysequence.h>
#include <qlogging.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qmessagebox.h>
#include <qstatusbar.h>
#include <qstring.h>

#include "../core/parameters.h"
#include "settings_dialog.h"

class QWidget;

namespace room_sketcher {

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags) {
  setObjectName("MainWindow");
  setWindowTitle(parameters::window_title);

  setupMenuBar();

  statusBar()->showMessage(tr("Status Bar"));
}

void MainWindow::setupMenuBar() {
  QMenu *file_menu = menuBar()->addMenu(tr("&File"));
  QAction *new_act =
      file_menu->addAction(tr("&New"), this, &MainWindow::createProject);
  new_act->setShortcut(m_Settings->newShortcut());
  connect(m_Settings.get(), &Settings::newShortcutChanged, new_act,
          &QAction::setShortcut);
  new_act->setStatusTip(tr("Create a new project"));
  QAction *open_act =
      file_menu->addAction(tr("&Open"), this, &MainWindow::openProject);
  open_act->setShortcut(m_Settings->openShortcut());
  connect(m_Settings.get(), &Settings::openShortcutChanged, open_act,
          &QAction::setShortcut);
  open_act->setStatusTip(tr("Open an existing project"));
  QAction *save_act =
      file_menu->addAction(tr("&Save"), this, &MainWindow::saveProject);
  save_act->setShortcut(m_Settings->saveShortcut());
  connect(m_Settings.get(), &Settings::saveShortcutChanged, save_act,
          &QAction::setShortcut);
  save_act->setStatusTip(tr("Save the project to disk"));
  QAction *save_as_act =
      file_menu->addAction(tr("&Save As"), this, &MainWindow::saveAsProject);
  save_as_act->setShortcut(m_Settings->saveAsShortcut());
  connect(m_Settings.get(), &Settings::saveAsShortcutChanged, save_as_act,
          &QAction::setShortcut);
  save_as_act->setStatusTip(tr("Save the project to disk with a new name"));
  file_menu->addSeparator();
  QAction *settings_act =
      file_menu->addAction(tr("&Settings"), this, &MainWindow::settingsApp);
  settings_act->setShortcut(m_Settings->optionsShortcut());
  connect(m_Settings.get(), &Settings::optionsShortcutChanged, settings_act,
          &QAction::setShortcut);
  settings_act->setStatusTip(tr("Open settings dialog"));
  QAction *quit_act =
      file_menu->addAction(tr("&Quit"), qApp, &QCoreApplication::quit);
  quit_act->setShortcut(m_Settings->quitShortcut());
  connect(m_Settings.get(), &Settings::quitShortcutChanged, quit_act,
          &QAction::setShortcut);
  quit_act->setStatusTip(tr("Quit the application"));

  QMenu *edit_menu = menuBar()->addMenu(tr("&Edit"));
  QAction *undo_act =
      edit_menu->addAction(tr("&Undo"), this, &MainWindow::doUndo);
  undo_act->setShortcut(m_Settings->undoShortcut());
  connect(m_Settings.get(), &Settings::undoShortcutChanged, undo_act,
          &QAction::setShortcut);
  undo_act->setStatusTip(tr("Undo the last action"));
  QAction *redo_act =
      edit_menu->addAction(tr("&Redo"), this, &MainWindow::doRedo);
  redo_act->setShortcut(m_Settings->redoShortcut());
  connect(m_Settings.get(), &Settings::redoShortcutChanged, redo_act,
          &QAction::setShortcut);
  redo_act->setStatusTip(tr("Redo the last action"));
  edit_menu->addSeparator();
  QAction *copy_act =
      edit_menu->addAction(tr("&Copy"), this, &MainWindow::doCopy);
  copy_act->setShortcut(m_Settings->copyShortcut());
  connect(m_Settings.get(), &Settings::copyShortcutChanged, copy_act,
          &QAction::setShortcut);
  copy_act->setStatusTip(tr("Copy the selected item"));
  QAction *paste_act =
      edit_menu->addAction(tr("&Paste"), this, &MainWindow::doPaste);
  paste_act->setShortcut(m_Settings->pasteShortcut());
  connect(m_Settings.get(), &Settings::pasteShortcutChanged, paste_act,
          &QAction::setShortcut);
  paste_act->setStatusTip(tr("Paste the selected item"));
  QAction *cut_act = edit_menu->addAction(tr("&Cut"), this, &MainWindow::doCut);
  cut_act->setShortcut(m_Settings->cutShortcut());
  connect(m_Settings.get(), &Settings::cutShortcutChanged, cut_act,
          &QAction::setShortcut);
  cut_act->setStatusTip(tr("Cut the selected item"));

  QMenu *help_menu = menuBar()->addMenu(tr("&Help"));
  QAction *about_act =
      help_menu->addAction(tr("&About"), this, &MainWindow::aboutApp);
  about_act->setStatusTip(tr("Show the application's About box"));
  QAction *about_qt_act =
      help_menu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
  about_qt_act->setStatusTip(tr("Show the Qt library's About box"));
}

void MainWindow::aboutApp() {
  QMessageBox::about(this, QString("About %1").arg(config::project_name),
                     QString("<p>Version: %1</p>"
                             "<p>Copyright %3 %4. All rights reserved.</p>")
                         .arg(config::project_version)
                         .arg(QDate::currentDate().year())
                         .arg(config::organization_name));
}

void MainWindow::settingsApp() {
  SettingsDialog settings_dialog(m_Settings.get(), this);
  settings_dialog.exec();
}

void MainWindow::createProject() { qInfo("createProject"); }

void MainWindow::openProject() { qInfo("openProject"); }

void MainWindow::saveProject() { qInfo("saveProject"); }

void MainWindow::saveAsProject() { qInfo("saveAsProject"); }

void MainWindow::doUndo() { qInfo("doUndo"); }

void MainWindow::doRedo() { qInfo("doRedo"); }

void MainWindow::doCopy() { qInfo("doCopy"); }

void MainWindow::doPaste() { qInfo("doPaste"); }

void MainWindow::doCut() { qInfo("doCut"); }

Settings *MainWindow::settings() const { return m_Settings.get(); }

}  // namespace room_sketcher