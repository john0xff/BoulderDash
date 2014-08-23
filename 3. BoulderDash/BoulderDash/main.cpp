
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <time.h>

#include "variables.h"
#include "graphic.h"
#include "player.h"
#include "monsters.h"
#include "stones.h"
#include "diamonds.h"
#include "map.h"
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


//#include <time.h>
//#include <conio.h>
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    
//    time_t czas;
//    struct tm * data;
//    char godzina[ 80 ];
//  while(true)
//  {
//    time( & czas );
//    data = localtime( & czas );
//    
//    strftime( godzina, 80, "Teraz jest %H:%M:%S.", data );
//    cout << godzina;
//
//	system("cls");
//   } 
//    getch();
//    return 0;
//}