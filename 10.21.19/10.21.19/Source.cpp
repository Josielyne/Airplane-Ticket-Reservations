#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
using namespace std;
// Function to display plane and seats available/unavailable
void DisplayPlane(int s[4][27])
{
	const int rows = 4;
	const int cols = 27;
	char RowName[] = { 'A','B','C','D' };
	cout << "                                \\            \\" << endl;
	cout << "                                 \\            \\" << endl;
	cout << "                                  \\            \\" << endl;
	cout << "-----------------------------------------------------------------------------------\\\\" << endl;
	cout << "------------------------------------------------------------------------------------\\\\" << endl;
	cout << "  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27" << endl;
	for (int row = 0; row < rows; row++)
	{
		cout << RowName[row] << " ";
		for (int col = 0; col < cols; col++)
		{
			if (s[row][col] == 0)
				cout << char(219) << "  ";
			else if (s[row][col] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				cout << "X";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
				cout << "  ";
			}
		}
		cout << endl << endl;

	}
	cout << "------------------------------------------------------------------------------------//" << endl;
	cout << "-----------------------------------------------------------------------------------//" << endl;
	cout << "                                  /            /"  << endl;
	cout << "                                 /            / " << endl;
	cout << "                                /            /" << endl;
}
// Function to display menu options
void DisplayMenu()
{
	cout << "Welcome to GG Airlines! Thank you for choosing us as your desginated flight provider!" << endl;
	cout << "What would you like to do today? :)" << endl;
	while (1)
	{
		cout << "1) Reserve Seats" << endl;
		cout << "2) Cancel Reservation" << endl;
		cout << "3) Reservation List" << endl;
		cout << "4) Number of Seats Reserved" << endl;
		cout << "5) Number of Empty Seats" << endl;
		break;
	}

}
// Function that reads user's input from menu
int ReadOption()
{
	int answer;
	cin >> answer;
	cin.ignore();
	return answer;
}
// Function that executes user's choice from menu
void ExecuteOption(int answer, int s[4][27], string n[4][27])
{
	static int val = 0;
	static int c;
	static char r;
	static string name;
	if (answer == 1)
	{
		// reads name and seat number to make a reservation
		cout << "Enter your name" << endl;
		getline(cin, name);
		cout << "Enter the seat you want reserved" << endl;
		cin >> r >> c;
		s[r - 65][c - 1] = 1;
		n[r - 65][c - 1] = name;
		cout << "Seat " << r << c << " Reserved! :D" << endl;
		val++;
	}
	else if (answer == 2)
	{
		// reads seat number to cancel reservation
		cout << "To cancel your reservation, enter the seat you want canceled" << endl;
		cin >> r >> c;
		s[r - 65][c - 1] = 0;
		cout << "Your reservation has been canceled successfully!" << endl;
		system("pause");
		val--;
	}
	else if (answer == 3)
	{
		// displays list of people who reserved seats and the seats they reserved
		cout << n[r - 65][c - 1] << ", your seat, " << r << c << " is reserved." << endl;
		system("pause");
	}
	else if (answer == 4)
	{
		// prints how many seats are taken
		cout << "There are " << val << " seat(s) reserved" << endl;
	}
	else if (answer == 5)
	{
		// prints how many seats are available
		cout << "There are " << 4 * 27 - val << " seat(s) open" << endl;
	}
}
void main()
{
	// Arary of seats in plane created
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
	system("cls");
	const int rows = 4;
	const int cols = 27;
	string names[4][27] = { " " };
	int seats[rows][cols] =
	{
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },

	};
	int answer;
	// call functions
	while (1)
	{
		DisplayPlane(seats);
		DisplayMenu();
		answer = ReadOption();
		ExecuteOption(answer, seats, names);

	}
	system("pause");
}
