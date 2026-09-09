#pragma once

#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <stdbool.h>
#include "G2D.h"
#include "Player.h"
#include "Border.h"
#include "AsteroidList.h"
#include "WaveManager.h"

#define HEIGHT_PIX 900
#define WIDTH_PIX 900

/*
Classe contenant les données du jeu
*/
struct GameData
{
	int     idFrame = 0;
	int     HeightPix = HEIGHT_PIX;          // hauteur de la fenétre de jeu
	int     WidthPix = WIDTH_PIX;          // largeur de la fenétre de jeu

	/*
    Attribut contenant le joueur
    */
	Player aPlayer;

	/*
	Bordure du jeu
	*/
	Border aBorder;

	/*
	Liste des astéroïds présents dans le jeu
	*/
	AsteroidList aAsteroids;

	/*
	Gère les vagues d'astéroids
	*/
	WaveManager aWaveManager;

	/*Constructeur de la classe GameData*/
	GameData();

	/*
	Indique si la partie est terminée ou non. La partie est terminée lorsque le joueur est mort
	*/
	bool isFinished() const;

	/*
	Vérifie si le joueur est en collision avec les bordures du jeu, et s'il l'est,
	effectue les actions nécessaires pour qu'il reste dans la zone de jeu
	==> on le téléporte sur le côté de la fenêtre opposé au côté de la fenêtre d'où il vient de sortir
	*/
	void managePlayerCollisionWithBorders();

	/*
	Vérifie si le joueur entre en collision avec des astéroids, et s'il l'est,
	diminue les points de vie du joueur
	*/
	void managePlayerCollisionWithAsteroids();

	/*
	Vérifie si le joueur veut effectuer des actions et effectue les traitements nécessaires si c'est le cas
	*/
	void managePlayerActions();

	/*
	Effectue les traitements nécessaires sur les astéroids.
	Vérifie notamment si ceux-ci rentrent en collision avec des lasers du joueurs
	*/
	void manageAsteroidsActions();

	/*
	Gère le démarrage des vagues d'astéroides
	*/
	void manageWaves();

	/*
	Gère les évènements à effectuer lors de la fin du jeu
	*/
	void manageEndOfTheGame();

	/*
	Affiche l'écran de fin de jeu
	*/
	void displayEndGameScreen() const;

};