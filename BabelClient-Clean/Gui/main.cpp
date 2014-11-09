#include	"../Includes/IGui.hh"
#include	"../Includes/Connection.hh"

#ifdef		_WIN32
#include	<QtWidgets/QApplication>
#else
#include	<QApplication>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IGui    *gui;

    gui = new Connection;
    gui->init();
    
    return a.exec();
}
