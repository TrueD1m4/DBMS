cmake_minimum_required (VERSION 3.8)

add_executable (DBMS "DBMS.cpp" "DBMS.hpp"
	 
	"src/Logger/Logger.hpp" "src/Logger/Logger.cpp"
	"src/MenuHandler/Menu.hpp" "src/MenuHandler/Menu.cpp"
	"src/RequestHandler/Parser.hpp" "src/RequestHandler/Parser.cpp"
	"src/FileHandler/FileHandler.hpp" "src/FileHandler/FileHandler.cpp"
	"src/EncoderAndDecoder/Encryption.hpp" "src/EncoderAndDecoder/Encryption.cpp"
	"src/Core/Core.hpp" "src/Core/Core.cpp" 
 ) 