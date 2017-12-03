#ifndef CUSTOMDOUBLEVALIDATOR_H
#define CUSTOMDOUBLEVALIDATOR_H

#include <QDoubleValidator>

class CustomDoubleValidator : public QDoubleValidator {
       QStringList _decimalPoints;
   public:
       CustomDoubleValidator();
       State validate(QString &str, int &pos) const;
};

#endif // CUSTOMDOUBLEVALIDATOR_H
