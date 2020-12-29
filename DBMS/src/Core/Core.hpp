#pragma once

#ifndef CORE
#define CORE

#include <iostream>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <thread>
#include <mutex>

#include "../EncoderAndDecoder/Encryption.hpp"
#include "../FileHandler/FileHandler.hpp"
#include "../Logger/Logger.hpp"
#include "../MenuHandler/Menu.hpp"
#include "../RequestHandler/Parser.hpp"

#define STRINGIFY(msg) #msg
#define i8 int8_t
#define i16 int16_t 
#define i32 int32_t
#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

namespace core {
	
	class SystemKernel {
	private:
		SystemKernel();
		virtual ~SystemKernel();

	private:

		static SystemKernel* c_sys_kernel;
		bool m_isExists = false;

	public:

		SystemKernel(const SystemKernel& other) = delete;
		SystemKernel& operator= (const SystemKernel& other) = delete;

		SystemKernel* getInstance();
		bool isExists();
		bool deleteInstance();

	public:

	};

}

#endif //!CORE