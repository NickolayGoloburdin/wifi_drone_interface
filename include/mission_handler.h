#ifndef MISSIONHANDLER_H
#define MISSIONHANDLER_H
#include "abstract_handler.h"
#include <ardupilotmega/mavlink.h>
#include <QVector>
namespace domain
{
class MissionHandler: public AbstractHandler
{
        Q_OBJECT

    public:
        MissionHandler(MavLinkCommunicator* communicator);
    signals:
        void synchronizeSignal(int id, int seq);

    public slots:
        void processMessage(const mavlink_message_t& message) override;
        void missionDataRecieved(QVector<mavlink_mission_item_int_t>* waypoints);
    private:
        QVector<mavlink_mission_item_int_t>* waypoints_;
        QString data;
};
}
#endif // MISSIONHANDLER_H
