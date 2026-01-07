#ifndef DEPLACER_H
#define DEPLACER_H
#include "actionrobot.h"
#include "contexterobot.h"

class Deplacer : public ActionRobot
{
private:
    double m_dx, m_dy, m_dz;
public:
    Deplacer(double p_dx, double p_dy, double p_dz);
    ~Deplacer() override = default ;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;

};

#endif // DEPLACER_H
