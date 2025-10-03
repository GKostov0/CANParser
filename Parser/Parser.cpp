#include "Parser.h"

Parser::Parser()
	: _rawMessages{}, _filteredMessages{}, _message{},
		_consecutiveMsgSize{ 0 }, _consecutiveMessage{}
{}

Parser::Parser(std::vector<std::string>&& msg)
	: _rawMessages(std::move(msg)), _filteredMessages{}, _message{},
		_consecutiveMsgSize{ 0 }, _consecutiveMessage{}
{
	FilterMessages();
	GetMessages();
}

void Parser::FilterMessages()
{
	for (const auto& x : _rawMessages)
	{
		CANMessage msg(x.substr(0, 3), x.substr(3, 2), x.substr(5));
		_filteredMessages.push_back(std::move(msg));
	}
}

void Parser::GetMessages()
{
	for (auto& msg : _filteredMessages)
	{
		switch (msg.type.high)
		{
			case '0': GetSingleFrameMessage(msg); break;
			case '1': GetFirstFrameMessage(msg); break;
			case '2': GetConsecutiveFrameMessage(msg); break;
			default: break;
		}
	}
}

void Parser::GetSingleFrameMessage(CANMessage& msg)
{
	msg.message = msg.message.substr(0, (msg.type.low - '0') * 2);

	_message.push_back(Message(msg.header, msg.message));
}

void Parser::GetFirstFrameMessage(CANMessage& msg)
{
	// Reset from prev stich
	_consecutiveMessage = "";

	_consecutiveMsgSize = std::stoul(msg.message.substr(0, 2), nullptr, 16);
	_consecutiveMessage += msg.message.substr(2);
	
	_consecutiveMsgSize -= FIRST_FRAME_OFFSET;
}

void Parser::GetConsecutiveFrameMessage(const CANMessage& msg)
{
	_consecutiveMsgSize -= FULL_FRAME_SIZE;

	if (_consecutiveMsgSize > 0)
	{
		_consecutiveMessage += msg.message.substr(0);
	}
	else
	{
		// _consecutiveMsgSize is now negative.
		// Need to find how many bytes to get since we don't need all.
		_consecutiveMessage += msg.message.substr(0, (((FULL_FRAME_SIZE * 2) - (_consecutiveMsgSize * -2))));
		_message.push_back(Message(msg.header, _consecutiveMessage));
	}
}
