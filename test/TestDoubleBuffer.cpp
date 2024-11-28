#include <iostream>

#include <DoubleBuffer/Actor.h>
#include <DoubleBuffer/Comedian.h>
#include <DoubleBuffer/Stage.h>

using namespace double_buffer;

int main()
{
	std::cout << "Test Double Buffer\n\n";

	auto harry = std::make_shared<Comedian>("Harry");
	auto baldy = std::make_shared<Comedian>("Baldy");
	auto chump = std::make_shared<Comedian>("Chump");

	harry->set_facing_actor(baldy);
	baldy->set_facing_actor(chump);
	chump->set_facing_actor(harry);

	std::cout << "[First performance]\n";

	Stage stage;
	stage.add_actor(harry);
	stage.add_actor(baldy);
	stage.add_actor(chump);

	harry->slap();

	for (int i = 0; i < 9; ++i)
	{
		std::cout << i << ": \n";
		stage.update();
	}

	std::cout << "\n";
	stage.clean();

	std::cout << "[Second performance]\n";

	stage.add_actor(chump);
	stage.add_actor(baldy);
	stage.add_actor(harry);

	harry->slap();

	for (int i = 0; i < 9; ++i)
	{
		std::cout << i << ": \n";
		stage.update();
	}

	return 0;
}
