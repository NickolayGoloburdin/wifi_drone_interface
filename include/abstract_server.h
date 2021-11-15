#ifndef ABSTRACTSERVER_H
#define ABSTRACTSERVER_H

#include <QHostAddress>
#include <QObject>

namespace domain
{
class AbstractServer: public QObject
{
        Q_OBJECT

        Q_PROPERTY(bool isUp READ isUp NOTIFY upChanged)

    public:
        explicit AbstractServer(QObject* parent = nullptr);

        virtual bool isUp() const = 0;

    public slots:
        virtual void up() = 0;
        virtual void down() = 0;

    signals:
        void upChanged(bool isUp);
        void dataReceived(const QByteArray& data, QString sender);
};
}

#endif // ABSTRACTSERVER_H
