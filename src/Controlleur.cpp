#include "Controlleur.hpp"

#include <CrcLib.h>

#include "utils.hpp"

void Controlleur::update(const Actions& actions, US deltaTime)
{
    //actions.print();
    (void)deltaTime;
    this->gererMouvement(actions);
    this->gererDELs();
}

void Controlleur::gererMouvement(const Actions& actions)
{
    const int16_t avant = actions.avant;
    const int16_t lacet = actions.lacet;
    const int16_t lateral = actions.lateral;

    const int8_t min = ROUES_VITESSE_MIN;
    const int8_t max = ROUES_VITESSE_MAX;
    const int8_t avantGauche = utils::conversionClamp(avant - lacet - lateral, min, max);
    const int8_t arriereGauche = utils::conversionClamp(avant - lacet + lateral, min, max);
    const int8_t avantDroite = utils::conversionClamp(avant + lacet + lateral, min, max);
    const int8_t arriereDroite = utils::conversionClamp(avant + lacet - lateral, min, max);

    CrcLib::SetPwmOutput(ROUE_AVANT_GAUCHE_PIN, avantGauche);
    CrcLib::SetPwmOutput(ROUE_ARRIERE_GAUCHE_PIN, arriereGauche);
    CrcLib::SetPwmOutput(ROUE_AVANT_DROITE_PIN, avantDroite);
    CrcLib::SetPwmOutput(ROUE_ARRIERE_DROITE_PIN, arriereDroite);
}

void Controlleur::gererDELs(){
    const bool limitOuvertureMax = CrcLib::GetDigitalInput(OUVERTURE_FOURCHE_LIMIT_SWITCH_MAX);
    CrcLib::SetDigitalOutput(DEL_ROUGE_1, limitOuvertureMax);
    CrcLib::SetDigitalOutput(DEL_ROUGE_2, limitOuvertureMax);
    const bool limitOuvertureMin = !CrcLib::GetDigitalInput(OUVERTURE_FOURCHE_LIMIT_SWITCH_MIN);
    CrcLib::SetDigitalOutput(DEL_BLANCHE_1, limitOuvertureMin);
    CrcLib::SetDigitalOutput(DEL_BLANCHE_2, limitOuvertureMin);
    
    const bool avantGauche = (20 < CrcLib::GetAnalogInput(AVANT_GAUCHE_LIMIT_SWITCH));
    const bool avantDroite = (20 < CrcLib::GetAnalogInput(AVANT_DROITE_LIMIT_SWITCH));
    CrcLib::SetDigitalOutput(
        DEL_VERT_2,
        avantGauche
    );
    CrcLib::SetDigitalOutput(
        DEL_VERT_1,
        avantDroite
    );
}