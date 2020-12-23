cmake_minimum_required (VERSION 3.8)

add_executable (DBMS "DBMS.cpp" "DBMS.hpp"
	 
	"src/Logger/Logger.hpp" "src/Logger/Logger.cpp"
	"src/Menu.hpp" "src/Menu.cpp"
	"src/RequestParser/Parser.hpp" "src/RequestParser/Parser.cpp"
	"src/DataHandler/DataHandler.hpp" "src/DataHandler/DataHandler.cpp"
	
	)