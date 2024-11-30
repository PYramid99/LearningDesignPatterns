#include <CommandPattern/Actor.h>

#include <iostream>

namespace command_pattern
{
void Actor::move_to(int x, int y)
{
	mX = x;
	mY = y;
}

int Actor::get_x()
{
	return mX;
}

int Actor::get_y()
{
	return mY;
}

void Actor::print_state()
{
	std::cout << "Current Position: (" << mX << ", " << mY << ")\n";
}
}
