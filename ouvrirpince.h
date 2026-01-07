#ifndef OUVRIRPINCE_H
#define OUVRIRPINCE_H
#include "actionrobot.h"
#include "contexterobot.h"

class OuvrirPince : public ActionRobot
{
private:

public:
    OuvrirPince();
    ~OuvrirPince() override = default;

    void executer(ContexteRobot& ctx) override;
    void afficherNom() const override;
};

#endif // OUVRIRPINCE_H



