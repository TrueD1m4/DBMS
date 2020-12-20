#include "DataHandler.h"

namespace DataHandler {

	template<typename T>
	Data<T>::Data(T data) : m_data(data){
	}

	template<typename T>
	T Data<T>::getData() noexcept {
		return this->m_data;
	}

	template<typename T>
	void Data<T>::setData(T data) {
		this->m_data = data;
	}

	template class Data<int>;
	template class Data<double>;
	template class Data<std::string>;
}