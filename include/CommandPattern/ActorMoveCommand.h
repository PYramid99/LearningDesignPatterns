#pragma once

#include <memory>

#include <CommandPattern/Command.h>

namespace command_pattern
{
class Actor;

class ActorMoveCommand : public Command
{
public:
	ActorMoveCommand(const std::weak_ptr<Actor>& actor, int x, int y);

	virtual void execute() override;

	virtual void undo() override;

private:
	std::weak_ptr<Actor> mActor;

	int mOriginalX{ 0 }, mOriginalY{ 0 };

	int mTargetX, mTargetY;
};
}
