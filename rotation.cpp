#include "rotation.h"
#include <iostream>


rotation::rotation(int p_angle): m_angle(p_angle)
{
}

void rotation::executer(ContexteRobot &ctx){
    ctx.Rotation(ctx.getAngleActuel()+ m_angle);

}

void rotation::afficherNom() const{
    std::cout << "Action : Rotation de ("
        << m_angle <<")" << std::endl;
}
