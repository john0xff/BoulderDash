
bool getFileName(char* fileName)
{
	setPosition(0, 0);

	fileName[0] = NULL;

	char key = 0;
	int i = 0;

	while(true)
	{
		if(_kbhit())
		{
			key = _getch();

			if(key == 27)
				break;

			if(key == 13)
			{
				fileName[i] = 0;
				break;
			}

			if(key == 8)
			{
				--i;

				if(i < 0)
					i = 0;

				fileName[i] = NULL;

				setBlackConsoleTextAttribute(3 + i, 5);
				std::cout << ' ';
				continue;
			}

			if(i > 23)
				return true;
			
			fileName[i] = key;
			fileName[i + 1] = 0;

			setBlackConsoleTextAttribute(3 + i, 5);
			std::cout << fileName[i];

			++i;
		}
	}
	
	if(key == 27)
		return false;

	return true;
}

void saveMap()
{
	setPosition(3, 3);
	std::cout << "File name: " << "\n";

	char fileName[25];

	if(getFileName(fileName) == false)
		return;

	FILE* pFile;

	if((pFile = fopen (fileName, "wb")) != 0)
	{
		for(int y = 0; y < mapHeight; ++y)
		{
			fwrite(map[y], sizeof(char), mapWidth, pFile);  
		}
		
		fclose(pFile);

		setBlackConsoleTextAttribute(3, 7);
		std::cout << "Map was saved as: "
				  << fileName;

		_getch();
	}
	else
	{
		std::cout << "Save error";
	}
}