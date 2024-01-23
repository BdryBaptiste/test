#ifndef GUIDISPLAY_H
#define GUIDISPLAY_H

#include "display.h"
#include <QWidget>
#include <string>
#include "../ui_MainWindow.h"

class GUIDisplay :public QMainWindow, public Display {
    Q_OBJECT
public:
    Ui::MainWindow *ui;
    QMainWindow *mainWindow;
    explicit GUIDisplay(QWidget *parent = nullptr);
    void displayBoard(const Board& board) override;
    void displayPositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves) override;
    void showMessage(const std::string& message) override;
    void displayInstructions() override;

};

#endif // GUIDISPLAY_H
