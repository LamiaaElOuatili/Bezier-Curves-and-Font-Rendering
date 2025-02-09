#ifndef POLICE1_H
#define POLICE1_H

#include "PoliceBase.h"

/**
 * @brief Classe pour dessiner des lettres avec la police 1.
 * 
 * Cette classe utilise la méthode `drawContour` pour dessiner uniquement
 * le contour des lettres sur un bitmap.
 */
class Police1 : public PoliceBase {
public:
    /**
     * @brief Constructeur de la classe Police1.
     * 
     * @param width Largeur du bitmap.
     * @param height Hauteur du bitmap.
     */
    Police1(int width, int height) : PoliceBase(width, height) {}

    /**
     * @brief Affiche une lettre en utilisant la police 1.
     * 
     * Cette méthode génère un glyphe correspondant à la lettre spécifiée,
     * dessine son contour sur un bitmap, puis affiche le résultat dans une
     * fenêtre SDL.
     * 
     * @param lettre La lettre à afficher.
     */
    void afficherLettre(char lettre) const override {
        Bitmap bitmap(width, height);
        Glyph glyph = generateGlyph(lettre);
        glyph.drawContour(bitmap);

        SDL sdl(width, height, std::string("Police 1 - ").append(1, lettre).c_str());
        sdl.renderBitmap(bitmap);
        sdl.mainLoop();
    }
};

#endif

