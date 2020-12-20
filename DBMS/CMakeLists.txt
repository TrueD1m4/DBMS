cmake_minimum_required (VERSION 3.8)

add_executable (DBMS "DBMS.cpp" "DBMS.h"
	 
	"src/Logger/Logger.h" "src/Logger/Logger.cpp"
	"src/Menu.h" "src/Menu.cpp"
	"src/RequestParser/Parser.h" "src/RequestParser/Parser.cpp"
	"src/DataHandler/DataHandler.cpp" "src/DataHandler/DataHandler.h"
	
	)