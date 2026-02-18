#include "ouvrirpince.h"
#include <iostream>

OuvrirPince::OuvrirPince()
{
}

void OuvrirPince::executer(ContexteRobot &ctx){
    ctx.ouvrirPince();
    afficherNom();
}

void OuvrirPince::afficherNom() const{

    std::cout << "Action : Ouvrir pince " << std::endl;
}







