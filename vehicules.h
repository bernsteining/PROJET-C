#include "librairies.h"
#define FEU_EST_ROUGE 'f'
#define CAR_IS_HERE 'c'


enum type	// Enumeration des differents types de vehicules
{
	Jaguar,
	Peugeot,
	Fiat,
	Porsche,
	Ferrari,
	Batmobile,
	Renault,
};

typedef enum type type;

enum Carburant	// Enumeration des differents etats du carburant pour un vehicule
{
	FAIBLE,
	PLEIN,
};

typedef enum Carburant Carburant;

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

typedef struct Position
{
	int posX;
	int posY;
			
} Position;

#define position
	typedef struct Vehicule
{
	Direction Direction;
	int posX;
	int posY;
	int Compteur;
	int vitesse;
	char custom;
	char CaseDecision;
	Carburant Carburant;
	int virage;	

} Vehicule;


typedef struct VehiculeList // Liste chainee de vehicules pour la gestion du trafic
{
	Vehicule* Vehicule;
	struct VehiculeList *next;
} VehiculeList;

Position* positionFuture(Vehicule* vehicule); //Fonction renvoyant un struct Position (qui sera la position de vehicule à la frame suivante) en fonction de sa Direction

VehiculeList* vehiculeEater(VehiculeList **List, Vehicule* Vehicule); //Fonction ayant pour but de supprimer de la liste VehiculeList les Vehicules sortant de la map. L'appeler lorsque PositionFuture(Vehicule) renvoit une position dont au moins une coordonnée est hors de la map

void appendVehiculeList(VehiculeList **List, Vehicule* Vehicule); //Fonction permettant d'ajouter un Vehicule à la liste des Vehicules (à appeler après le Spawner)

void vehiculeSpawner(int posX, int posY, Direction Direction, Carburant Carburant, char a, char** MatriceDecision, VehiculeList** ListeDesVehicules); // Spawner de Vehicules

void visualiserVehiculeList(VehiculeList *List); //permet de visualiser une liste de vehicules (affiche les positions de ces vehicules)

void setNewVehiculeDirection(Vehicule* Vehicule, char ** MatriceDecision, VehiculeList *ListeDesVehicules); //Fonction determinant la direction future de la voiture en fonction de la case sur laquelle elle se trouve (carrefour, ou route) /!\ Etablir un code permettant de faire la disjonction de cas de cette fonction

Direction directionAleatoire(Direction A, Direction B);

void placeTerminale(int posX, int posY); //Fonction permettant de s'éviter la syntaxe trop lourde du placement du curseur dans le terminal

void setNewPositionVehicule(Vehicule* vehicule); //Met a jour la position de la voiture dans sa struct

void roulementVehiculesPosition(char ** MatriceMap, char*** MatriceDecision, VehiculeList** List); //Actualise la position des vehicules

Vehicule* oldVehiculeSpawner(int posX, int posY, Direction Direction); // Ancienne fonction pour tester un truc

int Obstacle(char** MatriceDecision, int i, int j);

void affichageVehicule(Vehicule* V); //Fonction d'affichage de Vehicule

char AleatoireCustomVehicule(); // Renvoie un skin de vehicule aléatoirement

void affichagePartielVehicule(char ** matrice, Vehicule * V);

void animationDeRemplissage(Vehicule * V);