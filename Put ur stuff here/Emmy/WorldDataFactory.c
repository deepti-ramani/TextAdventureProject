/******************************************************************************
filename    Emmy
author      Emmy Berg
DP email    emily.berg@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
My own file for inputting world data 

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */


Room* Room16_Build()
{
	Room* room = NULL;

	room = Room_Create("There’s a strange mist in the room that leaks from an unknown source. Empty metal cots line the walls. The light flickers on and off above you. You can occasionally catch a glimpse of an unmoving shape in the corner.\n");

	Room_PrintDialog(room, "Enter Dialog");

	Room_AddRoomExit(room, "east", 15);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room17_Build()
{
	Room* room = NULL;

	room = Room_Create("There are metal bunk beds leaning against the walls. All the pillows and blankets have been dragged over to a corner and piled up. Something shivers and quakes under the pile.\n");

	Room_PrintDialog(room, "Enter Dialog");

	Room_AddRoomExit(room, "north", 16);

	Room_PrintExitDesc(room, "Description of the Door");

}

WorldData* CreateInitialWorldData()
{
	WorldData* worldData;
	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 18;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	WorldData_SetRoom(worldData, 0 , Room9_Build());
	/* TODO ADVANCED: add additional advanced rooms */
	WorldData_SetRoom(worldData, 1, Room10_Build());
	WorldData_SetRoom(worldData, 0, Room1_Build());
	WorldData_SetRoom(worldData, 1, Room2_Build());
	WorldData_SetRoom(worldData, 2, Room3_Build());
	WorldData_SetRoom(worldData, 3, Room4_Build());
	WorldData_SetRoom(worldData, 4, Room5_Build());
	WorldData_SetRoom(worldData, 5, Room6_Build());
	WorldData_SetRoom(worldData, 6, Room7_Build());
	WorldData_SetRoom(worldData, 7, Room8_Build());
	WorldData_SetRoom(worldData, 8 , Room9_Build());
	WorldData_SetRoom(worldData, 9, Room10_Build());
	WorldData_SetRoom(worldData, 10, Room11_Build());
	WorldData_SetRoom(worldData, 11, Room12_Build());
	WorldData_SetRoom(worldData, 12, Room13_Build());
	WorldData_SetRoom(worldData, 13, Room14_Build());
	WorldData_SetRoom(worldData, 14, Room15_Build());
	WorldData_SetRoom(worldData, 15, Room16_Build());
	WorldData_SetRoom(worldData, 16, Room17_Build());
	WorldData_SetRoom(worldData, 17, Room18_Build());
	/* return the new object */
	return worldData;
}