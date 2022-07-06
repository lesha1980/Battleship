#pragma once

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;




#include "Model/Enums/StatusTurn.h"
#include "Model/CoordXY.h"
#include "Model/ZoneDeck.h"
#include "Model/Deck.h"
#include "Model/Ship.h"
#include "Model/SingleDeck.h"
#include "Model/MultiDeck.h"
#include "Model/DoubleDeck.h"
#include "Model/ThreeDeck.h"
#include "Model/FourDeck.h"
#include "Model/Cell.h";
#include "Model/Turn.h"
#include "Model/GameBoard.h"
#include "Model/Tabloid.h"
#include "Model/Gamer.h"
#include "Model/ComputerGamer.h"
#include "Model/HumanGamer.h"
#include "Model/StrategyGame.h"
#include "Model/StrategyRandomShot.h"
#include "Model/StrategyDontShotZoneShip.h"




#include "Services/BattleMapGenerateService.h"
#include "Services/BattleShipGenerateService.h"
#include "Services/BattleShipMapValidationService.h"
#include "Services/BattleShipMapBindingService.h"
#include "Services/BattleGamerGenerateService.h"
#include "Services/StrategyContextService.h"


#include "Model/GameBoardContext.h"

#include "Controller/GameBoardContextController.h"
#include "Controller/GamerController.h"
#include "Controller/PCGamerController.h"
#include "Controller/HumanGamerController.h"
#include "Controller/GameActionController.h"

#include "View/Screen.h"
#include "View/GameView.h"
#include "View/GameMode.h"
#include "View/GameHumanPCMode.h"
#include "View/GamePCPCMode.h"




void startGame();
void human_pc();
void pc_pc();

#define TIMENULL time(NULL);
#define CLEARSCREEN system("cls")
#define SETLOCAL setlocale(LC_ALL, "");
#define GETCH _getch();