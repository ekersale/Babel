/********************************************************************************
** Form generated from reading UI file 'Home.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Home
{
public:
    QWidget *centralwidget;
    QLabel *_label_background;
    QLabel *_label_logo;
    QLabel *_label_bandeau;
    QLabel *_label_backgroundBtnAdd;
    QLabel *_label_backgroundBtnCall;
    QTextEdit *_text_chat;
    QLineEdit *_text_msg;
    QPushButton *_btnClose;
    QLineEdit *_line_addContact;
    QPushButton *_btnAddContact;
    QPushButton *_btnInviteContact;
    QPushButton *_btnMicro;
    QPushButton *_btnCam;
    QPushButton *_btnHangUp;
    QLabel *_label_name;
    QLabel *_label_nickname;
    QLabel *_label_PhoneNumberImg;
    QLabel *_label_Localisation;
    QLabel *_label_Birthsday;
    QListWidget *_listContact;
    QPushButton *_btn_Online;
    QPushButton *_btn_Away;
    QPushButton *_btn_Busy;
    QLabel *_label_Video;
    QLabel *_label_StatusInfos;
    QLabel *label;
    QLabel *_label_VideoPerso;
    QLineEdit *_lineContactName;
    QLineEdit *_lineSurnameEdit;
    QLineEdit *_linePhoneNumber;
    QLineEdit *_lineLocalisation;
    QLineEdit *_lineBirthday;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Home)
    {
        if (Home->objectName().isEmpty())
            Home->setObjectName(QString::fromUtf8("Home"));
        Home->resize(1080, 929);
        Home->setMaximumSize(QSize(1080, 929));
        Home->setSizeIncrement(QSize(1080, 929));
        Home->setBaseSize(QSize(1080, 929));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Home->setWindowIcon(icon);
        centralwidget = new QWidget(Home);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setMinimumSize(QSize(1080, 929));
        centralwidget->setMaximumSize(QSize(1080, 929));
        centralwidget->setSizeIncrement(QSize(1080, 929));
        centralwidget->setBaseSize(QSize(1080, 929));
        _label_background = new QLabel(centralwidget);
        _label_background->setObjectName(QString::fromUtf8("_label_background"));
        _label_background->setGeometry(QRect(0, 0, 1080, 929));
        _label_background->setMinimumSize(QSize(1080, 929));
        _label_background->setMaximumSize(QSize(1080, 929));
        _label_background->setPixmap(QPixmap(QString::fromUtf8("Images/background.png")));
        _label_background->setScaledContents(true);
        _label_logo = new QLabel(centralwidget);
        _label_logo->setObjectName(QString::fromUtf8("_label_logo"));
        _label_logo->setGeometry(QRect(80, 60, 131, 61));
        _label_logo->setPixmap(QPixmap(QString::fromUtf8("Images/logo.png")));
        _label_bandeau = new QLabel(centralwidget);
        _label_bandeau->setObjectName(QString::fromUtf8("_label_bandeau"));
        _label_bandeau->setGeometry(QRect(294, 130, 791, 109));
        _label_bandeau->setMinimumSize(QSize(781, 109));
        _label_bandeau->setMaximumSize(QSize(805, 109));
        _label_bandeau->setBaseSize(QSize(805, 109));
        _label_bandeau->setPixmap(QPixmap(QString::fromUtf8("Images/bandeau.png")));
        _label_backgroundBtnAdd = new QLabel(centralwidget);
        _label_backgroundBtnAdd->setObjectName(QString::fromUtf8("_label_backgroundBtnAdd"));
        _label_backgroundBtnAdd->setGeometry(QRect(0, 816, 281, 64));
        _label_backgroundBtnAdd->setMinimumSize(QSize(271, 64));
        _label_backgroundBtnAdd->setMaximumSize(QSize(281, 64));
        _label_backgroundBtnAdd->setPixmap(QPixmap(QString::fromUtf8("Images/backgroundBtnAdd.png")));
        _label_backgroundBtnAdd->setScaledContents(true);
        _label_backgroundBtnCall = new QLabel(centralwidget);
        _label_backgroundBtnCall->setObjectName(QString::fromUtf8("_label_backgroundBtnCall"));
        _label_backgroundBtnCall->setGeometry(QRect(302, 570, 771, 52));
        _label_backgroundBtnCall->setPixmap(QPixmap(QString::fromUtf8("Images/backgroundBtnCall.png")));
        _text_chat = new QTextEdit(centralwidget);
        _text_chat->setObjectName(QString::fromUtf8("_text_chat"));
        _text_chat->setGeometry(QRect(300, 630, 771, 211));
        _text_chat->setMinimumSize(QSize(771, 211));
        _text_chat->setMaximumSize(QSize(771, 211));
        _text_chat->setBaseSize(QSize(771, 211));
        _text_chat->setFrameShape(QFrame::NoFrame);
        _text_chat->setReadOnly(true);
        _text_msg = new QLineEdit(centralwidget);
        _text_msg->setObjectName(QString::fromUtf8("_text_msg"));
        _text_msg->setGeometry(QRect(300, 850, 771, 31));
        _btnClose = new QPushButton(centralwidget);
        _btnClose->setObjectName(QString::fromUtf8("_btnClose"));
        _btnClose->setGeometry(QRect(1010, 70, 40, 40));
        _btnClose->setMinimumSize(QSize(40, 40));
        _btnClose->setMaximumSize(QSize(40, 40));
        _btnClose->setSizeIncrement(QSize(40, 40));
        _btnClose->setBaseSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Images/btnClose.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnClose->setIcon(icon1);
        _btnClose->setIconSize(QSize(40, 40));
        _btnClose->setFlat(true);
        _line_addContact = new QLineEdit(centralwidget);
        _line_addContact->setObjectName(QString::fromUtf8("_line_addContact"));
        _line_addContact->setGeometry(QRect(0, 790, 281, 23));
        _line_addContact->setMinimumSize(QSize(281, 23));
        _line_addContact->setMaximumSize(QSize(281, 23));
        _line_addContact->setMaxLength(10);
        _line_addContact->setClearButtonEnabled(false);
        _btnAddContact = new QPushButton(centralwidget);
        _btnAddContact->setObjectName(QString::fromUtf8("_btnAddContact"));
        _btnAddContact->setGeometry(QRect(120, 827, 43, 43));
        _btnAddContact->setMinimumSize(QSize(43, 43));
        _btnAddContact->setMaximumSize(QSize(43, 43));
        _btnAddContact->setBaseSize(QSize(43, 43));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Images/btnAddContact.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnAddContact->setIcon(icon2);
        _btnAddContact->setIconSize(QSize(43, 43));
        _btnAddContact->setFlat(true);
        _btnInviteContact = new QPushButton(centralwidget);
        _btnInviteContact->setObjectName(QString::fromUtf8("_btnInviteContact"));
        _btnInviteContact->setGeometry(QRect(620, 580, 25, 24));
        _btnInviteContact->setIcon(icon2);
        _btnInviteContact->setIconSize(QSize(25, 25));
        _btnInviteContact->setFlat(true);
        _btnMicro = new QPushButton(centralwidget);
        _btnMicro->setObjectName(QString::fromUtf8("_btnMicro"));
        _btnMicro->setGeometry(QRect(680, 580, 25, 25));
        _btnMicro->setMinimumSize(QSize(25, 25));
        _btnMicro->setMaximumSize(QSize(25, 25));
        _btnMicro->setBaseSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("Images/btnMicro.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnMicro->setIcon(icon3);
        _btnMicro->setIconSize(QSize(25, 25));
        _btnMicro->setFlat(true);
        _btnCam = new QPushButton(centralwidget);
        _btnCam->setObjectName(QString::fromUtf8("_btnCam"));
        _btnCam->setGeometry(QRect(740, 580, 25, 25));
        _btnCam->setMinimumSize(QSize(25, 25));
        _btnCam->setMaximumSize(QSize(25, 25));
        _btnCam->setBaseSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Images/btnCam.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnCam->setIcon(icon4);
        _btnCam->setIconSize(QSize(25, 25));
        _btnCam->setFlat(true);
        _btnHangUp = new QPushButton(centralwidget);
        _btnHangUp->setObjectName(QString::fromUtf8("_btnHangUp"));
        _btnHangUp->setGeometry(QRect(850, 580, 25, 25));
        _btnHangUp->setMinimumSize(QSize(25, 25));
        _btnHangUp->setMaximumSize(QSize(25, 25));
        _btnHangUp->setText(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("Images/btnHangUp.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btnHangUp->setIcon(icon5);
        _btnHangUp->setIconSize(QSize(25, 25));
        _btnHangUp->setFlat(true);
        _label_name = new QLabel(centralwidget);
        _label_name->setObjectName(QString::fromUtf8("_label_name"));
        _label_name->setGeometry(QRect(330, 190, 71, 21));
        _label_name->setStyleSheet(QString::fromUtf8("QLabel#_label_name {\n"
"	color : white;\n"
"}"));
        _label_nickname = new QLabel(centralwidget);
        _label_nickname->setObjectName(QString::fromUtf8("_label_nickname"));
        _label_nickname->setGeometry(QRect(330, 150, 81, 21));
        _label_nickname->setAutoFillBackground(false);
        _label_nickname->setStyleSheet(QString::fromUtf8("QLabel#_label_nickname {\n"
"	color : white;\n"
"}"));
        _label_PhoneNumberImg = new QLabel(centralwidget);
        _label_PhoneNumberImg->setObjectName(QString::fromUtf8("_label_PhoneNumberImg"));
        _label_PhoneNumberImg->setGeometry(QRect(600, 150, 25, 25));
        _label_PhoneNumberImg->setMinimumSize(QSize(25, 25));
        _label_PhoneNumberImg->setMaximumSize(QSize(25, 25));
        _label_PhoneNumberImg->setPixmap(QPixmap(QString::fromUtf8("Images/btnPhoneNumber.png")));
        _label_Localisation = new QLabel(centralwidget);
        _label_Localisation->setObjectName(QString::fromUtf8("_label_Localisation"));
        _label_Localisation->setGeometry(QRect(600, 190, 25, 25));
        _label_Localisation->setMinimumSize(QSize(25, 25));
        _label_Localisation->setMaximumSize(QSize(25, 25));
        _label_Localisation->setPixmap(QPixmap(QString::fromUtf8("Images/btnLocalisation.png")));
        _label_Birthsday = new QLabel(centralwidget);
        _label_Birthsday->setObjectName(QString::fromUtf8("_label_Birthsday"));
        _label_Birthsday->setGeometry(QRect(850, 150, 25, 25));
        _label_Birthsday->setPixmap(QPixmap(QString::fromUtf8("Images/btnBirthday.png")));
        _listContact = new QListWidget(centralwidget);
        _listContact->setObjectName(QString::fromUtf8("_listContact"));
        _listContact->setGeometry(QRect(0, 143, 281, 641));
        _listContact->setFrameShape(QFrame::NoFrame);
        _btn_Online = new QPushButton(centralwidget);
        _btn_Online->setObjectName(QString::fromUtf8("_btn_Online"));
        _btn_Online->setGeometry(QRect(10, 9, 31, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("Images/greenStatus.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btn_Online->setIcon(icon6);
        _btn_Online->setIconSize(QSize(32, 32));
        _btn_Online->setFlat(true);
        _btn_Away = new QPushButton(centralwidget);
        _btn_Away->setObjectName(QString::fromUtf8("_btn_Away"));
        _btn_Away->setGeometry(QRect(50, 9, 31, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("Images/orangeStatus.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btn_Away->setIcon(icon7);
        _btn_Away->setIconSize(QSize(32, 32));
        _btn_Away->setFlat(true);
        _btn_Busy = new QPushButton(centralwidget);
        _btn_Busy->setObjectName(QString::fromUtf8("_btn_Busy"));
        _btn_Busy->setGeometry(QRect(90, 9, 31, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("Images/redStatus.png"), QSize(), QIcon::Normal, QIcon::Off);
        _btn_Busy->setIcon(icon8);
        _btn_Busy->setIconSize(QSize(32, 32));
        _btn_Busy->setFlat(true);
        _label_Video = new QLabel(centralwidget);
        _label_Video->setObjectName(QString::fromUtf8("_label_Video"));
        _label_Video->setGeometry(QRect(380, 240, 611, 321));
        _label_Video->setScaledContents(true);
        _label_StatusInfos = new QLabel(centralwidget);
        _label_StatusInfos->setObjectName(QString::fromUtf8("_label_StatusInfos"));
        _label_StatusInfos->setGeometry(QRect(140, 13, 71, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(289, 129, 2, 680));
        label->setPixmap(QPixmap(QString::fromUtf8("Images/BabelHD_0000s_0001s_0001s_0003_separation-(bkg).png")));
        _label_VideoPerso = new QLabel(centralwidget);
        _label_VideoPerso->setObjectName(QString::fromUtf8("_label_VideoPerso"));
        _label_VideoPerso->setGeometry(QRect(380, 450, 161, 111));
        _label_VideoPerso->setScaledContents(true);
        _lineContactName = new QLineEdit(centralwidget);
        _lineContactName->setObjectName(QString::fromUtf8("_lineContactName"));
        _lineContactName->setGeometry(QRect(410, 150, 113, 22));
        _lineContactName->setStyleSheet(QString::fromUtf8("QLineEdit#_lineContactName {\n"
"	background : transparent;\n"
"	color: white;\n"
"}"));
        _lineContactName->setMaxLength(10);
        _lineContactName->setFrame(false);
        _lineContactName->setReadOnly(true);
        _lineContactName->setClearButtonEnabled(false);
        _lineSurnameEdit = new QLineEdit(centralwidget);
        _lineSurnameEdit->setObjectName(QString::fromUtf8("_lineSurnameEdit"));
        _lineSurnameEdit->setGeometry(QRect(410, 190, 113, 22));
        _lineSurnameEdit->setStyleSheet(QString::fromUtf8("QLineEdit#_lineSurnameEdit {\n"
"background : transparent;\n"
"color : white;\n"
"}"));
        _lineSurnameEdit->setMaxLength(10);
        _lineSurnameEdit->setFrame(false);
        _lineSurnameEdit->setReadOnly(true);
        _linePhoneNumber = new QLineEdit(centralwidget);
        _linePhoneNumber->setObjectName(QString::fromUtf8("_linePhoneNumber"));
        _linePhoneNumber->setGeometry(QRect(630, 150, 113, 22));
        _linePhoneNumber->setStyleSheet(QString::fromUtf8("QLineEdit#_linePhoneNumber {\n"
"	background : transparent;\n"
"	color : white;\n"
"}"));
        _linePhoneNumber->setFrame(false);
        _linePhoneNumber->setReadOnly(true);
        _linePhoneNumber->setClearButtonEnabled(false);
        _lineLocalisation = new QLineEdit(centralwidget);
        _lineLocalisation->setObjectName(QString::fromUtf8("_lineLocalisation"));
        _lineLocalisation->setGeometry(QRect(630, 190, 71, 16));
        _lineLocalisation->setStyleSheet(QString::fromUtf8("QLineEdit#_lineLocalisation {\n"
"	background : transparent;\n"
"	color : white;\n"
"}"));
        _lineLocalisation->setFrame(false);
        _lineLocalisation->setReadOnly(true);
        _lineBirthday = new QLineEdit(centralwidget);
        _lineBirthday->setObjectName(QString::fromUtf8("_lineBirthday"));
        _lineBirthday->setGeometry(QRect(890, 160, 113, 16));
        _lineBirthday->setStyleSheet(QString::fromUtf8("QLineEdit#_lineBirthday {\n"
"	background : transparent;\n"
"	color : white;\n"
"}"));
        _lineBirthday->setFrame(false);
        _lineBirthday->setReadOnly(true);
        Home->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Home);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setEnabled(false);
        menubar->setGeometry(QRect(0, 0, 0, 0));
        menubar->setMaximumSize(QSize(0, 0));
        Home->setMenuBar(menubar);
        statusbar = new QStatusBar(Home);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setMaximumSize(QSize(0, 0));
        Home->setStatusBar(statusbar);

        retranslateUi(Home);

        _listContact->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(Home);
    } // setupUi

    void retranslateUi(QMainWindow *Home)
    {
        Home->setWindowTitle(QApplication::translate("Home", "Studio Babel", 0, QApplication::UnicodeUTF8));
        _label_background->setText(QString());
        _label_logo->setText(QString());
        _label_bandeau->setText(QString());
        _label_backgroundBtnAdd->setText(QString());
        _label_backgroundBtnCall->setText(QString());
        _btnClose->setText(QString());
        _btnAddContact->setText(QString());
        _btnInviteContact->setText(QString());
        _btnMicro->setText(QString());
        _btnCam->setText(QString());
        _label_name->setText(QApplication::translate("Home", "Surname :", 0, QApplication::UnicodeUTF8));
        _label_nickname->setText(QApplication::translate("Home", "Name      :", 0, QApplication::UnicodeUTF8));
        _label_PhoneNumberImg->setText(QString());
        _label_Localisation->setText(QString());
        _label_Birthsday->setText(QString());
        _btn_Online->setText(QString());
        _btn_Away->setText(QString());
        _btn_Busy->setText(QString());
        _label_Video->setText(QString());
        _label_StatusInfos->setText(QApplication::translate("Home", "En ligne", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        _label_VideoPerso->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Home: public Ui_Home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
