#include "create_project_dialog.h"

namespace room_sketcher {

CreateProjectDialog::CreateProjectDialog(QWidget *parent) : QDialog(parent) {
  connect(m_ButtonBox.get(), &QDialogButtonBox::accepted, this,
          &QDialog::accept);
  connect(m_ButtonBox.get(), &QDialogButtonBox::rejected, this,
          &QDialog::reject);
  m_MainLayout->addWidget(m_WidthLabel.get());
  m_MainLayout->addWidget(m_Width.get());
  m_MainLayout->addWidget(m_HeightLabel.get());
  m_MainLayout->addWidget(m_Height.get());
  m_MainLayout->addWidget(m_ButtonBox.get());
  setLayout(m_MainLayout.get());
  setWindowTitle(tr("Create Project"));
}

QSizeF CreateProjectDialog::projectSize() const {
  return {m_Width->value(), m_Height->value()};
}

}  // namespace room_sketcher