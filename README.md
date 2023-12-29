# 2048 Terminal Game

A simple implementation of the classic 2048 game in C, designed to run in the terminal.

## Table of Contents

- [Features](#features)
- [How to Play](#how-to-play)
- [Requirements](#requirements)
- [Build and Run](#build-and-run)
- [Credits](#credits)
- [License](#license)

## Features

- Classic 2048 gameplay in the terminal.
- Responsive arrow key controls.
- Score tracking.
- Ability to undo one move.

## How to Play

The goal of the game is to combine number tiles by moving them in different directions using arrow keys, with the objective of reaching the tile with the value of 2048. When two tiles with the same value collide during a move, they merge into a new tile with the sum of their values. After each move, a new tile (either 2 or 4) will appear in an empty spot on the board. The game continues until there are no empty spots left on the board, and the player can no longer make valid moves, resulting in the game coming to an end.

## Requirements

- GNU Make
- C compiler (GCC or Clang)

## Build and Run

1. Clone the repository:
2. Navigate to the project directory:
3. Build the game:
4. Run the game:

    ```bash
    git clone https://github.com/your-username/2048-terminal-game.git
    cd 2048-terminal-game
    make
    ./bin/2048
    ```
5. Use arrow keys to play, and enjoy the game!

## Credits

This project is inspired by and incorporates ideas from the following project:

- [mevdschee/2048.c](https://github.com/mevdschee/2048.c)
- [alewmoose/2048-in-terminal](https://github.com/alewmoose/2048-in-terminal)


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.