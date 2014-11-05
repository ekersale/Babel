#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include    "IGui.hh"

#include <QWidget>

namespace Ui {
class Subscribe;
}

class Subscribe : public QWidget, public IGui
{
    Q_OBJECT

public:
    explicit Subscribe(QWidget *parent = 0);
    ~Subscribe();
    void    init();
    void    load();
    void    destroy();

private slots:
    void    toSubscribe();

private:
    Ui::Subscribe *ui;
};

#endif // SUBSCRIBE_H
