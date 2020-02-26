#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "fonctions.h"
#include "pointeur.h"

int affichageMenu(void)
{
    int choixMenu;

    printf("MAIN MENU\n");
    printf("1. Create New Game\n");
    printf("2. Load Saved Game\n");
    printf("3. About\n");
    printf("4. Exit\n\n\n");
    scanf("%d", &choixMenu);
    return choixMenu;
}
int main(void)
{
    switch(affichageMenu())
    {
                case 1:
                    printf("voila\n");
                    break;
                case 2:
                    printf("ok \n");
                    break;
                case 3:
                    printf("super \n");
                    break;
                case 4:
                    printf("cool ta vie \n");
                    break;
                default:
                    printf("Sélectionnez entre 1 et 4 \n");
                    break;
    }
    system("PAUSE");
    return 0;
}
