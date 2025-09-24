# Bézier Curves and Font Rendering in C++

## Project Overview   
The goal of this project is to design a **C++ program** that generates glyphs corresponding to uppercase letters of the alphabet in three distinct styles:  

1. **Black outline**  
2. **Filled + Bold**  
3. **Red outline**  

Rendering is implemented using the **SDL2 library**.    


## Features  
- Implementation of **Bézier curves** (linear, quadratic, and generic) using the **De Casteljau algorithm**.  
- Object-oriented design with modular, maintainable code.  
- Glyph generation for **all uppercase letters of the alphabet**.  
- Three rendering styles:  
  - 🖤 Black outline  
  - 🖤 Filled with a **bold** version displayed side by side  
  - ❤️ Red outline  


## Design & Architecture  

### Bézier Curves  
- **Linear curves** → Straight segments between two points.  
- **Quadratic curves** → Defined by three points (two endpoints + one control point).  
- **De Casteljau algorithm** → Iterative linear interpolation between control points until sufficient precision is reached.  

### Glyphs  
- Each uppercase letter is defined by one or more Bézier curves.  
- Example:  
  - **A** = two slanted segments + one horizontal bar.  
  - **O** = approximated with four quadratic Bézier curves forming an ellipse.  



### Compilation  
```bash
g++ -g -Wall -Wextra -o prog *.cpp $(pkg-config --cflags --libs sdl2)


