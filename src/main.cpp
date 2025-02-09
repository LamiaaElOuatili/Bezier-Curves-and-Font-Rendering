#include "Police1.h"
#include "Police2.h"
#include "Police3.h"
#include <iostream>

/**
 * @brief Point d'entrée du programme SDL.
 * 
 * La fonction principale initialise et utilise différentes classes de police
 * pour afficher des lettres dans des styles variés : contour, rempli, et contour rouge.
 * 
 * @param argc Nombre d'arguments passés en ligne de commande.
 * @param argv Tableau des arguments passés en ligne de commande.
 * @return int Code de retour du programme (0 si succès).
 */
int main(int argc, char* argv[]) {

    // Affiche le nombre et la liste des arguments de la ligne de commande
    std::cout << "Number of arguments: " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    // Initialisation des différentes classes de police
    Police1 police1(1200, 600);  ///< Police affichant uniquement le contour.
    Police2 police2(1200, 600);  ///< Police combinant le remplissage et le gras.
    Police3 police3(1200, 600);  ///< Police avec contour rouge.

    // Affichage des lettres dans des styles différents
    police1.afficherLettre('A');  // Affiche la lettre 'A' avec un contour.
    police2.afficherLettre('A');  // Affiche la lettre 'B' remplie.
    police3.afficherLettre('A');  // Affiche la lettre 'C' avec un contour rouge.

    return 0;
}
