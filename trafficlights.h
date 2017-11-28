#include "librairies.h"

#define trafficlights

#ifndef direction

enum Direction // Enumeration des directions possibles pour une entité
{
	NORD,
	EST,
	OUEST,
	SUD,
};

typedef enum Direction Direction;

#define direction

#endif

#ifndef tram

	typedef struct Tramway
{
	int posX;
	int posY;
	int vitesse;
	char CaseDecision;
	Direction Direction;
	int compteur;
	int compteur2;
	int virage;
} Tramway;

#define tram

#endif



typedef struct TrafficLight	
{
	int color;
	int posX;
	int posY;
	int Compteur;
} TrafficLight;

typedef struct TrafficLightList // Liste chainee des feux pour le roulement des feux sur la carte
{
	TrafficLight* TrafficLight;
	struct TrafficLightList *next;
} TrafficLightList;

TrafficLight* createTrafficLight(int posX, int posY, int color); //Permet d'instancier un feu

void appendTrafficLightList(TrafficLightList **list, TrafficLight*);	//Permet d'ajouter un feu a la liste chainee

void initialisationTrafficLights();				//Fonction theorique permettant l'initialisation de tous les feux de la map (a mettre en debut de loadmap())

//void showTrafficLight(TrafficLight TrafficLight);		//Permet d'afficher les informations relatives à un feu (un peu inutile mais permet de tester la cohérence du code)

//void visualiserTrafficLightList(TrafficLightList *List);	//Permet d'afficher toutes les positions des feux en parcourant la liste chainee des feux (same)

clock_t startChrono(double* montre);				//Fonction permettant de lancer un chronometre (marche pas encore)

double visualiserChrono(double* montre);			//Fonction permettant de regarder le chronometre (marche pas encore)

void roulement_feux(TrafficLightList ** List, char *** MatriceDecision);		//Fonction prenant en argument une liste de feu et incrémentant leur état de 1 unité. (vert => orange, etc ... modulo 4)

void modificationDuFeu(TrafficLight * T, char *** MatriceDecision, char caractere);

//void gestionDesFeux(TrafficLightList *List); //Fonction gérant les feux de la map en fonction d'un chronomètre qu'elle initialise. Ici elle ne prend en argument qu'une seule Liste de Feux, mais on peut la généraliser pour qu'elle en prenne plus. Tout dépend du choix qu'on fait sur la gestion des feux : 2 familles de feux, 1 famille de feux par carrefour ... etc

void affichageFeu(TrafficLight* trafficLight); //Fonction d'affichage de trafficlights

void modificationDeMatrice(TrafficLight * T, char *** MatriceDecision, char caractere);