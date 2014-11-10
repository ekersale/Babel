#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include    "IGui.hh"

#ifdef		_WIN32
#include	<QtWidgets/QWidget>

#else
#include	<QWidget>

#endif

namespace Ui {
class Subscribe;
}

class Subscribe : public QWidget, public IGui
{
    Q_OBJECT

public:
    explicit Subscribe(QWidget *parent = 0);
    ~Subscribe();
    bool    init();
    void    load();
    void    destroy();

private slots:
    void    toSubscribe();

private:
    Ui::Subscribe *ui;
};

#endif // SUBSCRIBE_H
