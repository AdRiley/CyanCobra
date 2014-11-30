#include "GameEngine.h"

GameEngine::GameEngine(std::shared_ptr<Input> input, std::shared_ptr<Player> player, std::shared_ptr<GameMap> gm, std::shared_ptr<GameMapView> gmv) :
    m_Input{input},
    m_Player{player},
    m_GameMap{gm},
    m_GameMapView{gmv},
    m_IsPassable{
        {Tile::Empty , true},
        {Tile::Floor , true},
        {Tile::Wall  , false},
        {Tile::Player, false}
    }
{
}

bool GameEngine::ProcessCommand()
{
    auto command = m_Input->GetCommand();
    switch (command)
    {
        case Command::Up:
            MovePlayer(0, -1);
            break;
        case Command::Down:
            MovePlayer(0, 1);
            break;
        case Command::Left:
            MovePlayer(-1, 0);
            break;
        case Command::Right:
            MovePlayer(1, 0);
            break;
        case Command::ActionUp:
            Action(0, -1);
            break;
        case Command::ActionDown:
            Action(0, 1);
            break;
        case Command::ActionLeft:
            Action(-1, 0);
            break;
        case Command::ActionRight:
            Action(1, 0);
            break;
        case Command::Exit:
            return false;
            break;
    }
    m_GameMapView->DrawMapAndPlayer(*m_GameMap, *m_Player);
    return true;
}

void GameEngine::MovePlayer(int deltaX, int deltaY)
{
    int destX = m_Player->GetX() + deltaX;
    int destY = m_Player->GetY() + deltaY;
    if (m_IsPassable[m_GameMap->GetTile(destX, destY)])
        m_Player->SetPosition(destX, destY);
}

void GameEngine::Action(int deltaX, int deltaY)
{
    int actionDestX = m_Player->GetX() + deltaX;
    int actionDestY = m_Player->GetY() + deltaY;
    ActionTile(actionDestX, actionDestY);
}

void GameEngine::ActionTile(int x, int y)
{
    auto tile = m_GameMap->GetTile(x, y);
    switch (tile)
    {
        case Tile::ClosedDoor:
            m_GameMap->SetTile(x, y, Tile::OpenDoor);
            break;
        default:
            break;
    }
}

