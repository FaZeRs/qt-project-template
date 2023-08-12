#include "mainwindow.h"

#include <config.h>

#include <QApplication>
#include <QDate>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QStyle>

#include "../core/settings.h"

namespace room_sketcher {

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags) {
  setObjectName("MainWindow");
  setWindowTitle(config::project_name);

  setupMenuBar();

  statusBar()->showMessage(tr("Status Bar"));
}

void MainWindow::setupMenuBar() {
  QMenu *file_menu = menuBar()->addMenu(tr("&File"));
  QAction *new_act = file_menu->addAction(tr("&New"));
  new_act->setShortcut(QKeySequence::New);
  new_act->setStatusTip(tr("Create a new project"));
  QAction *open_act = file_menu->addAction(tr("&Open"));
  open_act->setShortcut(QKeySequence::Open);
  open_act->setStatusTip(tr("Open an existing project"));
  QAction *save_act = file_menu->addAction(tr("&Save"));
  save_act->setShortcut(QKeySequence::Save);
  save_act->setStatusTip(tr("Save the project to disk"));
  QAction *save_as_act = file_menu->addAction(tr("&Save As"));
  save_as_act->setShortcut(QKeySequence::SaveAs);
  save_as_act->setStatusTip(tr("Save the project to disk with a new name"));
  file_menu->addSeparator();
  QAction *quit_act =
      file_menu->addAction(tr("&Quit"), qApp, &QCoreApplication::quit);
  quit_act->setShortcut(QKeySequence::Quit);
  quit_act->setStatusTip(tr("Quit the application"));

  QMenu *edit_menu = menuBar()->addMenu(tr("&Edit"));
  QAction *undo_act = edit_menu->addAction(tr("&Undo"));
  undo_act->setShortcut(QKeySequence::Undo);
  undo_act->setStatusTip(tr("Undo the last action"));
  QAction *redo_act = edit_menu->addAction(tr("&Redo"));
  redo_act->setShortcut(QKeySequence::Redo);
  redo_act->setStatusTip(tr("Redo the last action"));
  edit_menu->addSeparator();
  QAction *copy_act = edit_menu->addAction(tr("&Copy"));
  copy_act->setShortcut(QKeySequence::Copy);
  copy_act->setStatusTip(tr("Copy the selected item"));
  QAction *paste_act = edit_menu->addAction(tr("&Paste"));
  paste_act->setShortcut(QKeySequence::Paste);
  paste_act->setStatusTip(tr("Paste the selected item"));
  QAction *cut_act = edit_menu->addAction(tr("&Cut"));
  cut_act->setShortcut(QKeySequence::Cut);
  cut_act->setStatusTip(tr("Cut the selected item"));

  QMenu *tools_menu = menuBar()->addMenu(tr("&Tools"));
  tools_menu->addAction(tr("&Options"));

  QMenu *help_menu = menuBar()->addMenu(tr("&Help"));
  QAction *about_act =
      help_menu->addAction(tr("&About"), this, &MainWindow::about);
  about_act->setStatusTip(tr("Show the application's About box"));
  QAction *about_qt_act =
      help_menu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
  about_qt_act->setStatusTip(tr("Show the Qt library's About box"));
}

void MainWindow::about() {
  QMessageBox::about(this, QString("About %1").arg(config::project_name),
                     QString("<p>Version: %1</p>"
                             "<p>Copyright %3 %4. All rights reserved.</p>")
                         .arg(config::project_version)
                         .arg(QDate::currentDate().year())
                         .arg(config::organization_name));
}

}  // namespace room_sketcher