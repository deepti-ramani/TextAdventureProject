#pragma once

typedef struct Character Character;

typedef struct CharacterList CharacterList;

void CharacterList_Add(CharacterList** characterList, Character* character);

CharacterList* CharacterList_Remove(CharacterList* characterList, Character* character);

Character* CharacterList_Find(CharacterList* characterList, const char* characterName);

void CharacterList_Print(CharacterList* characterList);