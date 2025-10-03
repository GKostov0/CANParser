#pragma once

#include <string>

struct Message
{
	Message()
		: header{}, message{}
	{
	}

	Message(std::string h, std::string msg)
		: header{ h }, message{ msg }
	{
	}

	std::string header;
	std::string message;
};

struct CANType
{
	CANType()
		: high('0'), low('0')
	{
	}

	CANType(std::string val)
		: high(val[0]), low(val[1])
	{
	}

	// high - 0 - Single message, low - size of msg in bytes
	// high - 1 - First frame, low - 0, size should be the first byte in the msg
	// high - 2 - Consecutive message, low(1, 2, 3...n) message frame number
	// high - 3 - Acknowledgement(go ahead) from reciever, low - 0
	char high;
	char low;
};

struct CANMessage
{
	CANMessage(std::string head, CANType headerType, std::string msg)
		: header(head), type(headerType), message(msg)
	{
	}

	std::string header;
	CANType type;
	std::string message;
};