
bool loadMap()
{
	setPosition(3, 3);
	std::cout << "File name: " << "\n";

	char fileName[25];

	if(getFileName(fileName) == false)
		return false;

	FILE* pFile;

	if((pFile = fopen (fileName, "rb")) != 0)
	{
		for(int y = 0; y < mapHeight; ++y)
		{
			fread(map[y], sizeof(char), mapWidth, pFile);  
		}
		
		fclose(pFile);

		return true;
	}
	else
	{
		setPosition(3, 7);
		std::cout << "This map dosen't exist, yet";
		_getch();
	}

	return false;
}
