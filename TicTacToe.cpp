#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;
const int PLAYER_X = 0;
const int PLAYER_O = 1;
const int MODE_EASY = 1;
const int MODE_MEDIUM = 2;
const int MODE_HARD = 3;
class Tictactoe
{
private:
int mode;
vector <char> matrix;
//create vector of character

public:
Tictactoe()
{
matrix.resize(9);
for (int i = 0; i < matrix.size(); i++)
{
matrix.at(i) = '1' + i;
}
}
void set_mode(int m)
{
mode = m;
}
//show board game
void draw_board_game()
{

for (int i = 0; i < 9; i += 3)
{
cout << "  " << matrix.at(i) << "  |  " << matrix.at(i + 1) << "  |  "
<< matrix.at(i + 2) << "  " << endl;
if (i < 6)
cout << "-----|-----|-----" << endl;
}
cout << endl;
}






//convert char to possitio
int char_to_position(char position)
{
//there are 9 character
vector <char> vec(9);

for (int i = 0; i < vec.size(); i++)
{
vec.at(i) = '1' + i;
}

for (int i = 0; i < vec.size(); i++)
{
if (position == vec.at(i))
return i;
}

return 10;
}


//check position of current call
bool is_valid_position( int pos)
{
//if there is an empty statement then this function becomes true.
if (pos < matrix.size())
{
if ((matrix.at(pos) != 'x' && matrix.at(pos) != 'o'))
return true;
else
return false;
}
else
return false;
}

//play the game
int ask_user_play()
{
//the position inputted by user.
char pos;
int index;

do
{
cout << "Please choose a position: ";
cin >> pos;
cout << endl;

index = char_to_position (pos);
} while ((!is_valid_position(index)));
return index;
}
//play the game
int ask_comp_play()
{

int index = strategy();
cout<<endl;
return index;
}
//play the game
int strategy()
{
int index = MODE_EASY;
cout << "Computer: ";
switch (mode) {
case MODE_EASY:
do
{
index = index = rand()%9;
} while ((!is_valid_position(index)));
break;
case MODE_MEDIUM:
do
{
index = index = rand()%9;
} while ((!is_valid_position(index)));
break;
case MODE_HARD:
do
{
index = index = rand()%9;
} while ((!is_valid_position(index)));
break;
default:
break;
}
return index;
}

//check winner
bool is_game_end()
{
//horizontal and  vertical check
for (int i = 0; i < 3; i++)
{
if (matrix.at(3*i) == matrix.at(3*i+1)
&& matrix.at(3*i+1) == matrix.at(3*i+2))
return true;
else if (matrix.at(i) == matrix.at(i+3) && matrix.at(i+3) == matrix.at(i+6))
return true;
}

//diagonal check.
if (matrix.at(0) == matrix.at(4) && matrix.at(4) == matrix.at(8))
return true;
else if (matrix.at(2) == matrix.at(4) && matrix.at(4) == matrix.at(6))
return true;

return false;
}


//check if there is any empty slot
bool is_full()
{
//game is a draw when 9 turns have gone by with no winner.
int x_o_counter = 0;
for (int i = 0; i < matrix.size(); i++)
{
if (matrix.at(i) == 'x' || matrix.at(i) == 'o')
x_o_counter++;
}

if(x_o_counter == 9)
return true;
else
return false;
}

void play_the_game()
{
int curPos;
int turn = PLAYER_X; // Player X is teh first main


draw_board_game();


while (!is_full() && !is_game_end())
{
if(turn==PLAYER_X)
curPos = ask_user_play();
else
curPos = ask_comp_play();

matrix.at(curPos) = (turn == PLAYER_X) ? 'x' : 'o';

//Turn player
if (!is_full() && !is_game_end())
{
if (turn == PLAYER_X)
turn = PLAYER_O;
else if (turn == PLAYER_O)
turn = PLAYER_X;
}

draw_board_game();
}

if (turn == PLAYER_X && is_game_end())
cout << "Player X (x's) wins!" << endl << endl;
else if (turn == PLAYER_O && is_game_end())
cout << "Player O (o's) wins!" << endl << endl;
else
cout << "Tie" << endl << endl;
}
};


int main()
{
/* initialize random seed: */
srand (time(NULL));
int mode;
Tictactoe game;
cout<<"Which mode you want to play? (1 for EASY)(2 for MEDIUM) (3 for HARD) "<<endl;
cin>>mode;
game.set_mode(mode);
game.play_the_game();


return 0;
}

