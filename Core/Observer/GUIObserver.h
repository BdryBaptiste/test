#ifndef GUIOBSERVER_H
#define GUIOBSERVER_H

#include <string>
#include "InterfaceObserver.h"
#include "../Display/MainWindow.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class GUIObserver : public InterfaceObserver, public QWidget{
public:
    GUIObserver();
    QWidget *mainWindow;
    QVBoxLayout *layout;

    void updateStart() override;
    void updateBoard(Board& board) override;
    void updateInstructions(const std::string &status) override;
    void updateMessage(const std::string &status) override;
    void updateWarning(const std::string &status) override;
    void updateMenu(const std::string& menuItem) override;
    void updatePositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves) override;

};

#endif // GUIOBSERVER_H
