#ifndef CONFIG_HPP
#define CONFIG_HPP

/*****************************************************************************/
/* Ce fichier sert de configuration du robot. Modifiez les valeurs de ce     */
/* fichier selon vos besoins.                                                */
/*****************************************************************************/

#include <CrcLib.h>

// numéro de pin.
using Pin = uint8_t;
// microsecondes μs
using US = uint32_t;

// changer ceci de 1 ou 0 afin d'activer/désactiver le moniteur de série.
// Le moniteur de série peut causer beaucoup de latence. C'est utile pour le
// débogage mais ÇA DOIT _ABSOLUMENT_ ÊTRE DÉSACTIVÉ LORS DE LA COMPÉTITION.
#define SERIAL_ENABLE 0

/******************************************/
/*          Contrôles des roues.          */
/******************************************/

constexpr Pin ROUE_AVANT_GAUCHE_PIN = CRC_PWM_1;
constexpr Pin ROUE_AVANT_DROITE_PIN = CRC_PWM_4;
constexpr Pin ROUE_ARRIERE_GAUCHE_PIN = CRC_PWM_2;
constexpr Pin ROUE_ARRIERE_DROITE_PIN = CRC_PWM_3;
constexpr int8_t ROUES_VITESSE_MIN = -128;
constexpr int8_t ROUES_VITESSE_MAX = 90;