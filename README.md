# Jeu de la vie

Petit projet en C qui simule le célèbre automate cellulaire de Conway.

## Description

Le programme génère une grille aléatoire, puis affiche ses générations successives dans le terminal. Chaque cellule évolue selon les règles classiques du jeu de la vie :

- une cellule vivante survit si elle a 2 ou 3 voisines vivantes
- une cellule vivante meurt si elle a moins de 2 ou plus de 3 voisines vivantes
- une cellule morte renaît si elle a exactement 3 voisines vivantes

## Fichiers

- `jeuDeLaVie.c` : code principal du programme

## Prérequis

- Un compilateur C (par exemple `gcc`)
- Un terminal Unix/Linux

## Compilation

```bash
gcc -std=c11 -Wall -Wextra -o jeuDeLaVie jeuDeLaVie.c
```

## Lancement

```bash
./jeuDeLaVie
```

## Paramètres configurables

Le programme contient plusieurs constantes modifiables en haut du fichier :

- `LARGEUR` : largeur de la grille
- `HAUTEUR` : hauteur de la grille
- `REPETITION` : nombre de générations à afficher
- `POURCENTAGE` : densité initiale des cellules vivantes
- `TEMPS` : délai entre chaque génération

## Remarque

Dans cette version, les cellules vivantes sont représentées par des espaces (`' '`) et les cellules mortes par des `#`.

## Objectif pédagogique

Ce projet permet de découvrir :

- les tableaux en C
- la gestion de mémoire dynamique
- les fonctions de génération et d'affichage
- les automates cellulaires et la simulation
