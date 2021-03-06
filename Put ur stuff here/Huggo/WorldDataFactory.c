/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */

Room* Room1_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #1.\n");

	Room_AddRoomExit(room, "Direction", 2);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room2_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #2.\n");

	Room_AddRoomExit(room, "Direction", 3);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room3_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #3.\n");

	Room_AddRoomExit(room, "Direction", 4);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room4_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #4.\n");

	Room_AddRoomExit(room, "Direction", 5);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room5_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #5.\n");

	Room_AddRoomExit(room, "Direction", 6);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room6_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #6.\n");

	Room_AddRoomExit(room, "Direction", 7);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room7_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #7.\n");

	Room_AddRoomExit(room, "Direction", 8);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room8_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #8.\n");

	Room_AddRoomExit(room, "Direction", 9);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room8_Build()
{
	Room* room = NULL;
	
	room = Room_Create("A Dimly Lit Room with the Lights Flickering Repeatedly. In the Room's Corner, there is a Humanoid Figure Sitting Down.\n");
	
	Room_AddRoomExit(room, "west", 4);
	Room_AddRoomExit(room, "east", 9);

	
	Room_PrintExitDesc(room, "There is a Keycard Reader at the Door.");
	
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	
	return room;
}

Room* Room9_Build()
{
	
	Room* room = NULL;

	room = Room_Create("There is an Elevator at the End of the Room.\n");
	
	Room_AddRoomExit(room, "west", 8);
	Room_AddRoomExit(room, "up", 14);
	Room_AddRoomExit(room, "down", 10);

	Room_PrintExitDesc(room, "There is an Elevator at the End of the Room, it has two Directions to Travel to: Up and Down. There is a Door Traveling towards West.");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room11_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #11.\n");


	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room12_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #12.\n");

	Room_AddRoomExit(room, "Direction", 13);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room13_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #13.\n");

	Room_AddRoomExit(room, "Direction", 14);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room14_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #14.\n");

	Room_AddRoomExit(room, "Direction", 15);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room15_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #15.\n");

	Room_AddRoomExit(room, "Direction", 16);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room16_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #16.\n");

	Room_AddRoomExit(room, "Direction", 17);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room17_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #17.\n");

	Room_AddRoomExit(room, "Direction", 18);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room18_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #18.\n");

	Room_AddRoomExit(room, "Back", 17);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
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