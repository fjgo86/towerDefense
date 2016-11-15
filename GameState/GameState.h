#pragma once
class GameState {
public:

    char const* nombreEstado = "";

    virtual void handleInput() = 0;
    virtual void onTick() = 0;

    GameState();
    virtual ~GameState();
};

