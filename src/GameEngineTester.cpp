#include "gmock/gmock.h"
#include "GameMapView.h"
#include "GameEngine.h"
#include "GameMap.h"

using namespace ::testing;

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

class AGameEngine: public Test
{
public:
    std::shared_ptr<GameEngine> gEngine;
    std::shared_ptr<MockInput> input;
    std::shared_ptr<MockGameMapView> gmv;
    std::shared_ptr<GameMap> gm;
    std::shared_ptr<Player> player;

    AGameEngine()
    {
        input = std::make_shared<MockInput>();
        gmv = std::make_shared<MockGameMapView>();
        gm = std::make_shared<GameMap>(std::initializer_list<std::initializer_list<Tile>>{{}});
        player = std::make_shared<Player>(7, 4);
        gEngine = std::make_shared<GameEngine>(input, player, gm, gmv);
    }

    void Given_Command(Command c)
    {
        EXPECT_CALL(*input, GetCommand())
            .Times(1)
            .WillOnce(Return(c));
        EXPECT_CALL(*gmv, DrawMapAndPlayer(Ref(*gm), Ref(*player)))
            .Times(1);
    }

    void When_ProcessCommand()
    {
        gEngine->ProcessCommand();
    }

    void Expect_Player_Position(int x, int y)
    {
        EXPECT_THAT(y, Eq(player->GetY()));
        EXPECT_THAT(x, Eq(player->GetX()));
    }

};

TEST_F(AGameEngine, MovesAPlayerUpWhenItGetsAnUpCommand)
{
    Given_Command(Command::Up);
    When_ProcessCommand();
    Expect_Player_Position(7, 3);
}

TEST_F(AGameEngine, MovesAPlayerDownWhenItGetsADownCommand)
{
    Given_Command(Command::Down);
    When_ProcessCommand();
    Expect_Player_Position(7, 5);
}

TEST_F(AGameEngine, MovesAPlayerLeftWhenItGetsALeftCommand)
{
    Given_Command(Command::Left);
    When_ProcessCommand();
    Expect_Player_Position(6, 4);
}

TEST_F(AGameEngine, MovesAPlayerRightWhenItGetsARightCommand)
{
    Given_Command(Command::Right);
    When_ProcessCommand();
    Expect_Player_Position(8, 4);
}


