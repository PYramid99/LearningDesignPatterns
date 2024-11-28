#include <DoubleBuffer/Actor.h>

namespace double_buffer
{
void Actor::swap()
{
	mCurrSlapped = mNextSlapped;
	mNextSlapped = false;
}

void Actor::slap()
{
	mNextSlapped = true;
}

bool Actor::was_slapped()
{
	return mCurrSlapped;
}

void Actor::clean()
{
	mCurrSlapped = false;
	mNextSlapped = false;
}

std::string Actor::get_name()
{
	return mName;
}
}
