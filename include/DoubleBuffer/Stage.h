#pragma once

#include <list>
#include <memory>
#include <string>

namespace double_buffer
{
class Actor;

class Stage
{
public:
	Stage() = default;
	~Stage() = default;

	void update();

	void add_actor(const std::shared_ptr<Actor>& actor);

	void clean();

private:
	std::list<std::shared_ptr<Actor>> mActorList;
};
}
