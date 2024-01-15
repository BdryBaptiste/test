#include "ConsoleGameManager.h"

ConsoleGameManager::ConsoleGameManager() {
    display.reset(new Display());
    checkInputs = CheckInputs::getInstance(*display);
}

void ConsoleGameManager::startGameLoop() {
    bool playAgain = true;
    ConsoleObserver consoleObserver;
    display->addObserver(&consoleObserver);

    while (playAgain) {

        display->notifyStart();
        display->notifyInstructionsUpdate("Choisissez un jeu:");
        display->notifyGameChoiceMenuUpdate();

        int gameChoice = getGameChoice();
        std::shared_ptr<Player> player1, player2;
        int modeChoice = getModeChoice();

        configurePlayers(modeChoice, player1, player2);

        switch (gameChoice) {
        case 1:
            currentGame.reset(new TicTacToe(*display, player1.get(), player2.get()));
            break;
        case 2:
            currentGame.reset(new ConnectFour(*display, player1.get(), player2.get()));
            break;
        case 3:
            currentGame.reset(new Othello(*display, player1.get(), player2.get()));
            break;
        default:
            display->notifyWarningUpdate("Choix invalide!");
            continue;
        }

        currentGame->playGame();

        char replayChoice = getReplayChoice();
        playAgain = (replayChoice == 'o' || replayChoice == 'O');
    }
}

int ConsoleGameManager::getGameChoice() {
    display->notifyInstructionsUpdate("Choisissez un jeu (1/2/3/4): ");
    int choiceGame = checkInputs->getIntegerInput();

    while (choiceGame < 1 || choiceGame > 3) {
        display->notifyWarningUpdate("Choix invalide. Entrez 1, 2, 3 ou 4.");
        choiceGame = checkInputs->getIntegerInput();
    }

    return choiceGame;
}

int ConsoleGameManager::getModeChoice() {
    display->notifyInstructionsUpdate("Choisissez le mode de jeu:");
    display->notifyModeChoiceMenuUpdate();
    int modeChoice = checkInputs->getIntegerInput();

    while (modeChoice < 1 || modeChoice > 3) {
        display->notifyWarningUpdate("Choix invalide. Entrez 1/2/3.");
        modeChoice = checkInputs->getIntegerInput();
    }

    return modeChoice;
}

char ConsoleGameManager::getReplayChoice() {
    display->notifyWarningUpdate("Voulez-vous rejouer ? (o/n): ");
    char replayChoice = checkInputs->getCharInput();
    replayChoice = tolower(replayChoice);

    while (replayChoice != 'o' && replayChoice != 'n') {
        display->notifyWarningUpdate("Choix invalide. Entrez 'o' pour oui ou 'n' pour non.");
        replayChoice = checkInputs->getCharInput();
        replayChoice = tolower(replayChoice);
    }

    return replayChoice;
}

void ConsoleGameManager::configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2) {;
    player1.reset();
    player2.reset();

    switch (modeChoice) {
    case 1:  // Joueur vs Ordinateur
        player1.reset(new HumanPlayer(*display));
        player2.reset(new AIPlayer());
        break;
    case 2:  // Deux Joueurs
        player1.reset(new HumanPlayer(*display));
        player2.reset(new HumanPlayer(*display));
        break;
    case 3:  // Ordinateur vs Ordinateur
        player1.reset(new AIPlayer());
        player2.reset(new AIPlayer());
        break;
    default:
        throw std::runtime_error("Mode de jeu inconnu");
    }
}
