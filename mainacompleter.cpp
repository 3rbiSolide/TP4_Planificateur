#include <iostream>
#include <fstream>
#include <string>

#include "contexterobot.h"
#include "sequenceactions.h"
#include "actionrobot.h"
#include "ouvrirpince.h"
#include "fermerpince.h"
#include "deplacer.h"



int main() {

    std::ifstream fichier("data/plan.txt");
    if (!fichier.is_open()){
        std::cerr << "Erreur : impossible d'ouvrir le fichier plan.txt" << std::endl;
        return 1;
    }

    SequenceActions plan;
    std::string commande;
    while (fichier >> commande) {
        if (commande == "DEPLACER"){
            double dx, dy, dz;
            fichier >> dx>> dy>> dz;
            plan.ajouter(new Deplacer(dx, dy, dz));
        }
        else if (commande == "OUVRIR_PINCE") {
            plan.ajouter(new OuvrirPince());
        }

        else if (commande == "FERMER_PINCE") {
           plan.ajouter(new FermerPince());
        }

        else {
            std::cerr << "Commande inconnue : "<< commande << std::endl;
        }
    }

    ContexteRobot ctx(0, 0, 100, true);
    plan.executer(ctx);
    ctx.afficherPosition();
    plan.nettoyer();

    return 0;
}
