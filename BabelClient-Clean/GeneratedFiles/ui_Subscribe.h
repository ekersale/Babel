/********************************************************************************
** Form generated from reading UI file 'Subscribe.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSCRIBE_H
#define UI_SUBSCRIBE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Subscribe
{
public:
    QLabel *_label_logo;
    QLineEdit *_lineLogin;
    QLineEdit *_linePassword;
    QPushButton *_btnSubscribe;
    QLineEdit *_lineBirthsday;
    QLineEdit *_lineLocation;
    QLineEdit *_linePhoneNumber;
    QLabel *_labelBigLogo;

    void setupUi(QWidget *Subscribe)
    {
        if (Subscribe->objectName().isEmpty())
            Subscribe->setObjectName(QStringLiteral("Subscribe"));
        Subscribe->resize(1080, 929);
        QIcon icon;
        icon.addFile(QStringLiteral("./Images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Subscribe->setWindowIcon(icon);
        _label_logo = new QLabel(Subscribe);
        _label_logo->setObjectName(QStringLiteral("_label_logo"));
        _label_logo->setGeometry(QRect(0, 0, 1080, 929));
        _label_logo->setMinimumSize(QSize(1080, 929));
        _label_logo->setMaximumSize(QSize(1080, 929));
        _label_logo->setPixmap(QPixmap(QString::fromUtf8("./Images/background.png")));
        _lineLogin = new QLineEdit(Subscribe);
        _lineLogin->setObjectName(QStringLiteral("_lineLogin"));
        _lineLogin->setGeometry(QRect(370, 370, 381, 31));
        _linePassword = new QLineEdit(Subscribe);
        _linePassword->setObjectName(QStringLiteral("_linePassword"));
        _linePassword->setGeometry(QRect(370, 450, 381, 31));
        _linePassword->setEchoMode(QLineEdit::Password);
        _btnSubscribe = new QPushButton(Subscribe);
        _btnSubscribe->setObjectName(QStringLiteral("_btnSubscribe"));
        _btnSubscribe->setGeometry(QRect(450, 790, 194, 66));
        QIcon icon1;
        icon1.addFile(QStringLiteral("./Images/btnSubscribe.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnSubscribe->setIcon(icon1);
        _btnSubscribe->setIconSize(QSize(194, 66));
        _lineBirthsday = new QLineEdit(Subscribe);
        _lineBirthsday->setObjectName(QStringLiteral("_lineBirthsday"));
        _lineBirthsday->setGeometry(QRect(370, 530, 381, 31));
        _lineBirthsday->setMinimumSize(QSize(381, 0));
        _lineBirthsday->setCursorPosition(10);
        _lineLocation = new QLineEdit(Subscribe);
        _lineLocation->setObjectName(QStringLiteral("_lineLocation"));
        _lineLocation->setGeometry(QRect(370, 610, 381, 31));
        _linePhoneNumber = new QLineEdit(Subscribe);
        _linePhoneNumber->setObjectName(QStringLiteral("_linePhoneNumber"));
        _linePhoneNumber->setGeometry(QRect(370, 690, 381, 31));
        _labelBigLogo = new QLabel(Subscribe);
        _labelBigLogo->setObjectName(QStringLiteral("_labelBigLogo"));
        _labelBigLogo->setGeometry(QRect(330, 90, 451, 201));
        _labelBigLogo->setPixmap(QPixmap(QString::fromUtf8("./Images/bigLogo.png")));

        retranslateUi(Subscribe);

        QMetaObject::connectSlotsByName(Subscribe);
    } // setupUi

    void retranslateUi(QWidget *Subscribe)
    {
        Subscribe->setWindowTitle(QApplication::translate("Subscribe", "Studio Babel", 0));
        _label_logo->setText(QString());
        _btnSubscribe->setText(QString());
        _lineBirthsday->setText(QApplication::translate("Subscribe", "12/05/2014", 0));
        _lineLocation->setText(QApplication::translate("Subscribe", "Angers", 0));
        _labelBigLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Subscribe: public Ui_Subscribe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCRIBE_H