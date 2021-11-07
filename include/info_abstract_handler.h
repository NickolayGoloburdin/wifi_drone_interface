#ifndef INFO_ABSTRACT_HANDLER_H
#define INFO_ABSTRACT_HANDLER_H


// Qt
#include <QObject>

namespace domain
{
class InfoCommunicator;

class InfoAbstractHandler: public QObject
{
    Q_OBJECT

public:
    explicit InfoAbstractHandler(InfoCommunicator* communicator);

protected slots:
    virtual void processMessage(QString message) = 0;

protected:
    InfoCommunicator* const m_communicator;
};
}


#endif // INFO_ABSTRACT_HANDLER_H
