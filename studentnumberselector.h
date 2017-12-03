#ifndef STUDENTNUMBERSELECTOR_H
#define STUDENTNUMBERSELECTOR_H

#include <QWidget>

namespace Ui {
class StudentNumberSelector;
}

class StudentNumberSelector : public QWidget
{
    Q_OBJECT

public:
    explicit StudentNumberSelector(QWidget *parent = 0);
    ~StudentNumberSelector();

private slots:
    void on_goButton_clicked();

private:
    Ui::StudentNumberSelector *ui;
};

#endif // STUDENTNUMBERSELECTOR_H
