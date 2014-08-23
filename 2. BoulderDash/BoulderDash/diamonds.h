
void markDiamond(Diamond &diamond)
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)diamond.position.x + 1, (int)diamond.position.y + 1);

	map[(int)diamond.position.y][(int)diamond.position.x] = diamondChar;
	std::cout << map[(int)diamond.position.y][(int)diamond.position.x];
}

void unmarkDiamond(Diamond &diamond)
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)diamond.position.x + 1, (int)diamond.position.y + 1);

	map[(int)diamond.position.y][(int)diamond.position.x] = spaceChar;
	std::cout << map[(int)diamond.position.y][(int)diamond.position.x];
}

void checkDiamondCondition(Diamond &diamond)
{
	if(map[(int)diamond.position.y + 1][(int)diamond.position.x] == spaceChar){
		diamond.position.y += 1;
	}
	else if(map[(int)diamond.position.y + 1][(int)diamond.position.x + 1] == spaceChar){
		diamond.position.x += 1;
	}
	else if(map[(int)diamond.position.y + 1][(int)diamond.position.x -1 ] == spaceChar){
		diamond.position.x -= 1;
	}
}

bool addPoints(Diamond &diamond)
{
	if((map[(int)player.position.y][(int)player.position.x]) == 
	   (map[(int)diamond.position.y][(int)diamond.position.x]))
	{
		map[(int)diamond.position.y][(int)diamond.position.x] = spaceChar;
		++diamondPoints;

		SetConsoleTextAttribute(output, backgroundColorWHITE | foregroundColorGOLD);
		setPosition((int)player.position.x + 1, (int)player.position.y + 1);
		std::cout << map[(int)player.position.y][(int)player.position.x];

		return false;
	}

	return true;
}

bool diamondMove(Diamond &diamond)
{
	if((map[(int)diamond.position.y + 1][(int)diamond.position.x] != spaceChar) &&
	   (map[(int)diamond.position.y + 1][(int)diamond.position.x + 1] != spaceChar) &&
	   (map[(int)diamond.position.y + 1][(int)diamond.position.x - 1] != spaceChar)){
			return true;
	}

	unmarkDiamond(diamond);

	checkDiamondCondition(diamond);

	markDiamond(diamond);

	return true;
}
