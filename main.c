#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define SIZE
#ifdef _WIN32


#endif


//Initialisation
char tab[25][60];
void menu(){
    printf("                         ________________________________________________________         \n");
    printf("                        |                                                        |        \n");
    printf("                        |                                                        |        \n");
    printf("                        |              JEU DE LA LIGNE INVISIBLE                 |        \n");
    printf("                        |                                                        |        \n");
    printf("                        |                                                        |        \n");
    printf("                        |                                                        |        \n");
    printf("                        |________________________________________________________|        \n");

    printf("    \n");
    printf("    \n");
    printf("    \n");
    printf("    \n");
    printf("    \n");

    printf("                                          INSTRUCTIONS DU JEU :                                    \n");
    printf("    \n");
    printf("    \n");
    printf("            Au moins deux joueurs s'affrontent sur cette ar%cne .\n", 138);
    printf("            Pour vous d%cplacer, utilisez les touches suivantes :  - z pour ce d%cplacer vers le haut.\n", 130,130);
    printf("                                                                  - q pour ce d%cplacer vers la gauche. \n", 130);
    printf("                                                                  - s pour ce d%cplacer vers le bas. \n", 130);
    printf("                                                                  - d pour ce d%cplacer vers la droite. \n", 130);
    printf("          A chaque fois que le joueur ce d%cplace, la case sous laquelle il se trouve disparait.\n", 130);
    printf("          Ainsi votre but est de ne pas tomber et surtout de faire en sorte de survivre par tous les moyens. \n");

    printf("\nSaisie n'importe quelle touche pour commencer :\n");
    int z;
    scanf("%d", &z);




    }





void remplir_vide()
{
    int i, j;
    for (i=0; i<25; i++)
    {
        for(j=0; j<60; j++)
        {
            tab[i][j] = '.';
        }
    }
    for (i = 0; i<25; i++)
    {
        tab[i][59] = 'X';
        tab[i][0] ='X';
    }
    for (j = 0; j<60; j++)
    {
        tab[0][j] ='X';
        tab[24][j]='X';
    }
}


int touche;
int main (){
    //Initialisation
    menu();
    remplir_vide();
    int x,y;  // position joueur
    x = y = 1;
    touche = 0;
    while(touche!=27) // ECHAP
    {
        Afficher(x,y);
        touche = MyGetch();
        switch(touche)
        {
        case 'q':
            Mouvement(&x,&y,0,-1);
            break;
        case 'd':
            Mouvement(&x,&y,0,1);
            break;
        case 'z':
            Mouvement(&x,&y,-1,0);
            break;
        case 's':
            Mouvement(&x,&y,1,0);
        default:
            break;
        }
    }
    Afficher(x,y);
    //Message de fin
    printf("\n vous avez perdu");
    return 0;
}





int MyGetch()
{
#ifdef _WIN32
    return getch();
#endif
// trouver alternative hors Windows.
}

void Locate(int x,int y)
{
#ifdef _WIN32
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=(SHORT)x;
    C.Y=(SHORT)y;
    SetConsoleCursorPosition(H,C);
#endif
    // trouver alternative hors Windows.
}

void Afficher(int x,int y)
{
    int i,j;
    Locate(0,40);
    for (i = 0; i <= 29+1; i++)
    {
        printf("__");
    }
    printf("|\n|");
    for(i=0;i<25;i++)
    {
        for(j=0;j<60;j++)
        {
            if ((i==x && j==y) && touche != 27)
                printf("N");
            else
                printf("%c",tab[i][j]);
        }
        printf("|\n|");
    }
    for (i=0; i<30+1; i++)
    {
        printf("__");
    }

}


void Mouvement(int* x,int* y,int vx,int vy)
{
    if (tab[*x+vx][*y+vy]=='*')
        return;
    if (tab[*x+vx][*y+vy]==' ' || tab[*x+vx][*y+vy]=='X' ){
        tab[*x][*y] = ' ';
        touche = 27;
        return;
    }
    tab[*x][*y] = ' ';
    (*x)+=vx;
    (*y)+=vy;
}
