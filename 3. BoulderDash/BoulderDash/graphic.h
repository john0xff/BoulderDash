
void mainFrame()
{
	std::cout <<
		"o------------------------------------------------------------------------------o"
		"|      ______     ________   __    __   __        _____     ______   _____     |"
		"|     / ___  |   / ____  /  / /   / /  / /       / ___ |   / ____/  / ___ |    |"
		"|    / /__/ /   / /   / /  / /   / /  / /       / /  / /  / /__    / /__/ /    |"
		"|   / ___  /   / /   / /  / /   / /  / /       / /  / /  / ___/   / __   /     |"
		"|  / /__/  |  / /___/ /  / /___/ /  / /____   / /__/ /  / /___   / /  | \\      |"
		"| /_______/  /_______/  /_______/  /______/  /______/  /_____/  /_/   |_|      |"
		"|                                     ______     ________   ______    __    __ |"
		"|                                    / ___  |   / ____  /  / ____/   / /   / / |"
		"|                                   / /   / /  / /___/ /  / /___    / /___/ /  |"
		"|                                  / /   / /  / ____  /  |____  |  / ____  /   |"
		"|                                 / /___/ /  / /   / /  _____/ /  / /   / /    |"
		"|                                /_______/  /_/   /_/  /______/  /_/   /_/     |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"o------------------------------------------------------------------------------o";

	setPosition(0, 0);
}

void menuFrame()
{
	setPosition(10, 15);
	std::cout << "o----=MENU=-----o\n";

	for(int i = 16; i < 21; ++i)
	{
		setPosition(10, i);
		std::cout << "|               |\n";
	}

	setPosition(10, 21);
	std::cout << "o---------------o\n";
		

	setPosition(0, 0);
}

void gameFrame()
{
	std::cout << 
		"o-------------------------------=BOULDER DASH=---------------------------------o"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"o---------------------o--------------------------------------------------------o"
		"| DIAMONDS:           |                                                        |"
		"| MOVES:              |                                                        |"
		"| POINTS:             |                                                        |"
		"o---------------------o--------------------------------------------------------o";

	setPosition(0, 0);
}

void editFrame()
{
	std::cout << 
		"o--------------------------------=MAP EDITOR=----------------------------------o"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"|                                                                              |"
		"o------------------------------------------------------------------------------o";

	setPosition(0, 0);
}

void editSubFrame()
{
	setPosition(2, 1);
	std::cout << "o-------------o\n";

	for(int i = 2; i < 7; ++i)
	{
		setPosition(2, i);
		std::cout << "|             |\n";
	}

	setPosition(2, 7);
	std::cout << "o-------------o\n";
		
	setPosition(0, 0);
}

void clearMapScreen()
{
	for(int y = 1; y < mapHeight + 5; ++y)
	{
		for(int x = 1; x < mapWidth + 1; ++x)
		{
			setPosition(x, y);
			std::cout << " ";
		}
	}
}

void clearQuaterMapScreen()
{
	for(int y = 1; y < mapHeight / 2; ++y)
	{
		for(int x = 1; x < mapWidth / 2; ++x)
		{
			setPosition(x, y);
			std::cout << " ";
		}
	}
}

void setBlackConsoleTextAttribute(setConsolePositonX x, setConsolePositonY y)
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(x, y);
}

void setWhiteConsoleTextAttribute(setConsolePositonX x, setConsolePositonY y)
{
	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition(x, y);
}