/*
Filename: Character.c
Author: Deepti Ramani
Last Edited: 3/11/2020
Brief: This file contains functions for creating/using characters
 */

#include "Character.h"

#define MAX_CHARACTER_NAME_LENGTH 16

#define MAX_CHARACTER_DESCRIPTION_LENGTH 256

#define MAX_CHARACTER_DIALOGUE_LENGTH 256

#define MIN_CONVERSATIONS_TO_UNLOCK 3

typedef struct Character
{
	char name[MAX_CHARACTER_NAME_LENGTH];
	char description[MAX_CHARACTER_DESCRIPTION_LENGTH];
	char openingDialogue[MAX_CHARACTER_DIALOGUE_LENGTH];
	char regularDialogue[MAX_CHARACTER_DIALOGUE_LENGTH];
	char hiddenDialogue[MAX_CHARACTER_DIALOGUE_LENGTH];
	bool hiddenDialogueUnlocked;
	int conversationCounter;
} Character;

/* create a character */
Character* Character_Create(const char* name, const char* description, const char* openingDialogue, const char* regularDialogue, const char* hiddenDialogue, bool hiddenDialogueUnlocked)
{
	Character* character;

	if (name == NULL)
	{
		return NULL;
	}

	character = (Character*)malloc(sizeof(Character));
	if (character == NULL)
	{
		return NULL;
	}

	strcpy_s(character->name, MAX_CHARACTER_NAME_LENGTH, name);
	if (description != NULL)
	{
		strcpy_s(character->description, MAX_CHARACTER_DESCRIPTION_LENGTH, description);
	}
	if (openingDialogue != NULL)
	{
		strcpy_s(character->openingDialogue, MAX_CHARACTER_DIALOGUE_LENGTH, openingDialogue);
	}
	if (regularDialogue != NULL)
	{
		strcpy_s(character->regularDialogue, MAX_CHARACTER_DIALOGUE_LENGTH, regularDialogue);
	}
	if (hiddenDialogue != NULL)
	{
		strcpy_s(character->hiddenDialogue, MAX_CHARACTER_DIALOGUE_LENGTH, hiddenDialogue);
	}
	character->hiddenDialogueUnlocked = hiddenDialogueUnlocked;
	character->conversationCounter = 0;

	return character;
}

/* return their name */
const char* Character_GetName(Character* character)
{
	if (character != NULL)
	{
		return character->name;
	}
	return NULL;
}

/* return their description */
const char* Character_GetDescription(Character* character)
{
	if (character != NULL)
	{
		return character->description;
	}
	return NULL;
}

/* return their opening dialogue */
const char* Character_GetOpeningDialogue(Character* character)
{
	if (character != NULL)
	{
		return character->openingDialogue;
	}
	return NULL;
}

/* return their normal dialogue */
const char* Character_GetRegularDialogue(Character* character)
{
	if (character != NULL)
	{
		return character->regularDialogue;
	}
	return NULL;
}

/* return the character's hidden dialogue */
const char* Character_GetHiddenDialogue(Character* character)
{
	if (character != NULL && character->conversationCounter > MIN_CONVERSATIONS_TO_UNLOCK)
	{
		return character->hiddenDialogue;
	}
	return NULL;
}

/* get how many times we've spoken to a character */
int Character_GetConversationCount(Character* character)
{
	if (character != NULL)
	{
		return character->conversationCounter;
	}
	return 0;
}

/* increment this when we talk to a character */
void Character_UpdateConversationCount(Character* character)
{
	character->conversationCounter++;
}