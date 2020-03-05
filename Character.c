#pragma once
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

void Character_Free(Character** characterPtr)
{
	if (characterPtr == NULL | *characterPtr == NULL)
	{
		return;
	}

	free(*characterPtr);

	*characterPtr = NULL;
}

const char* Character_GetName(Character* character)
{
	if (character != NULL)
	{
		return character->name;
	}
	return NULL;
}

const char* Character_GetDescription(Character* character)
{
	if (character != NULL)
	{
		return character->description;
	}
	return NULL;
}

const char* Character_GetOpeningDialogue(Character* character)
{
	if (character != NULL)
	{
		return character->openingDialogue;
	}
	return NULL;
}

const char* Character_GetRegularDialogue(Character* character)
{
	if (character != NULL)
	{
		return character->regularDialogue;
	}
	return NULL;
}

const char* Character_GetHiddenDialogue(Character* character)
{
	if (character != NULL)
	{
		return character->hiddenDialogue;
	}
	return NULL;
}

void UpdateConversationCount(Character* character)
{
	character->conversationCounter++;
}

void Character_Print(Character* character)
{
	if (character == NULL)
	{
		return;
	}
	if (character->description != NULL)
	{
		printf("%s.\n", character->description);
		return;
	}
}