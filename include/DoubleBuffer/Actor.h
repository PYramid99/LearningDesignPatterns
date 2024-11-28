#pragma once

#include <string>
#include <array>

namespace double_buffer
{
class Actor
{
public:
	Actor(const std::string& name = "Actor");

	virtual ~Actor() = default;

	virtual void update() = 0;

	void slap();

	bool was_slapped();

	void clear();

	void clean();

	std::string get_name();

	static int next();

	static void swap();

private:
	std::string mName;

	std::array<bool, 2> mSlapped{ false, false };

	static int sCurrent;
};
}
