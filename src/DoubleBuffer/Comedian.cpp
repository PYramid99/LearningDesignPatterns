#include <DoubleBuffer/Comedian.h>

#include <iostream>

namespace double_buffer
{
void Comedian::update()
{
	if (was_slapped())
	{
		if (!mFacingActor.expired())
		{
			mFacingActor.lock()->slap();
			std::cout << mName << " was slapped, so he slaps " << mFacingActor.lock()->get_name() << ".\n";
		}
		else
		{
			std::cout << mName << " was slapped, but there is no one in front of him, so he does nothing.\n";
		}
	}
	else
	{
		std::cout << mName << " was not slapped, so he does nothing.\n";
	}
}

void Comedian::set_facing_actor(const std::weak_ptr<Actor>& actor)
{
	mFacingActor = actor;
}
}
