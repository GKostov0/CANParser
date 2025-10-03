#include "Parser.h"

Parser::Parser()
	: _message{}
{}

Parser::Parser(std::vector<std::string>&& msg)
	: _message(std::move(msg))
{
}
