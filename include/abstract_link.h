#ifndef ABSTRACT_LINK_H
#define ABSTRACT_LINK_H

#include <QObject>

namespace domain
{
class AbstractLink: public QObject
{
        Q_OBJECT

        Q_PROPERTY(bool isUp READ isUp NOTIFY upChanged)

    public:
        explicit AbstractLink(QObject* parent = nullptr);

        virtual bool isUp() const = 0;
        virtual int id() = 0;
    public slots:
        virtual void up() = 0;
        virtual void down() = 0;
        virtual void connected() = 0;
        virtual void disconnected() = 0;
        virtual void sendData(const QByteArray& data) = 0;
        virtual void reconnect() = 0;


    signals:
        void upChanged(bool isUp);
        void dataReceived(const QByteArray& data);
        void connect(int &uuid, bool connection);
};
}

#endif // ABSTRACT_LINK_H
