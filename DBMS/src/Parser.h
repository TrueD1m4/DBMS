#pragma once

#ifndef PARSER
#define PARSER

#include <string>
#include <iterator>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

#include "Logger.h"

namespace Parser {

	uint16_t getCountOfSpaces(std::string str);

	std::string getSubStr(std::string& str);

	bool readStr(std::vector<std::string> &buffer);

}

#endif // !PARSER


