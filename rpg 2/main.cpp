#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "structs.h"
#include "combat.h"
#include "events.h"
#include "skills.h"
#include "history.h"


int main()
{
	struct hero_data hero;

	set_hero_data(&hero);

	fight(&hero);

	free(&hero);

	getchar();
	return 0;
}