#include "play_game_view.h"

#include "../gameClient/game.h"

PlayGameView::PlayGameView() {

    this->setCenter((float)gGame._screenWidth * -1.5f, (float)gGame._screenHeight * 1.5f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    quickGame = new BigButton("", "Partida Rapida");
    quickGame->setColor(sf::Color::Green);
    quickGame->setOrigin(quickGame->getGlobalBounds().width / 2, 0.f);
    quickGame->setPosition((float)gGame._screenWidth * 0.25f, gGame._screenHeight * 0.1f);

    //quickGameBounds = quickGame->getGlobalBounds();

    rankedGame = new BigButton("", "Partida Clasificatoria");
    rankedGame->setColor(sf::Color::Cyan);
    rankedGame->setOrigin(rankedGame->getGlobalBounds().width / 2, 0.f);
    rankedGame->setPosition((float)gGame._screenWidth * 0.5f, gGame._screenHeight * 0.1f);

    //rankedGameBounds = rankedGame->getGlobalBounds();

    versusIaGame = new BigButton("", "Partida VS I.A.");
    versusIaGame->setColor(sf::Color::Magenta);
    versusIaGame->setOrigin(versusIaGame->getGlobalBounds().width / 2, 0.f);
    versusIaGame->setPosition((float)gGame._screenWidth * 0.75f, gGame._screenHeight * 0.1f);

    //versusIaGameBounds = versusIaGame->getGlobalBounds();
}

void PlayGameView::onTick() {

    gGame._gameWindow->setView((*this));
    gGame._gameWindow->draw(*quickGame);
    gGame._gameWindow->draw(*rankedGame);
    gGame._gameWindow->draw(*versusIaGame);
}

void PlayGameView::handleInput(sf::Event &event) {

    if (event.MouseMoved) {

        quickGameBounds = quickGame->getGlobalBounds();
        rankedGameBounds = rankedGame->getGlobalBounds();
        versusIaGameBounds = versusIaGame->getGlobalBounds();

        sf::Vector2i mousePos = sf::Mouse::getPosition(*gGame._gameWindow);

        if (quickGameBounds.contains((sf::Vector2f)mousePos)) {

            focusedButton = quickGame;
        }
        else if (rankedGameBounds.contains((sf::Vector2f)mousePos)) {

            focusedButton = rankedGame;
        }
        else if (versusIaGameBounds.contains((sf::Vector2f)mousePos)) {

            focusedButton = versusIaGame;
        }
        else {

            focusedButton = nullptr;
            quickGame->setOutlineThickness(2.f);
            rankedGame->setOutlineThickness(2.f);
            versusIaGame->setOutlineThickness(2.f);
        }

        if (focusedButton != nullptr) {

            std::cout << "no es null" << std::endl;
            focusedButton->setOutlineThickness(5.f);
        }
    }
}

PlayGameView::~PlayGameView() {

    delete quickGame;
    delete rankedGame;
    delete versusIaGame;
}