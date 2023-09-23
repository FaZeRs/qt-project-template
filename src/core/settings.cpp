#include "settings.h"

#include <qcontainerfwd.h>
#include <qforeach.h>
#include <qkeysequence.h>
#include <qvariant.h>

class QObject;

namespace room_sketcher {

Settings::Settings(QObject *parent) : QSettings(parent) {}

QString Settings::defaultLanguage() const { return "en_GB"; }

QString Settings::language() const {
  return contains("language") ? value("language").toString()
                              : defaultLanguage();
}

void Settings::setLanguage(const QString &language) {
  const QString existingValue = value("language", defaultLanguage()).toString();
  if (language == existingValue) return;

  setValue("language", language);
  emit languageChanged();
}

void Settings::resetShortcutsToDefaults() {
  static QVector<QString> allShortcuts;
  if (allShortcuts.isEmpty()) {
    allShortcuts.append("newShortcut");
    allShortcuts.append("openShortcut");
    allShortcuts.append("saveShortcut");
    allShortcuts.append("saveAsShortcut");
    allShortcuts.append("quitShortcut");
    allShortcuts.append("undoShortcut");
    allShortcuts.append("redoShortcut");
    allShortcuts.append("copyShortcut");
    allShortcuts.append("cutShortcut");
    allShortcuts.append("pasteShortcut");
    allShortcuts.append("optionsShortcut");
    allShortcuts.append("fullScreenToggleShortcut");
  }

  foreach (const QString &shortcut, allShortcuts) {
    remove(shortcut);
  }
}

// NOLINTNEXTLINE
#define GET_SHORTCUT(shortcutName, defaultValueFunction)         \
  return contains(shortcutName) ? value(shortcutName).toString() \
                                : defaultValueFunction();

// NOLINTNEXTLINE
#define SET_SHORTCUT(shortcutName, defaultValueFunction, notifySignal) \
  QVariant existingValue = value(shortcutName);                        \
  QString existingStringValue = defaultValueFunction();                \
  if (contains(shortcutName)) {                                        \
    existingStringValue = existingValue.toString();                    \
  }                                                                    \
                                                                       \
  if (shortcut == existingStringValue) return;                         \
                                                                       \
  setValue(shortcutName, shortcut);                                    \
  emit notifySignal(shortcut);

QString Settings::defaultNewShortcut() const {
  return QKeySequence(QKeySequence::New).toString();
}

QString Settings::newShortcut() const {
  GET_SHORTCUT("newShortcut", defaultNewShortcut)
}

void Settings::setNewShortcut(const QString &shortcut){
    SET_SHORTCUT("newShortcut", defaultNewShortcut, newShortcutChanged)}

QString Settings::defaultOpenShortcut() const {
  return QKeySequence(QKeySequence::Open).toString();
}

QString Settings::openShortcut() const {
  GET_SHORTCUT("openShortcut", defaultOpenShortcut)
}

void Settings::setOpenShortcut(const QString &shortcut){
    SET_SHORTCUT("openShortcut", defaultOpenShortcut, openShortcutChanged)}

QString Settings::defaultSaveShortcut() const {
  return QKeySequence(QKeySequence::Save).toString();
}

QString Settings::saveShortcut() const {
  GET_SHORTCUT("saveShortcut", defaultSaveShortcut)
}

void Settings::setSaveShortcut(const QString &shortcut){
    SET_SHORTCUT("saveShortcut", defaultSaveShortcut, saveShortcutChanged)}

QString Settings::defaultSaveAsShortcut() const {
  return QKeySequence(QKeySequence::SaveAs).toString();
}

QString Settings::saveAsShortcut() const {
  GET_SHORTCUT("saveAsShortcut", defaultSaveAsShortcut)
}

void Settings::setSaveAsShortcut(const QString &shortcut){
    SET_SHORTCUT("saveAsShortcut", defaultSaveAsShortcut,
                 saveAsShortcutChanged)}

QString Settings::defaultQuitShortcut() const {
  return QKeySequence(QKeySequence::Quit).toString();
}

QString Settings::quitShortcut() const {
  GET_SHORTCUT("quitShortcut", defaultQuitShortcut)
}
void Settings::setQuitShortcut(const QString &shortcut){
    SET_SHORTCUT("quitShortcut", defaultQuitShortcut, quitShortcutChanged)}

QString Settings::defaultUndoShortcut() const {
  return QKeySequence(QKeySequence::Undo).toString();
}

QString Settings::undoShortcut() const {
  GET_SHORTCUT("undoShortcut", defaultUndoShortcut)
}

void Settings::setUndoShortcut(const QString &shortcut){
    SET_SHORTCUT("undoShortcut", defaultUndoShortcut, undoShortcutChanged)}

QString Settings::defaultRedoShortcut() const {
  return QKeySequence(QKeySequence::Redo).toString();
}

QString Settings::redoShortcut() const {
  GET_SHORTCUT("redoShortcut", defaultRedoShortcut)
}

void Settings::setRedoShortcut(const QString &shortcut){
    SET_SHORTCUT("redoShortcut", defaultRedoShortcut, redoShortcutChanged)}

QString Settings::defaultCopyShortcut() const {
  return QKeySequence(QKeySequence::Copy).toString();
}

QString Settings::copyShortcut() const {
  GET_SHORTCUT("copyShortcut", defaultCopyShortcut)
}

void Settings::setCopyShortcut(const QString &shortcut){
    SET_SHORTCUT("copyShortcut", defaultCopyShortcut, copyShortcutChanged)}

QString Settings::defaultCutShortcut() const {
  return QKeySequence(QKeySequence::Cut).toString();
}

QString Settings::cutShortcut() const {
  GET_SHORTCUT("cutShortcut", defaultCutShortcut)
}

void Settings::setCutShortcut(const QString &shortcut){
    SET_SHORTCUT("cutShortcut", defaultCutShortcut, cutShortcutChanged)}

QString Settings::defaultPasteShortcut() const {
  return QKeySequence(QKeySequence::Paste).toString();
}

QString Settings::pasteShortcut() const {
  GET_SHORTCUT("pasteShortcut", defaultPasteShortcut)
}

void Settings::setPasteShortcut(const QString &shortcut){
    SET_SHORTCUT("pasteShortcut", defaultPasteShortcut, pasteShortcutChanged)}

QString Settings::defaultOptionsShortcut() const {
  return QKeySequence(QKeySequence::Preferences).toString();
}

QString Settings::optionsShortcut() const {
  GET_SHORTCUT("optionsShortcut", defaultOptionsShortcut)
}

void Settings::setOptionsShortcut(const QString &shortcut){
    SET_SHORTCUT("optionsShortcut", defaultOptionsShortcut,
                 optionsShortcutChanged)}

QString Settings::defaultFullScreenShortcut() const {
  return QKeySequence(QKeySequence::FullScreen).toString();
}

QString Settings::fullScreenShortcut() const {
  GET_SHORTCUT("fullScreenShortcut", defaultFullScreenShortcut)
}

void Settings::setFullScreenShortcut(const QString &shortcut) {
  SET_SHORTCUT("fullScreenShortcut", defaultFullScreenShortcut,
               fullScreenShortcutChanged)
}

}  // namespace room_sketcher
