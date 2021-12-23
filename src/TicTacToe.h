#include <ctime>	// for time()
#include <cstdlib>	// for srand() and rand()
#include "DataArray.h"

static int element_count=1;

class TicTacToe
{
	private:
		DataArray dataArr;
		int arrLength;
		int playerTurn;
		int numOfPlayer;
		int boardSize;
	public:
		void inputNumberOfPlayer();
		void init_TTT();
		int getRandPlayerTurn();
		void increasePlayerTurn();
		void decreasePlayerTurn();
		void drawBoard();
	    void drawLinePattern() const;
	    void drawNumberLinePattern();
	    void drawPlusSignPattern() const;	
		int checkWin(string);
		bool checkRow(int, string);
		bool checkColumn(int, string);
		bool checkLeftDiagonal(int, string);
		bool checkRightDiagonal(int, string);
		void play();		
};