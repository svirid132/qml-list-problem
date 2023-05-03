#ifndef LINKSEQUENCE_H
#define LINKSEQUENCE_H

#include <QDebug>
#include <QList>
#include "SequenceUnit.h"

class LinkSequence : public QObject {
    Q_OBJECT

public:
    explicit LinkSequence(QObject *parent = 0) { };

    Q_INVOKABLE SequenceUnit* createUnit() {
        return new SequenceUnit();
    }
};

#endif // LINKSEQUENCE_H
