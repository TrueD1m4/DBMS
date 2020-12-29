#pragma once
#pragma warning(disable : 26812)

#ifndef PARSER
#define PARSER

#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

#include "../Logger/Logger.hpp"

#define u8 uint8_t
#define u16 uint16_t

namespace parser {
	//tested, same as cpp
	enum class ReadState : u8 {
		FINE,
		EMPTY_STR,
		BAD_STR,
		BAD_CAST,
		NOT_DB_REQ,
		KW_ERR
	};

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

	u16 getCountOfSpaces(std::string str);
	std::string getSubStr(std::string& str);
	bool keyWordsToUpper(std::vector<std::string>& buffer);
	bool checkArr(const std::string& str);
	bool checkKeyWords(std::vector<std::string>& buffer);
	[[nodiscard]] ReadState readStr(std::vector<std::string> &buffer);

	class BufferManager {

	};
}

#endif // !PARSER