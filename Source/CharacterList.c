/*
Filename: CharacterList.c
Author: Deepti Ramani
Last Edited: 3/11/2020
Brief: This file contains functions for using/creating a list of characters
 */

#include "CharacterList.h"
#include "Character.h"
#include "stdafx.h"

typedef struct CharacterList
{
	Character* character;
	CharacterList* next;
} CharacterList;

/* get number of characters in a list */
unsigned int CharacterList_GetCount(CharacterList* characterList)
{
	/* make sure the list isn't null */
	if (characterList == NULL)
	{
		return 0;
	}

	/* return the number of nodes in the list (1 + number of recursive calls) */
	return 1 + CharacterList_GetCount(characterList->next);
}

/* check if a character is in the list */
bool CharacterList_IsInList(CharacterList* characterList, Character* character)
{
	if (characterList == NULL || character == NULL)
	{
		return false;
	}

	if (characterList->character == character)
	{
		return true;
	}

	return CharacterList_IsInList(characterList->next, character);
}

/* add a character to the list */
void CharacterList_Add(CharacterList** characterList, Character* character)
{
	CharacterList* NewCharacterList;
	if (characterList == NULL || CharacterList_IsInList(*characterList, character))
	{
		return;
	}

	NewCharacterList = (CharacterList*)malloc(sizeof(CharacterList));
	if (NewCharacterList == NULL)
	{
		return;
	}

	NewCharacterList->character = character;
	NewCharacterList->next = *characterList;

	*characterList = NewCharacterList;
}

/* remove a character from the list */
CharacterList* CharacterList_Remove(CharacterList* characterList, Character* character)
{
	CharacterList* result;

	if (characterList == NULL || character == NULL)
	{
		return characterList;
	}

	if (characterList->character == character)
	{
		result = characterList->next;
		free(characterList);
	}
	else
	{
		result = characterList;
		characterList->next = CharacterList_Remove(characterList->next, character);
	}

	return result;
}

/* get the first character in the list*/
Character* CharacterList_GetCurrent(CharacterList* characterList)
{
	if (characterList->character != NULL)
	{
		return characterList->character;
	}
	return NULL;
}

/* find a character in the list by name*/
Character* CharacterList_Find(CharacterList* characterList, const char* characterName)
{
	if (characterList == NULL || characterName == NULL)
	{
		return NULL;
	}

	if (Character_GetName(characterList->character) != NULL && strcmp(Character_GetName(characterList->character), characterName) == 0)
	{
		return characterList->character;
	}

	return CharacterList_Find(characterList->next, characterName);
}

/* print out the characters  in a list (name + description) */
void CharacterList_Print(CharacterList* characterList)
{
	unsigned int count = CharacterList_GetCount(characterList);
	unsigned int listIndex = 0;
	const char* characterDescription;
	const char* characterName;

	CharacterList* printedList = characterList;

	while (printedList != NULL)
	{
		characterName = Character_GetName(printedList->character);
		characterDescription = Character_GetDescription(printedList->character);
		if (characterDescription != NULL)
		{
			printf("%s, %s", characterName, characterDescription);		
			
			/* print punctuation */
			if (listIndex > 0 && listIndex < count - 1)
			{
				/* print a comma for 3 and more characters */
				if (count > 2)
				{
					printf(", \n");
				}
				/* print an and for 2 characters */
				else
				{
					printf(" and \n");
				}
			}

			/* print an and between the last and second-to-last characters */
			else if (listIndex == count - 1)
			{
				printf(", and \n");
			}
		}
		listIndex++;
		printedList = printedList->next;
	}
}