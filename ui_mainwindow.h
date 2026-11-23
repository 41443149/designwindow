/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionwwf;
    QAction *actionqfqf;
    QAction *actionqfwq;
    QAction *actionwgw;
    QAction *actionqtf;
    QAction *action22t;
    QAction *actionfq;
    QAction *actiontgk;
    QAction *actionkt;
    QAction *actionxs;
    QAction *action_T;
    QAction *action_C;
    QAction *action_A;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionwwf = new QAction(MainWindow);
        actionwwf->setObjectName("actionwwf");
        actionqfqf = new QAction(MainWindow);
        actionqfqf->setObjectName("actionqfqf");
        actionqfwq = new QAction(MainWindow);
        actionqfwq->setObjectName("actionqfwq");
        actionwgw = new QAction(MainWindow);
        actionwgw->setObjectName("actionwgw");
        actionqtf = new QAction(MainWindow);
        actionqtf->setObjectName("actionqtf");
        action22t = new QAction(MainWindow);
        action22t->setObjectName("action22t");
        actionfq = new QAction(MainWindow);
        actionfq->setObjectName("actionfq");
        actiontgk = new QAction(MainWindow);
        actiontgk->setObjectName("actiontgk");
        actionkt = new QAction(MainWindow);
        actionkt->setObjectName("actionkt");
        actionxs = new QAction(MainWindow);
        actionxs->setObjectName("actionxs");
        action_T = new QAction(MainWindow);
        action_T->setObjectName("action_T");
        action_C = new QAction(MainWindow);
        action_C->setObjectName("action_C");
        action_A = new QAction(MainWindow);
        action_A->setObjectName("action_A");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menu);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(menu_2->menuAction());
        menu->addSeparator();
        menu_2->addAction(actionqfqf);
        menu_2->addAction(actionqfwq);
        menu_2->addAction(actionwgw);
        menu_2->addSeparator();
        menu_2->addAction(actionqtf);
        menu_2->addAction(action22t);
        menu_2->addSeparator();
        menu_2->addAction(actionfq);
        menu_3->addAction(actionxs);
        menu_3->addAction(action_T);
        menu_3->addAction(action_C);
        menu_3->addAction(action_A);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionwwf->setText(QCoreApplication::translate("MainWindow", "wwf", nullptr));
        actionqfqf->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236(&N)", nullptr));
#if QT_CONFIG(shortcut)
        actionqfqf->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionqfwq->setText(QCoreApplication::translate("MainWindow", "\351\226\213\345\225\237(&O)", nullptr));
#if QT_CONFIG(shortcut)
        actionqfwq->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionwgw->setText(QCoreApplication::translate("MainWindow", "\351\227\234\351\226\211(&C)", nullptr));
        actionqtf->setText(QCoreApplication::translate("MainWindow", "\345\204\262\345\255\230(&S)", nullptr));
#if QT_CONFIG(shortcut)
        actionqtf->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action22t->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230(&A)", nullptr));
        actionfq->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", nullptr));
        actiontgk->setText(QCoreApplication::translate("MainWindow", "\345\234\250\346\255\244\350\274\270\345\205\245", nullptr));
        actionkt->setText(QCoreApplication::translate("MainWindow", "kt", nullptr));
        actionxs->setText(QCoreApplication::translate("MainWindow", "\351\202\204\345\216\237(&U)", nullptr));
#if QT_CONFIG(shortcut)
        actionxs->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_T->setText(QCoreApplication::translate("MainWindow", "\345\211\252\344\270\213(&T)", nullptr));
#if QT_CONFIG(shortcut)
        action_T->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_C->setText(QCoreApplication::translate("MainWindow", "\350\244\207\350\243\275(&C)", nullptr));
#if QT_CONFIG(shortcut)
        action_C->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        action_A->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\201\270(&A)", nullptr));
#if QT_CONFIG(shortcut)
        action_A->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\252\224\346\241\210", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\351\226\213\345\225\237(&D)", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\347\267\250\350\274\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
