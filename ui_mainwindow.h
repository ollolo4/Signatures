/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 23. Jun 16:44:42 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *Shnor;
    QLineEdit *Sh_M;
    QLineEdit *Sh_p;
    QLineEdit *Sh_q;
    QLineEdit *Sh_b;
    QLineEdit *Sh_r;
    QLineEdit *Sh_a;
    QLineEdit *Sh_x;
    QPushButton *pushSh;
    QLineEdit *Sh_y;
    QLineEdit *Sh_e;
    QLineEdit *Sh_v;
    QPushButton *pushVerify_Sh;
    QLineEdit *Sh;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushSh_M;
    QPushButton *pushButton_p_2;
    QPushButton *pushButton_q;
    QPushButton *pushButton_b;
    QPushButton *pushButton_r_2;
    QPushButton *pushButton_a;
    QPushButton *pushButton_x_2;
    QPushButton *pushButton_e;
    QPushButton *pushButton_y_2;
    QPushButton *pushButton_v;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *El_Gamal;
    QLineEdit *Eg_M;
    QLineEdit *Eg_m;
    QLineEdit *Eg_p;
    QLineEdit *Eg_g;
    QLineEdit *Eg_k;
    QLineEdit *Eg_x;
    QPushButton *pushEg;
    QLabel *label_6;
    QLineEdit *Eg_r;
    QLabel *label_7;
    QLineEdit *Eg_s;
    QLabel *label_8;
    QLineEdit *Eg_y;
    QPushButton *pushVerify_Eg;
    QLineEdit *Eg;
    QPushButton *pushButton_M;
    QPushButton *pushButton_m;
    QPushButton *pushButton_r;
    QPushButton *pushButton_s;
    QPushButton *pushButton_y;
    QPushButton *pushButton_p;
    QPushButton *pushButton_g;
    QPushButton *pushButton_k;
    QPushButton *pushButton_x;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_9;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(509, 552);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(260, 20, 241, 481));
        Shnor = new QGridLayout(gridLayoutWidget_2);
        Shnor->setSpacing(6);
        Shnor->setContentsMargins(11, 11, 11, 11);
        Shnor->setObjectName(QString::fromUtf8("Shnor"));
        Shnor->setContentsMargins(0, 0, 0, 0);
        Sh_M = new QLineEdit(gridLayoutWidget_2);
        Sh_M->setObjectName(QString::fromUtf8("Sh_M"));

        Shnor->addWidget(Sh_M, 1, 1, 1, 1);

        Sh_p = new QLineEdit(gridLayoutWidget_2);
        Sh_p->setObjectName(QString::fromUtf8("Sh_p"));

        Shnor->addWidget(Sh_p, 2, 1, 1, 1);

        Sh_q = new QLineEdit(gridLayoutWidget_2);
        Sh_q->setObjectName(QString::fromUtf8("Sh_q"));

        Shnor->addWidget(Sh_q, 3, 1, 1, 1);

        Sh_b = new QLineEdit(gridLayoutWidget_2);
        Sh_b->setObjectName(QString::fromUtf8("Sh_b"));

        Shnor->addWidget(Sh_b, 4, 1, 1, 1);

        Sh_r = new QLineEdit(gridLayoutWidget_2);
        Sh_r->setObjectName(QString::fromUtf8("Sh_r"));

        Shnor->addWidget(Sh_r, 5, 1, 1, 1);

        Sh_a = new QLineEdit(gridLayoutWidget_2);
        Sh_a->setObjectName(QString::fromUtf8("Sh_a"));

        Shnor->addWidget(Sh_a, 6, 1, 1, 1);

        Sh_x = new QLineEdit(gridLayoutWidget_2);
        Sh_x->setObjectName(QString::fromUtf8("Sh_x"));

        Shnor->addWidget(Sh_x, 8, 1, 1, 1);

        pushSh = new QPushButton(gridLayoutWidget_2);
        pushSh->setObjectName(QString::fromUtf8("pushSh"));

        Shnor->addWidget(pushSh, 9, 1, 1, 1);

        Sh_y = new QLineEdit(gridLayoutWidget_2);
        Sh_y->setObjectName(QString::fromUtf8("Sh_y"));

        Shnor->addWidget(Sh_y, 13, 1, 1, 1);

        Sh_e = new QLineEdit(gridLayoutWidget_2);
        Sh_e->setObjectName(QString::fromUtf8("Sh_e"));

        Shnor->addWidget(Sh_e, 11, 1, 1, 1);

        Sh_v = new QLineEdit(gridLayoutWidget_2);
        Sh_v->setObjectName(QString::fromUtf8("Sh_v"));

        Shnor->addWidget(Sh_v, 15, 1, 1, 1);

        pushVerify_Sh = new QPushButton(gridLayoutWidget_2);
        pushVerify_Sh->setObjectName(QString::fromUtf8("pushVerify_Sh"));

        Shnor->addWidget(pushVerify_Sh, 16, 1, 1, 1);

        Sh = new QLineEdit(gridLayoutWidget_2);
        Sh->setObjectName(QString::fromUtf8("Sh"));
        Sh->setEnabled(false);

        Shnor->addWidget(Sh, 17, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        Shnor->addWidget(label_12, 7, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        Shnor->addWidget(label_13, 14, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        Shnor->addWidget(label_14, 10, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        Shnor->addWidget(label_15, 12, 1, 1, 1);

        pushSh_M = new QPushButton(gridLayoutWidget_2);
        pushSh_M->setObjectName(QString::fromUtf8("pushSh_M"));
        pushSh_M->setEnabled(false);

        Shnor->addWidget(pushSh_M, 1, 0, 1, 1);

        pushButton_p_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_p_2->setObjectName(QString::fromUtf8("pushButton_p_2"));
        pushButton_p_2->setEnabled(false);

        Shnor->addWidget(pushButton_p_2, 2, 0, 1, 1);

        pushButton_q = new QPushButton(gridLayoutWidget_2);
        pushButton_q->setObjectName(QString::fromUtf8("pushButton_q"));
        pushButton_q->setEnabled(false);

        Shnor->addWidget(pushButton_q, 3, 0, 1, 1);

        pushButton_b = new QPushButton(gridLayoutWidget_2);
        pushButton_b->setObjectName(QString::fromUtf8("pushButton_b"));
        pushButton_b->setEnabled(false);

        Shnor->addWidget(pushButton_b, 4, 0, 1, 1);

        pushButton_r_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_r_2->setObjectName(QString::fromUtf8("pushButton_r_2"));
        pushButton_r_2->setEnabled(false);

        Shnor->addWidget(pushButton_r_2, 5, 0, 1, 1);

        pushButton_a = new QPushButton(gridLayoutWidget_2);
        pushButton_a->setObjectName(QString::fromUtf8("pushButton_a"));
        pushButton_a->setEnabled(false);

        Shnor->addWidget(pushButton_a, 6, 0, 1, 1);

        pushButton_x_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_x_2->setObjectName(QString::fromUtf8("pushButton_x_2"));
        pushButton_x_2->setEnabled(false);

        Shnor->addWidget(pushButton_x_2, 8, 0, 1, 1);

        pushButton_e = new QPushButton(gridLayoutWidget_2);
        pushButton_e->setObjectName(QString::fromUtf8("pushButton_e"));
        pushButton_e->setEnabled(false);

        Shnor->addWidget(pushButton_e, 11, 0, 1, 1);

        pushButton_y_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_y_2->setObjectName(QString::fromUtf8("pushButton_y_2"));
        pushButton_y_2->setEnabled(false);

        Shnor->addWidget(pushButton_y_2, 13, 0, 1, 1);

        pushButton_v = new QPushButton(gridLayoutWidget_2);
        pushButton_v->setObjectName(QString::fromUtf8("pushButton_v"));
        pushButton_v->setEnabled(false);

        Shnor->addWidget(pushButton_v, 15, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        Shnor->addWidget(label_10, 0, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 0, 141, 16));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAutoFillBackground(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 0, 171, 16));
        label->setFont(font);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 241, 482));
        El_Gamal = new QGridLayout(gridLayoutWidget);
        El_Gamal->setSpacing(6);
        El_Gamal->setContentsMargins(11, 11, 11, 11);
        El_Gamal->setObjectName(QString::fromUtf8("El_Gamal"));
        El_Gamal->setContentsMargins(0, 0, 0, 0);
        Eg_M = new QLineEdit(gridLayoutWidget);
        Eg_M->setObjectName(QString::fromUtf8("Eg_M"));

        El_Gamal->addWidget(Eg_M, 2, 2, 1, 1);

        Eg_m = new QLineEdit(gridLayoutWidget);
        Eg_m->setObjectName(QString::fromUtf8("Eg_m"));
        Eg_m->setEnabled(true);

        El_Gamal->addWidget(Eg_m, 3, 2, 1, 1);

        Eg_p = new QLineEdit(gridLayoutWidget);
        Eg_p->setObjectName(QString::fromUtf8("Eg_p"));

        El_Gamal->addWidget(Eg_p, 4, 2, 1, 1);

        Eg_g = new QLineEdit(gridLayoutWidget);
        Eg_g->setObjectName(QString::fromUtf8("Eg_g"));

        El_Gamal->addWidget(Eg_g, 5, 2, 1, 1);

        Eg_k = new QLineEdit(gridLayoutWidget);
        Eg_k->setObjectName(QString::fromUtf8("Eg_k"));

        El_Gamal->addWidget(Eg_k, 6, 2, 1, 1);

        Eg_x = new QLineEdit(gridLayoutWidget);
        Eg_x->setObjectName(QString::fromUtf8("Eg_x"));

        El_Gamal->addWidget(Eg_x, 9, 2, 1, 1);

        pushEg = new QPushButton(gridLayoutWidget);
        pushEg->setObjectName(QString::fromUtf8("pushEg"));

        El_Gamal->addWidget(pushEg, 10, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        El_Gamal->addWidget(label_6, 11, 2, 1, 1);

        Eg_r = new QLineEdit(gridLayoutWidget);
        Eg_r->setObjectName(QString::fromUtf8("Eg_r"));

        El_Gamal->addWidget(Eg_r, 12, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        El_Gamal->addWidget(label_7, 13, 2, 1, 1);

        Eg_s = new QLineEdit(gridLayoutWidget);
        Eg_s->setObjectName(QString::fromUtf8("Eg_s"));

        El_Gamal->addWidget(Eg_s, 14, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        El_Gamal->addWidget(label_8, 15, 2, 1, 1);

        Eg_y = new QLineEdit(gridLayoutWidget);
        Eg_y->setObjectName(QString::fromUtf8("Eg_y"));

        El_Gamal->addWidget(Eg_y, 16, 2, 1, 1);

        pushVerify_Eg = new QPushButton(gridLayoutWidget);
        pushVerify_Eg->setObjectName(QString::fromUtf8("pushVerify_Eg"));

        El_Gamal->addWidget(pushVerify_Eg, 17, 2, 1, 1);

        Eg = new QLineEdit(gridLayoutWidget);
        Eg->setObjectName(QString::fromUtf8("Eg"));
        Eg->setEnabled(false);

        El_Gamal->addWidget(Eg, 18, 2, 1, 1);

        pushButton_M = new QPushButton(gridLayoutWidget);
        pushButton_M->setObjectName(QString::fromUtf8("pushButton_M"));
        pushButton_M->setEnabled(false);
        pushButton_M->setAcceptDrops(false);

        El_Gamal->addWidget(pushButton_M, 2, 1, 1, 1);

        pushButton_m = new QPushButton(gridLayoutWidget);
        pushButton_m->setObjectName(QString::fromUtf8("pushButton_m"));

        El_Gamal->addWidget(pushButton_m, 3, 1, 1, 1);

        pushButton_r = new QPushButton(gridLayoutWidget);
        pushButton_r->setObjectName(QString::fromUtf8("pushButton_r"));
        pushButton_r->setEnabled(false);

        El_Gamal->addWidget(pushButton_r, 12, 1, 1, 1);

        pushButton_s = new QPushButton(gridLayoutWidget);
        pushButton_s->setObjectName(QString::fromUtf8("pushButton_s"));
        pushButton_s->setEnabled(false);

        El_Gamal->addWidget(pushButton_s, 14, 1, 1, 1);

        pushButton_y = new QPushButton(gridLayoutWidget);
        pushButton_y->setObjectName(QString::fromUtf8("pushButton_y"));
        pushButton_y->setEnabled(false);

        El_Gamal->addWidget(pushButton_y, 16, 1, 1, 1);

        pushButton_p = new QPushButton(gridLayoutWidget);
        pushButton_p->setObjectName(QString::fromUtf8("pushButton_p"));
        pushButton_p->setEnabled(false);

        El_Gamal->addWidget(pushButton_p, 4, 1, 1, 1);

        pushButton_g = new QPushButton(gridLayoutWidget);
        pushButton_g->setObjectName(QString::fromUtf8("pushButton_g"));
        pushButton_g->setEnabled(false);

        El_Gamal->addWidget(pushButton_g, 5, 1, 1, 1);

        pushButton_k = new QPushButton(gridLayoutWidget);
        pushButton_k->setObjectName(QString::fromUtf8("pushButton_k"));
        pushButton_k->setEnabled(false);

        El_Gamal->addWidget(pushButton_k, 6, 1, 1, 1);

        pushButton_x = new QPushButton(gridLayoutWidget);
        pushButton_x->setObjectName(QString::fromUtf8("pushButton_x"));
        pushButton_x->setEnabled(false);

        El_Gamal->addWidget(pushButton_x, 9, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        El_Gamal->addWidget(label_5, 8, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        El_Gamal->addItem(verticalSpacer_2, 7, 2, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        El_Gamal->addWidget(label_9, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 509, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushSh->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        pushVerify_Sh->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\272\321\200\320\265\321\202\320\275\321\213\320\271 \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\213\320\271 \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\320\260\321\217 \320\277\320\276\320\273\320\276\320\262\320\270\320\275\320\272\320\260 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\260\321\217 \320\277\320\276\320\273\320\276\320\262\320\270\320\275\320\272\320\260 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        pushSh_M->setText(QApplication::translate("MainWindow", "M", 0, QApplication::UnicodeUTF8));
        pushButton_p_2->setText(QApplication::translate("MainWindow", "p", 0, QApplication::UnicodeUTF8));
        pushButton_q->setText(QApplication::translate("MainWindow", "q", 0, QApplication::UnicodeUTF8));
        pushButton_b->setText(QApplication::translate("MainWindow", "b", 0, QApplication::UnicodeUTF8));
        pushButton_r_2->setText(QApplication::translate("MainWindow", "r", 0, QApplication::UnicodeUTF8));
        pushButton_a->setText(QApplication::translate("MainWindow", "a", 0, QApplication::UnicodeUTF8));
        pushButton_x_2->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        pushButton_e->setText(QApplication::translate("MainWindow", "e", 0, QApplication::UnicodeUTF8));
        pushButton_y_2->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        pushButton_v->setText(QApplication::translate("MainWindow", "v", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\205\320\265\320\274\320\260 \320\277\320\276\320\264\320\277\320\270\321\201\320\270 \320\250\320\275\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\241\321\205\320\265\320\274\320\260 \320\277\320\276\320\264\320\277\320\270\321\201\320\270 \320\255\320\273\321\214-\320\223\320\260\320\274\320\260\320\273\321\217", 0, QApplication::UnicodeUTF8));
        pushEg->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\320\260\321\217 \320\277\320\276\320\273\320\276\320\262\320\270\320\275\320\272\320\260 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\260\321\217 \320\277\320\276\320\273\320\276\320\262\320\270\320\275\320\272\320\260 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\213\320\271 \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        pushVerify_Eg->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214 \320\255\320\246\320\237", 0, QApplication::UnicodeUTF8));
        pushButton_M->setText(QApplication::translate("MainWindow", "M", 0, QApplication::UnicodeUTF8));
        pushButton_m->setText(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        pushButton_r->setText(QApplication::translate("MainWindow", "r", 0, QApplication::UnicodeUTF8));
        pushButton_s->setText(QApplication::translate("MainWindow", "s", 0, QApplication::UnicodeUTF8));
        pushButton_y->setText(QApplication::translate("MainWindow", "y", 0, QApplication::UnicodeUTF8));
        pushButton_p->setText(QApplication::translate("MainWindow", "p", 0, QApplication::UnicodeUTF8));
        pushButton_g->setText(QApplication::translate("MainWindow", "g", 0, QApplication::UnicodeUTF8));
        pushButton_k->setText(QApplication::translate("MainWindow", "k", 0, QApplication::UnicodeUTF8));
        pushButton_x->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "C\320\265\320\272\321\200\320\265\321\202\320\275\321\213\320\271 \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
