#include "Parser.h"

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

	static inline std::array<std::string, KeyWord::END + 1u> keyWords{
		"DB", "INT", "DOUBLE", "STR", "ADD", "CHANGE", "REMOVE", "END"
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
			ERROR_LOG("A space starts a line!");
			return "0";

		} else {
			
			std::string substr;

			if (position != 0) {
				substr = str.substr(0, position);//get word
				str.erase(0, ++position);//clear word with whitespace
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
			std::string str = getSubStr(temp);

			if (str._Equal("0")) {
				buffer.clear();
				return false;
			}

			buffer.push_back(str);
		}

		//if str != db request will return false, else true
		size_t lastPos = buffer.size() - 1;
		bool returnableValue = 
			(buffer.at(0)._Equal(*keyWords.begin())) && (buffer.at(lastPos)._Equal(keyWords[keyWords.size() - 1]));

		if (returnableValue) {
			INFO_LOG("Your commands is:");
			for (auto& str : buffer) {
				INFO_LOG("<" + str + ">");
			}
		} else {
			ERROR_LOG("Isn't database request!");
		}
		
		return returnableValue;
	}
}