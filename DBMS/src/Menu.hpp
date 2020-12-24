#pragma once

#ifndef MENU
#define MENU

#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace Menu {

	uint8_t getMenu() noexcept;


	void createDB();
	void openDB();
	void openSettings();
	void openCredits();

	inline uint8_t exit() {
		return 0;
	};
	// TODO: implement menu controller func/class
}

#define MENU() Menu::getMenu()
#define EXIT() Menu::exit()

#endif // !MENU