#include "Menu.hpp"

namespace Menu {

	uint8_t getMenu() noexcept {
		uint8_t value = 0;

		while (value == 0) {
			std::cout << "1. Create new database" << std::endl;
			std::cout << "2. Open recent" << std::endl;
			std::cout << "3. Settings" << std::endl;
			std::cout << "4. Credits" << std::endl;
			std::cout << "5. Exit" << std::endl;
			std::cout << std::endl;

			std::cout << "> ";
			std::cin >> value;

			bool cantWork = (value == 0 || value > 5);

			if (cantWork) {
				value = 0;

				std::cerr << "Bad value" << std::endl;
				system("pause");
				system("cls");
			}
		}

		return value;
	};


}
