#ifndef POINT_H // Vérifie si POINT_H n'est pas défini
#define POINT_H // Définit POINT_H

/**
 * Classe représentant un point en 2D.
 */
class Point {
public:
    /**
     * Constructeur par défaut.
     * Initialise le point à (0, 0).
     */
    Point(float x = 0.0f, float y = 0.0f);

    /**
     * Destructeur.
     */
    ~Point();

    /**
     * Getter pour la coordonnée X.
     * @return La coordonnée X.
     */
    float getX() const;

    /**
     * Getter pour la coordonnée Y.
     * @return La coordonnée Y.
     */
    float getY() const;

    /**
     * Setter pour la coordonnée X.
     * @param x La nouvelle valeur pour X.
     */
    void setX(float x);

    /**
     * Setter pour la coordonnée Y.
     * @param y La nouvelle valeur pour Y.
     */
    void setY(float y);

    /**
     * Méthode statique pour l'interpolation linéaire entre deux points.
     * @param p1 Le premier point.
     * @param p2 Le deuxième point.
     * @param t Le facteur d'interpolation (0.0 <= t <= 1.0).
     * @return Un nouveau point interpolé entre p1 et p2.
     */
    static Point interpolation(const Point& p1, const Point& p2, float t);

private:
    float x;  // Coordonnée X
    float y;  // Coordonnée Y
};

#endif
