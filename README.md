Knight's Tour Problem
Description
This project implements the solution to the Knight's Tour problem on a 5x5 chessboard. The Knight's Tour is a classic problem in chess where the goal is to move a knight across the chessboard so that it visits every square exactly once. The project implements various functions to solve the problem, including generating valid knight moves, exploring all possible paths, and finding a valid path that covers the entire board.

Files
Header.h: Header file containing structure definitions, function prototypes, and constants.
main.c: The main program file that interacts with the user, processes input, and displays the solution.
knight_moves.c: Contains functions for generating and storing valid knight moves.
pathfinding.c: Contains functions for finding all possible knight paths and finding a valid knight path that covers all squares on the board.
display.c: Functions to display the chessboard and knight's path.
Features
Board Initialization: A 5x5 chessboard is initialized with valid knight moves for each position.
Finding All Possible Paths: Recursively explores all possible knight paths starting from a given position.
Validating Moves: The program validates if the knight's moves are within the board's limits.
Displaying the Path: Once a valid knight's path covering all squares is found, it is displayed on the chessboard.
Memory Management: The program dynamically allocates memory for storing paths and chessboard configurations, ensuring efficient memory usage.

Usage

Compile the code usingg a C compiler:


gcc -o knight_tour main.c knight_moves.c pathfinding.c display.c
Run the program:


./knight_tour
Input a starting position for the knight in the format LetterNumber (e.g., A1, C3). The program will attempt to find a valid knight's tour path that covers all squares.

Example Input:
Copy code
A1
Example Output:
rust
Copy code
Knight's Path:
A1 -> B3 -> D4 -> E2 -> C1 -> A2 -> B4 -> D5 -> E3 -> C4 -> A5 -> B2 -> D3 -> E1 -> C5 -> E4 -> D2 -> B5 -> A4 -> C3 -> E5
If no valid tour can be found, the program will display:

No knight's tour

Memory Management:

The program uses dynamic memory allocation to store the chessboard, knight moves, and paths. It ensures that allocated memory is freed after use to prevent memory leaks.

Structure Definitions
chessPos: Represents a chessboard position, consisting of a letter for the row (A-E) and a number for the column (1-5).
treeNode: Represents a position in the path tree.
pathTree: Represents the entire tree of knight's paths.
chessPosArray: Stores valid knight moves for a given position.
chessPosList: Stores a list of chess positions in the path.
Functions
validKnightMoves(): Generates and returns all valid knight moves for each position on the chessboard.
buildKnightArrayPos(): Builds an array of valid knight moves from a given position.
findAllPossibleKnightPaths(): Recursively finds all possible knight paths starting from a given position.
findKnightPathCoveringAllBoard(): Finds a knight's path that covers all the squares on the board.
display(): Displays the knight's path on the chessboard.
License
This project is licensed under the MIT License - see the LICENSE file for details.
