#pragma once

#include <string>

#include <CommandPattern/InputHandler.h>

namespace command_pattern
{
class Actor;

class ActorInputHandler : public InputHandler
{
public:
	ActorInputHandler(const std::weak_ptr<Actor> actor);

	virtual void update() override;

private:
	std::weak_ptr<Actor> mActor;
};
}
