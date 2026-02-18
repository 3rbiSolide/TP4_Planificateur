#include "deplacer.h"
#include <iostream>


Deplacer::Deplacer(double p_dx, double p_dy, double p_dz): m_dx(p_dx), m_dy(p_dy), m_dz(p_dz)
{
}

void Deplacer::executer(ContexteRobot &ctx){
    ctx.deplacerVers(ctx.getX()+ m_dx, ctx.getY()+ m_dy, ctx.getZ()+ m_dz);

}

void Deplacer::afficherNom() const{
    std::cout << "Action : Deplacer de ("
        << m_dx << ", "<<m_dy <<", "<< m_dz << ")" << std::endl;
}
