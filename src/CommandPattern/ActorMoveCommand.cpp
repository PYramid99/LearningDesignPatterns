#include <CommandPattern/ActorMoveCommand.h>

#include <CommandPattern/Actor.h>

namespace command_pattern
{
ActorMoveCommand::ActorMoveCommand(const std::weak_ptr<Actor>& actor, int x, int y) : mActor(actor), mTargetX(x), mTargetY(y)
{
}

void ActorMoveCommand::execute()
{
	if (mActor.expired()) return;

	auto actor = mActor.lock();

	mOriginalX = actor->get_x();
	mOriginalY = actor->get_y();

	actor->move_to(mTargetX, mTargetY);
}

void ActorMoveCommand::undo()
{
	if (mActor.expired()) return;

	auto actor = mActor.lock();

	actor->move_to(mOriginalX, mOriginalY);
}
}
