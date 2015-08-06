#include "GameEngine.h"

GameEngine::GameEngine(std::shared_ptr<Input> input, std::shared_ptr<Player> player, std::shared_ptr<GameMap> gm, std::shared_ptr<GameMapView> gmv) :
    m_Input{input},
    m_Player{player},
    m_GameMap{gm},
    m_GameMapView{gmv}
{
}

bool GameEngine::ProcessCommand()
{
    auto command = m_Input->GetCommand();
    switch (command)
    {
        case Command::Up:
            MovePlayer(m_Player->GetLocation().Up());
            break;
        case Command::Down:
            MovePlayer(m_Player->GetLocation().Down());
            break;
        case Command::Left:
            MovePlayer(m_Player->GetLocation().Left());
            break;
        case Command::Right:
            MovePlayer(m_Player->GetLocation().Right());
            break;
        case Command::ActionUp:
            Action(m_Player->GetLocation().Up());
            break;
        case Command::ActionDown:
            Action(m_Player->GetLocation().Down());
            break;
        case Command::ActionLeft:
            Action(m_Player->GetLocation().Left());
            break;
        case Command::ActionRight:
            Action(m_Player->GetLocation().Right());
            break;
        case Command::Exit:
            return false;
            break;
    }
    m_GameMapView->DrawMapAndPlayer(*m_GameMap, *m_Player);
    return true;
}

void GameEngine::MovePlayer(Point destination)
{
    if (IsPassable(m_GameMap->GetTile(destination)))
        m_Player->SetLocation(destination);
}

void GameEngine::Action(Point target)
{
    ActionTile(target);
}

void GameEngine::ActionTile(Point target)
{
    auto tile = m_GameMap->GetTile(target);
    switch (tile)
    {
        case Tile::ClosedDoor:
            m_GameMap->SetTile(target, Tile::OpenDoor);
            break;
        case Tile::OpenDoor:
            m_GameMap->SetTile(target, Tile::ClosedDoor);
            break;
        default:
            break;
    }
}

bool GameEngine::IsPassable(Tile t) const
{
    return t==Tile::Empty || t==Tile::Floor || t==Tile::OpenDoor;
}

