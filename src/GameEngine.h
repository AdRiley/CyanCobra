#include <memory>
#include "Input.h"
#include "Player.h"
#include "GameMap.h"
#include "GameMapView.h"

class GameEngine
{
private:
    std::shared_ptr<Input> m_Input;
    std::shared_ptr<Player> m_Player;
    std::shared_ptr<GameMap> m_GameMap;
    std::shared_ptr<GameMapView> m_GameMapView;
public:
    GameEngine(std::shared_ptr<Input> input, std::shared_ptr<Player> player, std::shared_ptr<GameMap> gm, std::shared_ptr<GameMapView> gmv);
    bool ProcessCommand();
private:
    void MovePlayer(int deltaX, int deltaY);
};
