#include "fermerpince.h"
#include <iostream>

FermerPince::FermerPince()
{
}

void FermerPince::executer(ContexteRobot &ctx){
    ctx.fermerPince();
    afficherNom();
}

void FermerPince::afficherNom() const{

    std::cout << "Action : Fermer pince " << std::endl;
}

