#include "BezierCourbe.h"
#include <cstddef>

/**
 * @brief Calcul des points d'une courbe de Bézier linéaire.
 * 
 * Calcule les points d'un segment de droite en utilisant une interpolation
 * linéaire entre deux points.
 * 
 * @param P0 Le point de départ.
 * @param P1 Le point d'arrivée.
 * @param nb_points Nombre de points à générer pour le segment.
 * @return std::vector<Point> Un vecteur contenant les points calculés.
 */
std::vector<Point> BezierCourbe::courbeLineaire(const Point& P0, const Point& P1, int nb_points) {
    std::vector<Point> points;
    for (int i = 0; i <= nb_points; ++i) {
        float t = static_cast<float>(i) / nb_points;
        points.push_back(Point::interpolation(P0, P1, t));
    }
    return points;
}

/**
 * @brief Calcul des points d'une courbe de Bézier quadratique.
 * 
 * Utilise l'algorithme de de Casteljau pour calculer les points d'une courbe
 * quadratique définie par trois points de contrôle.
 * 
 * @param P0 Le point de départ.
 * @param C Le point de contrôle.
 * @param P1 Le point d'arrivée.
 * @param nb_points Nombre de points à générer pour la courbe.
 * @return std::vector<Point> Un vecteur contenant les points calculés.
 */
std::vector<Point> BezierCourbe::courbeQuadratique(const Point& P0, const Point& C, const Point& P1, int nb_points) {
    std::vector<Point> controlPoints = {P0, C, P1};
    return BezierCourbe::deCasteljau(controlPoints, nb_points);
}

/**
 * @brief Algorithme de de Casteljau pour les courbes de Bézier de degré N.
 * 
 * Calcule les points d'une courbe de Bézier générique en utilisant
 * l'algorithme de de Casteljau pour interpoler les points de contrôle.
 * 
 * @param controlPoints Un vecteur contenant les points de contrôle.
 * @param resolution Nombre de points à générer pour la courbe.
 * @return std::vector<Point> Un vecteur contenant les points calculés.
 */
std::vector<Point> BezierCourbe::deCasteljau(const std::vector<Point>& controlPoints, int resolution) {
    std::vector<Point> points;

    for (int i = 0; i <= resolution; ++i) {
        float t = static_cast<float>(i) / resolution;

        // Créer une copie des points de contrôle pour l'itération
        std::vector<Point> tempPoints = controlPoints;

        // Appliquer l'algorithme de de Casteljau
        while (tempPoints.size() > 1) {
            std::vector<Point> nextLevel;
            for (size_t j = 0; j < tempPoints.size() - 1; ++j) {
                nextLevel.push_back(Point::interpolation(tempPoints[j], tempPoints[j + 1], t));
            }
            tempPoints = nextLevel;
        }

        // Le point restant est le point de la courbe pour le t actuel
        points.push_back(tempPoints.front());
    }

    return points;
}
