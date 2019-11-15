#include <iostream>

using namespace std;

// Method to check if the given year is Leap year or not
bool IsLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}

// Main Method
int main()
{
	cout << "Is 2019 a Leap year ? : " << boolalpha << IsLeapYear(2019) << endl;
	cout << "Is 2020 a Leap year ? : " << boolalpha << IsLeapYear(2020) << endl;
	cout << "Is 2100 a Leap year ? : " << boolalpha << IsLeapYear(2100) << endl;
	cout << "Is 2012 a Leap year ? : " << boolalpha << IsLeapYear(2012) << endl;
}

/*

Output

Is 2019 a Leap year ? : false
Is 2020 a Leap year ? : true
Is 2100 a Leap year ? : false
Is 2012 a Leap year ? : true

*/
