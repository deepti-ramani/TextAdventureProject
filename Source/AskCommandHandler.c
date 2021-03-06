/*
Filename: AskCommandHandler.c
Author: Deepti Ramani
Last Edited: 3/11/2020
Brief: This file handles the player's conversations with npcs
 */

#include "stdafx.h" /* NULL, printf, strnlen_s */
#include "AskCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_Print, Room_GetItemList */
#include "CharacterList.h"
#include "Character.h"


/* Handles the ask command */
void HandleAskCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Character* character = NULL;
	CharacterList** characterList;
	Room* room;

	if (command == NULL || gameState == NULL || worldData == NULL)
	{
		return;
	}

	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	characterList = Room_GetCharacterList(room);
	if (characterList == NULL)
	{
		return;
	}
	else if (CharacterList_GetCount(*characterList) > 1)
	{
		if (command->noun == NULL)
		{
			printf("There are multiple people in the room. Who would you like to speak to?\n");
			return;
		}
		else
		{
			character = CharacterList_Find(*characterList, command->noun);
		}
	}
	/* if there's only one character in the room, get that character */
	else if (CharacterList_GetCount(*characterList) == 1)
	{
		character = CharacterList_GetCurrent(*characterList);
	}


	if (character != NULL)
	{
		Character_UpdateConversationCount(character);
		printf("You approach %s.\n", Character_GetName(character));

		if (Character_GetConversationCount(character) == 0)
		{
			printf("%s: %s.\n", Character_GetName(character), Character_GetOpeningDialogue(character));
		}
		else
		{
			printf("%s: %s.\n", Character_GetName(character), Character_GetRegularDialogue(character));
			if (Character_GetHiddenDialogue(character) != NULL)
			{
				printf("%s.\n", Character_GetHiddenDialogue(character));
			}
		}
		return;
	}
	printf("You do not see %s in the room.\n", command->noun);
}