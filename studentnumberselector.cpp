#include "studentnumberselector.h"
#include "ui_studentnumberselector.h"

#include "mainwindow.h"

StudentNumberSelector::StudentNumberSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentNumberSelector)
{
    ui->setupUi(this);
}

StudentNumberSelector::~StudentNumberSelector()
{
    delete ui;
}

void StudentNumberSelector::on_goButton_clicked()
{
    int studentNumber = ui->numberSpinBox->text().toInt();
    MainWindow* mainWindow = new MainWindow(studentNumber);
    mainWindow->show();
    this->hide();
}
