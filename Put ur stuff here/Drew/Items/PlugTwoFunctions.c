/******************************************************************************
filename    PlugTwoFunctions.c
author      Drew Jennings

Brief Description:
This file defines the functions to create a specific item, the "PlugTwo".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "PlugTwoFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the PlugTwo is taken. */
void PlugTwo_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the PlugTwo might be used, whenever it is picked up. */
	printf("It has some useful information on it\n");
}


/* Helper: The action performed when the PlugTwo is used. */
void PlugTwo_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* PlugTwo; /* The PlugTwo in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the PlugTwo out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the PlugTwo - inform the user of the problem and take no action */
		printf("You must have Plug #2 before you can use it.\n");
		return;
	}


	/* check if the cage has already been broken and scored */
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the PlugTwo in the player's inventory - it should be there, since we are in the Inventory context */
		PlugTwo = ItemList_FindItem(gameState->inventory, "PlugTwo");


		/* Tell the user what they did */
		printf("You used plug #2\n\n");

		/* Add to the player's score */
		/*GameState_ChangeScore(gameState, 10);*/

		/* Update the room description to reflect the change in the room */
		/*Room_SetDescription(room, "This is room 0.  You are in a display room.  There is a broken cage here.\n");*/

		/* Add an egg to the current room, since the cage has been bashed open */
		/**roomItemsPtr = ItemList_Add(*roomItemsPtr, Egg_Build());*/

		/* the gold piece has not been scored, so mark the flag */
		/*gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "UsedPlugTwo");*/
	}
}


/* Build a "PlugTwo" object */
Item* PlugTwo_Build()
{
	/* Create a "PlugTwo" item, using the functions defined in this file */
	return Item_Create("PlugTwo", "A usb with useful information contained on it.", true, PlugTwo_Use, PlugTwo_Take, NULL);
}