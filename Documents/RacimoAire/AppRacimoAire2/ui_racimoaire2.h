/********************************************************************************
** Form generated from reading UI file 'racimoaire2.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACIMOAIRE2_H
#define UI_RACIMOAIRE2_H

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

class Ui_RacimoAire2
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RacimoAire2)
    {
        if (RacimoAire2->objectName().isEmpty())
            RacimoAire2->setObjectName(QStringLiteral("RacimoAire2"));
        RacimoAire2->resize(400, 300);
        menuBar = new QMenuBar(RacimoAire2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RacimoAire2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RacimoAire2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RacimoAire2->addToolBar(mainToolBar);
        centralWidget = new QWidget(RacimoAire2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RacimoAire2->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RacimoAire2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RacimoAire2->setStatusBar(statusBar);

        retranslateUi(RacimoAire2);

        QMetaObject::connectSlotsByName(RacimoAire2);
    } // setupUi

    void retranslateUi(QMainWindow *RacimoAire2)
    {
        RacimoAire2->setWindowTitle(QApplication::translate("RacimoAire2", "RacimoAire2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RacimoAire2: public Ui_RacimoAire2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACIMOAIRE2_H
