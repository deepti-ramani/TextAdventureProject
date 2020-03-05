#include "CharacterList.h"
#include "Character.h"

typedef struct CharacterList
{
	Character* character;
	CharacterList* next;
} CharacterList;

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

	return CharacterList_IsInList(characterList, characterList->next);
}

CharacterList* CharacterList_Add(CharacterList* characterList, Character* character)
{
	CharacterList* NewCharacterList;
	if (characterList == NULL || CharacterList_IsInList(characterList, character))
	{
		return characterList;
	}

	NewCharacterList = (CharacterList*)malloc(sizeof(CharacterList));
	if (NewCharacterList == NULL)
	{
		return NULL;
	}

	NewCharacterList->character = character;
	NewCharacterList->next = characterList;
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

	if (Character_GetName(characterList->character) != NULL && strcomp(Character_GetName(characterList->character), characterName) == 0)
	{
		return characterList->character;
	}

	return CharacterList_Find(characterList->next, characterName);
}