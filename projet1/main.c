#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "structure.h"

// INITIALISATION DES FONCTIONS ! //

    int afficheMenu();
    int choixAction();
    int degatPerso();
    int degatMonstreFaible();
    int OpenInventaire();
    int degatPotionRenvoi();
    int combat();
    int choixDeplacement();
    int cartographie();

// DECLARATION DES VARIABLES DES TYPES PERSONNAGES ET MONSTREFAIBLES ET INVENTAIRE
    personnage Player1;
    monstreFaible Monster1;
    inventaire Sac;

// FONCTION PRINCIPALE


    int backupHpLvl1 = 500;
    int degatBackupPerso = 50;
    int degatBackupPersoNiv2 = 100;
    int degatBackupMonstreFaible = 20;
    int away = 0;
    int potionHealth = 200;
    int potionAtk = 50;
    int x = 0;
    int y = 0;
    int xp = 600;
    int stockXP = 1000;
    int fincombat = 0;



void main(void)
{

// DECLARATION DES VALEURS DU TYPE PERSONNAGES POUR LA VARIABLE PLAYER1
    Player1.niveau = 1;
    Player1.barreHP = 500 * Player1.niveau;
    Player1.degat = 50 * Player1.niveau;
    Player1.barreXP1 = 600;
    Player1.barreXP2 = 2000;
    Player1.deplacementFaux = 0;


// DECLARATION DES VALEURS POUR LA VARIABLE MONSTER1

    Monster1.barreHP = 200;
    Monster1.degat = 20;
    Monster1.niveau = 5;

// DECLARATION DES VALEURS POUR LA VARIABLE SAC

    Sac.potion = 2;
    Sac.potionRenvoi = 1;
    Sac.potionAtk = 1;

// DECLARATION DES VARIABLES NECESSAIRES POUR LE CODE


// PREMIER SWITCH POUR LAFFICHAGE DU MENU

    switch(afficheMenu()){

// SI LE CHOIX EST 1 ALORS
        case 1:
            printf("\nWelcome new player, what is your name?\n");
            printf("Enter an user name between 1 & 25 letters: ");
            scanf("%s", Player1.userName);
            printf("Hi, %s\n", Player1.userName);
            Sleep(2000);
            printf("You appeared in a dark forest surrounded by a big tree.\n");
            Sleep(2000);
            printf("In front of you, you see a monster.. \n");
            Sleep(2000);
            printf("It's a level 5 monster !! \n\n");
            Sleep(1000);

// DEUXIEME SWITCH POUR LES ACTIONS: ATK/INVENTAIRE/FUIR
            combat();
            cartographie();

            break;




            // CAS 2: POUR LANCER UNE PARTIE SAUVEGARDER ( PAS ENCORE FAIT)

            case 2:
                printf("Sauvegarde plus tard!");
                break;

            // CAS 3: PETIT RESUME DU JEU ( PAS FAIT )

            case 3:
                printf("Resume le jeu.\n Matthias \n Killian ");
                break;

            // QUITTER LE PROGRAMME

            case 4:
                exit(0);
                break;

            // SI AUTRE CHOSE QUITTER LE PROGRAMME

            default:
                exit(0);
                break;


            }

        }


// FONCTION POUR AFFICHER LE MENU PRINCIPAL

int afficheMenu(){

    int choix;
    printf("MAIN MENU: \n");
    printf("1- Create a new game.\n");
    printf("2- Load a save game.\n");
    printf("3- About.\n");
    printf("4- Exit\n\n");
    scanf("%d", &choix);

    return choix;
}

// FONCTION POUR AFFICHER LE MENU DACTION

int choixAction(){

    int choice;
    printf("\nWhat do you want to do: \n");
    printf("1- Attack the monster\n");
    printf("2- Open your inventory\n");
    printf("3- Run away (50 percent chance to get mid health) \n\n");
    scanf("%d", &choice);

    return choice;
}

// FONCTION POUR INFLIGER LES DEGATS AU MONSTRE (CRIT / MISS INCLU )

int degatPerso(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat;
        Monster1.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster1.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Monster1.barreHP -= Player1.degat;
    }

    return v;

}

// FONCTION DES DEGAT INFLIGER PAR DES MONSTRES FAIBLES

int degatMonstreFaible(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster1.degat = 0;
        Player1.barreHP -= Monster1.degat;
    }
    if(c < 2){
        Monster1.degat += Monster1.degat;
        Player1.barreHP -=Monster1.degat;
    }
    if(c > 1 && c < 9){
        Player1.barreHP -=Monster1.degat;
    }

    return c;



}

// FONCTION POUR AFFICHER L'INVENTAIRE

int OpenInventaire(){

    int choixx;
    printf("\INVENTORY : (If you don't have an item return to the menu or your turn will pass\n\n");
    printf("1- Health potion : %d\n", Sac.potion);
    printf("2- Return damage potion : %d\n", Sac.potionRenvoi);
    printf("3- Offensive potion : %d\n", Sac.potionAtk);
    printf("4- Return to choice menu\n\n");
    scanf("%d", &choixx);

    return choixx;
}

// FONCTION DEGAT DE LA POTION DE RENVOI

int degatPotionRenvoi(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster1.degat = 0;
        Monster1.barreHP -= Monster1.degat;
    }
    if(c < 2){
        Monster1.degat += Monster1.degat;
        Monster1.barreHP -=Monster1.degat;
    }
    if(c > 1 && c < 9){
        Monster1.barreHP -=Monster1.degat;
    }

    return c;



}

int degatPotionAtk(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat + potionAtk;
        Monster1.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster1.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Player1.degat += potionAtk;
        Monster1.barreHP -= Player1.degat;
    }

    return v;

}
// FONCTION ENTIERE DU COMBAT !

int combat(){

do{
        switch(choixAction()){

            //CAS 1 COUP DE POING AU MONSTRE

            case 1:
                printf("You just punched the monster! \n");
                degatPerso();
                Sleep(1000);
                printf("The monster took %d damage !\n", Player1.degat);
                Player1.degat = degatBackupPerso;
                Sleep(2000);
                printf("The monster still has %d life left! \n", Monster1.barreHP);
                Sleep(2000);

                // SI LE MONSTRE A ENCORE DE LA VIE, IL ATTAQUE

                if(Monster1.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreFaible();
                    printf("The monster did %d damage!\n", Monster1.degat);
                    Monster1.degat = degatBackupMonstreFaible;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }

                // SI LE MONSTRE N'A PLUS DE VIE: MESSAGE POUR AFFICHER QUE TU L'AS BATTU

                if(Monster1.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", xp,Player1.barreXP1);

                    if(stockXP >= Player1.barreXP1){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = degatBackupPerso * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        fincombat = 1;
                    }




                }

                break;

                // CAS 2: OUVERTURE DE LINVENTAIRE
            case 2:

            // SWITCH FONCTION OPEN INVENTAIRE

                switch(OpenInventaire()){

                // CAS 1: UTILISATION D'UNE POTION DE SOIN
                    case 1:

                        // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potion == 0){
                            printf("You don't have any health potion.");
                        }

                        // SI YA DES POTIONS : TU GAGNES DES HP MAIS TU PERDS 1 POTION !

                        if(Sac.potion > 0){

                            Player1.barreHP += potionHealth;
                            Sac.potion --;

                        // A RENDRE ADAPTATIF

                        if(Player1.barreHP > 500){
                        Player1.barreHP = 500;
                        }
                        printf("\nYou now have %d health point\n", Player1.barreHP);
                        }

                        break;

                // CAS 2: POTION DE RENVOI DE SORT ( SP5 E BOUCLIER TU CONNAIS )

                case 2:

                    // SI TA PAS DE POTION: MESSAGE ERREUR PAS DE POTION

                    if(Sac.potionRenvoi == 0){
                        printf("You don't have any Return damage potion !\n\n");
                        Sleep(2000);
                    }

                    // SI TU AS UNE POTION: TU UTILISE LA FONCTION DEGAT POTION RENVOI ET TU PERD UNE POTION

                    if(Sac.potionRenvoi > 0){
                        printf("Prepare to fire the monster attack\n\n");
                        Sac.potionRenvoi--;
                        Sleep(2000);
                        printf("You have returned %d damage !\n", Monster1.degat);
                        degatPotionRenvoi();
                        Monster1.degat = degatBackupMonstreFaible;
                        Sleep(2000);
                        printf("The monster still has %d life left! \n", Monster1.barreHP);
                        Sleep(2000);
                    }
                    if(Monster1.barreHP <= 0){

                            printf("You have beaten the monster! \n");
                            printf("You won %d XP\n\n", xp);
                            stockXP += xp;
                            printf("Barre XP %d/%d \n\n", xp,Player1.barreXP1);


                        if(stockXP >= Player1.barreXP1){
                            Player1.niveau++;
                            Player1.barreHP = backupHpLvl1 * Player1.niveau;
                            Player1.degat = degatBackupPerso * Player1.niveau;
                            printf("You are now level %d, Congratulations! \n", Player1.niveau);
                            printf("Your damage and your health level up too!\n\n");
                            Sleep(2000);
                            printf("Health: %d\n", Player1.barreHP);
                            printf("Damage: %d\n", Player1.degat);
                            fincombat = 1;


                        }
                    }
                        break;

                case 3:
                    // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potionAtk == 0){
                            printf("You don't have any health potion.");
                        }
                        if(Sac.potionAtk >0){
                                Sac.potionAtk--;
                                printf("You are going to attack!\n");
                                Sleep(2000);
                                printf("WOW! Your attack potion has done a lot of damage! \n");
                                degatPotionAtk();
                                Sleep(1000);
                                printf("The monster took %d damage !\n", Player1.degat);
                                Player1.degat = degatBackupPerso;
                                Sleep(2000);
                                printf("The monster still has %d life left! \n", Monster1.barreHP);
                                Sleep(2000);
                        }
                        if(Monster1.barreHP > 0){
                            printf("Be careful the monster replies! \n");
                            Sleep(2000);
                            degatMonstreFaible();
                            printf("The monster did %d damage!\n", Monster1.degat);
                            Monster1.degat = degatBackupMonstreFaible;
                            Sleep(1000);
                            printf("You have %d life left! \n", Player1.barreHP);

                        }
                        if(Monster1.barreHP <= 0){

                                printf("You have beaten the monster! \n");
                                printf("You won %d XP\n\n", xp);
                                stockXP += xp;
                                printf("Barre XP %d/%d", xp,Player1.barreXP1);

                            if(stockXP >= Player1.barreXP1){
                                Player1.niveau++;
                                Player1.barreHP = backupHpLvl1 * Player1.niveau;
                                Player1.degat = degatBackupPerso * Player1.niveau;
                                printf("You are now level %d, Congratulations! \n", Player1.niveau);
                                printf("Your damage and your health level up too!\n\n");
                                printf("Health: %d\n", Player1.barreHP);
                                printf("Damage: %d\n", Player1.degat);
                                fincombat = 1;
                            }

                        }
                        break;

                    case 4:
                        break;

                    }

            // PAS ENCORE FAIS MAIS C'EST POUR FUIR

                case 3:
                    away = 1;
                    break;


            }

           // TOUT CA A FAIRE TANT QUE TU N'AS PAS PERDU TOUTE TA VIE OU QUE LE MONSTRE N'EST PAS MORT

        }while(Player1.barreHP > 0 && fincombat == 0);

}

int choixDeplacement(){

    int choixxxxx;


    Sleep(2000);
    printf("\nMOVEMENT: \n\n");
    printf("-1 NORTH \n");
    printf("-2 SOUTH\n");
    printf("-3 EAST\n");
    printf("-4 WEST\n\n");
    scanf("%d", &choixxxxx);

    return choixxxxx;
}

int cartographie(){


    do{
    switch(choixDeplacement()){



    case 1:
        y--;
        Player1.deplacementFaux = 0;
        if((y<0 && x == 0 )|| (x<0 && y == 0 )|| (y<0 && x ==1)  || (y<0 && x ==2) || (y<0 && x == 3) || (y == 0 && x>3) || (y == 1 && x>3) || (y == 2 && x>3) || (y == 3 && x>3) || (y>3 && x==3) || (y>3 && x== 2) || (y>3 && x==1) || (y>3 && x== 0) || (y ==3 && x<0) ||  (y ==2 && x<0) || (y ==1 && x<0)){

            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            y++;
            Player1.deplacementFaux = 1;
        }
        else{

            printf("You are heading NORTH...\n");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", x,y);

        }
        break;

    case 2:
        y++;
        Player1.deplacementFaux = 0;
        if((y<0 && x == 0 )|| (x<0 && y == 0 )|| (y<0 && x ==1)  || (y<0 && x ==2) || (y<0 && x == 3) || (y == 0 && x>3) || (y == 1 && x>3) || (y == 2 && x>3) || (y == 3 && x>3) || (y>3 && x==3) || (y>3 && x== 2) || (y>3 && x==1) || (y>3 && x== 0) || (y ==3 && x<0) ||  (y ==2 && x<0) || (y ==1 && x<0)){
            y--;
            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            Player1.deplacementFaux = 1;



        }
        else{

            printf("You are heading SOUTH...");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", x,y);

        }
        break;

    case 3:
        x++;
        Player1.deplacementFaux = 0;
        if((y<0 && x == 0 )|| (x<0 && y == 0 )|| (y<0 && x ==1)  || (y<0 && x ==2) || (y<0 && x == 3) || (y == 0 && x>3) || (y == 1 && x>3) || (y == 2 && x>3) || (y == 3 && x>3) || (y>3 && x==3) || (y>3 && x== 2) || (y>3 && x==1) || (y>3 && x== 0) || (y ==3 && x<0) ||  (y ==2 && x<0) || (y ==1 && x<0)){
            x--;
            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            Player1.deplacementFaux = 1;


        }
        else{

            printf("You are heading EAST...");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", x,y);
        }
        break;

    case 4:
        x--;
        Player1.deplacementFaux = 0;
        if((y<0 && x == 0 )|| (x<0 && y == 0 )|| (y<0 && x ==1)  || (y<0 && x ==2) || (y<0 && x == 3) || (y == 0 && x>3) || (y == 1 && x>3) || (y == 2 && x>3) || (y == 3 && x>3) || (y>3 && x==3) || (y>3 && x== 2) || (y>3 && x==1) || (y>3 && x== 0) || (y ==3 && x<0) ||  (y ==2 && x<0) || (y ==1 && x<0)){
            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            x++;
            Player1.deplacementFaux = 1;

        }
        else{

            printf("You are heading WEST...");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", x,y);
        }
        break;

    }
    }while((y<0 && x == 0 )|| (x<0 && y == 0 )|| (y<0 && x ==1)  || (y<0 && x ==2) || (y<0 && x == 3) || (y == 0 && x>3) || (y == 1 && x>3) || (y == 2 && x>3) || (y == 3 && x>3) || (y>3 && x==3) || (y>3 && x== 2) || (y>3 && x==1) || (y>3 && x== 0) || (y ==3 && x<0) ||  (y ==2 && x<0) || (y ==1 && x<0)  ||  Player1.deplacementFaux == 1);

    if(y == 0 && x == 1){
            combat();
            cartographie();

    if(y == 0 && x == 2){
            combat();
            cartographie();

}

}

    }

