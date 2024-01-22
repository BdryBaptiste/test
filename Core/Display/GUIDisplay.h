#ifndef GUIDISPLAY_H
#define GUIDISPLAY_H

#include "display.h"
#include <QWidget>
#include <string>

class GUIDisplay : public Display, public QWidget {
    Q_OBJECT
public:
    void displayBoard(const Board& board);
    void displayPositionChoice(const Board& board, const std::vector<std::pair<int, int>>& validMoves);
    void showMessage(const std::string& message);
    void displayInstructions();
};

#endif // GUIDISPLAY_H
