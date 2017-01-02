#pragma once

#include <memory>

#include "../gameClient/gamestates/menu/viewsWrapper.h"

#include "../gameClient/gamestates/menu/ui/big_button.h"
#include "../gameClient/gamestates/menu/ui/little_button.h"

class PlayGameView : public ViewsWrapper {
private:
    BigButton* quickGame;
    BigButton* rankedGame;
    BigButton* versusIaGame;

    LittleButton* goBackButton;

    sf::RectangleShape* focusedButton;

    sf::FloatRect quickGameBounds, rankedGameBounds, versusIaGameBounds, goBackBounds;

    //std::unique_ptr<BigButton*> focusedButton;

public:
    PlayGameView();
    ~PlayGameView();

    // onTick del menu jugar
    void onTick();
    // handleInput del menu jugar
    void handleInput(sf::Event &event);
};

