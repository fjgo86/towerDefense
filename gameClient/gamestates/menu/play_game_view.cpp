#include "play_game_view.h"

#include "../gameClient/game.h"

PlayGameView::PlayGameView() {

    this->setCenter((float)gGame._screenWidth * -1.5f, (float)gGame._screenHeight * 1.5f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    pedo = new BigButton("", "pedo");
    pedo->setPosition(gGame._screenWidth / 2, 0);
}

void PlayGameView::onTick() {

    gGame._gameWindow->setView((*this));
    gGame._gameWindow->draw(*pedo);
}

void PlayGameView::handleInput(sf::Event &event) {


}

PlayGameView::~PlayGameView() {
}