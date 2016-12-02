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

		WHEN("a 7 is rolled as an arbitrary open frame value")
		{
			game.Roll(7);

			THEN("the score is 7")
			{
				REQUIRE(game.Score() == 7);
			}
		}
	}
}