#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the ask command */
void HandleAskCommand(CommandData* command, GameState *gameState, WorldData *worldData);