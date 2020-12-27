#include "DBMS.hpp"

using namespace std;

int main()
{
	
	vector<string> buf;

	if (parser::readStr(buf) == parser::ReadState::FINE) {

		if (parser::keyWordsToUpper(buf)) {
			for (auto& i : buf) {
				cout << i << "\t";
			}
		}

	} else {
		cout << "succ";
	}

	return EXIT_SUCCESS;
}
