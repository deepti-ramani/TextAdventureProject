/******************************************************************************
filename    Room.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Room interface, which is used to manage rooms in the game.

******************************************************************************/
#include "stdafx.h" /* NULL, malloc/free, printf, strcpy_s */
#include "Room.h" /* Function declarations */
#include "RoomExit.h" /* RoomExit_Add, RoomExit_Free, RoomExit_Print */
#include "ItemList.h" /* ItemList_Free, ItemList_Print */
#include "CharacterList.h"


/* The maximum length of a room description string */
#define MAX_ROOM_DESCRIPTION_LENGTH 1000


/* A room in the game */
typedef struct Room
{
	char roomdialog[MAX_ROOM_DESCRIPTION_LENGTH];
	char exitdesc[MAX_ROOM_DESCRIPTION_LENGTH];
	char description[MAX_ROOM_DESCRIPTION_LENGTH]; /* The description of the room */
	ItemList* itemList; /* A list of items in the room */
	RoomExit* roomExitHead; /* A list of exits from the room */
	CharacterList* characterList;
	const char* listenDescription;	/* can't get this from "look", only from "listen" */
	const char* peekDescription;
} Room;


/* Helper: Print the list of items in a room */
void PrintRoomItems(ItemList* itemList);

/* Helper: Print the list of exits from a room */
void PrintRoomExits(RoomExit* roomExitList);


/* Create an Room object with the provided data */
Room* Room_Create(const char* description)
{
	Room* room; /* the new room object */

	/* allocate the memory for the new object */
	room = (Room*)malloc(sizeof(Room));
	if (room == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* copy the data from the parameters to the new object */
	Room_SetDescription(room, description);

	/* initialize the new room's list pointers to NULL */
	room->itemList = NULL;
	room->characterList = NULL;
	room->roomExitHead = NULL;
	room->listenDescription = NULL;
	room->peekDescription = NULL;

	/* return the new Room object */
	return room;
}


/* Free the memory associated with the given room */
void Room_Free(Room** roomPtr)
{
	/* safety check on the parameters */
	if ((roomPtr == NULL) || (*roomPtr == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* free the item list in the room */
	ItemList_Free(&(*roomPtr)->itemList);

	/* free the room-exit list in the room */
	RoomExit_Free(&(*roomPtr)->roomExitHead);

	/* free the room object iteself */
	free(*roomPtr);

	/* clear the provided pointer*/
	*roomPtr = NULL;
}


/* Get a reference to the item list in the given room */
ItemList** Room_GetItemList(Room* room)
{
	/* return the data if the parameter is not NULL, otherwise return NULL */
	return (room != NULL) ? &(room->itemList) : NULL;
}

/* get a reference to the room's character list */
CharacterList** Room_GetCharacterList(Room* room)
{
	if (room != NULL)
	{
		return &(room->characterList);
	}
	return NULL;
}

/* Get the room index in the direction specified from the given room */
bool Room_GetNextRoomIndex(Room* room, const char* direction, int* outNextRoomIndex)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return false; /* return false if the parameters are invalid, since we can't perform the search */
	}

	return RoomExit_Find(room->roomExitHead, direction, outNextRoomIndex);
}


/* Add an exit to the given room */
void Room_AddRoomExit(Room* room, const char* direction, int nextRoomIndex)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* update the room's exit list with the new head */
	room->roomExitHead = RoomExit_Add(room->roomExitHead, direction, nextRoomIndex, true);
}


/* Add an exit to the given room, but don't display it in any printed help */
void Room_AddRoomExitShortcut(Room* room, const char* direction, int nextRoomIndex)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* update the room's exit list with the new head */
	room->roomExitHead = RoomExit_Add(room->roomExitHead, direction, nextRoomIndex, false);
}


/* Replace the description on the given room */
void Room_SetDescription(Room* room, const char* description)
{
	/* safety check on the parameters */
	if ((room == NULL) || (description == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* copy the parameter data into the given object */
	strcpy_s(room->description, MAX_ROOM_DESCRIPTION_LENGTH, description);
}

void Room_SetPeekDescription(Room* room, const char* peekDescription)
{
	room->peekDescription = peekDescription;
}

const char* Room_GetPeekDescription(Room* room)
{
	if (room != NULL && room->peekDescription != NULL)
	{
		return room->peekDescription;
	}
	return NULL;
}

/* add a listen description */
void Room_SetListenDescription(Room* room, const char* listenDescription)
{
	room->listenDescription = listenDescription;
}

/* get listen description of the room (if it exists) */
const char* Room_GetListenDescription(Room* room)
{
	if (room != NULL && room->listenDescription != NULL)
	{
		return room->listenDescription;
	}
	return NULL;
}

void Room_PrintExitDesc(Room* room, const char* doordesc)
{
	if ((room == NULL) || (doordesc == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}
	/* copy the data from the parameters to the new object */
	strcpy_s(room->exitdesc, MAX_ROOM_DESCRIPTION_LENGTH, doordesc);
	/* return the new Room object */
}

void Room_PrintDialog(Room* room, const char* dialog)
{
	if ((room == NULL) || (dialog == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}
	/* copy the data from the parameters to the new object */
	strcpy_s(room->roomdialog, MAX_ROOM_DESCRIPTION_LENGTH, dialog);
	/* return the new Room object */
}


/* Print the description of the given room to standard output */
void Room_Print(Room* room)
{
	/* safety check on the parameters */
	if (room == NULL)
	{
		return;  /* take no action if the parameters are invalid */
	}

	/* print the room description */
	printf(room->description);
	printf(room->roomdialog);
	/* print the set of items in the room */
	PrintRoomItems(room->itemList);

	/* print the set of exits in the given room */
	PrintRoomExits(room->roomExitHead);

	printf(room->exitdesc);
	printf("\n");
}


/* Helper: Print the list of items in a room */
void PrintRoomItems(ItemList* itemList)
{
	/* safety check on the parameters */
	if (itemList == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* print a header for the list */
	printf("In this room, you see: ");

	/* print the list itself */
	ItemList_Print(itemList);

	printf(".\n");
}


/* Helper: Print the list of exits from a room */
void PrintRoomExits(RoomExit* roomExitList)
{
	/* safety check on the parameters */
	if (roomExitList == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* print a header for the list */
	printf("Exits are: ");

	/* print the list itself */
	RoomExit_Print(roomExitList);

	printf(".\n");
}

/* Helper: Print the list of characters in a room */
void PrintRoomCharacters(CharacterList* characterList)
{
	printf("In this room, you see: \n");
	CharacterList_Print(characterList);
	printf(".\n");
}