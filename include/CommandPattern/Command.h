#pragma once

namespace command_pattern
{
class Command
{
public:
	Command() = default;
	
	virtual ~Command() = default;

	virtual void execute() = 0;

	virtual void undo() = 0;
};
}
