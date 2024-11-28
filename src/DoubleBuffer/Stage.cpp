#include <DoubleBuffer/Stage.h>

#include <DoubleBuffer/Actor.h>
#include <DoubleBuffer/Comedian.h>

namespace double_buffer
{
void Stage::update()
{
	for (auto& actor : mActorList)
	{
		actor->update();
	}

	Actor::swap();
}

void Stage::add_actor(const std::shared_ptr<Actor>& actor)
{
	mActorList.push_back(actor);
}

void Stage::clean()
{
	for (auto& actor : mActorList)
	{
		actor->clean();
	}
	mActorList.clear();
}
}
