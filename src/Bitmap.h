#ifndef BITMAP_H
#define BITMAP_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>

/**
 * @brief Classe représentant une grille de pixels (bitmap).
 * 
 * Permet de dessiner des points, de sauvegarder le bitmap dans un fichier au format PBM,
 * et de l'afficher dans une fenêtre SDL.
 * Les pixels sont représentés avec un entier, où des valeurs spécifiques peuvent
 * correspondre à différentes couleurs (par exemple, noir, blanc, rouge, etc.).
 */
class Bitmap {
public:
    /**
     * @brief Constructeur du bitmap.
     * 
     * Initialise un bitmap avec une largeur et une hauteur spécifiées,
     * et remplit tous les pixels avec la valeur par défaut (généralement blanc).
     * 
     * @param width Largeur du bitmap (en pixels).
     * @param height Hauteur du bitmap (en pixels).
     */
    Bitmap(int width, int height);

    /**
     * @brief Définit la couleur d'un pixel dans le bitmap.
     * 
     * Modifie la valeur d'un pixel à une position donnée dans la grille.
     * 
     * @param x Coordonnée X du pixel.
     * @param y Coordonnée Y du pixel.
     * @param color Couleur à attribuer au pixel (par exemple, 0 = blanc, 1 = noir, 2 = rouge).
     */
    void setPixel(int x, int y, int color);

    /**
     * @brief Récupère la couleur d'un pixel.
     * 
     * Retourne la valeur du pixel à une position donnée.
     * 
     * @param x Coordonnée X du pixel.
     * @param y Coordonnée Y du pixel.
     * @return int Couleur du pixel (par exemple, 0 = blanc, 1 = noir, 2 = rouge).
     */
    int getPixel(int x, int y) const;

    /**
     * @brief Sauvegarde le bitmap dans un fichier au format PBM.
     * 
     * Crée un fichier texte représentant le bitmap en utilisant la notation
     * PBM (Portable Bitmap). Cette méthode est utile pour visualiser le bitmap
     * dans un éditeur prenant en charge ce format.
     * 
     * @param filename Nom du fichier de sortie.
     */
    void saveToFile(const std::string& filename) const;

    /**
     * @brief Dessine le bitmap dans une fenêtre SDL.
     * 
     * Affiche le bitmap dans une fenêtre SDL en utilisant un renderer SDL.
     * Chaque pixel est dessiné avec la couleur appropriée selon sa valeur.
     * 
     * @param renderer Le renderer SDL utilisé pour dessiner les pixels.
     */
    void renderToSDL(SDL_Renderer* renderer) const;

    /**
     * @brief Getter pour la largeur du bitmap.
     * 
     * @return int Largeur du bitmap en pixels.
     */
    int getWidth() const;

    /**
     * @brief Getter pour la hauteur du bitmap.
     * 
     * @return int Hauteur du bitmap en pixels.
     */
    int getHeight() const;

private:
    int width;   ///< Largeur du bitmap
    int height;  ///< Hauteur du bitmap
    std::vector<std::vector<int>> pixels;  ///< Grille 2D représentant les couleurs des pixels
};

#endif
