
#include <string>
#include <map>
#include "board.hpp"

// Welcomes the players to the game
void welcome_message() {
    cout << "WELCOME TO:" << endl;
    cout << "######## ####  ######     ########    ###     ######     ########  #######  ######## " << endl;
    cout << "   ##     ##  ##    ##       ##      ## ##   ##    ##       ##    ##     ## ##       " << endl;
    cout << "   ##     ##  ##             ##     ##   ##  ##             ##    ##     ## ##       " << endl;
    cout << "   ##     ##  ##             ##    ##     ## ##             ##    ##     ## ######   " << endl;
    cout << "   ##     ##  ##             ##    ######### ##             ##    ##     ## ##       " << endl;
    cout << "   ##     ##  ##    ##       ##    ##     ## ##    ##       ##    ##     ## ##       " << endl;
    cout << "   ##    ####  ######        ##    ##     ##  ######        ##     #######  ######## " << endl;
    cout << "Demo version" << endl;
}

// Outputs the help message
// TODO: ENTER TO MOVE ON
void help_message() {
    cout << endl << endl;
    cout << "********** HELP **********" << endl;
    cout << "RULES:" << endl;
    cout << "   This game is played on a 3x3 board between two players. One player is X, and the other is O. The objective" << endl <<
            "       of this game is to get 3 in a row. After one player goes, the other player goes. This game continues until" << endl <<
            "       one player gets three of their marks to form a straight line or until the game is full." << endl;
    cout << endl;
    cout << "THE BOARD:" << endl;
    cout << endl;
    cout << "    0   1   2 " << endl;
    cout << " 0    |   |   " << endl;
    cout << "   ---+---+---" << endl;
    cout << " 1    |   |   " << endl;
    cout << "   ---+---+---" << endl;
    cout << " 2    |   |   " << endl;
    cout << endl;
    cout << "Example input:" << endl;
    cout << "   Player 1 > 0 1" << endl;
    cout << endl;
    cout << "Result: " << endl << endl;
    cout << "    0   1   2 " << endl;
    cout << " 0    | X |   " << endl;
    cout << "   ---+---+---" << endl;
    cout << " 1    |   |   " << endl;
    cout << "   ---+---+---" << endl;
    cout << " 2    |   |   " << endl;
    cout << "Press [ENTER] to continue " << flush;
    cout << endl;
}
// " << b(0,0) << " " << b(0,0) << " " << b(0,0) << "

// DONE: CHECK THE WIN OF EACH PLAYER AFTER THEY GO
// DONE: Optimise this function to use less code (?)
// TODO: Integrate this into the board class


// The actual game
// Find it and do it.
void play_game() {
    board ttt_board;
    cout << endl;
    cout << endl;

    // Will be initialised to something in the loop before it breaks.
    // This will determine who wins or if it is a draw.
    string winner;

    // GAME LOOP
    while(true) {

        ttt_board.draw_board();
        int i;
        int j;

        // PLAYER 1 GOES
        cout << "Player 1 > ";
        
        cin >> i;
        cin >> j;

        while(!ttt_board.valid_move(i, j)) {
            cout << "Player 1 > ";
            cin >> i;
            cin >> j;
        }
        cout << "Valid move" << endl;

        ttt_board(i, j) = cell('X');
        if(ttt_board.check_victory('X')) {
            winner = "P1";
            break;
        }
        if(!(ttt_board.moves_left())) {
            winner = "FULL";
            break;
        }

        // Player 2 goes
        ttt_board.draw_board();

        cout << "Player 2 > ";
        cin >> i;
        cin >> j;

        
        while(!ttt_board.valid_move(i, j)) {
            cout << "Player 2 > " << endl;
            cin >> i;
            cin >> j;
        }

        ttt_board(i, j) = cell('O');
        if(ttt_board.check_victory('O')) {
            winner = "P2";
            break;
        }
        if(!(ttt_board.moves_left())) {
            winner = "FULL";
            break;
        }

    }
    ttt_board.draw_board();
    if(winner == "P1") {
        cout << "Player 1 wins!" << endl;
    } else if(winner == "P2") {
        cout << "Player 2 wins!" << endl;
    } else {
        cout << "DRAW! No more moves." << endl;
    }

}

// What will actually run the program
void start_program() {
    cout << "MAIN MENU: " << endl;
    cout << "   play" << endl;
    cout << "   help" << endl;
    cout << "   quit" << endl;
    cout << "menu selection > ";
    string input;
    cin >> input;

    while(input != "quit") {
        if(input == "help") {
            help_message();
        } else if(input == "play") {
            while(true) {
                play_game();
                cout << "Do you wish to play again? (y/n) > ";
                char choice;
                cin >> choice;
                if(choice == 'n') {
                    break;
                }
            }
        } else {
            cout << "ERROR: '" << input << "' is not a valid command. Try again." << endl;
        }
        cout << "MAIN MENU: " << endl;
        cout << "   play" << endl;
        cout << "   help" << endl;
        cout << "   quit" << endl;
        cout << "menu selection > ";
        cin >> input;

    }
}

// Main function
int main () {
    // system("clear");
    welcome_message();
    cout << "\n\n\n" << endl;

    start_program();

    return 0;
}