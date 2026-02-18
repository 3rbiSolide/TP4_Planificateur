#include "contexterobot.h"
#include "sequenceactions.h"
#include "deplacer.h"
#include "fermerpince.h"
#include "ouvrirpince.h"
#include "rotation.h"
#include "limits"


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

            if (!(fichier >> dx >> dy >> dz)) {
            plan.ajouter(new Deplacer(dx, dy, dz));

            std::cerr << "Erreur : paramètres invalides pour DEPLACER\n";
            fichier.clear();
            fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
            }
            else {
                plan.ajouter(new Deplacer(dx, dy, dz));
            }
        }

        else if (commande == "ROTATION") {
           int angle;

           if (!(fichier >> angle)) {


           std::cerr << "Erreur : paramètres invalides pour ROTATION\n";
           fichier.clear();
           fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           continue;

           }
           else {
                         plan.ajouter(new rotation(angle));
           }
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

    plan.nettoyer();

    return 0;
}
