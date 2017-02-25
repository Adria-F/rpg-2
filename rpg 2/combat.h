#ifndef __COMBAT__
#define __COMBAT__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
#include "skills.h"

void fight(hero_data* hero);
void check_killed_goblin(monster_data* goblins, int objective, int* gold, int* exp, int* enemies_killed);

#endif