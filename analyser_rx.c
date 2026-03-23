#include <stdio.h>
#include <stdlib.h>

void afficherEntete() {
    system("clear"); 
    printf("==========================================\n");
    printf("||      NETWORK ANALYZER PRO v1.0       ||\n");
    printf("==========================================\n\n");
}

int main() {
    int choix = 0;

    while (choix != 4) {
        afficherEntete();
        printf("1. Lister les interfaces (IP Rapide)\n");
        printf("2. Afficher les statistiques détaillées\n");
        printf("3. Tester la connexion (Ping Google)\n");
        printf("4. Quitter\n\n");
        printf("Votre choix > ");
        
        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n'); // Nettoie le buffer en cas d'erreur
            continue;
        }

        printf("\n--- Résultat ---\n");
        switch (choix) {
            case 1:
                system("ip -brief address");
                break;
            case 2:
                system("ip link show");
                break;
            case 3:
                printf("Test en cours (3 paquets)...\n");
                system("ping -c 3 8.8.8.8");
                break;
            case 4:
                printf("Fermeture de l'utilitaire...\n");
                break;
            default:
                printf("Option invalide.\n");
        }
        
        if (choix != 4) {
            printf("\nAppuyez sur Entrée pour revenir au menu...");
            getchar(); // Consomme le \n précédent
            getchar(); // Attend l'appui
        }
    }

    return 0;
}
