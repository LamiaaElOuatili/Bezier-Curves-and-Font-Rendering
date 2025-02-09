#ifndef GLYPH_GENERATOR_H
#define GLYPH_GENERATOR_H

#include "Glyph.h"

/**
 * @brief Génère un glyphe pour une lettre donnée.
 * 
 * Cette fonction crée un glyphe correspondant à la lettre spécifiée
 * en utilisant des courbes de Bézier pour définir sa forme.
 * 
 * @param letter La lettre (en majuscule) pour laquelle générer le glyphe.
 * @return Glyph Le glyphe généré correspondant à la lettre.
 */
Glyph generateGlyph(char letter);

#endif

