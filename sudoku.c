#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
void selector(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}
int mat[9][9][9];
int sm1[9][9];
long sol[9][9],fattore;
int tt[9][9][3];
int met[9][9];
int x,y,z,w;
int co=0, ri=0, sq;
int appoggia, prendi=0;
int orsi=0;
int mettid(int sotto, int sopra);
int a,b,c,d,v,e,f,t,g,h,i,j,k;
int r,n=0,m=1,l=2,fag1,fag2,fag3,pluto;
void stampa();
void stampa1();
void matrici();
void smat(int dal,int al);
void numeri();
void tratto2();
void tratto();
void tratto1();
void componi();
void trattone();
void porcata();
void cornice();
void se0(int passa);
void inserimento();
void ipertratto();
int main()
{
	system("COLOR F0");
	numeri();
	printf("\n\n");
	componi();
	stampa();
	printf("\n\n");
	stampa1();
	//inserimento();
	printf("\n");
	fag3=1;
	smat(0,3);
	printf("\n");
	smat(3,6);
	printf("\n");
	smat(6,9);
	printf("\n");
	fag3=2;
	printf("\n");
	porcata();
	printf("\n");
	smat(0,3);
	system("PAUSE");
}
int mettid(int sotto, int sopra)
{
	int pippo;
	do
	{
		printf("(%d - %d): ",sotto,sopra);
		scanf("&d",&pippo);
	}
	while(pippo<sotto || pippo>sopra);
	return pippo;
}
void stampa()
{
	system("CLS");
	printf("\n PROGRAMMA SUDOKU\n\n");
	printf("   |");
	for(x=0;x<9;x++)
	{
		printf("%4d|",x+1);
	}
	for(x=0;x<9;x++)
	{
		tratto();
		printf("\n%3d|",x+1);
		for(z=0;z<9;z++)
		{
			if (sm1[x][z]>0)
			{
				printf(" %3d|",sm1[x][z]);
			}
			else
			{
				printf("    |");
			}
		}
	}
	tratto();
}
void stampa1()
{
	printf(" |");
	for(x=0;x<9;x++)
	{
		printf("%9u|",x+1);
	}
	for(x=0;x<9;x++)
	{
		tratto2();
		printf("\n%d|",x+1);
		for(z=0;z<9;z++)
		{
			if(sol[x][z]>0)
			{
				printf("%9u|",sol[x][z]);
			}
			else
			{
				printf("         |");
			}
		}
	}
	tratto2();
}
void tratto()
{
	printf("\n+--+");
	for(w=0;w<9;w++)
	{
		printf("----+");
	}
}
void tratto1()
{
	printf("\n+==+");
	for(w=0;w<9;w++)
	{
		printf("====+");
	}
}
void tratto2()
{
	printf("\n-+");
	for(w=0;w<9;w++)
	{
		printf("---------+");
	}
}
void trattone()
{
	printf("+--+");
	for(w=0;w<9;w++)
	{
		printf("-+");
	}
}
void smat(int fag1,int fag2)
{
	printf("\n");
	cornice();
	for(r=0;r<9;r++)
	{
		for(n=fag1;n<fag2;n++)
		{
			printf("%3d|",r+1);
			for(c=0;c<9;c++)
			{
				if (fag3==1)
				{
					pluto = mat[r][c][n];
				}
				else
				{
					pluto = tt[r][c][n];
				}				
				se0(pluto);
			}
		}
		printf("\n");
		ipertratto();
	}
	printf("\n");		
}
void porcata()
{
	printf("   cifre per riga        cifre per colonna     cifre per riquadro"); //da sistemare con "%d"
}
void numeri()
{
	for(r=0;r<9;r++)
	{
		for(c=0;c<9;c++)
		{
			for(n=0;n<9;n++)
			{
				mat[r][c][n]=n+1;
			}
		}
	}
}
void inserimento()
{
	printf("\n seleziona riga: (1-9) ");
	scanf("%d",co);
	system("cls");
	printf("\n seleziona colonna: (1-9) ");
	scanf("%d",ri);
	system("cls");
	printf("\n seleziona valore: (1-9) ");
	scanf("%d",v);
	met[co][ri]=v;
}
void cornice()
{
	printf("   ");
	for(x=0;x<3;x++)
	{
		for(m=0;m<9;m++)
		{
			printf("|%d",m+1);
		}
		printf("|   ");
	}
	printf("\n");
	ipertratto();
}
void se0(int passa)
{
	if(passa == 0)
	{
		printf(" |");
	}
	else
	{
		printf("%d|",passa);			
	}
}
void ipertratto()
{
	trattone();
	trattone();
	trattone();
	printf("\n");
}
void componi()
{
	long fattore;
	for(x=0;x<9;x++)
    {
		for(y=0;y<9;y++)
    	{
			sol[x][y] = 0;
    		fattore=100000000;
			for(z=0;z<9;z++)
			{
				sol[x][y]=(long)sol[x][y]+(mat[x][y][z]*fattore);
				fattore=fattore/10;
			}
		}
    }
}
