#pragma once

#include <QSettings>
#include <QString>

namespace room_sketcher {

class Settings : public QSettings {
  Q_OBJECT

 public:
  explicit Settings(QObject *parent = nullptr);

  [[nodiscard]] QString defaultLanguage() const;
  [[nodiscard]] QString language() const;
  void setLanguage(const QString &language);

  Q_INVOKABLE void resetShortcutsToDefaults();

  [[nodiscard]] QString defaultNewShortcut() const;
  [[nodiscard]] QString newShortcut() const;
  void setNewShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultOpenShortcut() const;
  [[nodiscard]] QString openShortcut() const;
  void setOpenShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultSaveShortcut() const;
  [[nodiscard]] QString saveShortcut() const;
  void setSaveShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultSaveAsShortcut() const;
  [[nodiscard]] QString saveAsShortcut() const;
  void setSaveAsShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultQuitShortcut() const;
  [[nodiscard]] QString quitShortcut() const;
  void setQuitShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultUndoShortcut() const;
  [[nodiscard]] QString undoShortcut() const;
  void setUndoShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultRedoShortcut() const;
  [[nodiscard]] QString redoShortcut() const;
  void setRedoShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultCopyShortcut() const;
  [[nodiscard]] QString copyShortcut() const;
  void setCopyShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultCutShortcut() const;
  [[nodiscard]] QString cutShortcut() const;
  void setCutShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultPasteShortcut() const;
  [[nodiscard]] QString pasteShortcut() const;
  void setPasteShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultOptionsShortcut() const;
  [[nodiscard]] QString optionsShortcut() const;
  void setOptionsShortcut(const QString &shortcut);

  [[nodiscard]] QString defaultFullScreenShortcut() const;
  [[nodiscard]] QString fullScreenShortcut() const;
  void setFullScreenShortcut(const QString &shortcut);

 signals:
  void languageChanged();

  void newShortcutChanged(const QString &shortcut);
  void openShortcutChanged(const QString &shortcut);
  void saveShortcutChanged(const QString &shortcut);
  void saveAsShortcutChanged(const QString &shortcut);
  void quitShortcutChanged(const QString &shortcut);

  void undoShortcutChanged(const QString &shortcut);
  void redoShortcutChanged(const QString &shortcut);
  void copyShortcutChanged(const QString &shortcut);
  void cutShortcutChanged(const QString &shortcut);
  void pasteShortcutChanged(const QString &shortcut);

  void optionsShortcutChanged(const QString &shortcut);
  void fullScreenShortcutChanged(const QString &shortcut);
  void aboutShortcutChanged(const QString &shortcut);
};

}  // namespace room_sketcher
