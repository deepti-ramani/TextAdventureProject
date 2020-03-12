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

/* Helper: The action performed when the SomeItem is used. */
void Terminal_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	char password[MAXPASSWORDLENGTH];

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);

	/* Do something when the item is used including printing out something about it happening. */

	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex); /* get the current room */
	roomItemsPtr = Room_GetItemList(room);
	
	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}
	
	/* get the list of items in the current room */
	if (roomItemsPtr == NULL)
	{
		return; /* take no action, as something is wrong - we should always have an item list */
	}

	if (gameState->currentRoomIndex == 4)
	{
		printf("Please input the 4 digit access code.\n>> ");
		fgets(password, MAXPASSWORDLENGTH, stdin);
		if (strcmp(password, "1416"))
		{
			puts("\nAccess Approved, Deactivating Door Security.");
			Room_AddRoomExit(room, "north", 7);
			Room_AddRoomExit(room, "east", 8);
			Room_SetDescription(room, "All the doors in this room are unlocked now.\n");
		}
		else
		{
			puts("Incorrect Password\n");
			puts("Access Denied\n");
			return;
		}
	}

	if (gameState->currentRoomIndex == 8)
	{
		printf("Please input the 4 digit access code.\n>> ");
		fgets(password, MAXPASSWORDLENGTH, stdin);
		if (strcmp(password, "1416"))
		{
			puts("\nAccess Approved, Deactivating Door Security.");
			Room_AddRoomExit(room, "east", 9);
			Room_SetDescription(room, "All the doors in this room are unlocked now.\n");
		}
		else
		{
			puts("Incorrect Password\n");
			puts("Access Denied\n");
			return;
		}
	}


}

/* Build a "SomeItem" object */
Item* Terminal_Build()
{
	/* Create a "SomeItem" item, using the functions defined in this file */
	return Item_Create("terminal", "The Terminal seems to be awaiting an input.", false, Terminal_Use, NULL, NULL);
}
