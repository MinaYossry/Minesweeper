# CS50 2022 Final Project: Minesweeper
#### Video Demo:  https://youtu.be/bldWocYIx6A

# Description:
Minesweeper is a puzzle video game first created in the 1960s. The game generally played on Personal Computer features a table of spaces to click.

The objective is to clear a rectangular board containing hidden "mines" without detonating any of them, with help from clues about the number of neighboring mines in each field.

When selecting a space, it will either show that there are no nearby bombs, the amount of mines that are adjacent to the square, or that the player has hit a mine, and lost the game.

In this project the entry point is SFML.cpp in main() function. Firstly, it creates a "menu" object from the Menu class and draws its content on the screen, allowing the player to choose the difficulty.
Secondly, it creates a "game" object with the desired challenge parameter. Finally, it remains in execution until the player loses or wins.

# Class Game Methods:
## drawBoard()
- Draws the matrix of cells on the board.
## generateMines()
- Generate the mines in such a way that the starting cell and all adjacent cells are empty and store the location in MinesLocation.
## assignMines()
- Read the location of mines in "MinesLocation" and assign to each cell in the table.
## calculateCells()
- Count the number of mines in the surrounding cells of each cell.
## changeStatus()
- Takes mouse input from the user and applies the change based on the status of each cell.
## isValidCell()
- Makes sure the coordinates are valid cells.
## openAdjacentCells()
- Opens the cell and all its adjacent cells when the value of the cell = 0.
## startGame()
- Generation of mines and opening the first cell.
## getWidth()
- Returns the cell count in the X direction.
## getHeight()
- Returns the cell count in the Y direction.
## isLost()
- Verify whether the player has lost.
## isWin()
- Verify whether the player has won.

# Class Cell methods:
## setStatus()
- Update cell status (OPEN, CLOSED, FLAG)
## setCount()
- Determines the number of mines within the adjacent cells of the cell.
## setMine()
- Set the cell as a mine
## getCell()
- Returns the sprite of the cell
## isMine()
- Verify whether the cell is a mine.
## getCount()
- Returns the count of mines in adjacent cells
## getStatus()
- Returns the status of the cell


# Technologies used:
The entire project has been developed in C++ with the SFML framework for graphics.
# Prerequisites:
- SFML framework: https://www.sfml-dev.org/download/sfml/2.5.1/


# TODO
- Make the game more interactive
- Custom user-given grid size and number of mines
- Add elapsed time and score
- Optimize the code

# Acknowledgments
- https://en.wikipedia.org/wiki/Minesweeper_(video_game)