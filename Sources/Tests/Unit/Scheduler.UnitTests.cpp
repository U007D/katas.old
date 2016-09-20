#include <atomic>

#include "catch.hpp"

#include "Helpers/Common.h"
#include "Kernel/Scheduler.h"
#include "Kernel/Task.h"

SCENARIO("uKernel Scheduler unit tests")
{
	GIVEN("a Scheduler")
	{
		using namespace Kernel;
		auto sched = Scheduler();

		WHEN("a task is scheduled")
		{
			std::atomic<usz> refCount { 0 };
			auto task = sched.AddTask([&refCount]() { ++refCount; });

			THEN("the task should execute")
			{
				auto expectedTaskState = task.State() == Task::States::Running || task.State() == Task::States::Completed;
				REQUIRE(expectedTaskState == true);
				while (task.State() == Task::States::Running) {};	//task.State is volatile; won't be optimized away
				REQUIRE(task.State() == Task::States::Completed);
				REQUIRE(refCount == 1);
			}
		}
	}
}
