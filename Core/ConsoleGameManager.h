#ifndef CONSOLEGAMEMANAGER_H
#define CONSOLEGAMEMANAGER_H

#include "GameManager.h"
#include "Utils/ConsoleCheckInput.h"

class ConsoleGameManager : public GameManager
{
public:
    ConsoleGameManager();
    void startGameLoop() override;

private:
    ConsoleCheckInputs* checkInputs;
    int getGameChoice() override;
    char getReplayChoice() override;
    int getModeChoice() override;
    void configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2) override;
};


#endif // CONSOLEGAMEMANAGER_H
