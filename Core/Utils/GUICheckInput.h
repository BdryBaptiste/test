#ifndef GUICHECKINPUTS_H
#define GUICHECKINPUTS_H

#include "CheckInputs.h"
#include <QObject>
#include <QEventLoop>
#include "../Display/GUIDisplay.h"
#include <QWidget>
#include <thread>
#include <chrono>

class GUICheckInputs : public QMainWindow, public CheckInputs {
    Q_OBJECT
public:
    Ui::MainWindow *ui;
    QMainWindow *mainWindow;
    GUICheckInputs(Display& display, QWidget *parent = nullptr);
    int getIntegerInput() override;
    char getCharInput() override;
    // std::string getStringInput() override;
    std::pair<int, int> getTwoIntsInput() override;
    std::pair<int, int> position;
    bool waitingForInput;

private slots:
    void on_Board_cellClicked(int row, int column);
};

#endif // GUICHECKINPUTS_H
