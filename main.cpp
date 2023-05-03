#include "LinkSequence.h"
#include "SequenceUnit.h"
#include "Vector.h"
#include "VectorController.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<Vector>("Model", 1, 0, "Vector");
    qmlRegisterType<SequenceUnit>("Model", 1, 0, "Unit");
    qmlRegisterType<VectorController>("Controller", 1, 0, "VectorController");
    qmlRegisterType<LinkSequence>("Controller", 1, 0, "LinkSequence");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
