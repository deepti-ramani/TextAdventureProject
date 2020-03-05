/* InspectCommandHandler.c
	by Deepti Ramani
	03/04/2020
	carries out inspect command (provides description of an item)
*/
#include "InspectCommandHandler.h" /* function declarations */
#include "stdafx.h" /* NULL */
#include "CommandData.h" /* struct CommandData, CommandContext */
#include "WorldData.h" /* WorldData_GetRoom, */
#include "GameState.h" /* struct GameState */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* ItemFunc, Item_GetDropFunc */

void HandleAskCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Character* Character;
	Room* room;
	ItemList* itemList;

	/* check parameters */
	if (command == NULL || command->noun == NULL || gameState == NULL || worldData == NULL)
	{
		return;
	}

	Character = CharacterList_FindCharacter(command->noun);

	/* check if we are holding the item */
	if (inspectedItem == NULL)
	{
		printf("You are not holding %s.\n", command->noun);
		return;
	}

	printf("%s\n", Item_GetDescription(inspectedItem));
	//TODO: possible "secret" description
	printf("%s\n", Item_GetHiddenDescription(inspectedItem));
}