#pragma once

#include "State.h"

class GameState :
    public State
{
private:

public:
    GameState(sf::RenderTarget* window);
    virtual ~GameState();

    //func
    void endState();

    void updateKeyBinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

};

