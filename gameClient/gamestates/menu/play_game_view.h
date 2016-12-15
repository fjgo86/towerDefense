#pragma once

#include "../gameClient/gamestates/menu/viewsWrapper.h"

#include "../gameClient/gamestates/menu/ui/big_button.h"

class PlayGameView : public ViewsWrapper {
private:
    BigButton* pedo;

public:
    PlayGameView();
    ~PlayGameView();

    // onTick del menu jugar
    void onTick();
    // handleInput del menu jugar
    void handleInput(sf::Event &event);
};

