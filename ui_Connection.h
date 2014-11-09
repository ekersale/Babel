/********************************************************************************
** Form generated from reading UI file 'Connection.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connection
{
public:
    QWidget *centralWidget;
    QLabel *_label_background;
    QLineEdit *_lineLogin;
    QLineEdit *_linePassword;
    QPushButton *_btnConnection;
    QPushButton *_btnSubscribe;
    QLabel *_label_BigLogo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Connection)
    {
        if (Connection->objectName().isEmpty())
            Connection->setObjectName(QString::fromUtf8("Connection"));
        Connection->resize(1080, 929);
        Connection->setMinimumSize(QSize(1080, 929));
        Connection->setMaximumSize(QSize(1080, 929));
        Connection->setBaseSize(QSize(1080, 929));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Connection->setWindowIcon(icon);
        centralWidget = new QWidget(Connection);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        _label_background = new QLabel(centralWidget);
        _label_background->setObjectName(QString::fromUtf8("_label_background"));
        _label_background->setGeometry(QRect(0, 0, 1080, 929));
        _label_background->setMinimumSize(QSize(1080, 929));
        _label_background->setMaximumSize(QSize(1080, 929));
        _label_background->setLayoutDirection(Qt::LeftToRight);
        _label_background->setLineWidth(0);
        _label_background->setText(QString::fromUtf8(""));
        _label_background->setPixmap(QPixmap(QString::fromUtf8("Images/background.png")));
        _label_background->setScaledContents(true);
        _lineLogin = new QLineEdit(centralWidget);
        _lineLogin->setObjectName(QString::fromUtf8("_lineLogin"));
        _lineLogin->setGeometry(QRect(360, 350, 381, 31));
        _linePassword = new QLineEdit(centralWidget);
        _linePassword->setObjectName(QString::fromUtf8("_linePassword"));
        _linePassword->setGeometry(QRect(360, 430, 381, 31));
        _linePassword->setEchoMode(QLineEdit::Password);
        _btnConnection = new QPushButton(centralWidget);
        _btnConnection->setObjectName(QString::fromUtf8("_btnConnection"));
        _btnConnection->setGeometry(QRect(450, 510, 194, 66));
        _btnConnection->setMinimumSize(QSize(194, 66));
        _btnConnection->setMaximumSize(QSize(194, 66));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Images/btnConnection.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnConnection->setIcon(icon1);
        _btnConnection->setIconSize(QSize(194, 66));
        _btnSubscribe = new QPushButton(centralWidget);
        _btnSubscribe->setObjectName(QString::fromUtf8("_btnSubscribe"));
        _btnSubscribe->setGeometry(QRect(450, 630, 194, 66));
        _btnSubscribe->setMinimumSize(QSize(194, 66));
        _btnSubscribe->setMaximumSize(QSize(194, 66));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Images/btnSubscribe.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnSubscribe->setIcon(icon2);
        _btnSubscribe->setIconSize(QSize(194, 66));
        _label_BigLogo = new QLabel(centralWidget);
        _label_BigLogo->setObjectName(QString::fromUtf8("_label_BigLogo"));
        _label_BigLogo->setGeometry(QRect(330, 80, 451, 221));
        _label_BigLogo->setPixmap(QPixmap(QString::fromUtf8("Images/bigLogo.png")));
        Connection->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Connection);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(false);
        mainToolBar->setMaximumSize(QSize(0, 0));
        Connection->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Connection);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(false);
        statusBar->setMaximumSize(QSize(0, 0));
        Connection->setStatusBar(statusBar);

        retranslateUi(Connection);

        QMetaObject::connectSlotsByName(Connection);
    } // setupUi

    void retranslateUi(QMainWindow *Connection)
    {
        Connection->setWindowTitle(QApplication::translate("Connection", "Studio Babel", 0, QApplication::UnicodeUTF8));
        _btnConnection->setText(QString());
        _btnSubscribe->setText(QString());
        _label_BigLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Connection: public Ui_Connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
