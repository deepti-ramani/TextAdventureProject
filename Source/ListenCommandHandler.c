#include "stdafx.h" /* NULL, printf, strnlen_s */
#include "ListenCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_Print, Room_GetItemList */


/* Handles the "listen" command */
void HandleListenCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Room* room;

	if (command == NULL || gameState == NULL || worldData == NULL)
	{
		return;
	}

	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	
	if(Room_GetListenDescription(room) != NULL)
	{
		printf("You hear %s.\n", Room_GetListenDescription(room));
	}
	else 
	{
		printf("You cannot hear anything.\n");
	}
}