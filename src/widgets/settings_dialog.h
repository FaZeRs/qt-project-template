#pragma once

#include <qboxlayout.h>
#include <qcombobox.h>
#include <qdialog.h>
#include <qdialogbuttonbox.h>
#include <qkeysequenceedit.h>
#include <qlabel.h>
#include <qtabwidget.h>
#include <qtmetamacros.h>
#include <qwidget.h>

#include "../core/base.h"
#include "../core/settings.h"

namespace room_sketcher {

class GeneralTab : public QWidget {
  Q_OBJECT

 public:
  explicit GeneralTab(Settings *settings, QWidget *parent = nullptr);
  QString language() const;

 private:
  Scope<QVBoxLayout> m_MainLayout;
  Scope<QLabel> m_LanguageLabel;
  Scope<QComboBox> m_LanguageEdit;
};

class ShortcutsTab : public QWidget {
  Q_OBJECT

 public:
  explicit ShortcutsTab(Settings *settings, QWidget *parent = nullptr);
  QString newShortcut() const;
  QString openShortcut() const;
  QString saveShortcut() const;
  QString saveAsShortcut() const;
  QString quitShortcut() const;
  QString undoShortcut() const;
  QString redoShortcut() const;
  QString copyShortcut() const;
  QString cutShortcut() const;
  QString pasteShortcut() const;
  QString optionsShortcut() const;
  QString fullScreenShortcut() const;

 private:
  Scope<QVBoxLayout> m_MainLayout;
  Scope<QLabel> m_NewShortcutLabel;
  Scope<QKeySequenceEdit> m_NewShortcutEdit;
  Scope<QLabel> m_OpenShortcutLabel;
  Scope<QKeySequenceEdit> m_OpenShortcutEdit;
  Scope<QLabel> m_SaveShortcutLabel;
  Scope<QKeySequenceEdit> m_SaveShortcutEdit;
  Scope<QLabel> m_SaveAsShortcutLabel;
  Scope<QKeySequenceEdit> m_SaveAsShortcutEdit;
  Scope<QLabel> m_QuitShortcutLabel;
  Scope<QKeySequenceEdit> m_QuitShortcutEdit;
  Scope<QLabel> m_UndoShortcutLabel;
  Scope<QKeySequenceEdit> m_UndoShortcutEdit;
  Scope<QLabel> m_RedoShortcutLabel;
  Scope<QKeySequenceEdit> m_RedoShortcutEdit;
  Scope<QLabel> m_CopyShortcutLabel;
  Scope<QKeySequenceEdit> m_CopyShortcutEdit;
  Scope<QLabel> m_CutShortcutLabel;
  Scope<QKeySequenceEdit> m_CutShortcutEdit;
  Scope<QLabel> m_PasteShortcutLabel;
  Scope<QKeySequenceEdit> m_PasteShortcutEdit;
  Scope<QLabel> m_OptionsShortcutLabel;
  Scope<QKeySequenceEdit> m_OptionsShortcutEdit;
  Scope<QLabel> m_FullScreenShortcutLabel;
  Scope<QKeySequenceEdit> m_FullScreenShortcutEdit;
};

class SettingsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit SettingsDialog(Settings *settings, QWidget *parent = nullptr);

 private:
  Scope<QTabWidget> m_TabWidget{CreateScope<QTabWidget>()};
  Scope<QDialogButtonBox> m_ButtonBox{CreateScope<QDialogButtonBox>(
      QDialogButtonBox::Ok | QDialogButtonBox::Cancel)};
  Scope<QVBoxLayout> m_MainLayout;
  Scope<GeneralTab> m_GeneralTab;
  Scope<ShortcutsTab> m_ShortcutsTab;
  Settings *m_Settings;

 private slots:
  void onAccepted();
};

}  // namespace room_sketcher