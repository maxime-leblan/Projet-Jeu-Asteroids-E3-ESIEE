# Contexte du projet
Ce projet a été développé individuellement dans le cadre de la formation en cycle ingénieur E3 à l'ESIEE Paris durant mars et avril 2026, dans le cadre de l'élective "Programmation C++" visant à apprendre les notions de base du langage C++. Afin d'évaluer nos compétences acquises au cours de cette élective, nos enseignement nous ont proposé de programmer, individuellement ou par binôme, un jeu en 2D ou en 3D soit inspiré d'un jeu existant ou d'une catégorie de jeu existante, soit une variante d'un jeu célèbre. J'ai dans mon cas décidé d'implémenter une variante simplifiée du jeu Asteroids (1979) en me concentrant principalement sur la gestion de la physique des astéroïdes, du joueur ainsi que d'un système de vague.

# Caractéristiques du projet
Afin d'implémenter cette variante du jeu Asteroids, nous avons été incité par nos professeurs à utiliser le paradigme de la Programmation Orientée Objets afin de structurer proprement et efficacement le code source de notre jeu. L'objectif principal de ce projet était de vérifier la maîtrise des notions de base de la programmation en C++ de chaque étudiants.

# Rapport vidéo
Pour avoir un meilleur aperçu sur le rendu final de ce projet, voici la vidéo ayant été produite dans le cadre de l'évaluation de celui-ci, et qui introduit les différentes fonctionnalités ayant été implémentées au sein du jeu.

[![Titre de la vidéo](https://img.youtube.com/vi/05ZLBF5-vjE/0.jpg)](https://www.youtube.com/watch?v=05ZLBF5-vjE)   

# Installation et test du jeu
Aucun fichier exécutable n'a été créé pour pouvoir lancer le jeu sans dépendances externes. Pour pouvoir installer et exécuter le jeu, il est impératif d'avoir au préalable installé le compilateur g++ permettant de compiler le code source du jeu.

Après avoir téléchargé le code et avoir ouvert le dossier dans un éditeur de code (exemple : VS Code), ouvrez l'invite de commande au même niveau d'arborescence que les fichiers terminant par l'extension `.cpp`. Tapez ensuite la commande de compilation suivante dans votre terminal :
```g++ *.cpp -lGL -lGLU -lglut```
Puis pour lancer le jeu, entrez la commande ci-dessous :
```./a.out```
