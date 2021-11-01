
#include <QApplication>
#include "gcs_communicator_factory.h"
#include "mavlink_communicator.h"
#include "info_communicator.h"
#include "udp_link.h"
#include <tuple>
#include <QMap>
int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    domain::GcsCommunicatorFactory factory;
    domain::MavLinkCommunicator *communicator;
    domain::InfoCommunicator* infcommun;


    std::tie(communicator, infcommun) = factory.create();
    communicator->setParent(&app);



    //domain::UdpLink drone1(14551, QString("192.168.2.1"), 14550);
    //domain::UdpLink drone2(14551, QString("192.168.2.2"), 14550);
    //domain::UdpLink linkinfo(7777, QString("127.0.0.1"), 7776);
    //domain::SerialLink link("/dev/ttyUSB0", 57600);
    //communicator->addLink(&drone1, MAVLINK_COMM_0);
    //communicator->addLink(&drone2, 1);

    //infcommun->addLink(&linkinfo, 0);
    //linkinfo.up();
    //drone1.up();
    //drone2.up();
    return app.exec();
}
