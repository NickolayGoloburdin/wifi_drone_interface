
#include <QApplication>
#include "gcs_communicator_factory.h"
#include "mavlink_communicator.h"
#include "info_communicator.h"

#include <tuple>
#include <QMap>
int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    app.setOrganizationName("IPU");
    app.setOrganizationDomain("IPU");

    domain::GcsCommunicatorFactory factory;
    domain::MavLinkCommunicator *communicator;
    domain::InfoCommunicator* infcommun;


    std::tie(communicator, infcommun) = factory.create();
    communicator->setParent(&app);




    return app.exec();
}
