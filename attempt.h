#ifndef ATTEMPT_H
#define ATTEMPT_H

#include <QWidget>
#include <QLineEdit>
#include "customdoublevalidator.h"

namespace Ui {
class Attempt;
}

class Attempt : public QWidget
{
    Q_OBJECT

public:
    explicit Attempt(QWidget *parent = 0);
    ~Attempt();

    bool isAdditionsEntered();

    std::vector<float> getAdditionsPercentage();

    void setProperties(std::vector<float> properties);

    void disableEditing();

    void setAttemptNumber(int attemptNumber);

    Attempt* clone();

private:
    Ui::Attempt *ui;

    void disableQLineEdit(QLineEdit* lineEdit);
};

#endif // ATTEMPT_H
