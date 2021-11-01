#ifndef GPS_HANDLER_H
#define GPS_HANDLER_H
#include "abstract_handler.h"

namespace domain
{
    class GPSHandler: public AbstractHandler
    {
        Q_OBJECT

    public:
        GPSHandler(MavLinkCommunicator* communicator);
    signals:
        void gpsSignal( const QString& id, int sattelites);
    public slots:
        void processMessage(const mavlink_message_t& message) override;
    };
}
#endif // GPS_HANDLER_H
