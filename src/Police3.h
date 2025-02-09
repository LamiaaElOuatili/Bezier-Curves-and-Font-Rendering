#pragma once
#include "PoliceBase.h"

/**
 * @brief Classe pour dessiner des lettres avec la police 3.
 * 
 * Cette classe utilise la méthode `drawWithRedOutline` pour dessiner les lettres
 * avec un contour rouge épais.
 */
class Police3 : public PoliceBase {
public:
    /**
     * @brief Constructeur de la classe Police3.
     * 
     * @param width Largeur du bitmap.
     * @param height Hauteur du bitmap.
     */
    Police3(int width, int height) : PoliceBase(width, height) {}

    /**
     * @brief Affiche une lettre en utilisant la police 3.
     * 
     * Cette méthode génère un glyphe pour la lettre spécifiée, applique un contour
     * rouge épais à la lettre, et l'affiche dans une fenêtre SDL.
     * 
     * @param lettre La lettre à afficher.
     */
    void afficherLettre(char lettre) const override {
        Bitmap bitmap(width, height);
        Glyph glyph = generateGlyph(lettre);
        glyph.drawWithRedOutline(bitmap, 15);

        SDL sdl(width, height, std::string("Police 3 - ").append(1, lettre).c_str());
        sdl.renderBitmap(bitmap);
        sdl.mainLoop();
    }
};

