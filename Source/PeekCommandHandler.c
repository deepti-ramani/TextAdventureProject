/*
Filename: PeekCommandHandler.c
Author: Deepti Ramani
Last Edited: 3/11/2020
Brief: This file handles the player's use of the "peek" command, and gives a description of an adjacent room.
 */

#include "stdafx.h" /* NULL, printf, strnlen_s */
#include "PeekCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_Print, Room_GetItemList */


/* Handles the peek command -> check adjacent room */
void HandlePeekCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Room* currRoom;
	Room* roomToCheck;
	int nextRoomIndex;

	if (command == NULL || gameState == NULL || worldData == NULL)
	{
		return;
	}

	currRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	if (Room_GetNextRoomIndex(currRoom, command->noun, &nextRoomIndex) == false)
	{
		printf("There is no room in that direction. Try checking somewhere else.\n");
		return;
	}

	roomToCheck = WorldData_GetRoom(worldData, nextRoomIndex);
	printf("You breifly check the room to the %s.\n", command->noun);
	if (Room_GetPeekDescription(roomToCheck) == NULL)
	{
		printf("You cannot determine anything about the room.\n");
	}
	else
	{
		printf("%s.\n", Room_GetPeekDescription(roomToCheck));
	}
}