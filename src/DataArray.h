#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class DataArray
{
	private:
		int size;
		vector<string> elementArr;
	public:
		int getNumOfElement() const;
		void setNumOfElement(int);
		vector<string> getElementArr() const;
		void init_array();
		string getElementAt(int) const;
		void setElementAt(int, string);
		void display() const;
		bool isDatachanged(int);
		bool isOriginalArray() ;
		string intToString(int);
};