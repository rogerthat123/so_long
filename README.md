# so\_long

so\_long is a 2D game built using the MiniLibX graphics library. This project is part of the 42 School curriculum and aims to reinforce fundamental C programming concepts, including memory management, file handling, and event-driven programming.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Files Overview](#files-overview)
- [Credits](#credits)

## Introduction

so\_long is a simple top-down game where a player moves a character through a map to collect items and reach the exit. The game uses textures for walls, background, collectibles, and the player character.

## Features

- Loads maps from a file
- Player movement using keyboard inputs
- Collision detection with walls
- Collectibles and an exit condition
- Graphical rendering using MiniLibX

## Installation

To compile and run the game, ensure you have MiniLibX installed on your system.

1. Clone the repository:

2. Compile the project:
   ```sh
   make
   ```
3. Run the game with a map file:
   ```sh
   ./so_long maps/valid4map.ber
   ```

## Usage

The game requires a valid `.ber` map file as an argument. The map must follow specific rules:

- Surrounded by walls
- Contains one player (P), at least one collectible (C), and one exit (E)

## Controls

- `W` - Move up
- `A` - Move left
- `S` - Move down
- `D` - Move right
- `ESC` - Exit the game

## Files Overview

- `main.c` - Entry point of the program, initializes the game.
- `init.c` - Loads game assets and initializes MiniLibX.
- `init_utils.c` - Handles player movement and image selection.
- `so_long.h` - Header file containing structure definitions and function prototypes.
- `Makefile` - Compilation rules for building the project.



For any issues or improvements, feel free to contribute or report them!

