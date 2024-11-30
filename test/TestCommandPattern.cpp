#include <iostream>

#include <CommandPattern/Actor.h>
#include <CommandPattern/ActorInputHandler.h>

using namespace command_pattern;

int main()
{
	std::cout << "Test Command Pattern\n\n";

	auto actor = std::make_shared<Actor>();

	auto actorInputHandler = std::make_shared<ActorInputHandler>(actor);

	while (true)
	{
		actorInputHandler->update();

		actor->print_state();

		std::cout << "\n";
	}

	return 0;
}
