#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include <iostream>
#include "Contessa.hpp"
#include "doctest.h"
TEST_CASE("some good, some bad things")
{

    coup::Game game = coup::Game();
    coup::Ambassador ambassador = coup::Ambassador(game,"lior");
    coup::Duke duke = coup::Duke(game,"nir");
    coup::Contessa contessa = coup::Contessa(game,"talia");
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(contessa.income());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(duke.block(ambassador));
    CHECK_NOTHROW(duke.income());
    CHECK_THROWS(duke.tax());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK_THROWS(contessa.block(duke));
    CHECK_THROWS_MESSAGE(contessa.block(duke),"cant stop player that is not assassin");
}
TEST_CASE("Good Game, 3 players")
{
    coup::Game game = coup::Game();
    coup::Assassin hawkeye = coup::Assassin(game,"clint");
    coup::Captain cap = coup::Captain(game,"steve");
    coup::Contessa black_widow = coup::Contessa(game,"natasha");
    CHECK_NOTHROW(hawkeye.foreign_aid());
    CHECK_NOTHROW(cap.foreign_aid());
    CHECK_NOTHROW(black_widow.income());
    CHECK_NOTHROW(hawkeye.income());
    CHECK_NOTHROW(cap.steal(black_widow));
    CHECK_NOTHROW(black_widow.foreign_aid());
    CHECK_NOTHROW(hawkeye.coup(cap));
    CHECK_NOTHROW(black_widow.foreign_aid());
    CHECK_NOTHROW(hawkeye.foreign_aid());
    CHECK_NOTHROW(black_widow.foreign_aid());
    CHECK_NOTHROW(hawkeye.foreign_aid());
    CHECK_NOTHROW(black_widow.income());
    CHECK_NOTHROW(hawkeye.coup(black_widow));
}