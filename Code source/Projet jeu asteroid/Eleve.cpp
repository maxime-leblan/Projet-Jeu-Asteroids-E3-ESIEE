#pragma warning( disable : 4996 ) 

#include "GameData.h"

using namespace std;

/*
Commande de compilation : 
g++ *.cpp -lGL -lGLU -lglut
*/

// touche ESC : ferme la fenêtre et quitte le jeu
///////////////////////////////////////////////////////////////////////////////
//
// 
//     fonction de rendu - reçoit en paramétre les données du jeu par référence



void render(const GameData& G)
{
	// fond noir	 
	G2D::clearScreen(Color::Black);

	// si la partie est terminée, on affiche juste le message de fin de partie
	if (G.isFinished())
	{
		G.displayEndGameScreen();
		// envoie les tracés à l'écran
		G2D::Show();
		return;
	}

	// précise que l'on est en pause
	if (G2D::isOnPause())
		G2D::drawStringFontMono(V2(100, G.HeightPix / 2), string("Pause"), 50, 5, Color::Yellow);

	// on affiche les bordures si le booléen vaut true
	G.aBorder.show(true);

	// on affiche tous les lasers tirés par le joueur
	G.aPlayer.showAllLasers();

	// on affiche tous les astéroids du jeu
	G.aAsteroids.showAll();

	// on affiche le joueur
	G.aPlayer.show();

	// on affiche le numéro de la vague en cours ainsi que le chrono
	G.aWaveManager.displayWaveNumber();
	
	// envoie les tracés à l'écran
	G2D::Show();
}


///////////////////////////////////////////////////////////////////////////////
//
//
//      Gestion de la logique du jeu - reéoit en paramétre les données du jeu par référence


void Logic(GameData& G) // appelé 20 fois par seconde
{
	G.idFrame += 1;

	// si le jeu est terminé, on arrête d'effectuer la logique d'une partie
	if (G.isFinished())
	{
		return;
	}

	// cout << "Score du joueur : " << G.aPlayer.aScore.aTotalScore << "\n";

	// on vérifie si le joueur est en collision avec les bordures du jeu et on effectue le traitement nécessaire
	G.managePlayerCollisionWithBorders();

	// on vérifie si le joueur rentre en collision avec des astéroides
	G.managePlayerCollisionWithAsteroids();

	// on vérifie si le joueur veut effectuer des actions, et on effectue les traitements nécessaires si c'est le cas
	G.managePlayerActions();

	// on gère les actions concernant les astéroïds
	G.manageAsteroidsActions();

	// on gère le démarrage des vagues d'astéroides
	G.manageWaves();
}


///////////////////////////////////////////////////////////////////////////////
//
//
//        Démarrage de l'application



int main(int argc, char* argv[])
{
	G2D::initWindow(V2(WIDTH_PIX, HEIGHT_PIX), V2(((1920 - WIDTH_PIX)/2), 50), string("Asteroid"));

	GameData G;   // instanciation de l'unique objet GameData qui sera passé aux fonctions render et logic

	int callToLogicPerSec = 60;  // si vous réduisez cette valeur => ralentit le jeu

	G2D::Run(Logic, render, G, callToLogicPerSec, true);
}





