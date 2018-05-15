/********************************************************************************
** Form generated from reading UI file 'mw1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MW1_H
#define UI_MW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MW1
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MW1)
    {
        if (MW1->objectName().isEmpty())
            MW1->setObjectName(QStringLiteral("MW1"));
        MW1->resize(800, 600);
        menubar = new QMenuBar(MW1);
        menubar->setObjectName(QStringLiteral("menubar"));
        MW1->setMenuBar(menubar);
        centralwidget = new QWidget(MW1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MW1->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MW1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MW1->setStatusBar(statusbar);

        retranslateUi(MW1);

        QMetaObject::connectSlotsByName(MW1);
    } // setupUi

    void retranslateUi(QMainWindow *MW1)
    {
        MW1->setWindowTitle(QApplication::translate("MW1", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MW1: public Ui_MW1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MW1_H
