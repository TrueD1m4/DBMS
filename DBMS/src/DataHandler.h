#pragma once

#ifndef DATA_HANDLER
#define DATA_HANDLER

#include <iostream>
#include <string>

//data handler namespace
namespace DataHandler {

	//class created for writing and reading data
	template<typename T>
	class Data {
	public:

		//constructors and destructors
		Data() = default;
		explicit Data(T data);
		~Data() = default;

		//getter and setter for data
		T getData() noexcept;
		void setData(T data);

		//overloaded operator >>
		friend std::istream& operator>>(std::istream& in, Data<T>& data) {
			T tmp;
			in >> tmp;

			data.setData(tmp);

			return in;
		}
		// overloaded operator <<
		friend std::ostream& operator<<(std::ostream& out, Data<T>& data) {

			out << data.getData();

			return out;
		}

	private:
		//single-type data
		T m_data;
	};

}

#endif // !DATA_HANDLER