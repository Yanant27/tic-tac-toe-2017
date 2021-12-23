#include "TicTacToe.h"
int main()
{
	char ch;
    bool invalid=true;
	do 
	{
        system("cls");
		TicTacToe ttt;
		ttt.inputNumberOfPlayer();
		ttt.init_TTT();
		ttt.play();
		do
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\nDo u want to continue (y/n)? ";
			cin >> ch;
			if (cin.fail() || (tolower(ch)!='n' && tolower(ch)!='y'))
			{
				cout << "Please enter only (y) or (n)" << endl;
			}
            else    
                invalid=false;
		} while(invalid);
    } while (ch=='y');
	return 0;
}