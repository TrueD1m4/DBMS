#include "Parser.h"

namespace Parser {

	enum KeyWord {
		DB,
		INT,
		DOUBLE,
		STR,
		END
	};

	std::array<std::string, KeyWord::END + 1u> keyWords{
		"DB", "INT", "DOUBLE", "STR", "END"
	};

	uint16_t getCountOfSpaces(std::string str) {
		uint16_t count = 0;

		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				count++;
			}
		}

		return count;
	}

	std::string getSubStr(std::string& str) {
		//get size of word
		int position = 0;
		for(size_t i = 0; i < str.length(); i++) {
			if (i == 0 && str[i] == ' ') {
				position = -1;
				break;
			} else if (str[i] == ' ') {
				position = i;
				break;
			}
		}

		if (position == -1) {
			//string cant starts by space
			throw std::runtime_error("A space starts a line!");
			ERROR_LOG("A space starts a line!");
			return "0";

		} else {
			
			std::string substr;

			if (position != 0) {
				substr = str.substr(0, position);//get word
				str.erase(0, position + 1);//clear word with whitespace
			} else {
				substr = str;
			}

			return substr;
		}
	}

	bool readStr(std::vector<std::string> &buffer) {
		std::string temp;
		std::getline(std::cin, temp);
		if (temp.empty()) {
			WARN_LOG("Empty string!");
			return false;
		}

		uint16_t countOfWords = getCountOfSpaces(temp);
		countOfWords++; //before the first whitespace and after the second whitespace

		for (uint16_t i = 0; i < countOfWords; i++) {
			buffer.push_back(getSubStr(temp));
		}
		
		return true;
	}
}