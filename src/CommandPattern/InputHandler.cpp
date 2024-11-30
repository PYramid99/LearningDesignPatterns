#include <CommandPattern/InputHandler.h>

namespace command_pattern
{
InputHandler::InputHandler()
{
	mNextCommandIter = mCommandList.end();
}

void InputHandler::clean_old_commands()
{
	mCommandList.erase(mNextCommandIter, mCommandList.end());
	mNextCommandIter = mCommandList.end();
}
}
