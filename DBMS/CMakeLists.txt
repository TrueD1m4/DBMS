cmake_minimum_required (VERSION 3.8)

add_executable (DBMS "DBMS.cpp" "DBMS.h"
	"src/DataHandler.h" "src/DataHandler.cpp"
	"src/Logger.h" "src/Logger.cpp"
	"src/Menu.h" "src/Menu.cpp"
	"src/Parser.h" "src/Parser.cpp"
)

