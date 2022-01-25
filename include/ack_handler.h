#ifndef ACK_HANDLER_H
#define ACK_HANDLER_H
#include "abstract_handler.h"
#include <ardupilotmega/mavlink.h>
namespace domain
{
 class AckHandler: public AbstractHandler
{
        Q_OBJECT

    public:
        AckHandler(MavLinkCommunicator* communicator);
    signals:
        void missionSignal(mavlink_mission_request_t mission_req, int id);
        void commandSignal(int id, bool res);
        void missionackSignal(int type, int id);

    public slots:
        void processMessage(const mavlink_message_t& message) override;
};
}
#endif // ACK_HANDLER_H
