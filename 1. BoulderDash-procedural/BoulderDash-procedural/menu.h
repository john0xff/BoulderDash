
extern void editMap();
extern void gameLoop();
extern void drawMainFrame();
extern void miniMenu();

void drawAttributeFirst()
{
	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition(12, 17);
	std::cout << "1. START GAME" << "\n";
		
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(12, 18);
	std::cout << "2. MAP EDITOR" << "\n";

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(12, 19);
	std::cout << "3. EXIT" << "\n";
}

void drawAttributeSecond()
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(12, 17);
	std::cout << "1. START GAME" << "\n";
		
	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition(12, 18);
	std::cout << "2. MAP EDITOR" << "\n";

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(12, 19);
	std::cout << "3. EXIT" << "\n";
}

void drawAttributeThird()
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(12, 17);
	std::cout << "1. START GAME" << "\n";
		
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(12, 18);
	std::cout << "2. MAP EDITOR" << "\n";

	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition(12, 19);
	std::cout << "3. EXIT" << "\n";
}

void menu()
{
	drawMainFrame();
	miniMenu();

	char key = 0;
	int position = 1;

	drawAttributeFirst();
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
					drawAttributeFirst();
					position = 1;
				}

				if(position == 2)
				{
					drawAttributeSecond();
					position = 2;
				}

				if(position == 3)
				{
					drawAttributeThird();
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
					drawAttributeFirst();
					position = 1;
				}

				if(position == 2)
				{
					drawAttributeSecond();
					position = 2;
				}

				if(position == 3)
				{
					drawAttributeThird();
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

void drawSubAttributeFirst()
{
	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition(4, 3);
	std::cout << "1. NEW MAP" << "\n";
		
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(4, 4);
	std::cout << "2. EDIT MAP" << "\n";

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(4, 5);
	std::cout << "3. BACK" << "\n";
}

void drawSubAttributeSecond()
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(4, 3);
	std::cout << "1. NEW MAP" << "\n";
		
	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition(4, 4);
	std::cout << "2. EDIT MAP" << "\n";

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(4, 5);
	std::cout << "3. BACK" << "\n";
}

void drawSubAttributeThird()
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(4, 3);
	std::cout << "1. NEW MAP" << "\n";
		
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition(4, 4);
	std::cout << "2. EDIT MAP" << "\n";

	SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
	setPosition(4, 5);
	std::cout << "3. BACK" << "\n";
}

void drawSubMenuFirst()
{
	clearMapScreen();
	subFrameMapEditor();
	drawSubAttributeFirst();
}

void drawSubMenuSecound()
{
	clearMapScreen();
	subFrameMapEditor();
	drawSubAttributeSecond();
}

void editionMenu()
{
	system("cls");
	frameMapEditor();

	char key = 0;
	int position = 1;

	subFrameMapEditor();
	drawSubAttributeFirst();
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
					drawSubAttributeFirst();
					position = 1;
				}

				if(position == 2)
				{
					drawSubAttributeSecond();
					position = 2;
				}

				if(position == 3)
				{
					drawSubAttributeThird();
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
					drawSubAttributeFirst();
					position = 1;
				}

				if(position == 2)
				{
					drawSubAttributeSecond();
					position = 2;
				}

				if(position == 3)
				{
					drawSubAttributeThird();
					position = 3;
				}
			}
			break;
		}

		SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);

		if((key == 13) && (position == 1))
		{
			newMapLoop();
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