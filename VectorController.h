#ifndef VECTORCONTROLLER_H
#define VECTORCONTROLLER_H

#include "Vector.h"

#include <QObject>

class VectorController : public QObject {
    Q_OBJECT

public:
    explicit VectorController(QObject *parent = 0) { };

    Q_INVOKABLE Vector* createVector() {
        return new Vector();
    }
};

#endif // VECTORCONTROLLER_H
