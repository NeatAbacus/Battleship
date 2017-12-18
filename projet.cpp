#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

int s2i(string s)
{
	int done = 0;
	for(int i=0;i<s.size();i++)
	{
		done *= 10;
		done += (int)s[i] - 48;
	}
	return done;
}

void set(char V, int H, int A[10][10])
{
	if(A[(int)V - 65][H] == 1)
	A[(int)V - 65][H] = -1;
	else
	A[(int)V - 65][H] = 2;
}

void fire(string s, int board[10][10])
{
	char V;
	int H;
	V = s[0];
	H = s2i(s.substr(1))-1;
	set(V, H, board);
}

bool good(string c)
{
	if(c.size() > 3) return 0;
	if(c.size() <= 1) return 0;
	return 1;
}

bool putboat(int X, int Y, int rot, int size, int board[10][10])
{
	if(rot)
	{//On dessine le bateau en descendant.
		for(int i=0;i<size;i++)
		{
			if(board[Y+i][X]) return 0;
		}
		for(int i=0;i<size;i++)
		{
			board[Y+i][X] = 1;
		}

	}
	else
	{//On dessine le bateau par la droite.
		for(int i=0;i<size;i++)
		{
			if(board[Y][X+i]) return 0;
		}
		for(int i=0;i<size;i++)
		{
			board[Y][X+i] = 1;
		}
	}
	return 1;
}

void randboat(int board[10][10])
{
	//Bx est un tableau des valeur pour les positions de bateau.
	//Le tableau est en ordre de grandeur des bateau. (2,3,3,4,5)
	//les valeurs sont donc accorde de facon a ne pas sortir de
	//la board.
	int B[5] = {0};
	B[0] = (rand()%9);
	B[1] = (rand()%8);
	B[2] = (rand()%8);
	B[3] = (rand()%7);
	B[4] = (rand()%6);

	//La taille des bateau a dessiner.
	int S[5] = {2, 3, 3, 4, 5};

	//On loop sur chaque bateau pour les dessiner dans la board.
	for(int i=0; i<5; i++)
	{
		int rot = rand()%2;
		if(rot)
		{//si on rotate le jeu alors on donne le nombre restreint a y.
			while(!putboat((rand()%10), B[i], rot, S[i], board)){continue;};
		}
		else
		{//si non on le donne a x.
			while(!putboat(B[i], (rand()%10), rot, S[i], board)){continue;};
		}
	}
}

void showascii()
{
	for(int i=0;i<200;i++)
	{
		printf("%c, %d\n", i, i);
	}
}

void showboard(int board[10][10])
{
printf("# 1 2 3 4 5 6 7 8 9 10\n");
for(int j=0;j<10;j++)
{
	printf("%c ", 65+j);
	for(int i=0; i<10; i++)
	{
		printf("%d ",board[j][i]);
	}
	printf("\n");
}
}

int main()
{
	int board[10][10] = {{0}};
	string comm;
	board[1][2] = 1;
	randboat(board);
	showboard(board);
	/*while(true)
	{
		cin>>comm;
		if(comm == "stop") break;
		if(good(comm)) fire(comm, board);
		showboard(board);
	}*/
	return 0;
}
