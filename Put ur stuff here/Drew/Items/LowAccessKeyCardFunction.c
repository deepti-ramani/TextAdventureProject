/******************************************************************************
filename    LowAccessKeyCardFunctions.c
author      Drew Jennings

Brief Description:
This file defines the functions to create a specific item, the "LowAccessKeyCard".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "LowAccessKeyCardFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the LowAccessKeyCard is taken. */
void LowAccessKeyCard_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the LowAccessKeyCard might be used, whenever it is picked up. */
	printf("It can unlock any door...\n");
}


/* Helper: The action performed when the LowAccessKeyCard is used. */
void LowAccessKeyCard_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* LowAccessKeyCard; /* The LowAccessKeyCard in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the LowAccessKeyCard out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the LowAccessKeyCard - inform the user of the problem and take no action */
		printf("You must have the Low Access Key Card before you can use it.\n");
		return;
	}


	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "usedLowAccessKeyCard"))
	{
		/* the player already used the LowAccessKeyCard - inform the user of the problem and take no action */
		printf("You already used the Low Access Key Card here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the LowAccessKeyCard in the player's inventory - it should be there, since we are in the Inventory context */
		LowAccessKeyCard = ItemList_FindItem(gameState->inventory, "LowAccessKeyCard");

		/* Remove the LowAccessKeyCard from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, LowAccessKeyCard);

		/* Tell the user what they did */
		printf("You used the Low Access Key Card\nDoors with a Low Access level are now unlocked.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		/*Room_SetDescription(room, "This is room 0.  You are in a display room.  There is a broken cage here.\n");*/

		/* Add an egg to the current room, since the cage has been bashed open */
		/**roomItemsPtr = ItemList_Add(*roomItemsPtr, Egg_Build());*/

		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "UsedLowAccessKeyCard");
	}
}


/* Build a "LowAccessKeyCard" object */
Item* LowAccessKey_Build()
{
	/* Create a "LowAccessKeyCard" item, using the functions defined in this file */
	return Item_Create("LowAccessKeyCard", "A Key Card that can be used to open low access doors.", true, LowAccessKeyCard_Use, LowAccessKeyCard_Take, NULL);
}