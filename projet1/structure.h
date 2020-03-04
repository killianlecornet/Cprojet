#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED


// DECLARATION DE LA STRUCTURE PERSONNAGE

typedef struct personnage personnage;
    struct personnage{

        char userName[25];
        int barreHP;
        int barreXP1;
        int barreXP2;
        int degat;
        int niveau;
        int deplacementFaux;

    };

// DECLARATION DE LA STRUCTURE MONSTRE FAIBLE

    typedef struct monstreFaible monstreFaible;
    struct monstreFaible{

        int barreHP;
        int niveau;
        int degat;

    };

// DECLARATION DE LA STRUCTURE DES MONSTRES MOYENS

    typedef struct monstreMoyen monstreMoyen;
    struct monstreMoyen{

        int barreHP;
        int niveau;
        int degat;

    };

// DECLARATION DE LA STRUCTURE DU BOSS

    typedef struct monstreBoss monstreBoss;
    struct monstreBoss{

        int barreHP;
        int niveau;
        int degat;

        };

// DECLARATION DE LA STRUCTURE DE L'INVENTAIRE

    typedef struct inventaire inventaire;
    struct inventaire{

        int potion;
        int potionRenvoi;
        int potionAtk;

        };


#endif // STRUCTURE_H_INCLUDED
