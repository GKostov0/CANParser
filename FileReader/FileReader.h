#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileReader
{
public:
	std::vector<std::string> ReadCANMessage(const char* filePath);

	void PrintCANMessage(const std::vector<std::string>& msg) const
	{
		for (const auto& x : msg)
		{
			std::cout << x << '\n';
		}
	}
};