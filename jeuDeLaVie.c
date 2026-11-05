#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int largeur = 100;
int hauteur = 20;
int repetition = 200;
int pourcentage = 20;
int temps = 1;

char* creeGrille();
char* creeRandomGrille();
void afficherGrille(char *grille);
int voisinVivant(char* grille, int h, int l);
char* nextGen(char* grille);
void attendre(int secondes);
int lancerPartie();
void selectionJeu();

int main(){
    
    selectionJeu();
    return 0;
}

void selectionJeu(){
    int selection;
    puts("Selectionner votre mode de jeu: ");
    puts("1 - Par defaut");
    puts("2 - Entrée vos valeur");
    printf("Selection: ");
    scanf("%d", &selection);
    if (selection == 1){
        lancerPartie();
    } else {
        printf("Choisissez la hauteur de la grille: ");
        scanf("%d", &hauteur);
        printf("%d", hauteur);

        printf("Choisissez la largeur de la grille: ");
        scanf("%d", &largeur);

        printf("Choisissez le nombre de génération à afficher: ");
        scanf("%d", &repetition);

        printf("Choisissez le pourcentage de cellules vivantes de la génération 0: ");
        scanf("%d", &pourcentage);

        printf("Choisissez le temps d'affichage entre chaque génération (en s): ");
        scanf("%d", &temps);
        lancerPartie();
    }
}

int lancerPartie(){
    char* grille = creeRandomGrille();

    if (grille != NULL){


        for (int i = 0; i < repetition; i++){
            printf("Génération %d:\n", i);
            afficherGrille(grille);
            char* new = nextGen(grille);
            free(grille);
            grille = new;
            attendre(temps);
            printf("\n");
            
        }
        

        free(grille);
    } else {
        return EXIT_FAILURE;
    }

}

char* nextGen(char* grille){
    char* copyGrille = malloc((largeur * hauteur) * sizeof(char));
    if (copyGrille == NULL){
        return NULL;
    }


    for (int i = 0; i < hauteur; i++){
        for (int j = 0; j < largeur; j++){
            copyGrille[i * largeur + j] = grille[i * largeur + j];
        }
    }



    for (int i = 0; i < hauteur; i++){
        for (int j = 0; j < largeur; j++){
            int vivant = voisinVivant(grille, i, j);
            if (grille[i * largeur + j] == ' '){
                if (vivant < 2 || vivant > 3){
                    copyGrille[i * largeur + j] = '#';
                } 
            } else {
                if (vivant == 3){
                    copyGrille[i * largeur + j] = ' ';
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
        if (grille[(h-1) * largeur + l] == ' '){
            n++;
        }
    }

    // EN BAS
    if (h != (hauteur-1)){
        if (grille[(h+1) * largeur + l] == ' '){
            n++;
        }
    }

    // À DROITE
    if (l != (largeur-1)){
        if (grille[h * largeur + (l+1)] == ' '){
            n++;
        }
    }

    // À GAUCHE
    if (l != 0){
        if (grille[h * largeur + (l-1)] == ' '){
            n++;
        }
    }

    // EN HAUT À DROITE
    if (h != 0 && l != (largeur-1)){
        if (grille[(h-1) * largeur + (l+1)] == ' '){
            n++;
        }
    }

    // EN HAUT À GAUCHE
    if (h != 0 && l != 0){
        if (grille[(h-1) * largeur + (l-1)] == ' '){
            n++;
        }
    }

    // EN BAS À DROITE
    if (h != (hauteur-1) && l != (largeur-1)){
        if (grille[(h+1) * largeur + (l+1)] == ' '){
            n++;
        }
    }

    // EN BAS À GAUCHE
    if (h != (hauteur-1) && l != 0){
        if (grille[(h+1) * largeur + (l-1)] == ' '){
            n++;
        }
    }

    return n;
}

char* creeRandomGrille(){

    srand(time(NULL));

    char* grille = malloc((largeur * hauteur) * sizeof(char));
    if (grille == NULL){
        return NULL;
    }

    for (int i = 0; i < hauteur; i++){
        for (int j = 0; j < largeur; j++){

            if ((rand() % 101) > pourcentage){
                grille[i * largeur + j] = '#';
            } else {
                grille[i * largeur + j] = ' ';
            }
        }
    }
    return grille;
}


char* creeGrille(){
    char* grille = malloc((largeur * hauteur) * sizeof(char));
    if (grille == NULL){
        return NULL;
    }

    for (int i = 0; i < hauteur; i++){
        for (int j = 0; j < largeur; j++){
            grille[i * largeur + j] = '#';
        }
    }
    return grille;
}

void afficherGrille(char *grille){
    for (int i = 0; i < hauteur; i++){
        for (int j = 0; j < largeur; j++){
            printf("%c", grille[i * largeur + j]);
        }
    printf("\n");
    }
}

void attendre(int secondes) {
    clock_t debut = clock();
    while (clock() - debut < (clock_t)secondes * CLOCKS_PER_SEC)
        ; // boucle d'attente
}