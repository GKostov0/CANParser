#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include "../Messages.h"

#define FIRST_FRAME_OFFSET 6
#define FULL_FRAME_SIZE 7

class Parser
{
public:
	Parser();
	Parser(std::vector<std::string>&& msg);
	~Parser() {};

	void PrintMessage() const
	{
		for (const auto& x : _message)
		{
			std::cout << x.header << ": " << x.message << '\n';
		}
	}

private:
	std::vector<std::string> _rawMessage;
	std::vector<CANMessage> _filteredMessage;
	std::vector<Message> _message;

	short _consecutiveMsgSize;
	std::string _consecutiveMessage;

	// Seperates headers, types and messages
	// FilterMessages does NOT give the final result, it only seperates the raw message 
	void FilterMessages();

	// Must FilterMessages() before getting the messages
	void GetMessages();

	void GetSingleFrameMessage(CANMessage& msg);
	void GetFirstFrameMessage(CANMessage& msg);
	void GetConsecutiveFrameMessage(const CANMessage& msg);
};