#pragma once

#ifndef PARSER
#define PARSER

#include <string>
#include <iterator>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

#include "../Logger/Logger.hpp"
#include "../DataHandler/DataHandler.hpp"

namespace Parser {

	enum KeyWord {
		DB,
		INT,
		DOUBLE,
		STR,
		ADD,
		CHANGE,
		REMOVE,
		END
	};

	static inline std::array<std::string, KeyWord::END + 1u> keyWords {
		"DB", "INT", "DOUBLE", "STR", "ADD", "CHANGE", "REMOVE", "END"
	};

	uint16_t getCountOfSpaces(std::string str);

	std::string getSubStr(std::string& str);

	bool readStr(std::vector<std::string> &buffer);

}

#endif // !PARSER


