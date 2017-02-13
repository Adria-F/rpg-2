#include "utility_functions.h"

char* get_string()
{
	char* charP = NULL;
	char temp = NULL;
	int i;
	for (i = 0; temp != '\n'; i++)
	{
		char* string = (char*)malloc((i + 2)*sizeof(char));
		if (charP != NULL)
		{
			for (int j = 0; j < i; j++)
			{
				string[j] = charP[j];
			}
			free(charP);
		}
		scanf_s("%c", &temp);
		string[i] = temp;
		charP = string;
	}
	charP[i - 1] = '\0';

	fflush(stdin);
	return charP;
}

int char_to_int(char str[])
{
	int num;
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
		hero[0].name = get_string();
	}
	else
	{
		fpos_t pos;
		fopen_s(&game, "game.txt", "r");
		char text[30];
		fgets(text, 30, game);
		fgetpos(game, &pos);
		text[pos - 2] = '\0';

		printf("Would you like to load the game of %s? (Y/N): ", text);
		char choice;
		scanf_s("%c", &choice);

		if (choice == 'N')
		{
			printf("Enter the name of our hero: ");
			hero[0].name = get_string();
		}
		else if (choice == 'Y')
		{
			hero[0].name = text;
			char saved_hp[3];
			fgets(saved_hp, 4, game);
			hero[0].hp = char_to_int(saved_hp);
			char saved_attack[3];
			fgets(saved_attack, 4, game);
			hero[0].attack = char_to_int(saved_attck);
			char saved_armor[3];
			fgets(saved_armor, 4, game);
			hero[0].armor = char_to_int(saved_armor);
			char saved_lvl[3];
			fgets(saved_lvl, 4, game);
			hero[0].lvl = char_to_int(saved_lvl);
			char saved_exp[3];
			fgets(saved_exp, 4, game);
			hero[0].exp = char_to_int(saved_exp);
			char saved_coins[3];
			fgets(saved_coins, 4, game);
			hero[0].coins = char_to_int(saved_coins);
		}
	}
}