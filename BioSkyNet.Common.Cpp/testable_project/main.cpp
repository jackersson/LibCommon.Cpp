#include <iostream>
#include <threadable.hpp>
#include "test.hpp"

#include <tbb/task_group.h>

tbb::task_group g;
bool busy;
void funct()
{
	if (busy)
	{
		std::cout << "rejected" << std::endl;
		return;
	}
	busy = true;
	g.run([]()
	{
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "done funct" << std::endl;
		busy = false;
	});
}

int main()
{
	funct();
	funct();
	funct();
	funct();
	std::cout << "after funct" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));

	return 0;
}
