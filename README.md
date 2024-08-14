# So Long - A 2D Collecting Game

## Project Overview
"So Long" is a simple 2D game developed in C using the MiniLibX library. The game involves navigating through a map to collect items and find an exit. It emphasizes the use of efficient algorithms, memory management, and graphical operations in a controlled environment.

## Features
- 2D grid-based map navigation.
- Collect items and find the exit to complete levels.
- Keyboard controls for movement (W, A, S, D or Arrow Keys).
- Window management including handling minimization and closure via ESC or the close button.
- Display of movements within the game window.

## Compilation and Execution
Compile the game using the provided Makefile with the command:
```bash
make
```
Run the game with:
```bash
./so_long [map_file.ber]
```
where `[map_file.ber]` is the path to a map configuration file.

## Game Controls
- **W or Up Arrow**: Move up
- **A or Left Arrow**: Move left
- **S or Down Arrow**: Move down
- **D or Right Arrow**: Move right
- **ESC**: Exit the game

## Files and Directories
- `src/` - Contains all the C source files.
  - `animation.c`
  - `checkin_map.c`
  - `display_image.c`
  - `display_image_bonus.c`
  - `moves.c`
  - `moves_again.c`
  - `so_long.c`
  - `so_long_utils.c`
  - etc.
- `include/` - Contains all header files.
  - `so_long.h`
  - `get_next_line.h`
- `maps/` - Contains map configuration files.
  - `1337map.ber`
  - `map.ber`
  - `map1.ber`
  - etc.
- `textures/` - Contains XPM image files used as textures.
  - `astro.xpm`
  - `earth.xpm`
  - `spship.xpm`
  - etc.
- `Makefile` - For compiling the sources.

## Resources
- [MiniLibX Usage and Examples](#)
- [C Programming Resources](#)
- [Game Development Basics](#)

## Acknowledgments
- Thanks to all who provided feedback and suggestions during development.
