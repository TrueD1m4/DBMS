#include "Parser.hpp"

namespace Parser {

	u16 getCountOfSpaces(std::string str) {
		u16 count = 0;

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
				position = (int)i;
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

		u16 countOfWords = getCountOfSpaces(temp);
		countOfWords++; //before the first whitespace whitespace

		for (u16 i = 0; i < countOfWords; i++) {
			std::string str = getSubStr(temp);

			if (str._Equal("0")) {
				buffer.clear();
				return false;
			}

			buffer.push_back(str);
		}

		//if str != db request will return false, else true
		size_t lastPos = buffer.size() - 1;

		//transform vec of str's to uppercase
		bool returnableValue = keyWordsToUpper(buffer);
		if (!returnableValue) {
			return false;
		}

		returnableValue = 
			(buffer.at(0)._Equal(*keyWords.begin())) && 
			(buffer.at(lastPos)._Equal(keyWords[keyWords.size() - 1]));

		if (returnableValue) {
			INFO_LOG("Your commands is:");
			for (auto& str : buffer) {
				TRACE_LOG("<" + str + ">");
			}
			INFO_LOG("End of command!");
		} else {
			ERROR_LOG("Isn't database request!");
			return returnableValue;
		}

		if (returnableValue) {
			returnableValue = checkKeyWords(buffer);
			if (!returnableValue) {
				return false;
			}
		}

		return returnableValue;
	}

	bool keyWordsToUpper(std::vector<std::string> &buffer) {

		std::string temp;

		if (buffer.empty()) {
			FATAL_LOG("EMPTY VEC BUFFER");
			return false;
		}

		for (size_t i = 0; i < buffer.size(); i++) {

			temp = buffer.at(i);
			std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

			if (i == 0) {
				buffer.at(i) = temp;
				temp.clear();
			} else if (i == (buffer.size() - 1)) {
				buffer.at(i) = temp;
				temp.clear();
			} else {

				bool isTypeOfData = (temp._Equal(keyWords.at(1))) ||
					(temp._Equal(keyWords.at(2))) || (temp._Equal(keyWords.at(3)));

				if (isTypeOfData) {
					buffer.at(i) = temp;
					temp.clear();
					i++;
				} else {
					buffer.at(i) = temp;
					temp.clear();
				}
			}
		}

		return true;
	}

	bool checkKeyWords(std::vector<std::string>& buffer) {

		for (size_t i = 1; i < buffer.size() - 1; i++) {
			std::string temp = buffer.at(i);
			if (!checkArr(temp)) {
				ERROR_LOG("Not a keyword<" + temp + ">");
				return false;
			}
			bool isTypeOfData = (temp._Equal(keyWords.at(1))) ||
				(temp._Equal(keyWords.at(2))) || (temp._Equal(keyWords.at(3)));
			if (isTypeOfData) {
				i++;
			}
		}

		return true;
	}

	bool checkArr(const std::string& str) {

		for (std::string& iter : keyWords) {
			if (str._Equal(iter)) {
				return true;
			}
		}

		return false;
	}

}