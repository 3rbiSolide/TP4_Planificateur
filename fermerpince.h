#ifndef FERMERPINCE_H
#define FERMERPINCE_H
#include "actionrobot.h"
#include "contexterobot.h"

class FermerPince : public ActionRobot
{
private:

public:
    FermerPince();
    ~FermerPince() override = default;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // FermerRPINCE_H



