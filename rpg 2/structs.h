#ifndef __STRUCTS__
#define __STRUCTS__

struct hero_data
{
	int exp;
	int coins;
	int attack;
	int armor;
	int hp;
	int lvl;
	char name[];
}hero;

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