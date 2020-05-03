/********************************************************************************
** Form generated from reading UI file 'appracimoaire.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPRACIMOAIRE_H
#define UI_APPRACIMOAIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_appRacimoAire
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *appRacimoAire)
    {
        if (appRacimoAire->objectName().isEmpty())
            appRacimoAire->setObjectName(QStringLiteral("appRacimoAire"));
        appRacimoAire->resize(400, 300);
        menuBar = new QMenuBar(appRacimoAire);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        appRacimoAire->setMenuBar(menuBar);
        mainToolBar = new QToolBar(appRacimoAire);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        appRacimoAire->addToolBar(mainToolBar);
        centralWidget = new QWidget(appRacimoAire);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        appRacimoAire->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(appRacimoAire);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        appRacimoAire->setStatusBar(statusBar);

        retranslateUi(appRacimoAire);

        QMetaObject::connectSlotsByName(appRacimoAire);
    } // setupUi

    void retranslateUi(QMainWindow *appRacimoAire)
    {
        appRacimoAire->setWindowTitle(QApplication::translate("appRacimoAire", "appRacimoAire", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class appRacimoAire: public Ui_appRacimoAire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPRACIMOAIRE_H
