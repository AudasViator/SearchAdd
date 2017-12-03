#include "congratulationsdialog.h"
#include "ui_congratulationsdialog.h"

CongratulationsDialog::CongratulationsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CongratulationsDialog)
{
    ui->setupUi(this);

    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags helpFlag = Qt::WindowContextHelpButtonHint;
    flags = flags & (~helpFlag);
    setWindowFlags(flags);
}

CongratulationsDialog::~CongratulationsDialog()
{
    delete ui;
}

void CongratulationsDialog::setAttempt(Attempt *attempt)
{
    auto clonedAttempt = attempt->clone();
    clonedAttempt->disableEditing();
    ui->attemptLayout->addWidget(clonedAttempt);
}
