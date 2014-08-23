
void markStone(Stone &stone)
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)stone.position.x + 1, (int)stone.position.y + 1);

	map[(int)stone.position.y][(int)stone.position.x] = stoneChar;
	std::cout << map[(int)stone.position.y][(int)stone.position.x];
}

void unmarkStone(Stone &stone)
{
	SetConsoleTextAttribute(output, backgroundColorBLACK | foregroundColorWHITE);
	setPosition((int)stone.position.x + 1, (int)stone.position.y + 1);

	map[(int)stone.position.y][(int)stone.position.x] = spaceChar;
	std::cout << map[(int)stone.position.y][(int)stone.position.x];
}

void checkStoneCondition(Stone &stone)
{
	if(map[(int)stone.position.y + 1][(int)stone.position.x] == spaceChar){
		stone.position.y += 1;
	}
	else if(map[(int)stone.position.y + 1][(int)stone.position.x + 1] == spaceChar){
		stone.position.x += 1;
	}
	else if(map[(int)stone.position.y + 1][(int)stone.position.x -1 ] == spaceChar){
		stone.position.x -= 1;
	}
}

void stoneMove(Stone &stone)
{
	if((map[(int)stone.position.y + 1][(int)stone.position.x] != spaceChar) &&
	   (map[(int)stone.position.y + 1][(int)stone.position.x + 1] != spaceChar) &&
	   (map[(int)stone.position.y + 1][(int)stone.position.x - 1] != spaceChar)){
			return;
	}

	unmarkStone(stone);

	checkStoneCondition(stone);

	markStone(stone);
}