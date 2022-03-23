// ABOUT THIS FILE
// This is the class file that will be used as part of the TicTacToe game design.

#include <iostream>

using namespace std;

const short N = 3;
const char EMPTY = ' ';
const char X = 'X';
const char O = 'O';

// This is what each box in the TicTacToe game will be.
struct cell {
    bool taken;
    char spot;

    cell() {
        taken = false;
        spot = EMPTY;
    }

    cell(char mySpot) {
        taken = true;
        spot = mySpot;
    }
};

class board {
    private:

        // The game board. 
        cell** grid;

        // Private function made to avoid code repitition
        // Purpose is to allocate the memory for the game board and initialise it.
        void _create() {
            grid = new cell*[N];
            for(int i = 0; i < N; i++) {
                grid[i] = new cell[N];
            }

        }

        // Private member function to avoid code repitition
        // Purpose is to deallocate the memory for the game board.
        void _destroy() {
            for (int i = 0; i < N; i++) {
                delete[] grid[i];
            }
            delete[] grid;
            grid = nullptr;

        }

    public:

        // The constructor
        board() {
            _create();
        }

        board(const board& other) {
            this->_create();

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    this->grid[i][j] = other.grid[i][j];
                }
            }

        }

        // destructor
        ~board() {
            _destroy();
        }

        cell& operator()(int i, int j) {
            if ((i >= N) || (i < 0)) {
                throw out_of_range("operator() out of range");
            }
            if ((j >= N) || (j < 0)) {
                throw out_of_range("operator() out of range");
            }

            return grid[i][j];
        }

        // Outputs the board
        // To do
        void draw_board() {
            cout << endl;
            cout << "    0   1   2 " << endl;
            cout << " 0  " << grid[0][0].spot << " | " << grid[0][1].spot << " | " << grid[0][2].spot << " " << endl;
            cout << "   ---+---+---" << endl;
            cout << " 1  " << grid[1][0].spot << " | " << grid[1][1].spot << " | " << grid[1][2].spot << " " << endl;
            cout << "   ---+---+---" << endl;
            cout << " 2  " << grid[2][0].spot << " | " << grid[2][1].spot << " | " << grid[2][2].spot << " " << endl;
            cout << endl;
        }

        // Think of it as scrapping the game board and drawing a new, empty board.
        void reset_board() {
            _destroy();
            _create();
        }

        // Given input i and j, it checks the input and the board to see if the move is valid. Returns true if it is
        // and false if it isn't.
        bool valid_move(int i, int j) {
            if ((i >= N) || (i < 0) || (j >= N) || (j < 0)) {
                cout << "ERROR: Your input can only be 0, 1, or 2. Try again." << endl;
                return false;
            }
            if(grid[i][j].taken) {
                cout << "ERROR: This space is already taken. Please choose an empty space" << endl;
                return false;
            }
            return true;
        }

        bool moves_left() {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(!grid[i][j].taken) {
                        return true;
                    }
                }
            }
            return false;
        }

        // FONE: Integrate victory function
        bool check_victory(char f) {
             // Check each row for a win.
            for(int i = 0; i < N; i++) {
                // If this is taken AND it equals 
                if((grid[i][0].taken) && (grid[i][0].spot == f)) {
                    if((grid[i][1].taken) && (grid[i][1].spot == f)) {
                        if((grid[i][2].taken) && (grid[i][2].spot == f)) {
                            return true;
                        }
                    }
                }
            }

            // Check each column for a win
            for(int i = 0; i < N; i++) {
                if((grid[0][i].taken) && (grid[0][i].spot == f)) {
                    if((grid[1][i].taken) && (grid[1][i].spot == f)) {
                        if((grid[2][i].taken) && (grid[2][i].spot == f)) {
                            return true;
                        }
                    }
                }
            }

            // Check both diagonal ways
            // Check one way
            if((grid[0][0].taken) && (grid[0][0].spot == f)) {
                if((grid[1][1].taken) && (grid[1][1].spot == f)) {
                    if((grid[2][2].taken) && (grid[2][2].spot == f)) {
                        return true;
                    }
                }
            }
            
            // Check the other way
            if((grid[0][2].taken) && (grid[0][2].spot == f)) {
                if((grid[1][1].taken) && (grid[1][1].spot == f)) {
                    if((grid[2][0].taken) && (grid[2][0].spot == f)) {
                        return true;
                    }
                }
            }

            return false;
        }

    // End of public
};