#include <vector>

#include "catch.hpp"

#include "Helpers/Common.h"

SCENARIO("std::vector unit tests")
{
	GIVEN("an empty vector")
	{
		std::vector<i64> vec;

		THEN("the size should be 0")
		{
			REQUIRE(vec.size() == 0);
		}

		WHEN("three elements are added")
		{
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);

			THEN("the size should be 3 and the capacity should be at least 3")
			{
				REQUIRE(vec.size() == 3);
				auto capacity_when_size_was_3 = vec.capacity();
				REQUIRE(capacity_when_size_was_3 >= 3);

				AND_WHEN("an element is removed")
				{
					vec.pop_back();

					THEN("the size should be 2 and the capacity should not decrease")
					{
						REQUIRE(vec.size() == 2);
						REQUIRE(vec.capacity() == capacity_when_size_was_3);
					}
				}
			}
		}

		WHEN("one more element than the vector's current capacity is added")
		{
			auto capacity_when_size_was_0 = vec.capacity();

			for (auto loopVars = std::make_pair(0_usz, decltype(vec)::value_type());
			     loopVars.first <= capacity_when_size_was_0;
			     ++loopVars.first)
			{
				vec.push_back(loopVars.second++);
			}

			THEN("the size should be equal to the former capacity + 1 and the capacity should be at least that too")
			{
				REQUIRE(vec.size() == capacity_when_size_was_0 + 1);
				REQUIRE(vec.capacity() >= capacity_when_size_was_0 + 1);
			}
		}
	}
}
