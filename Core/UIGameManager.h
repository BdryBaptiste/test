#ifndef UIGAMEMANAGER_H
#define UIGAMEMANAGER_H

#include <QtWidgets>
#include "ui_MainWindow.h"

class UIGameManager : public QMainWindow
{
    Q_OBJECT
public:
    explicit UIGameManager(QWidget *parent = nullptr);
    ~UIGameManager();

private:
    Ui::MainWindow *ui;

private slots:
    void onTicTacToeButtonClicked();

};

#endif // UIGAMEMANAGER_H
