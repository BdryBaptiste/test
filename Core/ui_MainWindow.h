/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel >

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *TicTacToeButton;
    QPushButton *ConnectFourButton;
    QPushButton *OthelloButton;
    QPushButton *DraughtsButton;
    QPushButton *TwoPlayersButton;
    QPushButton *PlayerVsComputerButton;
    QPushButton *ComputerVsComputerButton;
    QPushButton *StartButton;
    QTableWidget *Board;
    QLabel  *Label;

    void setupUi(QMainWindow  *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
        {
            MainWindow->setObjectName("MainWindow");
        }

        MainWindow->resize(554, 545);

        QWidget *centralWidget = new QWidget;
        MainWindow->setCentralWidget(centralWidget);

        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");

        Label = new QLabel (MainWindow);
        Label->setText("Welcome !");
        Label->setAlignment(Qt::AlignCenter);
        Label->adjustSize();

        TicTacToeButton = new QPushButton(MainWindow);
        TicTacToeButton->setObjectName("TicTacToeButton");
        verticalLayout->addWidget(TicTacToeButton);
        TicTacToeButton->hide();

        ConnectFourButton = new QPushButton(MainWindow);
        ConnectFourButton->setObjectName("ConnectFourButton");
        verticalLayout->addWidget(ConnectFourButton);
        ConnectFourButton->hide();

        OthelloButton = new QPushButton(MainWindow);
        OthelloButton->setObjectName("OthelloButton");
        verticalLayout->addWidget(OthelloButton);
        OthelloButton->hide();

        DraughtsButton = new QPushButton(MainWindow);
        DraughtsButton->setObjectName("DraughtsButton");
        verticalLayout->addWidget(DraughtsButton);
        DraughtsButton->hide();

        PlayerVsComputerButton = new QPushButton(MainWindow);
        PlayerVsComputerButton->setObjectName("PlayerVsComputerButton");
        verticalLayout->addWidget(PlayerVsComputerButton);


        TwoPlayersButton = new QPushButton(MainWindow);
        TwoPlayersButton->setObjectName("TwoPlayersButton");
        verticalLayout->addWidget(TwoPlayersButton);

        ComputerVsComputerButton = new QPushButton(MainWindow);
        ComputerVsComputerButton->setObjectName("ComputerVsComputerButton");
        verticalLayout->addWidget(ComputerVsComputerButton);

        StartButton = new QPushButton(MainWindow);
        StartButton->setObjectName("StartButton");
        verticalLayout->addWidget(StartButton);
        StartButton->setEnabled(false);

        Board = new QTableWidget(MainWindow);
        Board->setObjectName("Board");
        verticalLayout->addWidget(Board);
        Board->hide();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow  *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Dialog", nullptr));
        TicTacToeButton->setText(QCoreApplication::translate("MainWindow", "1.TicTacToe", nullptr));
        ConnectFourButton->setText(QCoreApplication::translate("MainWindow", "2.Connect Four", nullptr));
        OthelloButton->setText(QCoreApplication::translate("MainWindow", "3.Othello", nullptr));
        DraughtsButton->setText(QCoreApplication::translate("MainWindow", "4.Draughts", nullptr));
        PlayerVsComputerButton->setText(QCoreApplication::translate("MainWindow", "1. Player vs Computer", nullptr));
        TwoPlayersButton->setText(QCoreApplication::translate("MainWindow", "2. Two Players", nullptr));
        ComputerVsComputerButton->setText(QCoreApplication::translate("MainWindow", "3. Computer vs Computer", nullptr));
        StartButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
