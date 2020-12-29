#include "Core.hpp"

namespace core {

	SystemKernel::SystemKernel() {

	}

	SystemKernel* SystemKernel::getInstance() {
		if (!c_sys_kernel) {
			c_sys_kernel = new SystemKernel();
			m_isExists = true;
		}
		return c_sys_kernel;
	}

	bool SystemKernel::deleteInstance() {
		if (c_sys_kernel) {
			delete c_sys_kernel;
			c_sys_kernel = nullptr;
			return true;
		}
		return false;
	}

	bool SystemKernel::isExists() {
		return m_isExists;
	}

}