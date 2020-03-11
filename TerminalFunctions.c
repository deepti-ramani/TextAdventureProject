/*
Filename: TerminalFunctions.c
Author: Conor Brennan
Last Edited: 3/10/2020
Brief: This file defines the functions to create a specific item, the "terminal".
 */

#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "TerminalFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "stdio.h"

#define MAXPASSWORDLENGTH 128


 /* Helper: The action performed when the SomeItem is taken. */
void Terminal_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Do something when the item is taken including printing out something about it happening. */
}

/* Helper: The action performed when the SomeItem is used. */
void Terminal_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	char password[MAXPASSWORDLENGTH];

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);

	/* Do something when the item is used including printing out something about it happening. */

	Room* room; /* The current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex); /* get the current room */

	puts("Please input the 4 digit access code:\n");
	fgets(password, MAXPASSWORDLENGTH, stdin);
	if (strcmp(password, "1416\n"))
	{
		puts("Access Approved\n");
		puts("");
	}

}

void Terminal_Drop(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Do something when the item is dropped including printing out something about it happening. */
}


/* Build a "SomeItem" object */
Item* Terminal_Build()
{
	/* Create a "SomeItem" item, using the functions defined in this file */
	return Item_Create("SomeItem", "Oh man. That sure is some item.", true, Terminal_Use, Terminal_Take, Terminal_Drop);
}
