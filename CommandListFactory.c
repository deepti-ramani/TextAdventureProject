/******************************************************************************
filename    CommandFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the CommandList factory, creating the commands used
in this game.

******************************************************************************/
#include "stdafx.h" /* NULL */
#include "CommandListFactory.h" /* Function declarations */
#include "CommandList.h" /* CommandList and CommandList_Add */
#include "CommandHandlerFunctions.h" /* all Handle___Command functions */


/* Create the command list with all commands used in this game.*/
CommandList* CreateCommandList()
{
	/* The command list to be returned, starting empty */
	CommandList* commandList = NULL;
	CommandList** cmdListPtr = &commandList;

	/*
	* NOTES: - Add the commands in the reverse of the order they'll be used, to reduce searching.
	*		 - Short alias commands do not show up in help.
	*/

	/* EXAMPLE: This is how you create the "help" command
				and add it to the list of commands for the game
	   NOTICE:  It uses a function called HandleHelpCommand, you can find
				additional command handler functions by looking here: CommandHandlerFunctions.h */
	CommandList_Add(cmdListPtr, "help", HandleHelpCommand, true);
	/* TODO BASIC: add support for a short alias "h" */
	CommandList_Add(cmdListPtr, "h", HandleHelpCommand, true);

	/* TODO REQUIRED: create the "quit" command
	TODO BASIC: add a short alias "q" */
	CommandList_Add(cmdListPtr, "quit", HandleQuitCommand, true);
	CommandList_Add(cmdListPtr, "q", HandleQuitCommand, true);

	/* TODO REQUIRED: create the "drop" command
	TODO BASIC: add a short alias "d" */
	CommandList_Add(cmdListPtr, "drop", HandleDropCommand, true);
	CommandList_Add(cmdListPtr, "d", HandleDropCommand, true);

	/* TODO REQUIRED: create the "take" command
	TODO BASIC: add a short alias "t" */
	CommandList_Add(cmdListPtr, "take", HandleTakeCommand, true);
	CommandList_Add(cmdListPtr, "t", HandleTakeCommand, true);

	/* TODO REQUIRED: create the "use" command
	TODO BASIC: add a short alias "u" */
	CommandList_Add(cmdListPtr, "use", HandleUseCommand, true);
	CommandList_Add(cmdListPtr, "u", HandleUseCommand, true);

	/* TODO REQUIRED: create the "look" command
	TODO BASIC: add a short alias "l" */
	CommandList_Add(cmdListPtr, "look", HandleLookCommand, true);
	CommandList_Add(cmdListPtr, "l", HandleLookCommand, true);

	/* TODO REQUIRED: create the "inventory" command
	TODO BASIC: add a short alias "i" */
	CommandList_Add(cmdListPtr, "inventory", HandleInventoryCommand, true);
	CommandList_Add(cmdListPtr, "i", HandleInventoryCommand, true);

	/* TODO REQUIRED: create the "go" command
	TODO BASIC: add a short alias "g" */
	CommandList_Add(cmdListPtr, "go", HandleGoCommand, true);
	CommandList_Add(cmdListPtr, "g", HandleGoCommand, true);

	/* TODO ADVANCED: create 3 aditional commands -
	this should require the creation of additional .c files to implement the command functions */
	/* ask a character in the game for information */
	CommandList_Add(cmdListPtr, "ask", HandleAskCommand, true);
	CommandList_Add(cmdListPtr, "a", HandleAskCommand, true);

	/* listen for sounds in the room you're in */
	CommandList_Add(cmdListPtr, "listen", HandleListenCommand, true);
	CommandList_Add(cmdListPtr, "n", HandleListenCommand, true);

	/* get a description of an adjacent room (not as detailed, but still useful)*/
	CommandList_Add(cmdListPtr, "peek", HandlePeekCommand, true);
	CommandList_Add(cmdListPtr, "p", HandlePeekCommand, true);
	/* return the newly created command list */
	return commandList;
}