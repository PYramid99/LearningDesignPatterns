#include <CommandPattern/ActorInputHandler.h>

#include <string>
#include <iostream>

#include <CommandPattern/ActorMoveCommand.h>
#include <CommandPattern/Actor.h>

namespace command_pattern
{
ActorInputHandler::ActorInputHandler(const std::weak_ptr<Actor> actor) : mActor(actor)
{
}

void ActorInputHandler::update()
{
	std::cout << 
		"What will you do?\n" \
		"[w] go forward.    "\
		"[a] go left.    "\
		"[s] go backward.    "\
		"[d] go right.    \n"\
		"[z] undo.    "\
		"[y] redo.\n";

	std::string input;

	std::cin >> input;

	if (mActor.expired()) return;

	auto actor = mActor.lock();

	if (input == "w")
	{
		mCommandList.insert(mNextCommandIter, std::make_shared<ActorMoveCommand>(actor, actor->get_x(), actor->get_y() + 1));
		clean_old_commands();
		(*std::prev(mNextCommandIter))->execute();
	}
	else if (input == "a")
	{
		mCommandList.insert(mNextCommandIter, std::make_shared<ActorMoveCommand>(actor, actor->get_x() - 1, actor->get_y()));
		clean_old_commands();
		(*std::prev(mNextCommandIter))->execute();
	}
	else if (input == "s")
	{
		mCommandList.insert(mNextCommandIter, std::make_shared<ActorMoveCommand>(actor, actor->get_x(), actor->get_y() - 1));
		clean_old_commands();
		(*std::prev(mNextCommandIter))->execute();
	}
	else if (input == "d")
	{
		mCommandList.insert(mNextCommandIter, std::make_shared<ActorMoveCommand>(actor, actor->get_x() + 1, actor->get_y()));
		clean_old_commands();
		(*std::prev(mNextCommandIter))->execute();
	}
	else if (input == "z")
	{
		if (mNextCommandIter != mCommandList.begin())
		{
			(*std::prev(mNextCommandIter))->undo();
			--mNextCommandIter;
		}
	}
	else if (input == "y")
	{
		if (mNextCommandIter != mCommandList.end())
		{
			(*mNextCommandIter)->execute();
			++mNextCommandIter;
		}
	}
}
}
