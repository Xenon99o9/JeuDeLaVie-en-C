# Jeu de la vie

Projet en C qui simule le célèbre automate cellulaire de Conway dans le terminal.

## Description

Le programme affiche une grille de cellules qui évolue à chaque génération selon les règles du jeu de la vie :

- une cellule vivante survit si elle a 2 ou 3 voisines vivantes
- une cellule vivante meurt si elle a moins de 2 ou plus de 3 voisines vivantes
- une cellule morte devient vivante si elle a exactement 3 voisines vivantes

La simulation commence avec une grille générée aléatoirement, puis peut aussi être personnalisée par l'utilisateur via un menu interactif.

## Fonctionnalités

- génération aléatoire de la grille initiale
- affichage des générations dans le terminal
- choix entre mode par défaut et mode personnalisé
- possibilité de modifier :
  - la hauteur de la grille
  - la largeur de la grille
  - le nombre de générations
  - le pourcentage de cellules vivantes initiales
  - le délai entre chaque génération

## Fichiers

- `jeuDeLaVie.c` : code source principal du projet

## Prérequis

- compilateur C (`gcc` recommandé)
- environnement Unix/Linux ou terminal compatible

## Compilation

```bash
gcc -std=c11 -Wall -Wextra -o jeuDeLaVie jeuDeLaVie.c
```

## Lancement

```bash
./jeuDeLaVie
```

## Utilisation

Au démarrage, le programme propose un menu :

1. Mode par défaut
2. Mode personnalisé

### Mode par défaut

Le programme utilise les valeurs suivantes :

- largeur : 100
- hauteur : 20
- répétitions : 200
- pourcentage de cellules vivantes : 20%
- délai : 1 seconde

### Mode personnalisé

L'utilisateur peut entrer ses propres valeurs pour chaque paramètre.

## Représentation visuelle

- cellule vivante : espace (`' '`) 
- cellule morte : `#`

## Objectifs pédagogiques

Ce projet permet de pratiquer :

- les variables et les fonctions en C
- la gestion dynamique de la mémoire
- les boucles et les conditions
- la simulation d'un système cellulaire
- l'interaction utilisateur en console

## Remarque

Le programme est conçu comme un petit projet d'apprentissage et peut être facilement modifié pour ajouter des fonctionnalités telles que :

- pause / reprise
- sauvegarde de la grille
- chargement d'une configuration initiale
- interface graphique plus lisible
