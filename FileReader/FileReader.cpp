#include "FileReader.h"

std::vector<std::string> FileReader::ReadRawMessage(const char* filePath)
{
    // return empty if error reading
    std::vector<std::string> result;

    std::ifstream file(filePath);
    std::string line;

    if (!file.is_open())
    {
        std::cerr << "[Error]: Could not open file: " << filePath << std::endl;
        return result;
    }

    while (std::getline(file, line))
    {
        result.push_back(line);
    }

    file.close();

    return result;
}
