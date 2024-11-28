#include <DoubleBuffer/Actor.h>

namespace double_buffer
{
void Actor::reset()
{
	mSlapped = false;
}

void Actor::slap()
{
	mSlapped = true;
}

bool Actor::was_slapped()
{
	return mSlapped;
}
std::string Actor::get_name()
{
	return mName;
}
}
