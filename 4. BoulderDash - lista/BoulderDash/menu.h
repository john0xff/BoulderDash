
extern void editMap();
extern void gameLoop();
extern void mainFrame();
extern void menuFrame();

void drawMenu(bool flag, char* text, setConsolePositonX x, setConsolePositonY y)
{
	if(flag == true)
		setWhiteConsoleTextAttribute(x, y);
	else if(flag == false)
		setBlackConsoleTextAttribute(x, y);
	
	setPosition(x, y);
	std::cout << text << "\n";
}

void menu()
{
	mainFrame();
	menuFrame();

	char key = 0;
	int position = 1;

	drawMenu(1, "1. START GAME", 12, 17);
	drawMenu(0, "2. MAP EDITOR", 12, 18);
	drawMenu(0, "3. EXIT", 12, 19);

	setPosition(0, 0);

	while(true)
	{
		key = _getch();

		switch(key)
		{
		case 72:
			if(position > 1)
			{
				--position;

				if(position == 1)
				{
					drawMenu(1, "1. START GAME", 12, 17);
					drawMenu(0, "2. MAP EDITOR", 12, 18);
					drawMenu(0, "3. EXIT", 12, 19);
					position = 1;
				}

				if(position == 2)
				{
					drawMenu(0, "1. START GAME", 12, 17);
					drawMenu(1, "2. MAP EDITOR", 12, 18);
					drawMenu(0, "3. EXIT", 12, 19);
					position = 2;
				}

				if(position == 3)
				{
					drawMenu(0, "1. START GAME", 12, 17);
					drawMenu(0, "2. MAP EDITOR", 12, 18);
					drawMenu(1, "3. EXIT", 12, 19);
					position = 3;
				}
			}
			break;

		case 80:
			if(position < 3)
			{
				++position;

				if(position == 1)
				{
					drawMenu(1, "1. START GAME", 12, 17);
					drawMenu(0, "2. MAP EDITOR", 12, 18);
					drawMenu(0, "3. EXIT", 12, 19);
					position = 1;
				}

				if(position == 2)
				{
					drawMenu(0, "1. START GAME", 12, 17);
					drawMenu(1, "2. MAP EDITOR", 12, 18);
					drawMenu(0, "3. EXIT", 12, 19);
					position = 2;
				}

				if(position == 3)
				{
					drawMenu(0, "1. START GAME", 12, 17);
					drawMenu(0, "2. MAP EDITOR", 12, 18);
					drawMenu(1, "3. EXIT", 12, 19);
					position = 3;
				}
			}
			break;
		}

		SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);

		if((key == 13) && (position == 1))
		{
			gameLoop();
			system("cls");
			menu();
			continue;
		}

		else if((key == 13) && (position == 2))
		{
			editionMenu();
			continue;
		}

		else if((key == 13) && (position == 3))
		{
			exit(0);
		}

		if(key == 27)
			exit(0);

		setPosition(0, 0);
	}
}

void drawSubMenuFirst()
{
	clearMapScreen();
	editSubFrame();
	drawMenu(1, "1. NEW MAP", 4, 3);
	drawMenu(0, "2. EDIT MAP", 4, 4);
	drawMenu(0, "3. BACK", 4, 5);
}

void drawSubMenuSecound()
{
	clearMapScreen();
	editSubFrame();
	drawMenu(0, "1. NEW MAP", 4, 3);
	drawMenu(1, "2. EDIT MAP", 4, 4);
	drawMenu(0, "3. BACK", 4, 5);
}

void editionMenu()
{
	system("cls");
	editFrame();

	char key = 0;
	int position = 1;

	editSubFrame();

	drawMenu(1, "1. NEW MAP", 4, 3);
	drawMenu(0, "2. EDIT MAP", 4, 4);
	drawMenu(0, "3. BACK", 4, 5);

	setPosition(0, 0);

	while(true)
	{
		key = _getch();

		switch(key)
		{
		case 72:
			if(position > 1)
			{
				--position;

				if(position == 1)
				{
					drawMenu(1, "1. NEW MAP", 4, 3);
					drawMenu(0, "2. EDIT MAP", 4, 4);
					drawMenu(0, "3. BACK", 4, 5);
					position = 1;
				}

				if(position == 2)
				{
					drawMenu(0, "1. NEW MAP", 4, 3);
					drawMenu(1, "2. EDIT MAP", 4, 4);
					drawMenu(0, "3. BACK", 4, 5);
					position = 2;
				}

				if(position == 3)
				{
					drawMenu(0, "1. NEW MAP", 4, 3);
					drawMenu(0, "2. EDIT MAP", 4, 4);
					drawMenu(1, "3. BACK", 4, 5);
					position = 3;
				}
			}
			break;

		case 80:
			if(position < 3)
			{
				++position;

				if(position == 1)
				{
					drawMenu(1, "1. NEW MAP", 4, 3);
					drawMenu(0, "2. EDIT MAP", 4, 4);
					drawMenu(0, "3. BACK", 4, 5);
					position = 1;
				}

				if(position == 2)
				{
					drawMenu(0, "1. NEW MAP", 4, 3);
					drawMenu(1, "2. EDIT MAP", 4, 4);
					drawMenu(0, "3. BACK", 4, 5);
					position = 2;
				}

				if(position == 3)
				{
					drawMenu(0, "1. NEW MAP", 4, 3);
					drawMenu(0, "2. EDIT MAP", 4, 4);
					drawMenu(1, "3. BACK", 4, 5);
					position = 3;
				}
			}
			break;
		}

		SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);

		if((key == 13) && (position == 1))
		{
			editNewMap();
			drawSubMenuFirst();
		}

		else if((key == 13) && (position == 2))
		{
			editMap();
			drawSubMenuSecound();
		}

		else if((key == 13) && (position == 3))
		{
			menu();
		}

		if(key == 27)
			menu();

		setPosition(0, 0);
	}
}