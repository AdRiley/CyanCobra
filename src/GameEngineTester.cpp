#include "gmock/gmock.h"
#include "GameEngine.h"

using namespace ::testing;

class MockInput : public Input
{
public:
    MOCK_METHOD0(GetCommand, Command());
};

class AGameEngine: public Test
{
public:
    std::shared_ptr<GameEngine> gEngine;
    std::shared_ptr<MockInput> input;
    std::shared_ptr<Player> player;

    AGameEngine()
    {
        input = std::make_shared<MockInput>();
        player = std::make_shared<Player>(7, 4);
        gEngine = std::make_shared<GameEngine>(input, player);
    }
};

TEST_F(AGameEngine, MovesAPlayerUpWhenItGetsAnUpCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Up));

    gEngine->ProcessCommand();

    EXPECT_THAT(3, Eq(player->GetY()));
    EXPECT_THAT(7, Eq(player->GetX()));
}

TEST_F(AGameEngine, MovesAPlayerDownWhenItGetsADownCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Down));

    gEngine->ProcessCommand();

    EXPECT_THAT(5, Eq(player->GetY()));
    EXPECT_THAT(7, Eq(player->GetX()));
}

TEST_F(AGameEngine, MovesAPlayerLeftWhenItGetsALeftCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Left));

    gEngine->ProcessCommand();

    EXPECT_THAT(4, Eq(player->GetY()));
    EXPECT_THAT(6, Eq(player->GetX()));
}

TEST_F(AGameEngine, MovesAPlayerRightWhenItGetsARightCommand)
{
    EXPECT_CALL(*input, GetCommand())
        .Times(1)
        .WillOnce(Return(Command::Right));

    gEngine->ProcessCommand();

    EXPECT_THAT(4, Eq(player->GetY()));
    EXPECT_THAT(8, Eq(player->GetX()));
}


