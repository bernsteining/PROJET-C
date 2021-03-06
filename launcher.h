#include "librairies.h"
#include "boats.h"
#include "trafficlights.h"
#include "vehicules.h"
#include "decision.h"
#include "affichage.h"
#include "pietons.h"
#include "tramways.h"
#include "helicopteres.h"
#include "lapins.h"


void lancementMenu();

void lancementModeSafe();

void lancementModeDanger();

void creationDesFeux(TrafficLightList ** Liste);

void details();

void randomSpawnPieton(PietonList** ListeDesPietons);

void randomSpawnBoat(char ** MatriceDecision, BoatList** ListeDesBoats);

void randomSpawnLapin(LapinList** ListeDesLapins);

void randomSpawnHelicoptere(HelicoptereList** ListeDesHelicopteres);

void animation1(VehiculeList ** ListeDesVehicules, TramwayList ** ListeTramways, char *** MatriceDecision, char ** MatriceMap);