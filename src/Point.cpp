#include "Point.h"

/**
 * Constructeur du point.
 * Initialise les coordonnées x et y.
 */
Point::Point(float x, float y) : x(x), y(y) {}

/**
 * Destructeur du point.
 * Rien de particulier à gérer ici, mais inclus pour la complétude.
 */
Point::~Point() {}

/**
 * Getter pour la coordonnée X.
 * @return La valeur de X.
 */
float Point::getX() const {
    return x;
}

/**
 * Getter pour la coordonnée Y.
 * @return La valeur de Y.
 */
float Point::getY() const {
    return y;
}

/**
 * Setter pour la coordonnée X.
 * @param x La nouvelle valeur de X.
 */
void Point::setX(float x) {
    this->x = x;
}

/**
 * Setter pour la coordonnée Y.
 * @param y La nouvelle valeur de Y.
 */
void Point::setY(float y) {
    this->y = y;
}

/**
 * Interpolation linéaire entre deux points.
 * @param p1 Le premier point.
 * @param p2 Le deuxième point.
 * @param t Le facteur d'interpolation.
 * @return Un point interpolé.
 */
Point Point::interpolation(const Point& p1, const Point& p2, float t) {
    return Point(
        p1.x + t * (p2.x - p1.x),
        p1.y + t * (p2.y - p1.y)
    );
}
