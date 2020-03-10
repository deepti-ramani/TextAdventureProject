#include "CharacterList.h"
#include "Character.h"
#include "stdafx.h"

typedef struct CharacterList
{
	Character* character;
	CharacterList* next;
} CharacterList;

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