#ifndef POLICEBASE_H
#define POLICEBASE_H

#include "Glyph.h"
#include "Bitmap.h"
#include "Sdl.h"
#include "GlyphGenerator.h"

/**
 * @brief Classe de base pour les différentes polices de caractères.
 * 
 * Cette classe définit une interface commune pour afficher des lettres
 * dans différents styles de police. Les classes dérivées doivent implémenter
 * la méthode abstraite `afficherLettre`.
 */
class PoliceBase {
protected:
    int width;   ///< Largeur du bitmap.
    int height;  ///< Hauteur du bitmap.

public:
    /**
     * @brief Constructeur de la classe PoliceBase.
     * 
     * Initialise la largeur et la hauteur du bitmap pour le rendu.
     * 
     * @param width Largeur du bitmap.
     * @param height Hauteur du bitmap.
     */
    PoliceBase(int width, int height) : width(width), height(height) {}

    /**
     * @brief Destructeur virtuel.
     * 
     * Garantit que les destructeurs des classes dérivées sont appelés correctement.
     */
    virtual ~PoliceBase() = default;

    /**
     * @brief Méthode abstraite pour afficher une lettre.
     * 
     * Cette méthode doit être implémentée par les classes dérivées pour dessiner
     * une lettre spécifique dans le style de police correspondant.
     * 
     * @param lettre La lettre à afficher.
     */
    virtual void afficherLettre(char lettre) const = 0;
};

#endif
