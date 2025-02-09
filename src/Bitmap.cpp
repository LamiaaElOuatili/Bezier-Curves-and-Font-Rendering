#include "Bitmap.h"
#include <fstream>
#include <stdexcept>
#include <iostream> // Ajoutez cette ligne

/**
 * @brief Constructeur du bitmap.
 * 
 * Initialise un bitmap avec une largeur et une hauteur spécifiées.
 * Tous les pixels sont initialisés à blanc par défaut.
 * 
 * @param width Largeur du bitmap en pixels.
 * @param height Hauteur du bitmap en pixels.
 * 
 * @throws std::invalid_argument Si la largeur ou la hauteur est <= 0.
 */
Bitmap::Bitmap(int width, int height) : width(width), height(height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("La largeur et la hauteur doivent être positives.");
    }
    // Initialiser la grille de pixels avec des pixels blancs (valeur 0)
    pixels = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}

/**
 * @brief Définit la couleur d'un pixel dans le bitmap.
 * 
 * Modifie la valeur d'un pixel à une position donnée dans la grille.
 * 
 * @param x Coordonnée X du pixel.
 * @param y Coordonnée Y du pixel.
 * @param color La couleur à attribuer au pixel :
 * - 0 : Blanc
 * - 1 : Noir
 * - 2 : Rouge
 */
void Bitmap::setPixel(int x, int y, int color) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixels[y][x] = color; // Modifier la couleur du pixel
    }
}

/**
 * @brief Récupère la couleur d'un pixel dans le bitmap.
 * 
 * Retourne la valeur du pixel à une position donnée.
 * 
 * @param x Coordonnée X du pixel.
 * @param y Coordonnée Y du pixel.
 * @return int La couleur du pixel :
 * - 0 : Blanc (par défaut si hors limites)
 * - 1 : Noir
 * - 2 : Rouge
 */
int Bitmap::getPixel(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return pixels[y][x];
    }
    return 0; // Blanc par défaut
}

/**
 * @brief Sauvegarde le bitmap dans un fichier au format PBM.
 * 
 * Enregistre le contenu du bitmap dans un fichier au format PBM (Portable Bitmap).
 * Ce format est utile pour visualiser des images monochromes dans des éditeurs
 * prenant en charge PBM.
 * 
 * @param filename Le nom du fichier de sortie.
 * 
 * @throws std::ios_base::failure Si le fichier ne peut pas être créé ou ouvert.
 */
void Bitmap::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::ios_base::failure("Impossible de créer le fichier : " + filename);
    }

    // Écrire l'en-tête du format PBM
    file << "P1\n" << width << " " << height << "\n";

    // Écrire les pixels ligne par ligne
    for (const auto& row : pixels) {
        for (int pixel : row) {
            file << (pixel ? "1 " : "0 ");
        }
        file << "\n";
    }

    file.close();
}

/**
 * @brief Dessine le bitmap dans une fenêtre SDL.
 * 
 * Affiche le contenu du bitmap dans une fenêtre SDL en utilisant un renderer.
 * Chaque pixel est dessiné avec la couleur appropriée :
 * - Blanc (0) : RGB(255, 255, 255)
 * - Noir (1) : RGB(0, 0, 0)
 * - Rouge (2) : RGB(255, 0, 0)
 * 
 * @param renderer Le renderer SDL utilisé pour dessiner les pixels.
 */
void Bitmap::renderToSDL(SDL_Renderer* renderer) const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (pixels[y][x] == 1) { // Noir
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            } else if (pixels[y][x] == 2) { // Rouge
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            } else { // Blanc
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            }
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

/**
 * @brief Retourne la largeur du bitmap.
 * 
 * @return int La largeur du bitmap en pixels.
 */
int Bitmap::getWidth() const {
    return width;
}

/**
 * @brief Retourne la hauteur du bitmap.
 * 
 * @return int La hauteur du bitmap en pixels.
 */
int Bitmap::getHeight() const {
    return height;
}
