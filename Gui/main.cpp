#include    "../Includes/IGui.h"
#include    "../Includes/Connection.h"


#include    <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IGui    *gui;

    gui = new Connection;
    gui->init();
    //Connection w;
    //w.show();
    return a.exec();
}
