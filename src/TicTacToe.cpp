#include "TicTacToe.h"

void TicTacToe::inputNumberOfPlayer()
{
    while(true)
    {
        cout << "Enter the number of players (2 or 3 or 4) : ";
        cin >> numOfPlayer;
        if(cin.good() && numOfPlayer>=2 && numOfPlayer<=4)	
        {
            break;
        }    
        cout << "\nInvalid Number of Players !\n\n";
        cin.clear();
        cin.ignore(100,'\n');  //ignores up to 100 characters and removes them from input 
    }
    cout << endl; 
}

// Initialize data for TTT
void TicTacToe::init_TTT()
{
	boardSize=numOfPlayer+1;
	dataArr.setNumOfElement(boardSize*boardSize+1);
	dataArr.init_array();
	arrLength=dataArr.getNumOfElement();
	//cout << "Size is " << arrLength << endl;
	playerTurn=getRandPlayerTurn();
}

// Get Random number for playerTurn
int TicTacToe::getRandPlayerTurn()
{
	srand (time(NULL));
	int turn=1+rand()%numOfPlayer;
	return turn;
}

// Increase playerTurn
void TicTacToe::increasePlayerTurn()
{
	if (playerTurn==numOfPlayer)
		playerTurn=1;
	else
		++playerTurn;
}

// Decrease playerTurn
void TicTacToe::decreasePlayerTurn()
{
	--playerTurn;
}

/*
i=0		      |      |      	//      |      |      	i=0 for this pattern
i=1		   1  |   2  |   3  	
i=2		______|______|______	//   1  |   2  |   3  
		      |      |      	
i=3		   4  |   5  |   6  	 
i=4		______|______|______	//______|______|______	Take this pattern as one row     
		      |      |      	//      |      |      
i=5		   7  |   8  |   9  
i=6		      |      |        	   
Draw board for TTT game
*/
void TicTacToe::drawBoard()
{
	element_count=1;
    int maxrow=boardSize*2; 
    for(int row=0; row<=maxrow; row++)
    {
        if (row!=0 && row%2==0 && row!=maxrow)
            drawPlusSignPattern();
        else if (row%2==1)
            drawNumberLinePattern();
        else
            drawLinePattern();
    }
    cout << endl;
}

// Like this pattern "      |      |      " 
void TicTacToe::drawLinePattern() const
{
    
    for(int count=1; count<=boardSize; count++)
    {
        if (count==boardSize)
        {
            cout << "      " << endl;
        }
        else
        {
            cout << "      |";
        }
    }
}
// Like this pattern "   9  |  10  |  11  |  12  "
void TicTacToe::drawNumberLinePattern()
{
    for(int count=1; count<=boardSize; count++)
    {
        cout << "  " << dataArr.getElementAt(element_count) << "  ";
        if (count==boardSize) 
            cout << endl;
        else
            cout << "|";
        element_count++;
    }
}
// Like this pattern ______|______|______|______
//					       |      |      |     
void TicTacToe::drawPlusSignPattern() const
{
    for(int count=1; count<=boardSize; count++)
    {
        cout << "______";
        if (count==boardSize) 
            cout << endl;
        else
            cout << "|";
    }
    drawLinePattern();
}

/*
-1 => contine game
 1 => Game Win
 0 => Game Withdraw
*/
//Checking which player win
int TicTacToe::checkWin(string pattern)
{
	int increase=1;
	// Condition 1 : Check Win for all rows and columns
    for (int count=1; count<=boardSize; count++, increase+=boardSize)
    {
        //Only check for one row and only one column
        if(checkRow(increase, pattern) || checkColumn(count, pattern))
           return 1;
    }   
	// Condition 2 : Check Win for two diagonals
    if (checkLeftDiagonal(1, pattern) || checkRightDiagonal(boardSize, pattern))
        return 1;
    
	//  Condition 3 : Check draw
	else if (!dataArr.isOriginalArray())	
		return 0;
	// Condition 4 : Game will continue
    else 
    	return -1;
}

//Checking Row
bool TicTacToe::checkRow(int startPoint, string pattern)
{
    for(int i=1; i<=boardSize; i++, startPoint++)
    {
        if (dataArr.getElementAt(startPoint)!=pattern)
            return false;
    }
    return true;
}

//Checking Column
bool TicTacToe::checkColumn(int startPoint, string pattern)
{
    int increase=0;
    for(int i=1; i<=boardSize; i++)
    {
    	if (i==1)
    	{
	    	if(dataArr.getElementAt(startPoint)!=pattern)
		    	return false;
	    }
        else 
        {
            startPoint+=boardSize;
            if (dataArr.getElementAt(startPoint)!=pattern)
            	return false;
        }
    }
    return true;
}

//Checking Diagonal Lines from Left
bool TicTacToe::checkLeftDiagonal(int startPoint, string pattern)
{
    int increase=0;
    for(int i=1; i<=boardSize; i++, startPoint++)
    {
        if (dataArr.getElementAt(startPoint+increase)==pattern)
            increase+=boardSize;
        else
			return false;
    }
	return true;
}

//Checking Diagonal Line from Right
bool TicTacToe::checkRightDiagonal(int startPoint, string pattern)
{
    for(int i=1; i<=boardSize; i++)
    {
    	if (i==1)
    	{
	    	if (dataArr.getElementAt(startPoint)!=pattern)
	    		return false;
	    }
	    else
	    {
	    	startPoint+=numOfPlayer;
    		if (dataArr.getElementAt(startPoint)!=pattern)
    			return false;
    	}
    }
    return true;
}

// Start playing game
void TicTacToe::play()
{
	int choice, check=-1;
	string pattern;
	do
	{
		drawBoard();
        cin.clear();
        cin.ignore(100, '\n');
		cout << "\nPlayer-" << playerTurn << "\tEnter your choice number : ";
		cin >> choice;
		// Input index is already filled by other player or out of bound
		if (!cin.good() || (choice<1 || choice>arrLength) || dataArr.isDatachanged(choice))
		{
			cout<<"\nInvalid choice !\n";
		}
		// Valid case ( range from 1 to data length)
		else
		{
			switch (playerTurn)
			{
				case 1:
					pattern="P1";
					break;
				case 2:
					pattern="P2";
					break;
				case 3:
					pattern="P3";
					break;
				case 4:
					pattern="P4";
					break;
			}
			// Fill P1 for player-1, P2 for player-2, P3 for player-3 and P4 for player-4
			dataArr.setElementAt(choice, pattern);
			check=checkWin(pattern);
			increasePlayerTurn();
			
		}
	} while (check==-1);
	drawBoard();
	if (check==0)
		cout << "Game Draw " << endl;
	else
	{
		if (pattern=="P1")
			cout << "\nPlayer-1 wins !";
		else if (pattern=="P2")
			cout << "\nPlayer-2 wins !";
		else if (pattern=="P3")
			cout << "\nPlayer-3 wins !";
		else
			cout << "\nPlayer-4 wins !";
	}
}

