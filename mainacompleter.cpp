#include "contexterobot.h"
#include "sequenceactions.h"
#include "deplacer.h"
#include "fermerpince.h"
#include "ouvrirpince.h"
#include "rotation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
//#include "...............
//#include "...............
//.........................
using namespace std;


int main() {


    const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(chrono::seconds(2));



    ContexteRobot ctx(0, 0, 0, 0, true);

ifstream fichier("data/plan.txt");
if (!fichier.is_open()){
    cerr << "Erreur : impossible d'ouvrir le fichier  plan.txt" << endl;
    return 1;
}
ofstream journal("data/journal.txt", ios::out);
if (!journal.is_open()){
    cerr << "Erreur : impossible d'ouvrir le fichier  journal.txt" << endl;
    return 1;
}

 SequenceActions plan;

 string commande;
 while(fichier >> commande){
     if(commande == "DEPLACER"){
         double dx, dy, dz;
         fichier >> dx >> dy >> dz;
         plan.ajouter(new Deplacer(dx,dy,dz));
         journal << "DEPLACER " <<  dx << " " << dy << " " << dz << "\n";
          cerr << "DEPLACER " <<  dx << " " << dy << " " << dz <<endl;


     }
     else if(commande == "FERMER_PINCE"){
         plan.ajouter(new FermerPince);
         journal <<"fermer pince"<< "\n";
         cerr << "fermer pince"<< endl;


     }
     else if(commande == "OUVRIR_PINCE"){
         plan.ajouter(new OuvrirPince);
         journal <<"ouvrir pince"<< "\n";
         cerr << "ouvrir pince"<< endl;


     }
     else if(commande == "ROTATION"){
         double angle;
         fichier >> angle;
         plan.ajouter(new Rotation(angle));
         journal << "Rotation " << angle <<" " << "degres" << "\n";
          cerr << "Rotation " << angle <<" " << "degres" <<endl;
     }

     else {
         journal <<"commande inconnue : "<< commande << "\n";
         cerr << "commande inconnue : " << commande << endl;

     }
     std::this_thread::sleep_for(chrono::seconds(2));
 }

 const auto end = std::chrono::high_resolution_clock::now();
 auto duree = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
/*




    plan.ajouter(new Deplacer(100, 0, 0));
    plan.ajouter(new FermerPince());
    plan.ajouter(new Deplacer(100, 0, 0));
    plan.ajouter(new Deplacer(100, 0, 0));
    plan.ajouter(new OuvrirPince());
    plan.ajouter(new Deplacer(0, 0, 100));
    plan.ajouter(new Deplacer(0, 0, 100));
    plan.ajouter(new Rotation(80));


*/
    plan.executer(ctx);
    ctx.afficherPosition();

    plan.nettoyer();

    return 0;
}
