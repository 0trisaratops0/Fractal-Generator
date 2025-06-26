🌀 Fractal Generator



A simple and interactive fractal renderer written in C using the **MLX42** graphics library.  
It supports Mandelbrot, Julia, and Burning Ship fractals with smooth coloring and real-time zoom and pan controls.


---

🚀 Usage

make

# Mandelbrot or Burning Ship
./fractal mandelbrot
./fractal burning

# Julia with required real & imaginary parts between -2.0 and 2.0
./fractal julia -0.7 0.27015

# (Optional) Provide a palette index (0–4) as 4th argument
./fractal julia -0.7 0.27015 2


---

🎮 Controls

Key / Input	Action

← ↑ ↓ →	Move view
Mouse Scroll Up	Zoom in centered on mouse pointer
Mouse Scroll Down	Zoom out centered on mouse pointer
ENTER	Switch color palette
SPACE	Cycle through Julia parameters
ESC	Exit



---

🎨 Coloring

Fractals use smooth escape-time gradients with 5 built-in color palettes. You can:

Cycle palettes anytime with ENTER

Choose a starting palette by passing an optional palette index (0–4) when running Julia

Edit or add palettes in init_palette() for custom colors

