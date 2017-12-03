#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class GameOverDialog;
}

class GameOverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameOverDialog(QWidget *parent = 0);
    ~GameOverDialog();

private:
    Ui::GameOverDialog *ui;
};

#endif // GAMEOVERDIALOG_H
