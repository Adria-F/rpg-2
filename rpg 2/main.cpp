#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "structs.h"
#include "combat.h"
#include "events.h"
#include "skills.h"
#include "history.h"
#include "utility_functions.h"


int main()
{
	struct hero_data hero;

	FILE* game;
	fopen_s(&game, "game.txt", "a");
	fclose(game);

	check_and_load_game(game, &hero);


	//fight(&hero);

	getchar();
	return 0;
}