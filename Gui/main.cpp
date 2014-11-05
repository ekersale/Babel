#include    "../Includes/IGui.hh"
#include    "../Includes/Connection.hh"


#include    <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IGui    *gui;

    gui = new Connection;
    gui->init();
    
    return a.exec();
}
