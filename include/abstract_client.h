#ifndef ABSTRACTCLIENT_H
#define ABSTRACTCLIENT_H


#include <QObject>

namespace domain
{
class AbstractClient: public QObject
{
        Q_OBJECT

    public:
        explicit AbstractClient(QObject* parent = nullptr);

        virtual bool isUp() const = 0;

    public slots:

        virtual void sendData(const QByteArray& data) = 0;

};
}
#endif // ABSTRACTCLIENT_H
