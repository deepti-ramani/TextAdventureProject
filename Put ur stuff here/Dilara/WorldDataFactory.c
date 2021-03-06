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

Room* Room0_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #0.\n");

	Room_AddRoomExit(room, "east", 1);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room1_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #1.\n");

	Room_AddRoomExit(room, "west", 0);
	Room_AddRoomExit(room, "east", 2);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room2_Build()
{
	Room* room = NULL;

	room = Room_Create("The room is grey and mostly blank.\n");

	Room_AddRoomExit(room, "north", 3);
	Room_AddRoomExit(room, "east", 4);
	Room_AddRoomExit(room, "south", 6);
	Room_AddRoomExit(room, "west", 1);

	Room_PrintExitDesc(room, "You see four doors north, south, east, and west of you.\n");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room3_Build()
{
	Room* room = NULL;

	room = Room_Create("The door is cracked.");
	room = Room_Create("You see a woman with a bandage wrapped around her leg in a corner.\n");

	Room_AddRoomExit(room, "south", 2);

	Room_PrintExitDesc(room, "You see a door south of you.\n");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room4_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #4.\n");

	Room_AddRoomExit(room, "north", 7);
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

	room = Room_Create("Room #5.\n");

	Room_AddRoomExit(room, "north", 4);
	Room_AddRoomExit(room, "east", 6);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room6_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #6.\n");

	Room_AddRoomExit(room, "north", 2);
	Room_AddRoomExit(room, "east", 5);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room7_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #7.\n");

	Room_AddRoomExit(room, "south", 4);
	Room_AddRoomExit(room, "down", 13);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room8_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */
	room = Room_Create("A Dimly Lit Room with the Lights Flickering Repeatedly. In the Room's Corner, there is a Humanoid Figure Sitting Down.\n");
	/*Exit Description*/
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	Room_AddRoomExit(room, "west", 4);
	Room_AddRoomExit(room, "east", 9);
	Room_PrintExitDesc(room, "There is a Keycard Reader at the Door.");
	/* TODO BASIC: Add room exit shortcut for "n" */
	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
}

Room* Room9_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */
	room = Room_Create("There is an Elevator at the End of the Room.\n");
	/*Exit Description*/
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	Room_AddRoomExit(room, "west", 8);
	Room_AddRoomExit(room, "up", 14);
	Room_AddRoomExit(room, "down", 10);

	Room_PrintExitDesc(room, "There is a Keycard Reader at the Elevator.");
	/* TODO BASIC: Add room exit shortcut for "n" */
	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room10_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #10.\n");

	Room_AddRoomExit(room, "west", 11);
	Room_AddRoomExit(room, "up", 9);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room11_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #11.\n");

	Room_AddRoomExit(room, "west", 12);
	Room_AddRoomExit(room, "east", 10);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room12_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #12.\n");

	Room_AddRoomExit(room, "north", 13);
	Room_AddRoomExit(room, "east", 11);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room13_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #13.\n");

	Room_AddRoomExit(room, "up", 7);
	Room_AddRoomExit(room, "south", 12);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room14_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #14.\n");

	Room_AddRoomExit(room, "west", 15);
	Room_AddRoomExit(room, "down", 9);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room15_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #15.\n");

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

	room = Room_Create("Room #16.\n");

	Room_AddRoomExit(room, "east", 15);

	Room_PrintExitDesc(room, "Description of the Door");

	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	return room;
}

Room* Room17_Build()
{
	Room* room = NULL;

	room = Room_Create("Room #17.\n");

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
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

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