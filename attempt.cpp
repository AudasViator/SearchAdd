#include "attempt.h"
#include "ui_attempt.h"

#include <cassert>

Attempt::Attempt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Attempt)
{
    ui->setupUi(this);

    ui->calciumEdit->setValidator(new CustomDoubleValidator());
    ui->titaniumEdit->setValidator(new CustomDoubleValidator());
    ui->zincEdit->setValidator(new CustomDoubleValidator());
    ui->siliconEdit->setValidator(new CustomDoubleValidator());
}

Attempt::~Attempt()
{
    delete ui;
}

std::vector<float> Attempt::getAdditionsPercentage()
{
    std::vector<float> additionsPercentage(4);

    QLocale english(QLocale::English);

    additionsPercentage[0] = english.toFloat(ui->calciumEdit->text());
    additionsPercentage[1] = english.toFloat(ui->titaniumEdit->text());
    additionsPercentage[2] = english.toFloat(ui->zincEdit->text());
    additionsPercentage[3] = english.toFloat(ui->siliconEdit->text());

    return additionsPercentage;
}


void Attempt::setProperties(std::vector<float> properties) {
    assert (properties.size() == 4);

    ui->plastisityAnswer->setText(QString::number(properties[0], 'f', 3));
    ui->corrosAnswer->setText(QString::number(properties[1], 'f', 3));
    ui->strengthAnswer->setText(QString::number(properties[2], 'f', 3));
    ui->fluidityAnswer->setText(QString::number(properties[3], 'f', 3));
}

void Attempt::disableEditing()
{
    disableQLineEdit(ui->calciumEdit);
    disableQLineEdit(ui->titaniumEdit);
    disableQLineEdit(ui->zincEdit);
    disableQLineEdit(ui->siliconEdit);
}

Attempt *Attempt::clone()
{
    auto clonedAttempt = new Attempt();

    clonedAttempt->ui->calciumEdit->setText(ui->calciumEdit->text());
    clonedAttempt->ui->titaniumEdit->setText(ui->titaniumEdit->text());
    clonedAttempt->ui->zincEdit->setText(ui->zincEdit->text());
    clonedAttempt->ui->siliconEdit->setText(ui->siliconEdit->text());

    clonedAttempt->ui->plastisityAnswer->setText(ui->plastisityAnswer->text());
    clonedAttempt->ui->corrosAnswer->setText(ui->corrosAnswer->text());
    clonedAttempt->ui->strengthAnswer->setText(ui->strengthAnswer->text());
    clonedAttempt->ui->fluidityAnswer->setText(ui->fluidityAnswer->text());

    return clonedAttempt;
}

void Attempt::disableQLineEdit(QLineEdit* lineEdit)
{
    lineEdit->setReadOnly(true);

    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::lightGray);
    lineEdit->setPalette(*palette);
}
