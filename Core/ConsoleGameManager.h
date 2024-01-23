#ifndef CONSOLEGAMEMANAGER_H
#define CONSOLEGAMEMANAGER_H

#include "GameManager.h"
#include "Utils/ConsoleCheckInput.h"
#include "Display/DisplayConsole.h"

class ConsoleGameManager : public GameManager
{
public:
    ConsoleGameManager();
    void startGameLoop() override;

private:
    std::shared_ptr<DisplayConsole> display;
    std::shared_ptr<ConsoleCheckInputs> checkInput;
    int getGameChoice();
    char getReplayChoice();
    int getModeChoice();
    void configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2);
};


#endif // CONSOLEGAMEMANAGER_H
