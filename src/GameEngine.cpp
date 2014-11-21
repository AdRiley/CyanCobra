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

