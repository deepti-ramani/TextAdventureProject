#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the peek command -> check an adjacent room */
void HandlePeekCommand(CommandData* command, GameState* gameState, WorldData* worldData);