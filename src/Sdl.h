#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include "Bitmap.h"
#include <string>

/**
 * @brief Classe pour gérer l'affichage avec SDL.
 * 
 * Cette classe encapsule les fonctionnalités de SDL pour créer une fenêtre,
 * rendre un bitmap et gérer une boucle principale d'événements.
 */
class SDL {
public:
    /**
     * @brief Constructeur pour initialiser SDL.
     * 
     * Crée une fenêtre SDL avec un renderer pour afficher des graphiques.
     * 
     * @param width Largeur de la fenêtre en pixels.
     * @param height Hauteur de la fenêtre en pixels.
     * @param title Titre de la fenêtre.
     */
    SDL(int width, int height, const std::string& title);

    /**
     * @brief Destructeur pour nettoyer SDL.
     * 
     * Libère les ressources allouées pour la fenêtre et le renderer SDL.
     */
    ~SDL();

    /**
     * @brief Rendu d'un bitmap dans la fenêtre.
     * 
     * Dessine le contenu d'un bitmap dans la fenêtre SDL à l'aide du renderer.
     * 
     * @param bitmap Le bitmap à dessiner.
     */
    void renderBitmap(const Bitmap& bitmap);

    /**
     * @brief Boucle principale pour gérer les événements.
     * 
     * Gère les événements SDL (comme la fermeture de la fenêtre) et maintient
     * la fenêtre active jusqu'à ce que l'utilisateur décide de quitter.
     */
    void mainLoop();

private:
    SDL_Window* window;      ///< Pointeur vers la fenêtre SDL.
    SDL_Renderer* renderer;  ///< Pointeur vers le renderer SDL.
    bool isRunning;          ///< Indique si la boucle principale est active.
};

#endif
