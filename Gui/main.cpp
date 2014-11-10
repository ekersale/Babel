#include    "IGui.hh"
#include    "Connection.hh"

#ifdef _WIN32
#include    <QtWidgets/QApplication>
#else
#include    <QApplication>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IGui    *gui;

    gui = new Connection;
    
    if (gui->init() == false)
      return (-1);
    return a.exec();
}
