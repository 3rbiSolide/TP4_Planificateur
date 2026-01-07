#ifndef ROTATION_H
#define ROTATION_H
#include "actionrobot.h"
#include "contexterobot.h"

class rotation : public ActionRobot
{
private:
    int m_angle;
public:
    rotation(int p_angle);
    ~rotation() override = default ;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;

};

#endif // DEPLACER_H
