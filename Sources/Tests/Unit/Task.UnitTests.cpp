#include <atomic>
#include <cstdint>
#include <functional>

#include "catch.hpp"

#include "Helpers/Common.h"
#include "Kernel/Task.h"

SCENARIO("uKernel Task unit tests")
{
	GIVEN("a Thread manager")
	{
		auto thread = Kernel::Task();

		WHEN("one thread is spawned")
		{
			std::atomic<u32> numberOfThreadsRun{0_u32};
			const auto expectedNumberOfThreadsRun{1_u32};

			auto task = thread.Spawn([&numberOfThreadsRun]() { ++numberOfThreadsRun; });
			thread.Join(task);

			THEN("the effects of the spawned thread (an instance counter) should be observed (should be 1)")
			{
				REQUIRE(numberOfThreadsRun == expectedNumberOfThreadsRun);
			}
		}
	}
}
