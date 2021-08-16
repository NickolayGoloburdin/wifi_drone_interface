#include "mainwindow.h"

#include <QApplication>
#include "gcs_communicator_factory.h"
#include "mavlink_communicator.h"
#include "info_communicator.h"

#include "udp_link.h"
#include <tuple>
int main(int argc, char *argv[])
{


    QApplication app(argc, argv);

    domain::GcsCommunicatorFactory factory;
    domain::MavLinkCommunicator *communicator;
    domain::InfoCommunicator* infcommun;
    std::tie(communicator, infcommun) = factory.create();
    communicator->setParent(&app);

    domain::UdpLink link(14551, QString("127.0.0.1"), 58047);
    domain::UdpLink linkinfo(7777, QString("127.0.0.1"), 7776);
    //domain::SerialLink link("/dev/ttyUSB0", 57600);
    communicator->addLink(&link, MAVLINK_COMM_0);
    infcommun->addLink(&linkinfo, 0);
    linkinfo.up();
    link.up();
    return app.exec();
}
