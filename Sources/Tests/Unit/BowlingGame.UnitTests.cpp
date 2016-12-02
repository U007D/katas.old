#include <regex>

#include "catch.hpp"

#include "BowlingGame.h"

SCENARIO("BowlingGame unit tests")
{
	GIVEN("an empty bowling game")
	{
		auto game = BowlingGame();

		THEN("the score is 0")
		{
			REQUIRE(game.Score() == 0);
		}

		AND_THEN("the current frame is 1")
		{
			REQUIRE(game.CurrentFrame() == 1);
		}

		AND_THEN("the current ball is 1")
		{
			REQUIRE(game.CurrentBall() == 1);
		}

		WHEN("a gutterball is rolled")
		{
			game.Roll(0);

			THEN("the score is 0")
			{
				REQUIRE(game.Score() == 0);
			}

			AND_THEN("the current frame is 1")
			{
				REQUIRE(game.CurrentFrame() == 1);
			}

			AND_THEN("the current ball is 2")
			{
				REQUIRE(game.CurrentBall() == 2);
			}
		}
	}
}