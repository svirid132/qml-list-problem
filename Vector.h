#ifndef VECTOR_H
#define VECTOR_H

#include <QObject>
#include <QPointF>
#include <QVariantList>

class Vector : public QObject {
    Q_OBJECT
    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY changedIndex)
    Q_PROPERTY(QPointF point READ point WRITE setPoint NOTIFY changedPoint)

public:
    explicit Vector(QObject *parent = 0) {}

    int index() {
        return m_index;
    }
    void setIndex(int index) {
        if (m_index == index) {
            return;
        }

        m_index = index;
        emit changedIndex();
    }

    QPointF point() {
        return m_point;
    }
    void setPoint(const QPointF& point) {
        if (m_point == point) {
            return;
        }

        m_point = point;
        emit changedPoint();
    }

signals:
    void changedIndex();
    void changedPoint();

private:
    int m_index = -1;
    QPointF m_point = QPointF(0, 0);
};
#endif // VECTOR_H
