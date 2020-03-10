#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "look" command, which outputs a description of an item or the current room */
void HandleAskCommand(CommandData* command, GameState *gameState, WorldData *worldData);