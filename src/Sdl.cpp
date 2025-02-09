#include "Sdl.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Constructeur de la classe SDL.
 * 
 * Initialise la bibliothèque SDL, crée une fenêtre et un renderer pour afficher des graphiques.
 * 
 * @param width Largeur de la fenêtre en pixels.
 * @param height Hauteur de la fenêtre en pixels.
 * @param title Titre de la fenêtre.
 * 
 * @throws std::runtime_error Si l'initialisation de SDL, la création de la fenêtre, ou celle du renderer échoue.
 */
SDL::SDL(int width, int height, const std::string& title)
    : window(nullptr), renderer(nullptr), isRunning(true) {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw std::runtime_error(std::string("Erreur SDL_Init : ") + SDL_GetError());
    }

    // Création de la fenêtre
    window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        throw std::runtime_error(std::string("Erreur SDL_CreateWindow : ") + SDL_GetError());
    }

    // Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        throw std::runtime_error(std::string("Erreur SDL_CreateRenderer : ") + SDL_GetError());
    }
}

/**
 * @brief Destructeur de la classe SDL.
 * 
 * Nettoie les ressources allouées, y compris le renderer, la fenêtre et arrête SDL.
 */
SDL::~SDL() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}

/**
 * @brief Rendu d'un bitmap dans la fenêtre SDL.
 * 
 * Affiche le contenu d'un bitmap sur la fenêtre SDL en dessinant chaque pixel
 * avec la couleur appropriée (blanc, noir, ou rouge).
 * 
 * @param bitmap Le bitmap à afficher.
 */
void SDL::renderBitmap(const Bitmap& bitmap) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);  // Blanc
    SDL_RenderClear(renderer);

    for (int y = 0; y < bitmap.getHeight(); ++y) {
        for (int x = 0; x < bitmap.getWidth(); ++x) {
            int pixel = bitmap.getPixel(x, y);
            if (pixel == 1) { // Noir
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            } else if (pixel == 2) { // Rouge
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
            } else { // Blanc
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            }
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    SDL_RenderPresent(renderer);
}

/**
 * @brief Boucle principale pour gérer les événements SDL.
 * 
 * Maintient la fenêtre active jusqu'à ce que l'utilisateur décide de quitter.
 * Gère les événements SDL tels que la fermeture de la fenêtre.
 */
void SDL::mainLoop() {
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }
        SDL_Delay(16);  // Pour limiter l'utilisation du CPU (~60 FPS)
    }
}

