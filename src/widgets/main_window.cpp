#include "main_window.h"

#include <config.h>

#include <QAction>
#include <QApplication>
#include <QCoreApplication>
#include <QDateTime>
#include <QKeySequence>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QString>

#include "../core/parameters.h"
#include "create_project_dialog.h"
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
  auto addActionToMenu = [&settings = m_Settings, this](
                             QMenu *menu, const QString &text,
                             const QString &iconName, const QString &shortcut,
                             const QString &statusTip, auto triggeredSlot,
                             auto shortcutChangedSlot) {
    auto action = new QAction(text, this);
    action->setIcon(QIcon::fromTheme(iconName));
    action->setShortcut(shortcut);
    action->setStatusTip(statusTip);
    menu->addAction(action);
    connect(action, &QAction::triggered, this, triggeredSlot);
    connect(settings.get(), shortcutChangedSlot, action, &QAction::setShortcut);
  };

  QMenu *file_menu = menuBar()->addMenu(tr("&File"));
  addActionToMenu(file_menu, tr("&New"), "document-new",
                  m_Settings->newShortcut(), tr("Create a new project"),
                  &MainWindow::createProject, &Settings::newShortcutChanged);
  addActionToMenu(file_menu, tr("&Open"), "document-open",
                  m_Settings->openShortcut(), tr("Open an existing project"),
                  &MainWindow::openProject, &Settings::openShortcutChanged);
  addActionToMenu(file_menu, tr("&Save"), "document-save",
                  m_Settings->saveShortcut(), tr("Save the project"),
                  &MainWindow::saveProject, &Settings::saveShortcutChanged);
  addActionToMenu(file_menu, tr("&Save As"), "document-save-as",
                  m_Settings->saveAsShortcut(),
                  tr("Save the project with a new name"),
                  &MainWindow::saveAsProject, &Settings::saveAsShortcutChanged);
  file_menu->addSeparator();
  addActionToMenu(file_menu, tr("&Settings"), "preferences-system",
                  m_Settings->optionsShortcut(), tr("Open settings dialog"),
                  &MainWindow::settingsApp, &Settings::optionsShortcutChanged);
  file_menu->addSeparator();
  addActionToMenu(file_menu, tr("&Quit"), "application-exit",
                  m_Settings->quitShortcut(), tr("Quit the application"),
                  &QCoreApplication::quit, &Settings::quitShortcutChanged);

  QMenu *edit_menu = menuBar()->addMenu(tr("&Edit"));
  addActionToMenu(edit_menu, tr("&Undo"), "edit-undo",
                  m_Settings->undoShortcut(), tr("Undo the last action"),
                  &MainWindow::doUndo, &Settings::undoShortcutChanged);
  addActionToMenu(edit_menu, tr("&Redo"), "edit-redo",
                  m_Settings->redoShortcut(), tr("Redo the last action"),
                  &MainWindow::doRedo, &Settings::redoShortcutChanged);
  edit_menu->addSeparator();
  addActionToMenu(edit_menu, tr("&Copy"), "edit-copy",
                  m_Settings->copyShortcut(), tr("Copy the selected item"),
                  &MainWindow::doCopy, &Settings::copyShortcutChanged);
  addActionToMenu(edit_menu, tr("&Paste"), "edit-paste",
                  m_Settings->pasteShortcut(), tr("Paste the selected item"),
                  &MainWindow::doPaste, &Settings::pasteShortcutChanged);
  addActionToMenu(edit_menu, tr("&Cut"), "edit-cut", m_Settings->cutShortcut(),
                  tr("Cut the selected item"), &MainWindow::doCut,
                  &Settings::cutShortcutChanged);

  QMenu *help_menu = menuBar()->addMenu(tr("&Help"));
  addActionToMenu(help_menu, tr("&About"), "help-about", "",
                  tr("Show the application's About box"), &MainWindow::aboutApp,
                  &Settings::aboutShortcutChanged);
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
  SettingsDialog dialog(m_Settings.get(), this);
  dialog.exec();
}

void MainWindow::createProject() {
  CreateProjectDialog dialog(this);
  dialog.exec();
  if (dialog.result() == QDialog::Accepted) {
    m_ProjectManager.createProject(dialog.projectSize());
  }
}

void MainWindow::openProject() { qInfo("openProject"); }

void MainWindow::saveProject() { qInfo("saveProject"); }

void MainWindow::saveAsProject() { qInfo("saveAsProject"); }

void MainWindow::doUndo() { qInfo("doUndo"); }

void MainWindow::doRedo() { qInfo("doRedo"); }

void MainWindow::doCopy() { qInfo("doCopy"); }

void MainWindow::doPaste() { qInfo("doPaste"); }

void MainWindow::doCut() { qInfo("doCut"); }

}  // namespace room_sketcher
