#include <DoubleBuffer/Actor.h>

namespace double_buffer
{
Actor::Actor(const std::string& name) : mName(name) {}

void Actor::slap()
{
	mSlapped[next()] = true;
}

bool Actor::was_slapped()
{
	return mSlapped[sCurrent];
}

void Actor::clear()
{
	mSlapped[sCurrent] = false;
}

void Actor::clean()
{
	std::fill(mSlapped.begin(), mSlapped.end(), false);
}

std::string Actor::get_name()
{
	return mName;
}

int Actor::next()
{
	return 1 - sCurrent;
}

void Actor::swap()
{
	sCurrent = next();
}

int Actor::sCurrent{ 0 };
}
