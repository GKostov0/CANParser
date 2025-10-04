#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileReader
{
public:
	FileReader() {}
	~FileReader() {}

	std::vector<std::string> ReadRawMessage(const char* filePath);
};