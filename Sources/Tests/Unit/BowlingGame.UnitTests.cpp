#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
	GIVEN("an empty bowling game")
	{
		auto game = BowlingGame();

		THEN("the game is score 0, frame 1, ball 1")
		{
			REQUIRE(game.Score().value() == 0);
			REQUIRE(game.Frame() == 1);
			REQUIRE(game.Ball() == 1);
		}

		WHEN("a gutterball is rolled")
		{
			game.Roll(0);

			THEN("the game is score 0, frame 1, ball 2")
			{
				REQUIRE(game.Score().value() == 0);
				REQUIRE(game.Frame() == 1);
				REQUIRE(game.Ball() == 2);
			}
		}

		WHEN("a 7 is rolled as an arbitrary open frame value")
		{
			game.Roll(7);

			THEN("the game is score 7, frame 1, ball 2")
			{
				REQUIRE(game.Score().value() == 7);
				REQUIRE(game.Frame() == 1);
				REQUIRE(game.Ball() == 2);
			}

			AND_WHEN("a 2 is rolled as a second ball with an arbitrary open frame value")
			{
				game.Roll(2);

				THEN("the game is score 9, frame 2, ball 1")
				{
					REQUIRE(game.Score().value() == 9);
					REQUIRE(game.Frame() == 2);
					REQUIRE(game.Ball() == 1);
				}
			}
		}

        WHEN("a 10 is rolled as the first ball in a frame")
        {
            game.Roll(10);

            THEN("the game scored is undefined, frame 2 ball 1")
            {
                REQUIRE(game.Score() == xstd::nullopt);
                REQUIRE(game.Frame() == 2);
                REQUIRE(game.Ball() == 1);
            }
        }
	}
}