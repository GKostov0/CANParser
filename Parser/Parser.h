#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Parser
{
public:
	Parser();
	Parser(std::vector<std::string>&& msg);
	~Parser() {};

	/*inline const std::vector<std::string>& GetMessage() const { return _message; }*/

	void PrintCANMessage() const
	{
		for (const auto& x : _message)
		{
			std::cout << x << '\n';
		}
	}

private:
	std::vector<std::string> _message;
};