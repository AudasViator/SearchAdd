#ifndef CONGRATULATIONSDIALOG_H
#define CONGRATULATIONSDIALOG_H

#include <QDialog>
#include "attempt.h"

namespace Ui {
class CongratulationsDialog;
}

class CongratulationsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CongratulationsDialog(QWidget *parent = 0);
    ~CongratulationsDialog();

    void setAttempt(Attempt* attempt);

private:
    Ui::CongratulationsDialog *ui;
};

#endif // CONGRATULATIONSDIALOG_H
