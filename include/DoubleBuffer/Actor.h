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

	void swap();

	void slap();

	bool was_slapped();

	void clean();

	std::string get_name();

protected:
	std::string mName;
	bool mCurrSlapped{ false };
	bool mNextSlapped{ false };
};
}
