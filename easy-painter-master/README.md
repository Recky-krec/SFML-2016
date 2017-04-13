## easy-painter
A simple C++ painting application. You have multiple colors and configurable pen sizes.

## Dependencies:
- SFML 2.4

## Installing Dependencies:
1º Download library: http://www.sfml-dev.org/download/sfml/2.4.2
- Linux
  
  2º Extract the file and move the folder "SFML" which path is "(extracted library folder path)/include/SFML" to /usr/include
  
  3º Rename "lib" folder by "SFML_LIB" and move it to /usr/lib
 
## Building with SFML in Linux:
``g++ -c main.cpp FrameEngine.cpp Pen.cpp -I /usr/include``

``g++ main.o FrameEngine.o Pen.o -o easy-painter -lsfml-graphics -lsfml-window -lsfml-system``

## Usage:
- Up: Change colors up
- Down: Change colors down
- Left: Cleans screen with white
- Right: Cleans screen with black
- Mouse left: Paints
- Mouse wheel up: Increments pen trace size
- Mouse wheel down: Decrements pen trace size

## Tips:
If you want to change the background to a different color then white or black, increment your pen size a lot, choose one of the ten colors and fill the background with it.

There is no eraser in this program. You are presented with 10 different colors, so, if you want to erase something, you will need to select the same color as the background have and "erase" with it.
## Setting program frame rate.
Uncomment line 17 in main.cpp and feel free to change the standard value: 60; Change to whatever you want.
