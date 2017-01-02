#include "play_game_view.h"

#include "../gameClient/game.h"

PlayGameView::PlayGameView() {

    this->setCenter((float)gGame._screenWidth * -1.5f, (float)gGame._screenHeight * 1.5f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    quickGame = new BigButton("", "Partida Rapida");
    quickGame->setFillColor(sf::Color::Black);
    quickGame->setPosition(gGame._screenWidth * 0.25f, gGame._screenHeight * 0.2f);

    rankedGame = new BigButton("", "Partida Competitiva");
    rankedGame->setFillColor(sf::Color::Magenta);
    rankedGame->setPosition(gGame._screenWidth * 0.5f, gGame._screenHeight * 0.2f);

    versusIaGame = new BigButton("", "Partida Competitiva");
    versusIaGame->setFillColor(sf::Color::Blue);
    versusIaGame->setPosition(gGame._screenWidth * 0.75f, gGame._screenHeight * 0.2f);

    goBackButton = new LittleButton("Atras");
    goBackButton->setFillColor(sf::Color::Green);
    goBackButton->setPosition(gGame._screenWidth * 0.99f, gGame._screenHeight * 0.99f);

    quickGame->setOutlineThickness(2.f);
    rankedGame->setOutlineThickness(2.f);
    versusIaGame->setOutlineThickness(2.f);
    goBackButton->setOutlineThickness(2.f);
}

void PlayGameView::onTick() {

    gGame._gameWindow->setView((*this));

    gGame._gameWindow->draw(*quickGame);
    gGame._gameWindow->draw(*rankedGame);
    gGame._gameWindow->draw(*versusIaGame);

    gGame._gameWindow->draw(*goBackButton);
}

void PlayGameView::handleInput(sf::Event &event) {
    
    if (event.MouseMoved) {

        quickGameBounds = quickGame->getGlobalBounds();
        rankedGameBounds = rankedGame->getGlobalBounds();
        versusIaGameBounds = versusIaGame->getGlobalBounds();
        goBackBounds = goBackButton->getGlobalBounds();

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
        else if (goBackBounds.contains((sf::Vector2f)mousePos)) {

            focusedButton = goBackButton;
        }
        else {

            focusedButton = nullptr;
            quickGame->setOutlineThickness(2.f);
            rankedGame->setOutlineThickness(2.f);
            versusIaGame->setOutlineThickness(2.f);
            goBackButton->setOutlineThickness(2.f);
        }

        if (focusedButton != nullptr) {

            focusedButton->setOutlineThickness(5.f);
        }
    }
}

PlayGameView::~PlayGameView() {

    delete quickGame;
    delete rankedGame;
    delete versusIaGame;
}