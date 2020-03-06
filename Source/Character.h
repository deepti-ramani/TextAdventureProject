#pragma once

#include "stdafx.h"

typedef struct GameState GameState;
typedef struct WorldData WorldData;

typedef struct Character Character;

Character* Character_Create(const char* name, const char* description, const char* openingDialogue, const char* regularDialogue, const char* hiddenDialogue, bool hiddenDialogueUnlocked);

const char* Character_GetName(Character* character);

const char* Character_GetDescription(Character* character);

const char* Character_GetOpeningDialogue(Character* character);

const char* Character_GetRegularDialogue(Character* character);

const char* Character_GetHiddenDialogue(Character* character);

int Character_GetConversationCount(Character* character);

void Character_UpdateConversationCount(Character* character);

void Character_Print(Character* character);