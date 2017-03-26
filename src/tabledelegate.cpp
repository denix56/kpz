#include "tabledelegate.h"

TableDelagte::TableDelagte()
{

}

QWidget* TableDelagte::createEditor(QWidget *parent, const QStyleOptionViewItem &,
                      const QModelIndex &) const
{
    QLineEdit *lineEdit = new QLineEdit(parent);
    lineEdit->setFrame(false);
    // Set validator
    QIntValidator *validator = new QIntValidator(0, 100, lineEdit);
    lineEdit->setValidator(validator);
    return lineEdit;
}
