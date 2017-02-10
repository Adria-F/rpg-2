#include <stdio.h>
#include <Windows.h>

int main()
{
	char per1[278] = " 	      ######\n 	    ##########\n 	   #############\n 	   #############\n 	    ##########\n 	      ######\n   	        ##\n    	       ####\n   	    ### ## ###\n    	 ###    ##    ###\n                ##\n                ##\n               #  #\n              #    #\n            ##      ##";
	char per2[278] = " 	      ######\n 	    ##########\n 	   #############\n 	   #############\n 	    ##########\n 	      ######\n   	        ##\n    	       ####\n   	    ### ## ###\n    	 ###    ##    ###\n                ##\n                ##\n               #  #\n               #  #\n             ##    ##";
	char per3[278] = " 	      ######\n 	    ##########\n 	   #############\n 	   #############\n 	    ##########\n 	      ######\n   	        ##\n    	       ####\n   	    ### ## ###\n    	 ###    ##    ###\n                ##\n                ##\n               #  #\n               #  #\n              #    #";
	char per4[278] = " 	      ######\n 	    ##########\n 	   #############\n 	   #############\n 	    ##########\n 	      ######\n   	        ##\n    	       ####\n   	    ### ## ###\n    	 ###    ##    ###\n                ##\n                ##\n                ##\n               #  #\n               #  #";
	char per5[278] = " 	      ######\n 	    ##########\n 	   #############\n 	   #############\n 	    ##########\n 	      ######\n   	        ##\n    	       ####\n   	    ### ## ###\n    	 ###    ##    ###\n                ##\n                ##\n                ##\n                ##\n                ##";
	//hola
	//Adrià - HOLA MUY BUENAS COMPIS!
	char* pers[5];
	pers[0] = per1;
	pers[1] = per2;
	pers[2] = per3;
	pers[3] = per4;
	pers[4] = per5;
	
	while (true)
	{
		for (int i = 0; i < 5; i++)
		{
			if (system("CLS")) system("clear");
			printf("%s", pers[i]);
			Sleep(500);
		}
		for (int i = 4; i > 0; i--)
		{
			if (system("CLS")) system("clear");
			printf("%s", pers[i]);
			Sleep(500);
		}
	}

	getchar();
	return 0;
}