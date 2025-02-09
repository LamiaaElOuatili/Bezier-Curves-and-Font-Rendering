#ifndef GLYPH_H
#define GLYPH_H

#include "Bitmap.h"
#include <vector>
#include "BezierCourbe.h"
#include "Point.h"

/**
 * @brief Classe représentant un glyphe (caractère) composé de courbes de Bézier.
 * 
 * Permet de dessiner, remplir, ou appliquer différents styles (gras, contour rouge)
 * sur un glyphe dans un bitmap.
 */
class Glyph {
public:
    /**
     * @brief Constructeur par défaut pour un glyphe vide.
     */
    Glyph() = default;

    /**
     * @brief Constructeur initialisant le glyphe avec des courbes.
     * 
     * @param curves Un vecteur de vecteurs de points représentant les courbes de Bézier.
     */
    Glyph(const std::vector<std::vector<Point>>& curves);

    /**
     * @brief Dessine le contour du glyphe.
     * 
     * Trace les courbes de Bézier définissant le contour du glyphe dans le bitmap.
     * 
     * @param bitmap Le bitmap où dessiner le contour.
     */
    void drawContour(Bitmap& bitmap) const;

    /**
     * @brief Remplit l'intérieur du glyphe.
     * 
     * Utilise un algorithme pour remplir les pixels à l'intérieur des contours du glyphe.
     * 
     * @param bitmap Le bitmap où remplir l'intérieur du glyphe.
     */
    void fillInside(Bitmap& bitmap) const;

    /**
     * @brief Dessine le contour du glyphe en rouge.
     * 
     * Trace les courbes de Bézier définissant le contour en utilisant la couleur rouge.
     * 
     * @param bitmap Le bitmap où dessiner le contour rouge.
     */
    void drawRedContour(Bitmap& bitmap) const;

    /**
     * @brief Dessine le glyphe rempli (contour + intérieur).
     * 
     * Combine le contour et le remplissage pour dessiner un glyphe complet.
     * 
     * @param bitmap Le bitmap où dessiner le glyphe rempli.
     */
    void drawFilled(Bitmap& bitmap) const;

    /**
     * @brief Dessine le glyphe avec un effet de gras.
     * 
     * Ajoute de l'épaisseur au contour du glyphe pour produire un effet gras.
     * 
     * @param bitmap Le bitmap où dessiner le glyphe.
     * @param thickness L'épaisseur du contour (valeur par défaut : 2).
     */
    void drawBold(Bitmap& bitmap, int thickness = 2) const;

    /**
     * @brief Dessine le glyphe avec un contour rouge et un effet d'épaisseur.
     * 
     * Trace un contour rouge épais autour des courbes du glyphe.
     * 
     * @param bitmap Le bitmap où dessiner le glyphe.
     * @param thickness L'épaisseur du contour rouge (valeur par défaut : 2).
     */
    void drawWithRedOutline(Bitmap& bitmap, int thickness = 2) const;

private:
    std::vector<std::vector<Point>> curves; ///< Les courbes de Bézier définissant le glyphe.
};

#endif // GLYPH_H
