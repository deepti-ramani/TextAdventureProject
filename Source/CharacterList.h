#pragma once

typedef struct Character Character;

typedef struct CharacterList CharacterList;

CharacterList* CharacterList_Add(CharacterList* characterList, Character* character);

CharacterList* CharacterList_Remove(CharacterList* characterList, Character* character);

Character* CharacterList_Find(CharacterList* characterList, const char* characterName);