#pragma once

#include <memory>
#include <list>

namespace command_pattern
{
class Command;

class InputHandler
{
public:
	InputHandler();

	virtual ~InputHandler() = default;

	virtual void update() = 0;

protected:
	void clean_old_commands();

protected:
	std::list<std::shared_ptr<Command>> mCommandList;

	std::list<std::shared_ptr<Command>>::iterator mNextCommandIter;
};
}
