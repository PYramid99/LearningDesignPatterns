#pragma once

#include <string>

namespace double_buffer
{
class Actor
{
public:
	Actor(const std::string& name = "Actor") : mName(name) {}

	virtual ~Actor() = default;

	virtual void update() = 0;

	void reset();

	void slap();

	bool was_slapped();

	std::string get_name();

protected:
	std::string mName;
	bool mSlapped{ false };
};
}
