#include "test.h"
#include "GameMapView.h"
#include "GameEngine.h"
#include "GameMap.h"

class MockInput : public Input
{
public:
    MOCK_METHOD0(GetCommand, Command());
};

class MockGameMapView : public GameMapView
{
public:
    MOCK_METHOD1(DrawMap, void(const GameMap&));
    MOCK_METHOD2(DrawMapAndPlayer, void(const GameMap&, const Player&));
};

class TestFixture
{
public:
    std::shared_ptr<GameEngine> gEngine;
    std::shared_ptr<MockInput> input;
    std::shared_ptr<MockGameMapView> gmv;
    std::shared_ptr<GameMap> gm;
    std::shared_ptr<Player> player;
    
    TestFixture()
    {
        input = std::make_shared<MockInput>();
        gmv = std::make_shared<MockGameMapView>();
        gm = std::make_shared<GameMap>(std::initializer_list<std::initializer_list<Tile>>{{}});
        player = std::make_shared<Player>(7, 4);
        gEngine = std::make_shared<GameEngine>(input, player, gm, gmv);
    }

    void GetCommand(Command c)
    {
        EXPECT_CALL(*input, GetCommand())
            .Times(1)
            .WillOnce(Return(c));
        EXPECT_CALL(*gmv, DrawMapAndPlayer(Ref(*gm), Ref(*player)))
            .Times(1);
    }

    void ProcessCommand()
    {
        REQUIRE(gEngine->ProcessCommand());
    }

    void Require_Player_Position(int x, int y)
    {
        REQUIRE(player->GetY() == y);
        REQUIRE(player->GetX() == x);
    }
};

TEST_CASE_METHOD(TestFixture, "")
{
    GIVEN("Command up")
    {
        GetCommand(Command::Up);
        WHEN("Process command")
        {
            ProcessCommand();
            THEN("Player in correct position")
            {
                Require_Player_Position(7,3);
            }
        }
    }
    
    GIVEN("Command down")
    {
        GetCommand(Command::Down);
        WHEN("Process command")
        {
            ProcessCommand();
            THEN("Player in correct position")
            {
                Require_Player_Position(7,5);
            }
        }
    }
    
    GIVEN("Command left")
    {
        GetCommand(Command::Left);
        WHEN("Process command")
        {
            ProcessCommand();
            THEN("Player in correct position")
            {
                Require_Player_Position(6,4);
            }
        }
    }
    
    GIVEN("Command Right")
    {
        GetCommand(Command::Right);
        WHEN("Process command")
        {
            ProcessCommand();
            THEN("Player in correct position")
            {
                Require_Player_Position(8,4);
            }
        }
    }
    
    GIVEN("Command Exit")
    {
        EXPECT_CALL(*input, GetCommand())
            .Times(1)
            .WillOnce(Return(Command::Exit));
        THEN("Expect returns false when process Command")
        {
            REQUIRE(gEngine->ProcessCommand() == false);
        }
    }
}

TEST_CASE_METHOD(TestFixture, "Test a player does not move to an impassable tile")
{
    GIVEN("A Map with a floor, wall and player")
    {
        gm->SetMap({
        {Tile::Floor, Tile::Wall}
        });
        player->SetPosition(0, 0);
        WHEN("A right command is given")
        {
            GetCommand(Command::Right);
            ProcessCommand();
            THEN("The player has not moved")
            {
                Require_Player_Position(0, 0);
            }
        }
    }
}

TEST_CASE_METHOD(TestFixture, "Test a player moves to an open door")
{
    GIVEN("A Map with a floor, open door and player")
    {
        gm->SetMap({
        {Tile::Floor, Tile::OpenDoor}
        });
        player->SetPosition(0, 0);
        WHEN("A right command is given")
        {
            GetCommand(Command::Right);
            ProcessCommand();
            THEN("The player has moved")
            {
                Require_Player_Position(1, 0);
            }
        }
    }
}

TEST_CASE_METHOD(TestFixture, "A Closed Door Chnages to An Open Door when actioned")
{
    GIVEN("A Map with a floor, closed door and player")
    {
        gm->SetMap({
        {Tile::Floor, Tile::ClosedDoor}
        });
        player->SetPosition(0, 0);
        WHEN("A ActionRight command is given")
        {
            GetCommand(Command::ActionRight);
            ProcessCommand();
            THEN("The door has opened")
            {
                REQUIRE(gm->GetTile(1, 0) == Tile::OpenDoor);
            }
        }
    }
}

TEST_CASE_METHOD(TestFixture, "An Open Door Chnages to A closed Door when actioned")
{
    GIVEN("A Map with a floor, open door and player")
    {
        gm->SetMap({
        {Tile::Floor, Tile::OpenDoor}
        });
        player->SetPosition(0, 0);
        WHEN("A ActionRight command is given")
        {
            GetCommand(Command::ActionRight);
            ProcessCommand();
            THEN("The door has closed")
            {
                REQUIRE(gm->GetTile(1, 0) == Tile::ClosedDoor);
            }
        }
    }
}



