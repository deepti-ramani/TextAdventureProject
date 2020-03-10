#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "listen" command */
void HandleListenCommand(CommandData* command, GameState *gameState, WorldData *worldData);