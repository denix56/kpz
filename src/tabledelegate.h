#ifndef TABLEDELAGTE_H
#define TABLEDELAGTE_H

#include <QItemDelegate>
#include <QLineEdit>

class TableDelagte : public QItemDelegate
{

public:
    TableDelagte();

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &,
                          const QModelIndex &) const;
};

#endif // TABLEDELAGTE_H
