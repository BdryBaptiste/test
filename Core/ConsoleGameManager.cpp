#include "ConsoleGameManager.h"


ConsoleGameManager::ConsoleGameManager() {
    display.reset(new DisplayConsole());

    checkInput.reset(new ConsoleCheckInputs(*display));
}

void ConsoleGameManager::startGameLoop() {
    bool playAgain = true;

    while (playAgain) {
        display->showMessage("Choisissez un jeu:");
        display->showMessage("1. Tic Tac Toe");
        display->showMessage("2. Connect Four");
        display->showMessage("3. Othello");
        display->showMessage("4. Daughter");

        int gameChoice = getGameChoice();
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
            display->showMessage("Choix invalide!");
            continue;
        }

        currentGame->playGame();

        char replayChoice = getReplayChoice();
        playAgain = (replayChoice == 'o' || replayChoice == 'O');
    }
}

int ConsoleGameManager::getGameChoice() {
    display->showMessage("Choisissez un jeu (1/2/3/4): ");
    int choiceGame = checkInput->getIntegerInput();

    while (choiceGame < 1 || choiceGame > 3) {
        display->showMessage("Choix invalide. Entrez 1, 2, 3 ou 4.");
        choiceGame = checkInput->getIntegerInput();
    }

    return choiceGame;
}

int ConsoleGameManager::getModeChoice() {
    display->showMessage("Choisissez le mode de jeu:");
    display->showMessage("1. Joueur vs ordinateur");
    display->showMessage("2. Deux joueurs");
    display->showMessage("3. Ordinateur vs ordinateur ");
    int modeChoice = checkInput->getIntegerInput();

    while (modeChoice < 1 || modeChoice > 3) {
        display->showMessage("Choix invalide. Entrez 1/2/3.");
        modeChoice = checkInput->getIntegerInput();
    }

    return modeChoice;
}

char ConsoleGameManager::getReplayChoice() {
    display->showMessage("Voulez-vous rejouer ? (o/n): ");
    char replayChoice = checkInput->getCharInput();
    replayChoice = tolower(replayChoice);

    while (replayChoice != 'o' && replayChoice != 'n') {
        display->showMessage("Choix invalide. Entrez 'o' pour oui ou 'n' pour non.");
        replayChoice = checkInput->getCharInput();
        replayChoice = tolower(replayChoice);
    }

    return replayChoice;
}

void ConsoleGameManager::configurePlayers(int modeChoice, std::shared_ptr<Player>& player1, std::shared_ptr<Player>& player2) {;
    switch (modeChoice) {
    case 1:  // Joueur vs Ordinateur
        player1.reset(new HumanPlayer(*display, *checkInput));
        player2.reset(new AIPlayer());
        break;
    case 2:  // Deux Joueurs
        player1.reset(new HumanPlayer(*display, *checkInput));
        player2.reset(new HumanPlayer(*display, *checkInput));
        break;
    case 3:  // Ordinateur vs Ordinateur
        player1.reset(new AIPlayer());
        player2.reset(new AIPlayer());
        break;
    default:
        throw std::runtime_error("Mode de jeu inconnu");
    }
}
