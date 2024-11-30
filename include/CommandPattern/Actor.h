#pragma once

namespace command_pattern
{
class Actor
{
public:
	Actor() = default;

	void move_to(int x, int y);

	int get_x();

	int get_y();

	void print_state();

private:
	int mX{ 0 }, mY{ 0 };
};
}
