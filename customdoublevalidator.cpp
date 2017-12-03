#include "customdoublevalidator.h"

CustomDoubleValidator::CustomDoubleValidator() {
    _decimalPoints.append(".");
    _decimalPoints.append(",");
}

CustomDoubleValidator::State CustomDoubleValidator::validate(QString &str, int &pos) const {
    QString s(str);

    for(QStringList::ConstIterator point = _decimalPoints.begin(); point != _decimalPoints.end(); ++point){
        s.replace(*point, locale().decimalPoint());
    }

    return QDoubleValidator::validate(s, pos);
}
