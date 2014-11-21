#include <memory>
#include "Input.h"
#include "Player.h"

class GameEngine
{
private:
    std::shared_ptr<Input> m_Input;
    std::shared_ptr<Player> m_Player;
public:
    GameEngine(std::shared_ptr<Input> i, std::shared_ptr<Player> p);
    bool ProcessCommand();
private:
    void MovePlayer(int deltaX, int deltaY);
};
