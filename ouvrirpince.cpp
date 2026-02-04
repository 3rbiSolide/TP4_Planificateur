#include "ouvrirpince.h"
#include <iostream>

OuvrirPince::OuvrirPince()
{
}

void OuvrirPince::executer(ContexteRobot &ctx){
    ctx.ouvrirPince();

}

void OuvrirPince::afficherNom() const{

    std::cout << "Action : Ouvrir pince " << std::endl;
}







