#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int longueur, i;
    char pssword[65]; // 64 caractères + 1 pour le caractère de fin de chaîne
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@?-_#$%^&*";
    char commande[256];
    printf("--- Génerateur de Mots de Passe Sécurisés ---\n");
    
    // Interaction utilisateur
    do
    {
        printf("Entrez la longueur souhaitée pour le mot de passe ,entre 4 et 64.\n");
        printf("----------->:");
        scanf("%d", &longueur);
        
        
    
        if (longueur < 4 || longueur > 64) {
            printf("Longueur invalide. Veuillez réessayer.\n");
        }
    } while (longueur < 8 || longueur > 64);
    

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    printf("Votre mot de passe généré : ");
    
    // Réalité de calcul : boucle de sélection aléatoire
    for (i = 0; i < longueur; i++) {
        int index = rand() % (int)(sizeof(charset) - 1);
        pssword[i] = charset[index];
    }
    pssword[longueur] = '\0'; // Ajout du caractère de fin de chaîne
    // À la place du printf de mot de passe
    
    sprintf(commande, "zenity --info --title='Gererateur de mot de passe' --text='Votre mot de passe est : %s'", pssword);
    system(commande);
    
    printf("\n----------------------------------------------\n");
    return 0;
}