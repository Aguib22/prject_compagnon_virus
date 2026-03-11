#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Configuration de la fenêtre
    const int screenWidth = 800;
    const int screenHeight = 500;
    InitWindow(screenWidth, screenHeight, "Password Gen v1.0");

    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@?-_#$%^&*";
    char password[65] = "Cliquez pour generer";
    int longueur = 16;

    SetTargetFPS(60);
    srand(time(NULL));

    while (!WindowShouldClose()) {
        // Logique : si on presse ESPACE, on génère un nouveau mot de passe
        if (IsKeyPressed(KEY_SPACE)) {
            for (int i = 0; i < longueur; i++) {
                password[i] = charset[rand() % (int)(sizeof(charset) - 1)];
            }
            password[longueur] = '\0';
        }

        if (IsKeyPressed(KEY_C)) {
            char commande[512];
            
            sprintf(commande, "echo -n '%s' | xclip -selection clipboard &", password);
            system(commande);
            sprintf(commande, "zenity --info --title='Copier le mot de passe' --text='Votre mot de passe est : %s'", password);
            system(commande);
        }

        // Rendu Graphique
        BeginDrawing();
            ClearBackground(RAYWHITE);

            // Titre principal (Ton style actuel)
            DrawText("GENERATEUR DE MOT DE PASSE", 220, 50, 20, DARKBLUE);
            
            // Un rectangle plus grand et centré
            DrawRectangle(150, 150, 500, 80, LIGHTGRAY);
            DrawText(password, 180, 175, 20, DARKGREEN); // Texte plus gros (30)

            // Instructions décalées vers le bas
            DrawText("ESPACE : Generer un nouveau mot de passe", 150, 300, 20, GRAY);
            DrawText("C : Copier dans le presse-papier", 150, 340, 20, DARKBLUE);
            DrawText("ESC : Quitter le programme", 150, 380, 20, MAROON);
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}