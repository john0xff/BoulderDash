
void markMonster(Monster &monster)
{
	setBlackConsoleTextAttribute((int)monster.position.x + 1, (int)monster.position.y + 1);
	
	map[(int)monster.position.y][(int)monster.position.x] = monsterChar;
	std::cout << map[(int)monster.position.y][(int)monster.position.x];
}

void unmarkMonster(Monster &monster)
{
	setBlackConsoleTextAttribute((int)monster.position.x + 1, (int)monster.position.y + 1);
	
	map[(int)monster.position.y][(int)monster.position.x] = spaceChar;
	std::cout << map[(int)monster.position.y][(int)monster.position.x];
}

void rotateLeft(Monster &monster)
{
	double tmp = monster.direction.x;
	monster.direction.x = monster.direction.y;
	monster.direction.y = -tmp;
}

void rotateRight(Monster &monster)
{
	double tmp = monster.direction.x;
	monster.direction.x = -monster.direction.y;
	monster.direction.y = tmp;
}

bool checkRightWall(Monster &monster)
{
	double wallX = monster.position.x - monster.direction.y;
	double wallY = monster.position.y + monster.direction.x;

	const char tmp = map[(int)wallY][(int)wallX];

	if((tmp != hashChar) && 
	   (tmp != wallChar) && 
	   (tmp != stoneChar) && 
	   (tmp != playerChar))
		return false;

	return true;
}

bool checkBeforeWall(Monster &monster)
{
	double wallX = monster.position.x + monster.direction.x;
	double wallY = monster.position.y + monster.direction.y;

	const char tmp = map[(int)wallY][(int)wallX];

	if((tmp != hashChar) && 
	   (tmp != wallChar) && 
	   (tmp != stoneChar) && 
	   (tmp != playerChar))
		return false;

	return true;
}

bool checkCornerWall(Monster &monster)
{
	double wallX = monster.position.x - monster.direction.y - monster.direction.x;
	double wallY = monster.position.y + monster.direction.x - monster.direction.y;

	const char tmp = map[(int)wallY][(int)wallX];

	if((tmp != hashChar) && 
	   (tmp != wallChar) && 
	   (tmp != stoneChar) && 
	   (tmp != playerChar))
		return false;

	return true;
}

bool rotateMonster(Monster &monster)
{
	if(checkBeforeWall(monster))
	{
		rotateLeft(monster);

		if(checkBeforeWall(monster))
		{
			rotateLeft(monster);

			return checkBeforeWall(monster);
		}
	}

	return false;
}

void checkMonsterCondition(Monster &monster)
{
	if(checkRightWall(monster))
	{
		if(rotateMonster(monster))
			return;
	}
	else
	{
		if(checkCornerWall(monster))
		{
			rotateRight(monster);
		}
		else
		{
			if(rotateMonster(monster))
				rotateLeft(monster);
		}
	}
}

void monsterMove(Monster &monster)
{
	unmarkMonster(monster);

	checkMonsterCondition(monster);

	monster.position.x += monster.direction.x;
	monster.position.y += monster.direction.y;

	markMonster(monster);
}