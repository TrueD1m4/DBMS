#pragma once

#ifndef ENCRYPTION
#define ENCRYPTION

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <bitset>

#include "../Logger/Logger.hpp"

#define u8 uint8_t
#define Stringify(msg) #msg

namespace encryption {

	/*
	Encryption for database	
	The algotihm DES will be used for encryption data of db and structure 
	for this data.
	*/
	class Encoder {
	public:

		Encoder() = default;
		~Encoder() = default;

	public:
		enum class State : u8 {
			FAIL,
			WORKING,
			ENCODED
		};
		
	private:
		State stateOfEncoding;
		//TODO: add functionality to UNICODE
		const u8 sizeOfBlock = 64; //size of block into DES
		const u8 sizeOfChar = 8; //size of char in utf-8
		const u8 shfitKey = 2; //shift 
		const u8 quantityOfRonuds = 16;

		std::vector<std::bitset<8>> blocks;
	};

	class Decoder{};

}
#endif // !ENCRYPTION