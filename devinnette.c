#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficherInterface() {
    printf("====================================================\n");
    printf("||                                                ||\n");
    printf("||   [****]  JEUX DE DEVINNETE  [****]            ||\n");
    printf("||                                                ||\n");
    printf("====================================================\n");
    printf("       _      _      _      _      _    \n");
    printf("      ( )    ( )    ( )    ( )    ( )   \n");
    printf("      / \\    / \\    / \\    / \\    / \\  \n");
    printf("     |___|  |___|  |___|  |___|  |___| \n");
    printf("\n");
};

void afficherMenu() {
    printf(" =================== MENU ===================\n");
    printf("1. Jouer\n");
    printf("2. Règles du jeu\n");
    printf("3. Quitter\n");
    printf("============================================\n");
    printf("Votre choix : ");
}

void afficherRegles() {
    printf("============== Règles du jeu ==============\n");
    printf("1. Le joueur doit deviner un nombre entre 1 et 100.\n");
    printf("2. Après chaque tentative, le jeu indiquera si le nombre est trop haut, trop bas ou correct.\n");
    printf("3. Le joueur a un nombre limité de tentatives pour trouver le nombre.\n");
    printf("4. Le jeu se termine lorsque le joueur trouve le nombre ou que le nombre d'essais est atteint.\n");
}

void jouer() {
    int choix,randnum, cpt=1;
    srand(time(NULL));
    randnum = rand() % 100 + 1; // Génère un nombre aléatoire entre 1 et 100

    do {
        printf("Entrez votre devinette (entre 1 et 100) : ");
        scanf("%d", &choix);
        while (choix < 1 || choix > 100) {
            printf("Entrez un nombre entre 1 et 100 : ");
            scanf("%d", &choix);
        }
        
        if (cpt > 5) {
            printf("=========================================================\n");
            printf("||                                                     ||\n");
            printf("||             ** ECHEC ! **              ||\n");
            printf("||desolé, vous avez dépassé le nombre maximum d'essais.||\n", randnum);
            printf("||             Le nombre était : %d.                   ||\n", randnum);
            printf("=========================================================\n");
            break;
        }

        if (choix < randnum) {
            printf("Trop petit ! Essayez encore.\n");
        } else if (choix > randnum) {
            printf("Trop grand ! Essayez encore.\n");
        } else {
            printf("====================================================\n");
            printf("||                                                ||\n");
            printf("||             ** FÉLICITATIONS ! **              ||\n");
            printf("||     Vous avez trouvé le nombre en %d essais.   ||\n", cpt);
            printf("====================================================\n");
            
        }
        cpt++;
    } while (choix != randnum);
}

void quitter() {
    printf("Merci d'avoir joué ! À bientôt !\n");
    exit(0);
}


int main(){
    int continuer = 1;
    afficherInterface();
    
    int option;

    while (continuer) {
        switch (option) {
            case 1:
                jouer();
                break;
            case 2:
                afficherRegles();
                break;
            case 3:
                continuer = 0;
                quitter();
                break;
        }
        afficherMenu();
        scanf("%d", &option);
        while (option < 1 || option > 3) {
            printf("Veuillez entrer une option valide (1, 2 ou 3) : ");
            scanf("%d", &option);
        }
    }
    







    return 0;


}