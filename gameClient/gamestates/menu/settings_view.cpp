#include "settings_view.h"

#include "../gameClient/game.h"

SettingsView::SettingsView() {

    this->setCenter((float)gGame._screenWidth * -1.5f, (float)gGame._screenHeight * -0.5f);
    this->setSize((float)gGame._screenWidth, (float)gGame._screenHeight);

    pedo = new BigButton("", "settings");
    pedo->setPosition(gGame._screenWidth / 2, 0);
}

void SettingsView::onTick() {

    gGame._gameWindow->setView((*this));
    gGame._gameWindow->draw(*pedo);
}

void SettingsView::handleInput(sf::Event &event) {


}

SettingsView::~SettingsView() {
}
