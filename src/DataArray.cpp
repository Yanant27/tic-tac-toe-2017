#include "DataArray.h"
int DataArray::getNumOfElement() const
{
	return size;
}

void DataArray::setNumOfElement(int arr_size)
{
	size=arr_size;
}

vector<string> DataArray::getElementArr() const
{
	return elementArr;
}

void DataArray::init_array()
{
	for(int i=0; i<size; i++)	// if 3x3, size is (3*3 +1) = 10. It sets data from '0' to '9'.
		elementArr.push_back(intToString(i));
}

string DataArray::getElementAt(int pos) const
{
	return elementArr[pos];
}

void DataArray::setElementAt(int pos, string s)
{
	elementArr[pos]=s;
}

void DataArray::display() const
{
	for (int i=0; i<=size; i++)
		cout << elementArr[i] << "\t";
	cout << endl;
}

// Checking original data is changed or not
bool DataArray::isDatachanged(int pos)
{
	if (elementArr[pos]==intToString(pos))
		return false;
	else
		return true;
}

// Checking whether entire original array is changed or not
bool DataArray::isOriginalArray()
{
	bool unchanged=false;
	for (int i=1; i<size; i++)	
	{
		if (elementArr[i]==intToString(i))
			unchanged=true;
	}
	return unchanged;
}


// Change integer into string
string DataArray::intToString(int num)
{
	stringstream ss;
	string result;
	ss << num;
	if (num>9)
		result=ss.str();
	else
		result=" "+ss.str();
	ss.str("");	// clear contents of ss
	return result;
}