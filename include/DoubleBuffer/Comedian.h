#pragma once

#include <memory>

#include <DoubleBuffer/Actor.h>

namespace double_buffer
{
class Comedian : public Actor
{
public:
	Comedian(const std::string& name = "Comedian") : Actor(name) {}

	virtual void update() override;

	void set_facing_actor(const std::weak_ptr<Actor>& actor);

private:
	std::weak_ptr<Actor> mFacingActor;
};
}
