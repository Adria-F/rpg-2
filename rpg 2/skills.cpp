#include "skills.h"

void skills() 
{
	
}

void spin_attack(monster_data* goblins, int hero_damage, int enemy_num, int* gold, int* exp, int* enemies_killed)//makes a little damage to all the goblins you encounter during the battle
{
	int damage;
	printf("You used spin attack and dealt:");
	for (int i = 0; i < enemy_num; i++)
	{
		damage = hero_damage / 2 - goblins[i].armor;
		if (damage < 0)
		{
			damage = 0;
		}
		goblins[i].hp -= damage;
		printf("\n%d damage to goblin #%d", damage, goblins[i].number);
		check_killed_goblin(goblins, i, gold, exp, enemies_killed);
	}
}

void stab_attack(monster_data* goblins, int objective, int hero_damage)//makes 50% more damage to the goblin you're actually attacking
{
	int damage = hero_damage - goblins[objective].armor;
	damage *= 1.5;
	if (damage < 0)
	{
		damage = 0;
	}
	printf("You used stab attack and dealt %d damage to goblin #%d", damage, goblins[objective].number);
	goblins[objective].hp -= damage;
}
