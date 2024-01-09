#include "settings_dialog.h"

namespace room_sketcher {

SettingsDialog::SettingsDialog(Settings *settings, QWidget *parent)
    : QDialog(parent), m_Settings(settings) {
  m_GeneralTab = CreateScope<GeneralTab>(settings, this);
  m_ShortcutsTab = CreateScope<ShortcutsTab>(settings, this);
  m_TabWidget->addTab(m_GeneralTab.get(), tr("General"));
  m_TabWidget->addTab(m_ShortcutsTab.get(), tr("Shortcuts"));

  connect(m_ButtonBox.get(), &QDialogButtonBox::accepted, this,
          &SettingsDialog::onAccepted);
  connect(m_ButtonBox.get(), &QDialogButtonBox::rejected, this,
          &QDialog::reject);
  m_MainLayout = CreateScope<QVBoxLayout>();
  m_MainLayout->addWidget(m_TabWidget.get());
  m_MainLayout->addWidget(m_ButtonBox.get());
  setLayout(m_MainLayout.get());
  setWindowTitle(tr("Settings"));
}

void SettingsDialog::onAccepted() {
  m_Settings->setLanguage(m_GeneralTab->language());
  m_Settings->setNewShortcut(m_ShortcutsTab->newShortcut());
  m_Settings->setOpenShortcut(m_ShortcutsTab->openShortcut());
  m_Settings->setSaveShortcut(m_ShortcutsTab->saveShortcut());
  m_Settings->setSaveAsShortcut(m_ShortcutsTab->saveAsShortcut());
  m_Settings->setQuitShortcut(m_ShortcutsTab->quitShortcut());
  m_Settings->setUndoShortcut(m_ShortcutsTab->undoShortcut());
  m_Settings->setRedoShortcut(m_ShortcutsTab->redoShortcut());
  m_Settings->setCopyShortcut(m_ShortcutsTab->copyShortcut());
  m_Settings->setCutShortcut(m_ShortcutsTab->cutShortcut());
  m_Settings->setPasteShortcut(m_ShortcutsTab->pasteShortcut());
  m_Settings->setOptionsShortcut(m_ShortcutsTab->optionsShortcut());
  m_Settings->setFullScreenShortcut(m_ShortcutsTab->fullScreenShortcut());

  accept();
}

GeneralTab::GeneralTab(Settings *settings, QWidget *parent) : QWidget(parent) {
  m_LanguageLabel = CreateScope<QLabel>(tr("Language:"));
  m_LanguageEdit = CreateScope<QComboBox>();
  m_LanguageEdit->addItem(tr("English"), "en_GB");
  m_LanguageEdit->setCurrentIndex(
      m_LanguageEdit->findData(settings->language()));

  m_MainLayout = CreateScope<QVBoxLayout>();
  m_MainLayout->addWidget(m_LanguageLabel.get());
  m_MainLayout->addWidget(m_LanguageEdit.get());
  m_MainLayout->addStretch(1);
  setLayout(m_MainLayout.get());
}

QString GeneralTab::language() const {
  return m_LanguageEdit->currentData().toString();
}

ShortcutsTab::ShortcutsTab(Settings *settings, QWidget *parent)
    : QWidget(parent) {
  m_NewShortcutLabel = CreateScope<QLabel>(tr("New Project:"));
  m_NewShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_NewShortcutEdit->setKeySequence(QKeySequence(settings->newShortcut()));

  m_OpenShortcutLabel = CreateScope<QLabel>(tr("Open Project:"));
  m_OpenShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_OpenShortcutEdit->setKeySequence(QKeySequence(settings->openShortcut()));

  m_SaveShortcutLabel = CreateScope<QLabel>(tr("Save Project:"));
  m_SaveShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_SaveShortcutEdit->setKeySequence(QKeySequence(settings->saveShortcut()));

  m_SaveAsShortcutLabel = CreateScope<QLabel>(tr("Save Project As:"));
  m_SaveAsShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_SaveAsShortcutEdit->setKeySequence(
      QKeySequence(settings->saveAsShortcut()));

  m_QuitShortcutLabel = CreateScope<QLabel>(tr("Quit:"));
  m_QuitShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_QuitShortcutEdit->setKeySequence(QKeySequence(settings->quitShortcut()));

  m_UndoShortcutLabel = CreateScope<QLabel>(tr("Undo:"));
  m_UndoShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_UndoShortcutEdit->setKeySequence(QKeySequence(settings->undoShortcut()));

  m_RedoShortcutLabel = CreateScope<QLabel>(tr("Redo:"));
  m_RedoShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_RedoShortcutEdit->setKeySequence(QKeySequence(settings->redoShortcut()));

  m_CopyShortcutLabel = CreateScope<QLabel>(tr("Copy:"));
  m_CopyShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_CopyShortcutEdit->setKeySequence(QKeySequence(settings->copyShortcut()));

  m_CutShortcutLabel = CreateScope<QLabel>(tr("Cut:"));
  m_CutShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_CutShortcutEdit->setKeySequence(QKeySequence(settings->cutShortcut()));

  m_PasteShortcutLabel = CreateScope<QLabel>(tr("Paste:"));
  m_PasteShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_PasteShortcutEdit->setKeySequence(QKeySequence(settings->pasteShortcut()));

  m_OptionsShortcutLabel = CreateScope<QLabel>(tr("Options:"));
  m_OptionsShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_OptionsShortcutEdit->setKeySequence(
      QKeySequence(settings->optionsShortcut()));

  m_FullScreenShortcutLabel = CreateScope<QLabel>(tr("Full Screen:"));
  m_FullScreenShortcutEdit = CreateScope<QKeySequenceEdit>();
  m_FullScreenShortcutEdit->setKeySequence(
      QKeySequence(settings->fullScreenShortcut()));

  m_MainLayout = CreateScope<QVBoxLayout>();
  m_MainLayout->addWidget(m_NewShortcutLabel.get());
  m_MainLayout->addWidget(m_NewShortcutEdit.get());
  m_MainLayout->addWidget(m_OpenShortcutLabel.get());
  m_MainLayout->addWidget(m_OpenShortcutEdit.get());
  m_MainLayout->addWidget(m_SaveShortcutLabel.get());
  m_MainLayout->addWidget(m_SaveShortcutEdit.get());
  m_MainLayout->addWidget(m_SaveAsShortcutLabel.get());
  m_MainLayout->addWidget(m_SaveAsShortcutEdit.get());
  m_MainLayout->addWidget(m_QuitShortcutLabel.get());
  m_MainLayout->addWidget(m_QuitShortcutEdit.get());
  m_MainLayout->addWidget(m_UndoShortcutLabel.get());
  m_MainLayout->addWidget(m_UndoShortcutEdit.get());
  m_MainLayout->addWidget(m_RedoShortcutLabel.get());
  m_MainLayout->addWidget(m_RedoShortcutEdit.get());
  m_MainLayout->addWidget(m_CopyShortcutLabel.get());
  m_MainLayout->addWidget(m_CopyShortcutEdit.get());
  m_MainLayout->addWidget(m_CutShortcutLabel.get());
  m_MainLayout->addWidget(m_CutShortcutEdit.get());
  m_MainLayout->addWidget(m_PasteShortcutLabel.get());
  m_MainLayout->addWidget(m_PasteShortcutEdit.get());
  m_MainLayout->addWidget(m_OptionsShortcutLabel.get());
  m_MainLayout->addWidget(m_OptionsShortcutEdit.get());
  m_MainLayout->addWidget(m_FullScreenShortcutLabel.get());
  m_MainLayout->addWidget(m_FullScreenShortcutEdit.get());
  m_MainLayout->addStretch(1);
  setLayout(m_MainLayout.get());
}

QString ShortcutsTab::newShortcut() const {
  return m_NewShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::openShortcut() const {
  return m_OpenShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::saveShortcut() const {
  return m_SaveShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::saveAsShortcut() const {
  return m_SaveAsShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::quitShortcut() const {
  return m_QuitShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::undoShortcut() const {
  return m_UndoShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::redoShortcut() const {
  return m_RedoShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::copyShortcut() const {
  return m_CopyShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::cutShortcut() const {
  return m_CutShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::pasteShortcut() const {
  return m_PasteShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::optionsShortcut() const {
  return m_OptionsShortcutEdit->keySequence().toString();
}

QString ShortcutsTab::fullScreenShortcut() const {
  return m_FullScreenShortcutEdit->keySequence().toString();
}

}  // namespace room_sketcher
