#pragma once

#include <qtmetamacros.h>

#include <QObject>
#include <QSettings>


namespace room_sketcher {

class Settings : public QSettings {
  Q_OBJECT

  Q_PROPERTY(
      QString language READ language WRITE setLanguage NOTIFY languageChanged)
  Q_PROPERTY(qreal windowOpacity READ windowOpacity WRITE setWindowOpacity
                 NOTIFY windowOpacityChanged)
  Q_PROPERTY(bool fpsVisible READ isFpsVisible WRITE setFpsVisible NOTIFY
                 fpsVisibleChanged)

  Q_PROPERTY(QString newShortcut READ newShortcut WRITE setNewShortcut NOTIFY
                 newShortcutChanged)
  Q_PROPERTY(QString openShortcut READ openShortcut WRITE setOpenShortcut NOTIFY
                 openShortcutChanged)
  Q_PROPERTY(QString saveShortcut READ saveShortcut WRITE setSaveShortcut NOTIFY
                 saveShortcutChanged)
  Q_PROPERTY(QString saveAsShortcut READ saveAsShortcut WRITE setSaveAsShortcut
                 NOTIFY saveAsShortcutChanged)
  Q_PROPERTY(QString quitShortcut READ quitShortcut WRITE setQuitShortcut NOTIFY
                 quitShortcutChanged)
  Q_PROPERTY(QString undoShortcut READ undoShortcut WRITE setUndoShortcut NOTIFY
                 undoShortcutChanged)
  Q_PROPERTY(QString redoShortcut READ redoShortcut WRITE setRedoShortcut NOTIFY
                 redoShortcutChanged)
  Q_PROPERTY(QString copyShortcut READ copyShortcut WRITE setCopyShortcut NOTIFY
                 copyShortcutChanged)
  Q_PROPERTY(QString cutShortcut READ cutShortcut WRITE setCutShortcut NOTIFY
                 cutShortcutChanged)
  Q_PROPERTY(QString pasteShortcut READ pasteShortcut WRITE setPasteShortcut
                 NOTIFY pasteShortcutChanged)
  Q_PROPERTY(QString optionsShortcut READ optionsShortcut WRITE
                 setOptionsShortcut NOTIFY optionsShortcutChanged)
  Q_PROPERTY(QString fullScreenShortcut READ fullScreenShortcut WRITE
                 setFullScreenShortcut NOTIFY fullScreenShortcutChanged)

 public:
  explicit Settings(QObject *parent = nullptr);

  [[nodiscard]] QString defaultLanguage() const;
  [[nodiscard]] QString language() const;
  void setLanguage(const QString &language);

  [[nodiscard]] qreal defaultWindowOpacity() const;
  [[nodiscard]] qreal windowOpacity() const;
  void setWindowOpacity(qreal opacity);

  [[nodiscard]] bool defaultFpsVisible() const;
  [[nodiscard]] bool isFpsVisible() const;
  void setFpsVisible(bool fpsVisible);

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
  void windowOpacityChanged();
  void fpsVisibleChanged();

  void newShortcutChanged();
  void openShortcutChanged();
  void saveShortcutChanged();
  void saveAsShortcutChanged();
  void quitShortcutChanged();

  void undoShortcutChanged();
  void redoShortcutChanged();
  void copyShortcutChanged();
  void cutShortcutChanged();
  void pasteShortcutChanged();

  void optionsShortcutChanged();
  void fullScreenShortcutChanged();
};

}  // namespace room_sketcher
