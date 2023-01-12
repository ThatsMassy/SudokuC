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
long sol[9][9];
int tt[9][9][3];
int x,y,z,w;
int co=0, ri=0, sq;
int appoggia, prendi=0;
int orsi=0;
int mettid(int sotto, int sopra);
int a,b,c,d,e,f,g,h,i,j,k;
int r,n=0,m=1,l=2,fag1,fag2;
void stampa();
void stampa1();
void matrici();
void smat(int dal,int al);
void numeri();
void tratto();
void paguri();
void tratto1();
void tratto2();
void trattone();
void porcata();
void cornice();
void interno(int passa);
void interno1(int passa);
void inserimento();
void ipertratto();
int main()
{
	system("COLOR F0");
	numeri();
	printf("\n\n");
	stampa();
	printf("\n\n");
	stampa1();
	//inserimento();
	printf("\n");
	matrici();
	printf("\n");
	smat(0,3);
	printf("\n");
	smat(3,6);
	printf("\n");
	smat(6,9);
	printf("\n");
	paguri();
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
			printf(" %3d|",sm1[x][z]);
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
			printf("%9u|",sol[x][z]);
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
void matrici()
{
	printf("\n  Matrici\n\n");
	printf("    1		  	  2			3");	//da sistemare con ciclo for
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
	cornice();
	for(r=0;r<9;r++)
	{
		for(n=fag1;n<fag2;n++)
		{
			printf("%3d|",r+1);
			interno(n);
		}
		printf("\n");
		ipertratto();
	}
	printf("\n");		
}
void paguri()
{
	printf("\n");
	porcata();
	printf("\n");
	cornice();
	for(r=0;r<9;r++)
	{
		for(n=0;n<3;n++)
		{
			printf("%3d|",r+1);
			for(c=0;c<9;c++)
			{
				interno1(n);
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
		for(n=0;n<9;n++)
		{
			for(c=0;c<9;c++)
			{
				mat[r][c][n]=n+1;
			}
		}
	}
}
void inserimento()
{
	printf("\n riga: (1-9) ");
	scanf("%d",co);
	printf("\n colonna: (1-9) ");
	scanf("%d",ri);
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
void interno(int passa)
{
	int pippo;
	pippo = mat[r][c][passa];
	for(c=0;c<9;c++)
	{
		if(pippo == mat[r][c][passa])
		{
			printf(" |");
		}
		else
		printf("%d|",mat[r][c][passa]);
	}
}
void interno1(int passa)
{
	int pippo;
	pippo = tt[r][c][passa];
	for(c=0;c<9;c++)
	{
		if(pippo == tt[r][c][passa])
		{
			printf(" |",tt[r][c][passa]);
		}
		printf("%d|",tt[r][c][passa]);
	}
}
void ipertratto()
{
	trattone();
	trattone();
	trattone();
	printf("\n");
}
