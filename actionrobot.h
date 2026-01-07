#ifndef ACTIONROBOT_H
#define ACTIONROBOT_H

#include "contexterobot.h"
class ActionRobot {
public:
    virtual ~ActionRobot() = default;
    virtual void executer(ContexteRobot& ctx) = 0; // méthode virtuelle pure, ce qui fait de la classe ActionRobot une classe abstraite (qui ne peut être instanciée)
    virtual void afficherNom() const;
};


#endif // ACTIONROBOT_H
