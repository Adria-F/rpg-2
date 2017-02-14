#include "utility_functions.h"

int char_to_int(char str[])
{
	int num = 0;
	num += (str[2] - 48);
	num += (str[1] - 48) * 10;
	num += (str[0] - 48) * 100;

	return num;
}

void save_game()
{

}

void check_and_load_game(FILE* game, hero_data* hero)
{
	fopen_s(&game, "game.txt", "a");
	long text_size;
	fseek(game, 0, SEEK_END);
	text_size = ftell(game);
	fclose(game);

	if (text_size == 0)
	{
		printf("Enter the name of our hero: ");
		scanf_s("%s", &hero[0].name, 30);
	}
	else
	{
		fpos_t pos;
		fopen_s(&game, "game.txt", "r");
		fgets(hero[0].name, 30, game);
		fgetpos(game, &pos);
		hero[0].name[pos - 2] = '\0';

		printf("Would you like to load the game of %s? (y/n): ", hero[0].name);
		char choice;
		scanf_s("%c", &choice);

		if (choice == 'n')
		{
			printf("Enter the name of our hero: ");
			scanf_s("%s", &hero[0].name, 30);
		}
		else if (choice == 'y')
		{
			char saved_hp[4];
			fgets(saved_hp, 4, game);
			hero[0].hp = char_to_int(saved_hp);
			fgetc(game);
			char saved_attack[4];
			fgets(saved_attack, 4, game);
			hero[0].attack = char_to_int(saved_attack);
			fgetc(game);
			char saved_armor[4];
			fgets(saved_armor, 4, game);
			hero[0].armor = char_to_int(saved_armor);
			fgetc(game);
			char saved_lvl[4];
			fgets(saved_lvl, 4, game);
			hero[0].lvl = char_to_int(saved_lvl);
			fgetc(game);
			char saved_exp[4];
			fgets(saved_exp, 4, game);
			hero[0].exp = char_to_int(saved_exp);
			fgetc(game);
			char saved_coins[4];
			fgets(saved_coins, 4, game);
			hero[0].coins = char_to_int(saved_coins);
			printf("Game Loaded.");
			fflush(stdin);
			getchar();
		}
		fclose(game);
	}
}