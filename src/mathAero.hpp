#ifndef mathAeroAERO_H
#define mathAeroAERO_H


#include "QtCore/qstring.h"
class mathAero
{
public:
    mathAero();
    double convertDMSToDecimal(const QString& dmsCoordinate);
};

#endif // mathAeroAERO_H
