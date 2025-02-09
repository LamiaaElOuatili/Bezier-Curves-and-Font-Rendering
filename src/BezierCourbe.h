#ifndef BEZIERCOURBE_H
#define BEZIERCOURBE_H

#include "Point.h"
#include <vector>

/**
 * @brief Classe utilitaire pour gérer les calculs des courbes de Bézier.
 * 
 * Cette classe utilise l'algorithme de de Casteljau pour calculer les points
 * des courbes de Bézier de différents degrés (linéaire, quadratique, générique).
 */
class BezierCourbe {

public:
    /**
     * @brief Calcul des points d'une courbe de Bézier linéaire (segment de droite).
     * 
     * @param P0 Le point de départ.
     * @param P1 Le point d'arrivée.
     * @param nb_points Nombre de points à générer pour la courbe.
     * @return std::vector<Point> Un vecteur contenant les points calculés.
     */
    static std::vector<Point> courbeLineaire(const Point& P0, const Point& P1, int nb_points);

    /**
     * @brief Calcul des points d'une courbe de Bézier quadratique.
     * 
     * @param P0 Le point de départ.
     * @param C Le point de contrôle.
     * @param P1 Le point d'arrivée.
     * @param nb_points Nombre de points à générer pour la courbe.
     * @return std::vector<Point> Un vecteur contenant les points calculés.
     */
    static std::vector<Point> courbeQuadratique(const Point& P0, const Point& C, const Point& P1, int nb_points);

    /**
     * @brief Calcul générique des points d'une courbe de Bézier de degré N.
     * 
     * Utilise l'algorithme de de Casteljau pour calculer les points d'une
     * courbe de Bézier avec une liste de points de contrôle.
     * 
     * @param controlPoints Liste des points de contrôle.
     * @param resolution Nombre de points à générer pour la courbe.
     * @return std::vector<Point> Un vecteur contenant les points calculés.
     */
    static std::vector<Point> deCasteljau(const std::vector<Point>& controlPoints, int resolution);

};

#endif
