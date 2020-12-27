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

	struct Settings {
		//TODO: add functionality to UNICODE
#ifdef _UNICODE
		const u8 sizeOfBlock = 128; //size of block into DES
		const u8 sizeOfChar = 16; //size of char in unicode
#else
		const u8 sizeOfBlock = 64; //size of block into DES
		const u8 sizeOfChar = 8; //size of char in utf-8
#endif

		const u8 shfitKey = 2; //shift 
		const u8 quantityOfRonuds = 16;
	};

	class Encoder : private Settings {
	public:

		Encoder() = default;
		~Encoder() = default;

	public:
		enum class State : u8 {
			FAIL,
			WORKING,
			ENCODED
		};
		
		State getState();

	private:
		State m_stateOfEncoding;
		State setState();

		std::vector<std::bitset<8>> blocks;
	};

	class Decoder : private Settings {
	public:

		Decoder() = default;
		~Decoder() = default;

	public:
		enum class State : u8 {
			FAIL,
			WORKING,
			DECODED
		};

		State getState();

	private:
		State m_stateOfDecoding;
		State setState();
	};

}
#endif // !ENCRYPTION