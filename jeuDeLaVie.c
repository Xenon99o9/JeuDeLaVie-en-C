#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LARGEUR 100
#define HAUTEUR 20
#define REPETITION 200
#define POURCENTAGE 20
#define TEMPS 1

char* creeGrille();
char* creeRandomGrille();
void afficherGrille(char *grille);
int voisinVivant(char* grille, int h, int l);
char* nextGen(char* grille);
void attendre(int secondes);
int lancerPartie();

int main(){

    lancerPartie();
    return 0;
}

int lancerPartie(){
    char* grille = creeRandomGrille();

    if (grille != NULL){


        for (int i = 0; i < REPETITION; i++){
            printf("Génération %d:\n", i);
            afficherGrille(grille);
            char* new = nextGen(grille);
            free(grille);
            grille = new;
            attendre(TEMPS);
            printf("\n");
            
        }
        

        free(grille);
    } else {
        return EXIT_FAILURE;
    }

}

char* nextGen(char* grille){
    char* copyGrille = malloc((LARGEUR * HAUTEUR) * sizeof(char));
    if (copyGrille == NULL){
        return NULL;
    }


    for (int i = 0; i < HAUTEUR; i++){
        for (int j = 0; j < LARGEUR; j++){
            copyGrille[i * LARGEUR + j] = grille[i * LARGEUR + j];
        }
    }



    for (int i = 0; i < HAUTEUR; i++){
        for (int j = 0; j < LARGEUR; j++){
            int vivant = voisinVivant(grille, i, j);
            if (grille[i * LARGEUR + j] == ' '){
                if (vivant < 2 || vivant > 3){
                    copyGrille[i * LARGEUR + j] = '#';
                } 
            } else {
                if (vivant == 3){
                    copyGrille[i * LARGEUR + j] = ' ';
                }
            }
        }
    }

    return copyGrille;
}

int voisinVivant(char* grille, int h, int l){
    int n = 0;
    
    // EN HAUT
    if (h != 0){
        if (grille[(h-1) * LARGEUR + l] == ' '){
            n++;
        }
    }

    // EN BAS
    if (h != (HAUTEUR-1)){
        if (grille[(h+1) * LARGEUR + l] == ' '){
            n++;
        }
    }

    // À DROITE
    if (l != (LARGEUR-1)){
        if (grille[h * LARGEUR + (l+1)] == ' '){
            n++;
        }
    }

    // À GAUCHE
    if (l != 0){
        if (grille[h * LARGEUR + (l-1)] == ' '){
            n++;
        }
    }

    // EN HAUT À DROITE
    if (h != 0 && l != (LARGEUR-1)){
        if (grille[(h-1) * LARGEUR + (l+1)] == ' '){
            n++;
        }
    }

    // EN HAUT À GAUCHE
    if (h != 0 && l != 0){
        if (grille[(h-1) * LARGEUR + (l-1)] == ' '){
            n++;
        }
    }

    // EN BAS À DROITE
    if (h != (HAUTEUR-1) && l != (LARGEUR-1)){
        if (grille[(h+1) * LARGEUR + (l+1)] == ' '){
            n++;
        }
    }

    // EN BAS À GAUCHE
    if (h != (HAUTEUR-1) && l != 0){
        if (grille[(h+1) * LARGEUR + (l-1)] == ' '){
            n++;
        }
    }

    return n;
}

char* creeRandomGrille(){

    srand(time(NULL));

    char* grille = malloc((LARGEUR * HAUTEUR) * sizeof(char));
    if (grille == NULL){
        return NULL;
    }

    for (int i = 0; i < HAUTEUR; i++){
        for (int j = 0; j < LARGEUR; j++){

            if ((rand() % 101) > POURCENTAGE){
                grille[i * LARGEUR + j] = '#';
            } else {
                grille[i * LARGEUR + j] = ' ';
            }
        }
    }
    return grille;
}


char* creeGrille(){
    char* grille = malloc((LARGEUR * HAUTEUR) * sizeof(char));
    if (grille == NULL){
        return NULL;
    }

    for (int i = 0; i < HAUTEUR; i++){
        for (int j = 0; j < LARGEUR; j++){
            grille[i * LARGEUR + j] = '#';
        }
    }
    return grille;
}

void afficherGrille(char *grille){
    for (int i = 0; i < HAUTEUR; i++){
        for (int j = 0; j < LARGEUR; j++){
            printf("%c", grille[i * LARGEUR + j]);
        }
    printf("\n");
    }
}

void attendre(int secondes) {
    clock_t debut = clock();
    while (clock() - debut < (clock_t)secondes * CLOCKS_PER_SEC)
        ; // boucle d'attente
}