#ifndef UNITSEQUENCE_H
#define UNITSEQUENCE_H

#include "Vector.h"
#include <QObject>

class SequenceUnit : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QObject* unit READ unit WRITE setUnit NOTIFY unitChanged)

public:
    QString type() {
        return m_type;
    }
    void setType(QString type) {
        if (m_type == type) {
            return;
        }

        emit typeChanged();
        m_type = type;
    }

    QObject* unit() {
        return m_unit;
    }
    void setUnit(QObject* unit) {
        if (m_unit == unit) {
            return;
        }

        emit unitChanged();
        m_unit = unit;
    }

signals:
    void typeChanged();
    void unitChanged();

private:
    QString m_type;
    QObject* m_unit;
};

#endif // UNITSEQUENCE_H
