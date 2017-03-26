#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabledelegate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Lab1, Denys Senkin");

    ui->tableWidget->setItemDelegate(new TableDelagte());
    ui->tableWidget_2->setItemDelegate(new TableDelagte());

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem());
    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem());

    //from first table to second
    connect(ui->tableWidget, &QTableWidget::cellChanged, [&](int row, int column)
    {
        if (row == ui->tableWidget->rowCount() - 1) {
            ui->tableWidget->blockSignals(true);
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(row + 1, column, new QTableWidgetItem());
            ui->tableWidget->blockSignals(false);
        }

        if(row >= ui->tableWidget_2->rowCount()) {
            ui->tableWidget_2->insertRow(row);
            ui->tableWidget_2->setItem(row, column,
                                       new QTableWidgetItem(
                                           ui->tableWidget->item(row, column)->text()));
        } else {
            ui->tableWidget_2->item(row, column)->setText(ui->tableWidget->item(row, column)->text());
        }
    });

    //from second table to first
    connect(ui->tableWidget_2, &QTableWidget::cellChanged, [&](int row, int column)
    {
        if (row == ui->tableWidget_2->rowCount() - 1) {
            ui->tableWidget_2->blockSignals(true);
            ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
            ui->tableWidget_2->setItem(row + 1, column, new QTableWidgetItem());
            ui->tableWidget_2->blockSignals(false);
        }

        if(row >= ui->tableWidget->rowCount()) {
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, column,
                                       new QTableWidgetItem(
                                           ui->tableWidget_2->item(row, column)->text()));
        } else {
            ui->tableWidget->item(row, column)->setText(ui->tableWidget_2->item(row, column)->text());
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
