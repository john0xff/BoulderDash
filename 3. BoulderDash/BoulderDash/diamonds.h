
void markDiamond(Diamond &diamond)
{
	setBlackConsoleTextAttribute((int)diamond.position.x + 1, (int)diamond.position.y + 1);

	map[(int)diamond.position.y][(int)diamond.position.x] = diamondChar;
	std::cout << map[(int)diamond.position.y][(int)diamond.position.x];
}

void unmarkDiamond(Diamond &diamond)
{
	setBlackConsoleTextAttribute((int)diamond.position.x + 1, (int)diamond.position.y + 1);
	
	map[(int)diamond.position.y][(int)diamond.position.x] = spaceChar;
	std::cout << map[(int)diamond.position.y][(int)diamond.position.x];
}

void checkDiamondCondition(Diamond &diamond)
{
	if(map[(int)diamond.position.y + 1][(int)diamond.position.x] == spaceChar)
	{
		diamond.position.y += 1;
	}
	else if((map[(int)diamond.position.y + 1][(int)diamond.position.x + 1] == spaceChar) &&
			(map[(int)diamond.position.y][(int)diamond.position.x + 1] == spaceChar))
	{
		diamond.position.x += 1;
	}
	else if((map[(int)diamond.position.y + 1][(int)diamond.position.x -1 ] == spaceChar) &&
			(map[(int)diamond.position.y][(int)diamond.position.x -1 ] == spaceChar))
	{
		diamond.position.x -= 1;
	}
}

bool diamondMove(Diamond &diamond)
{
	if((map[(int)diamond.position.y][(int)diamond.position.x]) == 
		(map[(int)player.position.y][(int)player.position.x]))
	{
		map[(int)diamond.position.y][(int)diamond.position.x] = spaceChar;

		return true;
	}

	if((map[(int)diamond.position.y + 1][(int)diamond.position.x] != spaceChar) &&
	   (map[(int)diamond.position.y + 1][(int)diamond.position.x + 1] != spaceChar) &&
	   (map[(int)diamond.position.y + 1][(int)diamond.position.x - 1] != spaceChar))
	{
			return true;
	}

	

	unmarkDiamond(diamond);

	checkDiamondCondition(diamond);

	markDiamond(diamond);

	return true;
}
