#include "Rengine/Core/Console.hpp"

ren::Console::Console()
{
}

ren::Console::~Console()
{
}

bool ren::Console::modifyCvar(const std::string& identifier, float new_value)
{
	if (!f_cvars.contains(identifier)) return false;
	f_cvars[identifier] = new_value;
	return true;
}

bool ren::Console::modifyCvar(const std::string& identifier, int new_value)
{
	if (!i_cvars.contains(identifier)) return false;
	i_cvars[identifier] = new_value;
	return true;
}

bool ren::Console::modifyCvar(const std::string& identifier, bool new_value)
{
	if (!b_cvars.contains(identifier)) return false;
	b_cvars[identifier] = new_value;
	return true;
}

bool ren::Console::registerCvar(const std::string& identifier, float default_value)
{
	if (f_cvars.contains(identifier)) return false;
	f_cvars.insert(std::make_pair(identifier, default_value));
	return true;
}

bool ren::Console::registerCvar(const std::string& identifier, int default_value)
{
	if (i_cvars.contains(identifier)) return false;
	i_cvars.insert(std::make_pair(identifier, default_value));
	return true;
}

bool ren::Console::registerCvar(const std::string& identifier, bool default_value)
{
	if (b_cvars.contains(identifier)) return false;
	b_cvars.insert(std::make_pair(identifier, default_value));
	return true;
}
