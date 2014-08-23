
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <cstdio>

#include "variables.h"
#include "player.h"
#include "monsters.h"
#include "stones.h"
#include "diamonds.h"
#include "mapEditor.h"
#include "saveMap.h"
#include "loadMap.h"
#include "menu.h"
#include "gameLoop.h"

int main()
{
	createMap();
	menu();
	deleteMap();

	return 0;
}