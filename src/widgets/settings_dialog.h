#pragma once

#include <QBoxLayout>
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QKeySequenceEdit>
#include <QLabel>
#include <QTabWidget>
#include <QWidget>

#include "../core/base.h"
#include "../core/settings.h"

namespace room_sketcher {

class GeneralTab : public QWidget {
  Q_OBJECT

 public:
  explicit GeneralTab(Settings *settings, QWidget *parent = nullptr);
  [[nodiscard]] QString language() const;

 private:
  Scope<QVBoxLayout> m_MainLayout;
  Scope<QLabel> m_LanguageLabel;
  Scope<QComboBox> m_LanguageEdit;
};

class ShortcutsTab : public QWidget {
  Q_OBJECT

 public:
  explicit ShortcutsTab(Settings *settings, QWidget *parent = nullptr);
  [[nodiscard]] QString newShortcut() const;
  [[nodiscard]] QString openShortcut() const;
  [[nodiscard]] QString saveShortcut() const;
  [[nodiscard]] QString saveAsShortcut() const;
  [[nodiscard]] QString quitShortcut() const;
  [[nodiscard]] QString undoShortcut() const;
  [[nodiscard]] QString redoShortcut() const;
  [[nodiscard]] QString copyShortcut() const;
  [[nodiscard]] QString cutShortcut() const;
  [[nodiscard]] QString pasteShortcut() const;
  [[nodiscard]] QString optionsShortcut() const;
  [[nodiscard]] QString fullScreenShortcut() const;

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
