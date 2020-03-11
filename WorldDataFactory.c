/******************************************************************************
filename    WorldDataFactory.c
author      Evening Class
DP email    @digipen,edu
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

Room* Room0_Build()
{
	Room* room = NULL;

	room = Room_Create("Sir, the ship has successfully made contact with the dominion. Let me know when you want to proceed with the investigation. Feel free to look around until you are ready.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "east", 1);

	Room_PrintExitDesc(room, "The exit is an air-tight channel.");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room1_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #1 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "west", 0);
	Room_AddRoomExit(room, "east", 2);

	Room_PrintExitDesc(room, "The West exit takes you to your shuttle. The East exit will take you to the main floor of The Dominion. ");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room2_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #2 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "north", 3);
	Room_AddRoomExit(room, "east", 4);
	Room_AddRoomExit(room, "south", 6);
	Room_AddRoomExit(room, "west", 1);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room3_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #3 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "south", 2);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room4_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #4 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "North", 7);
	Room_AddRoomExit(room, "east", 8);
	Room_AddRoomExit(room, "south", 5);
	Room_AddRoomExit(room, "west", 2);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room5_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #5 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "north", 4);
	Room_AddRoomExit(room, "east", 6);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room6_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #6 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "north", 2);
	Room_AddRoomExit(room, "east", 5);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room7_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #7 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "south", 4);
	Room_AddRoomExit(room, "down (Elevator)", 13);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room8_Build()
{
	Room* room = NULL;

	room = Room_Create("A Dimly Lit Room with the Lights Flickering Repeatedly. In the Room's Corner, there is a Humanoid Figure Sitting Down.\n");

	Room_PrintDialog(room, "");

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

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "west", 8);
	Room_AddRoomExit(room, "up", 14);
	Room_AddRoomExit(room, "down", 10);
	
	Room_PrintExitDesc(room, "There is a Keycard Reader at the Elevator.");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room10_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #10 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "west", 11);
	Room_AddRoomExit(room, "up", 9);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room11_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #11 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "west", 12);
	Room_AddRoomExit(room, "east", 10);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room12_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #12 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "north", 13);
	Room_AddRoomExit(room, "east", 11);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room13_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #13 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "up", 7);
	Room_AddRoomExit(room, "south", 12);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room14_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #14 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "west", 15);
	Room_AddRoomExit(room, "down", 9);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room15_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #15 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "west", 16);
	Room_AddRoomExit(room, "east", 14);
	Room_AddRoomExit(room, "south", 17);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room16_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #16 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "east", 15);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room17_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #17 Description.\n");

	Room_PrintDialog(room, "");

	Room_AddRoomExit(room, "north", 16);

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
	worldData = WorldData_Create("You are an agent that has been dispatched from the Global Space. \n Several days ago, scientists picked up a distress signal from within deep space, originating from a ship that went off the radar a week ago. \nYou have been sent out in your own shuttle to investigate the location of the ship and rescue any survivors on board.\n Launching in 5...4...3...2...1...\n ... \n ... \n ... \n Hours later, you have connected your shuttle to the lost stranded ship, The Dominion.", roomCount);

	/* build each room and assign them to the world data */
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	/* TODO ADVANCED: add additional advanced rooms */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 2, Room2_Build());
	WorldData_SetRoom(worldData, 3, Room3_Build());
	WorldData_SetRoom(worldData, 4, Room4_Build());
	WorldData_SetRoom(worldData, 5, Room5_Build());
	WorldData_SetRoom(worldData, 6, Room6_Build());
	WorldData_SetRoom(worldData, 7, Room7_Build());
	WorldData_SetRoom(worldData, 8, Room8_Build());
	WorldData_SetRoom(worldData, 9, Room9_Build());
	WorldData_SetRoom(worldData, 10, Room10_Build());
	WorldData_SetRoom(worldData, 11, Room11_Build());
	WorldData_SetRoom(worldData, 12, Room12_Build());
	WorldData_SetRoom(worldData, 13, Room13_Build());
	WorldData_SetRoom(worldData, 14, Room14_Build());
	WorldData_SetRoom(worldData, 15, Room15_Build());
	WorldData_SetRoom(worldData, 16, Room16_Build());
	WorldData_SetRoom(worldData, 17, Room17_Build());
	/* return the new object */
	return worldData;
}