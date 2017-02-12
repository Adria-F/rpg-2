#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "structs.h"
#include "combat.h"
#include "events.h"
#include "skills.h"
#include "text_function.h"


int main()
{
	struct hero_data* hero = (struct hero_data*)malloc(sizeof(struct hero_data));
	set_hero_data(hero);

	fight(hero);

	free(hero);

	getchar();
	return 0;
}