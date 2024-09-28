#pragma once
#include<map>
#include<string>



#include"Rengine/Config.hpp"

namespace ren
{
	class REN_API Console
	{
	public:
		
		Console();
		virtual ~Console();

		bool modifyCvar(const std::string& identifier, float new_value);
		bool modifyCvar(const std::string& identifier, int new_value);
		bool modifyCvar(const std::string& identifier, bool new_value);

		bool registerCvar(const std::string& identifier, float default_value);
		bool registerCvar(const std::string& identifier, int default_value);
		bool registerCvar(const std::string& identifier, bool default_value);

	private:
		std::map<std::string, float> f_cvars;
		std::map<std::string, int> i_cvars;
		std::map<std::string, bool> b_cvars;
	};
}
