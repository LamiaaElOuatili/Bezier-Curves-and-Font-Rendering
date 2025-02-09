/// Glyph.cpp
#include "Glyph.h"
#include <algorithm>
#include <iostream> // Ajoutez cette ligne

/**
 * @brief Constructeur prenant les courbes de Bézier définissant le glyphe.
 * 
 * @param curves Liste des courbes de Bézier définissant le glyphe.
 */
Glyph::Glyph(const std::vector<std::vector<Point>>& curves) : curves(curves) {}

/**
 * @brief Dessine le contour du glyphe dans un bitmap.
 * 
 * Utilise l'algorithme de De Casteljau pour tracer les points des courbes
 * définissant le contour du glyphe.
 * 
 * @param bitmap Le bitmap où dessiner le contour.
 */
void Glyph::drawContour(Bitmap& bitmap) const {
    for (const auto& curve : this->curves) {
        auto points = BezierCourbe::deCasteljau(curve, 100);
        for (const auto& point : points) {
            bitmap.setPixel(static_cast<int>(point.getX()), static_cast<int>(point.getY()), true);
        }
    }
}

/**
 * @brief Remplit l'intérieur du glyphe dans un bitmap.
 * 
 * Utilise un algorithme de parité (scanline) pour remplir l'intérieur du glyphe.
 * 
 * @param bitmap Le bitmap où remplir l'intérieur.
 */
void Glyph::fillInside(Bitmap& bitmap) const {
    for (int y = 0; y < bitmap.getHeight(); ++y) {
        bool inside = false;
        for (int x = 0; x < bitmap.getWidth(); ++x) {
            if (bitmap.getPixel(x, y)) {
                inside = !inside;
            }
            if (inside) {
                bitmap.setPixel(x, y, true);
            }
        }
    }
}

/**
 * @brief Ajoute un contour rouge au glyphe dans un bitmap.
 * 
 * Trace un contour rouge autour des courbes définissant le glyphe.
 * 
 * @param bitmap Le bitmap où dessiner le contour rouge.
 */
void Glyph::drawRedContour(Bitmap& bitmap) const {
    Bitmap temp(bitmap.getWidth(), bitmap.getHeight());
    drawContour(temp);
    for (int y = 0; y < bitmap.getHeight(); ++y) {
        for (int x = 0; x < bitmap.getWidth(); ++x) {
            if (temp.getPixel(x, y)) {
                for (int dy = -2; dy <= 2; ++dy) {
                    for (int dx = -2; dx <= 2; ++dx) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < bitmap.getWidth() && ny >= 0 && ny < bitmap.getHeight()) {
                            bitmap.setPixel(nx, ny, true); // Rouge
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Dessine le glyphe en gras.
 * 
 * Épaissit les contours du glyphe en dessinant plusieurs fois autour des points
 * définissant les courbes.
 * 
 * @param bitmap Le bitmap où dessiner le glyphe.
 * @param thickness L'épaisseur du contour (par défaut : 2).
 */
void Glyph::drawBold(Bitmap& bitmap, int thickness) const {
    for (const auto& curve : curves) {
        auto points = BezierCourbe::deCasteljau(curve, 100); // Points sur la courbe
        for (const auto& point : points) {
            for (int dx = -thickness; dx <= thickness; ++dx) {
                for (int dy = -thickness; dy <= thickness; ++dy) {
                    int x = static_cast<int>(point.getX()) + dx;
                    int y = static_cast<int>(point.getY()) + dy;
                    if (x >= 0 && x < bitmap.getWidth() && y >= 0 && y < bitmap.getHeight()) {
                        bitmap.setPixel(x, y, true); // Noircir le pixel
                    }
                }
            }
        }
    }
}

/**
 * @brief Dessine le glyphe avec son intérieur rempli.
 * 
 * Remplit l'intérieur du glyphe après avoir dessiné son contour.
 * 
 * @param bitmap Le bitmap où dessiner le glyphe rempli.
 */
void Glyph::drawFilled(Bitmap& bitmap) const {
    drawContour(bitmap);

    int minX = bitmap.getWidth(), maxX = 0;
    int minY = bitmap.getHeight(), maxY = 0;

    for (const auto& curve : curves) {
        auto points = BezierCourbe::deCasteljau(curve, 100);
        for (const auto& point : points) {
            int x = static_cast<int>(point.getX());
            int y = static_cast<int>(point.getY());
            if (x >= 0 && x < bitmap.getWidth() && y >= 0 && y < bitmap.getHeight()) {
                minX = std::min(minX, x);
                maxX = std::max(maxX, x);
                minY = std::min(minY, y);
                maxY = std::max(maxY, y);
            }
        }
    }

    for (int y = minY; y <= maxY; ++y) {
        int left = -1, right = -1;
        for (int x = minX; x <= maxX; ++x) {
            if (bitmap.getPixel(x, y)) {
                if (left == -1) {
                    left = x;
                }
                right = x;
            }
        }
        if (left != -1 && right != -1 && right > left) {
            for (int x = left; x <= right; ++x) {
                bitmap.setPixel(x, y, true);
            }
        }
    }
}

/**
 * @brief Dessine le glyphe avec un contour rouge épais.
 * 
 * Ajoute un contour rouge autour des courbes du glyphe et recouvre les bords
 * avec des pixels noirs.
 * 
 * @param bitmap Le bitmap où dessiner le glyphe.
 * @param thickness L'épaisseur du contour rouge (par défaut : 2).
 */
void Glyph::drawWithRedOutline(Bitmap& bitmap, int thickness) const {
    for (const auto& curve : curves) {
        auto points = BezierCourbe::deCasteljau(curve, 100); // Points sur la courbe
        for (const auto& point : points) {
            for (int dx = -thickness; dx <= thickness; ++dx) {
                for (int dy = -thickness; dy <= thickness; ++dy) {
                    int x = static_cast<int>(point.getX()) + dx;
                    int y = static_cast<int>(point.getY()) + dy;

                    if (x >= 0 && x < bitmap.getWidth() && y >= 0 && y < bitmap.getHeight()) {
                        if (bitmap.getPixel(x, y) == 0) {
                            bitmap.setPixel(x, y, 2); // Rouge
                        }
                    }
                }
            }
        }
    }

    for (const auto& curve : curves) {
        auto points = BezierCourbe::deCasteljau(curve, 100);
        for (const auto& point : points) {
            for (int dx = -(thickness - 4); dx <= (thickness - 4); ++dx) {
                for (int dy = -(thickness - 4); dy <= (thickness - 4); ++dy) {
                    int x = static_cast<int>(point.getX()) + dx;
                    int y = static_cast<int>(point.getY()) + dy;
                    if (x >= 0 && x < bitmap.getWidth() && y >= 0 && y < bitmap.getHeight()) {
                        bitmap.setPixel(x, y, true); // Noircir le pixel
                    }
                }
            }
        }
    }
}
