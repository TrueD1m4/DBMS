
#include "DBMS.h"

using namespace std;

int main()
{
	
	vector<string> buf;
	if (Parser::readStr(buf)) {

		for (string& i : buf) {
			cout << i << "\t";
		}
	} else {
		cout << "succ" << endl;
	}
	return 0;
}
