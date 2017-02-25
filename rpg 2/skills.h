#ifndef __SKILLS__
#define __SKILLS__
#include <stdio.h>
#include "structs.h"
#include "combat.h"

void skills();
void spin_attack(monster_data* goblins, int hero_damage, int enemy_num, int* gold, int* exp, int* enemies_killed);
void stab_attack(monster_data* goblins, int objective, int hero_damage);

#endif
