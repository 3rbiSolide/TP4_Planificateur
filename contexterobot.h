#ifndef CONTEXTEROBOT_H
#define CONTEXTEROBOT_H

class ContexteRobot {
private:
    double m_x, m_y, m_z;
    bool m_pince_ouverte;
    int m_angleActuel;
public:
    // Constructeur
    ContexteRobot(double p_x, double p_y, double p_z, bool p_pince_ouverte);

    // Accès lecture
    double getX();
    double getY();
    double getZ();
    bool PinceEstOuverte();
    int getAngleActuel();

    // Actions
    void deplacerVers(double p_x, double p_y, double p_z);
    void ouvrirPince();
    void fermerPince();
    void Rotation(int p_angle);

    // Affichage
    void afficherPosition();
};

#endif // CONTEXTEROBOT_H
