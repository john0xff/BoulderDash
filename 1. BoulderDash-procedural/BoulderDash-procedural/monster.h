
void markMonster(Monster &monster, char** &_loadedMap)
{
	_loadedMap[(int)monster.position.y][(int)monster.position.x] = monsterChar;

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)monster.position.x + 1, (int)monster.position.y + 1);
	std::cout << _loadedMap[(int)monster.position.y][(int)monster.position.x];
}

void unmarkMonster(Monster &monster, char** &_loadedMap)
{
	_loadedMap[(int)monster.position.y][(int)monster.position.x] = spaceChar;

	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)monster.position.x + 1, (int)monster.position.y + 1);
	std::cout << _loadedMap[(int)monster.position.y][(int)monster.position.x];
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

bool checkRightWall(Monster &monster, char** &_loadedMap)
{
	double wallX = monster.position.x - monster.direction.y;
	double wallY = monster.position.y + monster.direction.x;

	const char tmp = _loadedMap[(int)wallY][(int)wallX];

	if((tmp != hashChar) && (tmp != wallChar))
		return false;

	return true;
}

bool checkBeforeWall(Monster &monster, char** &_loadedMap)
{
	double wallX = monster.position.x + monster.direction.x;
	double wallY = monster.position.y + monster.direction.y;

	const char tmp = _loadedMap[(int)wallY][(int)wallX];

	if((tmp != hashChar) && (tmp != wallChar))
		return false;

	return true;
}

bool checkCornerWall(Monster &monster, char** &_loadedMap)
{
	double wallX = monster.position.x - monster.direction.y - monster.direction.x;
	double wallY = monster.position.y + monster.direction.x - monster.direction.y;

	const char tmp = _loadedMap[(int)wallY][(int)wallX];

	if((tmp != hashChar) && (tmp != wallChar))
		return false;

	return true;
}

bool rotateMonster(Monster &monster, char** &_loadedMap)
{
	if(checkBeforeWall(monster, _loadedMap))
	{
		rotateLeft(monster);

		if(checkBeforeWall(monster, _loadedMap))
		{
			rotateLeft(monster);

			return checkBeforeWall(monster, _loadedMap);
		}
	}

	return false;
}

void checkMonsterCondition(Monster &monster, char** &_loadedMap)
{
	if(checkRightWall(monster, _loadedMap))
	{
		if(rotateMonster(monster, _loadedMap))
			return;
	}
	else
	{
		if(checkCornerWall(monster, _loadedMap))
		{
			rotateRight(monster);
		}
		else
		{
			if(rotateMonster(monster, _loadedMap))
				rotateLeft(monster);
		}
	}
}

Monster monsterMove(Monster &monster, char** &_loadedMap)
{
	unmarkMonster(monster, _loadedMap);

	checkMonsterCondition(monster, _loadedMap);

	monster.position.x += monster.direction.x;
	monster.position.y += monster.direction.y;

	markMonster(monster, _loadedMap);

	return monster;
}