// C++ program to illustrate the
// above concepts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 3
#define M 3

class abhi
{
public:
	int data;
private:
}
// Matrix Class
class Matrix {
private:
	int arr[N][M];

public:
	// Overloading of input stream
	friend istream& operator>>(
		istream&, Matrix&);

	// Overloading of output stream
	friend ostream& operator<<(
		ostream&, Matrix&);
	int& operator()(int, int);
};

// Function to overload the input
// ">>" operator
istream& operator>>(istream& cin,
					Matrix& m)
{
	int x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// Overloading operator()
			// to take input
			cin >> m(i, j);
		}
	}
	return cin;
}

// Function to overload the output
// "<<" operator
ostream& operator<<(ostream& cout,
					Matrix& m)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			// Overloading operator() to
			// take input m.operator()(i, j);
			cout << m(i, j) << " ";
		}
		cout << endl;
	}
	return cout;
}

// Function to call the operator
// function to overload the operators
int& Matrix::operator()(int i, int j)
{
	return arr[i][j];
}

// Driver Code
int main()
{
	Matrix m;
	int var=5;
	printf("Input the matrix:\n");

	// Compiler calls operator >> and
	// passes object cin and object m
	// as parameter operator>>(cin, m);
	cin >> m;

	printf("The matrix is:\n");
	// Compiler calls operator << and
	// passes object cout and object m
	// as parameter operator<<(cin, m);
	cout << m;
	var = m(3,3);
	return 0;
}
