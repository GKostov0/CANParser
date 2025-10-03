#include "FileReader/FileReader.h"
#include "Parser/Parser.h"

int main()
{
    FileReader reader;
    Parser parser(reader.ReadCANMessage("Messages/CANMessage.txt"));
    parser.PrintCANMessage();
    
    return 0;
}