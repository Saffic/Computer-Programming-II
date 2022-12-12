// Computer Programming II (in class).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

char rerun;
struct student {
	string name;
	int IDnum;
	float grade;
};

void week11_2() {
	student std1;
	do {
		cout << "Grade: ";
		cin >> std1.grade;
		while (!cin) {
			system("cls");
			cout << "Make sure to use the correct data type and try again" << endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Grade: ";
			cin >> std1.grade;
		}
	} while (!cin);
	system("cls");
	cout << "-------------------------------------" << endl;
	cout << "Student 1's profile" << endl;
	cout << "	Student name: " << std1.name << endl;
	cout << "	Student ID: " << std1.IDnum << endl;
	cout << "	Grade: " << std1.grade << endl;
	cout << "-------------------------------------" << endl;

	cin >> rerun;
}

void week12_1() {
	int x = 5;
	int* ptr = &x;
	cout << "Value of x [*ptr]: " << *ptr << endl;
	cout << "Address of x (Value of ptr) [ptr]: " << ptr << endl;
	cout << "Address of ptr [&ptr]: " << &ptr << endl;
	delete ptr;
}
void week12_2() {
		double* sales,        // To  dynamically allocate an  array 
			total = 0.0,      // Accumulator
			average;          // To hold average sales
		int numDays;          // To  hold number of  days of  sales

	 //Get  number of  days of  sales
		cout << "How many days of  sales figures do  you wish ";
		cout << "to  process ? ";
		cin >> numDays;
		//Dynamically allocate an  array large enough
		//to hold that many days of  sales amounts
		sales = new double[numDays]; // Allocate memory

		//Get the sales figures for each day 
		cout << "Enter the sales figures below. \n";
		for (int count = 0; count < numDays; count++)
		{
			cout << "Day " << (count + 1) << ":  ";
			cin >> sales[count];
		}

		//Calculate the total sales 
		for (int count = 0; count < numDays; count++)
		{
			total += sales[count];
		}


		//Calculate the average sales per day 
		average = total / numDays;

		//Display the results 
		cout << setprecision(2) << fixed << showpoint;
		cout << " \n \nTotal Sales: $ " << total << endl;
		cout << "Average Sales: $" << average << endl;

		//Free dynamically allocated memory
		delete[] sales;
		sales = 0;
}
void week12_2_challenge_func1(double *arr, int length) {
	double temp = 0;
	for (int u = 0; u < length; u++)
	{
		for (int i = 0; i < length - u -1; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}
double week12_2_challenge_func2(double *array, int length) {
	double average;
	double total = 0;
	for (int i = 0; i < length; i++) {
		total += array[i];
	}
	average = total / length;
	return average;
}
void week12_2_challenge_main() {
	int numberOfScores;
	double* testScores;
	bool invalid = false;
	cout << "Enter the amount of test scores: ";
	cin >> numberOfScores;
	testScores = new double[numberOfScores];
	for (int i = 0; i < numberOfScores; i++) {
		cout << "Score #" << i + 1 << ": ";
		cin >> testScores[i];
		if (testScores[i] < 0) invalid = true;
	}
	system("cls");
	if (invalid == false) {
		week12_2_challenge_func1(testScores, numberOfScores);
		cout << "Scores (smallest to greatest): " << endl;
		for (int i = 0; i < numberOfScores; i++) {
			cout << setprecision(2) << fixed << testScores[i] << ", ";
		}
		cout << endl << endl << "The average is " << setprecision(2) << fixed << week12_2_challenge_func2(testScores, numberOfScores) << endl;
		delete[] testScores;
	}
	else {
		cout << "Test scores entered must be greater than 0!" << endl;
	}
}
void pointer() {
	int* ip;
	ip = new int[2];
	ip[1] = 5;
	*ip = 5;
	cout << *ip << ", " << endl;
	delete ip;
}
int main()
{
	do{
		week12_2_challenge_main();				
		cout << endl << "Rerun [y/n]" << endl;
		cin >> rerun;
		system("cls");
		} while (tolower(rerun) == 'y');
}
