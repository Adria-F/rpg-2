#ifndef __STRUCTS__
#define __STRUCTS__

struct hero_data
{
	int hp = 500;
	int attack = 80;
	int armor = 10;
	int lvl = 1;
	int exp = 0;
	int coins = 0;
	char name[30];
};

struct monster_data
{
	int hp;
	int coins;
	int attack;
	int armor;
	int exp;
	int number;
	char* type_name;
};

#endif