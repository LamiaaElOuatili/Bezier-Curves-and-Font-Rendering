#include "GlyphGenerator.h"
#include <iostream>

/**
 * @brief Génère un glyphe basé sur une lettre donnée.
 * 
 * Cette fonction crée un glyphe correspondant à la lettre spécifiée
 * en utilisant des courbes de Bézier pour définir sa forme.
 * Si la lettre n'est pas supportée, un glyphe vide est retourné.
 * 
 * @param letter La lettre (en majuscule) pour laquelle générer le glyphe.
 * @return Glyph Le glyphe généré correspondant à la lettre.
 */


Glyph generateGlyph(char letter) {
    std::vector<std::vector<Point>> curves;
    switch (letter) {
    case 'A':
        curves.push_back({Point(100, 500), Point(300, 100)});
        curves.push_back({Point(300, 100), Point(500, 500)});
        curves.push_back({Point(200, 300), Point(400, 300)});
        break;

    case 'B':
        curves.push_back({
            Point(100, 100),  
            Point(100, 500)  
        });

        // Top semi-circle
        curves.push_back({
            Point(100, 100),  
            Point(300, 200),  
            Point(100, 300)   
        });

        // Bottom semi-circle
        curves.push_back({
            Point(100, 300),
            Point(300, 400), 
            Point(100, 500)  
        });
        break;

    case 'C':
        curves.push_back({Point(300, 100), Point(50, 225), Point(300, 350)});
        break;

    case 'D':
        curves.push_back({
            Point(100, 100),
            Point(100, 500)  
        });

        curves.push_back({
            Point(100, 100),  
            Point(400, 300),  
            Point(100, 500)  
        });
        break;


    case 'E':
        curves.push_back({
            Point(100, 100), 
            Point(100, 500)
        });

        curves.push_back({
            Point(100, 100), 
            Point(400, 100) 
        });

        curves.push_back({
            Point(100, 300),  
            Point(300, 300)  
        });

        curves.push_back({
            Point(100, 500),  
            Point(400, 500)  
        });
        break;


    case 'F':

        curves.push_back({
            Point(100, 100),  
            Point(100, 500)   
        });

        curves.push_back({
            Point(100, 100),
            Point(400, 100) 
        });


        curves.push_back({
            Point(100, 300), 
            Point(300, 300) 
        });
        break;


    
    case 'G': 
        // Semi-circle from middle to bottom-right
        curves.push_back({
            Point(300, 300),  // P0: Start point
            Point(500, 433),  // P1: Control point 1
            Point(433, 500),  // P2: Control point 2
            Point(300, 500)   // P3: End point
        });

        // Semi-circle from bottom-right to middle-left
        curves.push_back({
            Point(300, 500),  // P0: Start point
            Point(167, 500),  // P1: Control point 1
            Point(100, 433),  // P2: Control point 2
            Point(100, 300)   // P3: End point
        });

        // Semi-circle from middle-left to top
        curves.push_back({
            Point(100, 300),  // P0: Start point
            Point(100, 167),  // P1: Control point 1
            Point(167, 100),  // P2: Control point 2
            Point(300, 100)   // P3: End point
        });

        // Horizontal line for the "G" opening
        curves.push_back({
            Point(250, 300),  // Start of the horizontal line
            Point(350, 300)   // End of the horizontal line
        });

        break;

    case 'H':
        // Left vertical line
        curves.push_back({
            Point(100, 100),  // Start of the left vertical line (top-left)
            Point(100, 500)   // End of the left vertical line (bottom-left)
        });

        // Right vertical line
        curves.push_back({
            Point(400, 100),  // Start of the right vertical line (top-right)
            Point(400, 500)   // End of the right vertical line (bottom-right)
        });

        // Horizontal bar in the middle
        curves.push_back({
            Point(100, 300),  // Start of the horizontal bar (middle-left)
            Point(400, 300)   // End of the horizontal bar (middle-right)
        });
        break;


    case 'I':
        // Vertical line in the center
        curves.push_back({
            Point(250, 300),  // Start of the vertical line (top-center)
            Point(250, 500)   // End of the vertical line (bottom-center)
        });

        // Optional: Top bar
        curves.push_back({
            Point(200, 300),  // Start of the top bar (top-left)
            Point(300, 300)   // End of the top bar (top-right)
        });

        // Optional: Bottom bar
        curves.push_back({
            Point(200, 500),  // Start of the bottom bar (bottom-left)
            Point(300, 500)   // End of the bottom bar (bottom-right)
        });
        break;


    case 'J':
        // Vertical line on the right
        curves.push_back({
            Point(400, 100),  // Start of the vertical line (top-right)
            Point(400, 400)   // End of the vertical line (near bottom-right)
        });

        // Semi-circle at the bottom
        curves.push_back({
            Point(400, 400),  // Start of the semi-circle (bottom-right)
            Point(300, 500),  // Control point (center-bottom, bulging outward)
            Point(200, 400)   // End of the semi-circle (bottom-left)
        });

        // Optional: Top bar
        curves.push_back({
            Point(350, 100),  // Start of the top bar (top-left)
            Point(450, 100)   // End of the top bar (top-right)
        });
        break;


    case 'K':
        curves.push_back({Point(100, 100), Point(100, 500)});
        curves.push_back({Point(100, 300), Point(200, 100)});
        curves.push_back({Point(100, 300), Point(200, 500)});
        break;


    case 'L':
        // Vertical line on the left
        curves.push_back({
            Point(100, 100),  // Start of the vertical line (top-left)
            Point(100, 500)   // End of the vertical line (bottom-left)
        });

        // Horizontal line at the bottom
        curves.push_back({
            Point(100, 500),  // Start of the horizontal line (bottom-left)
            Point(400, 500)   // End of the horizontal line (bottom-right)
        });
        break;


    case 'M':
        // Left vertical line
        curves.push_back({
            Point(100, 100),  // Start of the left vertical line (top-left)
            Point(100, 500)   // End of the left vertical line (bottom-left)
        });

        // Right vertical line
        curves.push_back({
            Point(400, 100),  // Start of the right vertical line (top-right)
            Point(400, 500)   // End of the right vertical line (bottom-right)
        });

        // Left diagonal
        curves.push_back({
            Point(100, 100),  // Start of the left diagonal (top-left)
            Point(250, 300)   // End of the left diagonal (middle peak)
        });

        // Right diagonal
        curves.push_back({
            Point(250, 300),  // Start of the right diagonal (middle peak)
            Point(400, 100)   // End of the right diagonal (top-right)
        });
        break;


    case 'N':
        // Left vertical line
        curves.push_back({
            Point(100, 100),  // Start of the left vertical line (top-left)
            Point(100, 500)   // End of the left vertical line (bottom-left)
        });

        // Right vertical line
        curves.push_back({
            Point(400, 100),  // Start of the right vertical line (top-right)
            Point(400, 500)   // End of the right vertical line (bottom-right)
        });

        // Diagonal line
        curves.push_back({
            Point(100, 100),  // Start of the diagonal (top-left)
            Point(400, 500)   // End of the diagonal (bottom-right)
        });
        break;


    case 'O': // For the letter 'O' representing the circle
        // Quadrant 1: Top-Right
        curves.push_back({
            Point(300, 100),  // P0: Start point
            Point(433, 100),  // P1: Control point 1
            Point(500, 167),  // P2: Control point 2
            Point(500, 300)   // P3: End point
        });

        // Quadrant 2: Bottom-Right
        curves.push_back({
            Point(500, 300),  // P0: Start point
            Point(500, 433),  // P1: Control point 1
            Point(433, 500),  // P2: Control point 2
            Point(300, 500)   // P3: End point
        });

        // Quadrant 3: Bottom-Left
        curves.push_back({
            Point(300, 500),  // P0: Start point
            Point(167, 500),  // P1: Control point 1
            Point(100, 433),  // P2: Control point 2
            Point(100, 300)   // P3: End point
        });

        // Quadrant 4: Top-Left
        curves.push_back({
            Point(100, 300),  // P0: Start point
            Point(100, 167),  // P1: Control point 1
            Point(167, 100),  // P2: Control point 2
            Point(300, 100)   // P3: End point
        });
        break;



    case 'P':
        // Vertical line on the left
        curves.push_back({
            Point(100, 100),  // Start of the vertical line (top-left)
            Point(100, 500)   // End of the vertical line (bottom-left)
        });

        // Semi-circle for the top curve
        curves.push_back({
            Point(100, 100),  // Start of the semi-circle (top-left)
            Point(300, 200),  // Control point (center-right, bulging outward)
            Point(100, 300)   // End of the semi-circle (middle-left)
        });
        break;



    case 'Q':
        // Top-right quadrant of the circle
        curves.push_back({
            Point(300, 100),  // Start
            Point(433, 100),  // Control point 1
            Point(500, 167),  // Control point 2
            Point(500, 300)   // End
        });

        // Bottom-right quadrant of the circle
        curves.push_back({
            Point(500, 300),  // Start
            Point(500, 433),  // Control point 1
            Point(433, 500),  // Control point 2
            Point(300, 500)   // End
        });

        // Bottom-left quadrant of the circle
        curves.push_back({
            Point(300, 500),  // Start
            Point(167, 500),  // Control point 1
            Point(100, 433),  // Control point 2
            Point(100, 300)   // End
        });

        // Top-left quadrant of the circle
        curves.push_back({
            Point(100, 300),  // Start
            Point(100, 167),  // Control point 1
            Point(167, 100),  // Control point 2
            Point(300, 100)   // End
        });

        // Diagonal tail
        curves.push_back({
            Point(400, 400),  // Start of the tail
            Point(500, 500)   // End of the tail
        });
        break;


    case 'R':
        // Vertical line on the left
        curves.push_back({
            Point(100, 100),  // Start of the vertical line (top-left)
            Point(100, 500)   // End of the vertical line (bottom-left)
        });

        // Semi-circle for the top curve
        curves.push_back({
            Point(100, 100),  // Start of the semi-circle (top-left)
            Point(300, 200),  // Control point (center-right, bulging outward)
            Point(100, 300)   // End of the semi-circle (middle-left)
        });

        // Diagonal line
        curves.push_back({
            Point(100, 300),  // Start of the diagonal line (middle-left)
            Point(400, 500)   // End of the diagonal line (bottom-right)
        });
        break;


    case 'S':
        // Top semi-circle
        curves.push_back({
            Point(300, 100),  // Start of the top semi-circle (top-middle)
            Point(100, 200),  // Control point (left-middle, bulging outward)
            Point(300, 300)   // End of the top semi-circle (center-middle)
        });

        // Bottom semi-circle
        curves.push_back({
            Point(300, 300),  // Start of the bottom semi-circle (center-middle)
            Point(500, 400),  // Control point (right-middle, bulging outward)
            Point(300, 500)   // End of the bottom semi-circle (bottom-middle)
        });
        break;


    case 'T':
        // Vertical line in the center
        curves.push_back({
            Point(250, 100),  // Start of the vertical line (top-center)
            Point(250, 500)   // End of the vertical line (bottom-center)
        });

        // Horizontal line at the top
        curves.push_back({
            Point(150, 100),  // Start of the horizontal line (top-left)
            Point(350, 100)   // End of the horizontal line (top-right)
        });
        break;


    case 'U':
        curves.push_back({Point(100, 100), Point(100, 500)});  // Left vertical line
        curves.push_back({Point(400, 100), Point(400, 500)});  // Right vertical line
        curves.push_back({Point(100, 500), Point(250, 550), Point(400, 500)});  // Bottom curve
        break;


    case 'V':
        curves.push_back({Point(100, 100), Point(250, 500)});  // Left diagonal
        curves.push_back({Point(250, 500), Point(400, 100)});  // Right diagonal
        break;


    case 'W':
        curves.push_back({Point(100, 100), Point(100, 500)});  // Left vertical line
        curves.push_back({Point(100, 500), Point(250, 300)});  // Left diagonal
        curves.push_back({Point(250, 300), Point(400, 500)});  // Right diagonal
        curves.push_back({Point(400, 500), Point(400, 100)});  // Right vertical line
        break;


    case 'X':
        curves.push_back({Point(100, 100), Point(400, 500)});  // Left diagonal
        curves.push_back({Point(400, 100), Point(100, 500)});  // Right diagonal
        break;


    case 'Y':
        curves.push_back({Point(100, 100), Point(250, 300)});  // Left diagonal
        curves.push_back({Point(400, 100), Point(250, 300)});  // Right diagonal
        curves.push_back({Point(250, 300), Point(250, 500)});  // Vertical line
        break;


    case 'Z':
        curves.push_back({Point(100, 100), Point(400, 100)});  // Top horizontal line
        curves.push_back({Point(400, 100), Point(100, 500)});  // Diagonal line
        curves.push_back({Point(100, 500), Point(400, 500)});  // Bottom horizontal line
        break;


    default:
        // Gérer les lettres non supportées
        std::cerr << "Lettre non supportée : " << letter << std::endl;
        return Glyph(std::vector<std::vector<Point>>{}); // Glyphe vide
    }


    return Glyph(curves);
}
