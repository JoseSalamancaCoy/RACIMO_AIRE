/********************************************************************************
** Form generated from reading UI file 'lecturaopcn2.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LECTURAOPCN2_H
#define UI_LECTURAOPCN2_H

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

class Ui_LecturaOPCN2
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LecturaOPCN2)
    {
        if (LecturaOPCN2->objectName().isEmpty())
            LecturaOPCN2->setObjectName(QStringLiteral("LecturaOPCN2"));
        LecturaOPCN2->resize(400, 300);
        centralWidget = new QWidget(LecturaOPCN2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 50, 95, 30));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 160, 95, 30));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 90, 95, 30));
        LecturaOPCN2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LecturaOPCN2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        LecturaOPCN2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LecturaOPCN2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LecturaOPCN2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LecturaOPCN2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LecturaOPCN2->setStatusBar(statusBar);

        retranslateUi(LecturaOPCN2);

        QMetaObject::connectSlotsByName(LecturaOPCN2);
    } // setupUi

    void retranslateUi(QMainWindow *LecturaOPCN2)
    {
        LecturaOPCN2->setWindowTitle(QApplication::translate("LecturaOPCN2", "LecturaOPCN2", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LecturaOPCN2", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LecturaOPCN2", "OFF_Fan", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("LecturaOPCN2", "Leer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LecturaOPCN2: public Ui_LecturaOPCN2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LECTURAOPCN2_H
