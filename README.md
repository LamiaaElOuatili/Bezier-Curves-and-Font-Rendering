# Bézier Curves and Font Rendering in C++

## Project Overview   
The goal of this project is to design a **C++ program** that generates glyphs corresponding to uppercase letters of the alphabet in three distinct styles:  

1. **Black outline**  
2. **Filled + Bold**  
3. **Red outline**  

Rendering is implemented using the **SDL2 library**.    

## What are Bézier Curves?  
Bézier curves are **mathematical curves** widely used in **computer graphics, design, and typography**. They were introduced by the French engineer **Pierre Bézier** in the 1960s for car body design at Renault.  

- A Bézier curve is defined by a set of **control points**:  
  - **Linear Bézier curve** → a straight line between 2 points.  
  - **Quadratic Bézier curve** → defined by 3 points (two endpoints and one control point).  
  - **Cubic Bézier curve** → defined by 4 points (two endpoints and two control points).
 
  <img width="718" height="231" alt="image" src="https://github.com/user-attachments/assets/83762fc8-0eb5-4529-8229-ef766f68a983" />


- The curve’s shape is influenced by its control points but only passes through the **endpoints**.  

- They are computed using the **De Casteljau algorithm**, which relies on repeated **linear interpolation** until the curve is fully defined.  

Bézier curves are the foundation of **vector graphics, TrueType fonts, and scalable digital typography**, since they allow smooth scaling without pixelation. 

## Features of the program
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


