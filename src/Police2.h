#pragma once
#include "PoliceBase.h"

/**
 * @brief Classe pour dessiner des lettres avec la police 2.
 * 
 * Cette classe combine le remplissage et le dessin en gras dans une même fenêtre.
 * Chaque lettre est divisée en deux parties : la version remplie et la version en gras.
 */
class Police2 : public PoliceBase {
public:
    /**
     * @brief Constructeur de la classe Police2.
     * 
     * @param width Largeur du bitmap.
     * @param height Hauteur du bitmap.
     */
    Police2(int width, int height) : PoliceBase(width, height) {}

    /**
     * @brief Affiche une lettre en utilisant la police 2.
     * 
     * Cette méthode génère un glyphe pour la lettre spécifiée, dessine à la fois
     * son intérieur rempli et sa version en gras, et les affiche côte à côte
     * dans une même fenêtre SDL.
     * 
     * @param lettre La lettre à afficher.
     */
    void afficherLettre(char lettre) const override {

        Glyph glyph = generateGlyph(lettre);

        // Créer un bitmap principal pour le rendu final
        Bitmap bitmap(width, height);

        // Créer des bitmaps temporaires pour le remplissage et le gras
        Bitmap filledBitmap(width, height); 
        Bitmap boldBitmap(width, height);  

        // Dessiner la lettre remplie
        glyph.drawFilled(filledBitmap);

        // Dessiner la lettre en gras
        glyph.drawBold(boldBitmap, 15);

        // Copier les deux versions dans le bitmap principal
        for (int y = 0; y < bitmap.getHeight(); ++y) {
            for (int x = 0; x < (width / 2); ++x) {
                if (filledBitmap.getPixel(x, y)) {
                    bitmap.setPixel(x, y, 1); // Noir pour la partie remplie
                }
                if (boldBitmap.getPixel(x, y)) {
                    bitmap.setPixel(x + (width / 2), y, 1); // Noir pour la partie en gras
                }
            }
        }

        // Afficher le bitmap dans une fenêtre SDL
        SDL sdl(width, height, std::string("Police 2 - ").append(1, lettre).c_str());
        sdl.renderBitmap(bitmap);
        sdl.mainLoop();
    }
};

