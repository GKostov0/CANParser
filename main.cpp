#include "FileReader/FileReader.h"
#include "Parser/Parser.h"

int main()
{
    FileReader reader;
    Parser parser(reader.ReadRawMessage("Messages/CANMessage.txt"));
    parser.PrintMessage();

    return 0;
}