/********************************************************************************
** Form generated from reading UI file 'racimoaire.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RACIMOAIRE_H
#define UI_RACIMOAIRE_H

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

class Ui_RACIMOAIRE
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RACIMOAIRE)
    {
        if (RACIMOAIRE->objectName().isEmpty())
            RACIMOAIRE->setObjectName(QStringLiteral("RACIMOAIRE"));
        RACIMOAIRE->resize(400, 300);
        menuBar = new QMenuBar(RACIMOAIRE);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RACIMOAIRE->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RACIMOAIRE);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RACIMOAIRE->addToolBar(mainToolBar);
        centralWidget = new QWidget(RACIMOAIRE);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RACIMOAIRE->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RACIMOAIRE);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RACIMOAIRE->setStatusBar(statusBar);

        retranslateUi(RACIMOAIRE);

        QMetaObject::connectSlotsByName(RACIMOAIRE);
    } // setupUi

    void retranslateUi(QMainWindow *RACIMOAIRE)
    {
        RACIMOAIRE->setWindowTitle(QApplication::translate("RACIMOAIRE", "RACIMOAIRE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RACIMOAIRE: public Ui_RACIMOAIRE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RACIMOAIRE_H
