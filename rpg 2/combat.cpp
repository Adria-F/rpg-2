#include "combat.h"

void set_hero_data(hero_data* hero)
{
	printf("Enter the name of our hero (max. 10 characters): ");
	scanf_s("%s", &hero[0].name, 10);

	printf("Enter stats for %s <HP, Attack, Armor>\n(Recomended: 500 80 15): ", hero[0].name);
	scanf_s("%d", &hero[0].hp);
	scanf_s("%d", &hero[0].attack);
	scanf_s("%d", &hero[0].armor);
	hero[0].coins = 0;
	hero[0].exp = 0;
	hero[0].lvl = 1;

	fflush(stdin);
}

void set_monster_data(monster_data* goblins, int enemy_num)
{
	for (int i = 0; i < enemy_num; i++)
	{
		goblins[i].hp = rand() % 76 + 75; //random number between 75 and 150
		goblins[i].attack = 35;
		goblins[i].armor = rand() % 10 + 1;
		goblins[i].coins = rand() % 16 + 5; //random number between 5 and 20
		goblins[i].exp = rand() % 31 + 20; //random number between 20 and 50
		goblins[i].number = i + 1;
		goblins[i].type_name = "goblin";
	}
}

void set_chief_data(monster_data* goblins)
{
	goblins[0].hp = rand() % 151 + 100; //random number between 100 and 250
	goblins[0].attack = 75;
	goblins[0].armor = rand() % 16 + 10; //random number between 10 and 25
	goblins[0].coins = rand() % 31 + 50; //random number between 50 and 80
	goblins[0].exp = rand() % 51 + 100; //random number between 100 and 150
	goblins[0].number = 1;
	goblins[0].type_name = "boss";
}

void check_and_do_lvl_up(hero_data* hero)
{
	int max_xp_per_level = (100 * hero[0].lvl);
	if (hero[0].exp >= max_xp_per_level)
	{
		int gain_hp = 8 + (2 * hero[0].lvl);
		int gain_attack = 5 * hero[0].lvl;
		int gain_armor = 1;
		hero[0].exp -= max_xp_per_level;
		hero[0].lvl += 1;
		printf("\nYou leveled up!. Now you are level %d.", hero[0].lvl);
		printf("\nHP + %d", gain_hp);
		printf("\nAttack + %d", gain_attack);
		printf("\nArmor + %d", gain_armor);
		hero[0].hp += gain_hp;
		hero[0].attack += gain_attack;
		hero[0].armor += gain_armor;
	}
}

void fight(hero_data* hero)
{
#define hero_hp hero[0].hp
#define hero_attack hero[0].attack
#define hero_armor hero[0].armor
#define hero_coins hero[0].coins
#define hero_xp hero[0].exp
#define hero_lvl hero[0].lvl

	int wave = 1;
	int coins_received = 0;
	int xp_received = 0;
	int total_xp = 0;
	while (hero_hp > 0)
	{
		srand(time(NULL));
		int enemies_killed = 0;
		int chief = rand() % 100;
		int enemy_num;
		if (chief < 10) //10% probability to find a boss
		{
			enemy_num = 1;
		}
		else
		{
			enemy_num = rand() % 5 + 1; //number of goblins between 1 and 6
		}
		struct monster_data* goblins = (struct monster_data*)malloc(enemy_num * sizeof(struct monster_data));
		if (chief < 10)
		{
			set_chief_data(goblins);
			printf("\nYou fight against a boss!");
		}
		else
		{
			set_monster_data(goblins, enemy_num);
			printf("\nYou fight against %d goblins", enemy_num);
		}

		while (enemies_killed != enemy_num && hero_hp > 0)
		{
			printf("\nYou have %d HP left and are lvl %d.", hero_hp, hero_lvl);
			int enemy_to_attack = rand() % enemy_num; //choose an enemy to attack between the possible number of enemies
			while (goblins[enemy_to_attack].hp <= 0) //if chosen enemy is dead, loop till it's not
			{
				enemy_to_attack = rand() % enemy_num;
			}
			int hero_damage = hero_attack;
			hero_damage -= goblins[enemy_to_attack].armor;
			if (hero_damage < 0) //make sure that hero_damage is not negative
			{
				hero_damage = 0;
			}
			printf("	You hit the %s #%d for %d!", goblins[enemy_to_attack].type_name, goblins[enemy_to_attack].number, hero_damage);
			goblins[enemy_to_attack].hp -= hero_damage;
			if (goblins[enemy_to_attack].hp <= 0)
			{
				printf("\nYou killed %s #%d!", goblins[enemy_to_attack].type_name, goblins[enemy_to_attack].number);
				coins_received += goblins[enemy_to_attack].coins;
				xp_received += goblins[enemy_to_attack].exp;
				enemies_killed++;
			}
			for (int i = 0; i < enemy_num; i++)
			{
				if (goblins[i].hp > 0)
				{
					int goblin_damage = goblins[i].attack;
					goblin_damage -= hero_armor;
					if (goblin_damage < 0) //make sure that goblin_damage is not negative
					{
						goblin_damage = 0;
					}
					printf("\n%s #%d hits you for %d", goblins[enemy_to_attack].type_name, goblins[i].number, goblin_damage);
					hero_hp -= goblin_damage;
				}
				if (hero_hp <= 0) //if a goblin kills you, the following ones shouldn't attack you. So it breaks.
				{
					break;
				}
			}
			getchar();
		}
		if (hero_hp > 0)
		{
			printf("\nYou completed wave '%d' and received %d coins and %d xp.", wave, coins_received, xp_received);
			hero_coins += coins_received; //add coins received in a wave into the total counter
			coins_received = 0;
			hero_xp += xp_received; //add xp received in a wave into the total counter
			xp_received = 0;
			total_xp += hero_xp; //another xp variable so it does not reset when hero level up
			check_and_do_lvl_up(hero);
			printf("\nYour current hp is: %d and you have %d coins and %d/%d xp.\n", hero_hp, hero_coins, hero_xp, (100 * hero_lvl));
			getchar();
			printf("You prepare for another fight...\n");
			getchar();
			wave++;
		}
		free(goblins);
	}
	printf("\n\nYou have died at wave: %d.\n", wave);
	hero_coins += coins_received;
	hero_xp += xp_received;
	printf("During your battles you got %d coins and %d xp.\n", hero_coins, total_xp);
}