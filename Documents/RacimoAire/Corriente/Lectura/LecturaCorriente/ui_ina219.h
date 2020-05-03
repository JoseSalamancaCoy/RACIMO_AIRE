/********************************************************************************
** Form generated from reading UI file 'ina219.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INA219_H
#define UI_INA219_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_INA219
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *INA219)
    {
        if (INA219->objectName().isEmpty())
            INA219->setObjectName(QStringLiteral("INA219"));
        INA219->resize(400, 300);
        centralWidget = new QWidget(INA219);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 30, 101, 31));
        INA219->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(INA219);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 27));
        INA219->setMenuBar(menuBar);
        mainToolBar = new QToolBar(INA219);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        INA219->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(INA219);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        INA219->setStatusBar(statusBar);

        retranslateUi(INA219);

        QMetaObject::connectSlotsByName(INA219);
    } // setupUi

    void retranslateUi(QMainWindow *INA219)
    {
        INA219->setWindowTitle(QApplication::translate("INA219", "INA219", Q_NULLPTR));
        pushButton->setText(QApplication::translate("INA219", "LeerCorriente", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class INA219: public Ui_INA219 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INA219_H
