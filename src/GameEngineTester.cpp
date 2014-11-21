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
};

TEST_F(AGameEngine, MovesAPlayerUpWhenItGetsAnUpCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Up));
    EXPECT_CALL(*gmv, DrawMapAndPlayer(Ref(*gm), Ref(*player)))
        .Times(1);

    gEngine->ProcessCommand();

    EXPECT_THAT(3, Eq(player->GetY()));
    EXPECT_THAT(7, Eq(player->GetX()));
}

TEST_F(AGameEngine, MovesAPlayerDownWhenItGetsADownCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Down));
    EXPECT_CALL(*gmv, DrawMapAndPlayer(Ref(*gm), Ref(*player)))
        .Times(1);

    gEngine->ProcessCommand();

    EXPECT_THAT(5, Eq(player->GetY()));
    EXPECT_THAT(7, Eq(player->GetX()));
}

TEST_F(AGameEngine, MovesAPlayerLeftWhenItGetsALeftCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Left));
    EXPECT_CALL(*gmv, DrawMapAndPlayer(Ref(*gm), Ref(*player)))
        .Times(1);

    gEngine->ProcessCommand();

    EXPECT_THAT(4, Eq(player->GetY()));
    EXPECT_THAT(6, Eq(player->GetX()));
}

TEST_F(AGameEngine, MovesAPlayerRightWhenItGetsARightCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Right));
    EXPECT_CALL(*gmv, DrawMapAndPlayer(Ref(*gm), Ref(*player)))
        .Times(1);

    gEngine->ProcessCommand();

    EXPECT_THAT(4, Eq(player->GetY()));
    EXPECT_THAT(8, Eq(player->GetX()));
}


