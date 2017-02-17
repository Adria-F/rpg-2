#ifndef __SKILLS__
#define __SKILLS__
#include <stdio.h>
#include "structs.h"

void skills();
void spin_attack(monster_data* goblins, int hero_damage, int enemy_num);
void stab_attack(monster_data* goblins, int objective, int hero_damage);

#endif
