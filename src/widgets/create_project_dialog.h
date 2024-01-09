#pragma once

#include <qboxlayout.h>
#include <qdialog.h>
#include <qdialogbuttonbox.h>
#include <qlabel.h>

#include <QDoubleSpinBox>

#include "../core/base.h"

namespace room_sketcher {

class CreateProjectDialog : public QDialog {
  Q_OBJECT

 public:
  explicit CreateProjectDialog(QWidget *parent = nullptr);
  QSizeF projectSize() const;

 private:
  Scope<QVBoxLayout> m_MainLayout{CreateScope<QVBoxLayout>()};
  Scope<QDialogButtonBox> m_ButtonBox{CreateScope<QDialogButtonBox>(
      QDialogButtonBox::Ok | QDialogButtonBox::Cancel)};
  Scope<QLabel> m_WidthLabel{CreateScope<QLabel>("Width:")};
  Scope<QDoubleSpinBox> m_Width{CreateScope<QDoubleSpinBox>()};
  Scope<QLabel> m_HeightLabel{CreateScope<QLabel>("Height:")};
  Scope<QDoubleSpinBox> m_Height{CreateScope<QDoubleSpinBox>()};
};

}  // namespace room_sketcher