#include "DBMS.hpp"

using namespace std;

int main()
{
	
	vector<string> buf;

	if (Parser::readStr(buf)) {

		if (Parser::keyWordsToUpper(buf)) {
			for (auto& i : buf) {
				cout << i << "\t";
			}
		}

	} else {
		cout << "succ";
	}

	return EXIT_SUCCESS;
}
