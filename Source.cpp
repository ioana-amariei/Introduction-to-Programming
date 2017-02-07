#include<iostream>
#include"t1.h"
#include<cassert>
#include<climits>

using namespace std;

void printMatrix(matrix mat) {
	for (unsigned i = 0; i < mat.lines; i++) {
		for (unsigned int j = 0; j < mat.columns; j++) {
			cout << mat.values[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// Tests for problem #1.
void test_invalid_isPalindrom() {
	assert(!isPalindrom(10), "invalidPalindrom(10)");
	assert(!isPalindrom(1100), "invalidPalindrom(1100)");
	assert(!isPalindrom(321), "invalidPalindrom(10)");
	assert(!isPalindrom(123), "invalidPalindrom(1100)");
}

void test_valid_isPalindrom() {
	for (int i = 0; i < 10; i++) {
		assert(isPalindrom(i), "test_valid_isPalindrom(i)");
	}

	assert(isPalindrom(11), "invalidPalindrom(11)");
	assert(isPalindrom(12321), "invalidPalindrom(10)");
	assert(isPalindrom(99599), "invalidPalindrom(1100)");
}

void test_boundaries_isPalindrom() {
	assert(isPalindrom(0), "invalidPalindrom(0)");
	assert(!isPalindrom(ULLONG_MAX), "invalidPalindrom(ULLONG_MAX)");
}

void test_isPalindrom() {
	test_valid_isPalindrom();
	test_invalid_isPalindrom();
	test_boundaries_isPalindrom();
}


// Tests for problem #2.
void test_valid_sumBinaryFigure() {
	assert(sumBinaryFigure(11) == 3, "test_valid_sumBinaryFigure");
	assert(sumBinaryFigure(5) == 2, "test_valid_sumBinaryFigure");
	assert(sumBinaryFigure(199) == 5, "test_valid_sumBinaryFigure");
}

void test_boundaries_sumBinaryFigure() {
	assert(sumBinaryFigure(0) == 0, "test_boundaries_sumBinaryFigure");
	assert(sumBinaryFigure(1) == 1, "test_boundaries_sumBinaryFigure");
	assert(sumBinaryFigure(1 << 3) == 1, "test_boundaries_sumBinaryFigure");
	assert(sumBinaryFigure(1 << 10) == 1, "test_boundaries_sumBinaryFigure");
	assert(sumBinaryFigure(1ULL << 63) == 1, "test_boundaries_sumBinaryFigure");
	assert(sumBinaryFigure(ULLONG_MAX) == 64, "test_boundaries_sumBinaryFigure");
}

void test_sumBinaryFigure() {
	test_valid_sumBinaryFigure();
	test_boundaries_sumBinaryFigure();
}

// Tests for Problem #3.
void test_valid_isLeapYear() {
	assert(isLeapYear(400), "test_valid_isLeapYear");
	assert(isLeapYear(2000), "test_valid_isLeapYear");
	assert(isLeapYear(2016), "test_valid_isLeapYear");
	assert(isLeapYear(2400), "test_valid_isLeapYear");
	assert(isLeapYear(0), "test_valid_isLeapYear");
}

void test_invalid_isLeapYear() {
	assert(!isLeapYear(1), "test_invalid_isLeapYear");
	assert(!isLeapYear(100), "test_invalid_isLeapYear");
	assert(!isLeapYear(2007), "test_invalid_isLeapYear");
	assert(!isLeapYear(2200), "test_invalid_isLeapYear");
	assert(!isLeapYear(1800), "test_invalid_isLeapYear");
}

void test_isLeapYear() {
	test_valid_isLeapYear();
	test_invalid_isLeapYear();
}

// Tests for Problem #4.
void test_valid_dayOfTheWeek() {
	assert(dayOfTheWeek(2016, 10, 1) == 6, "test_valid_dayOfTheWeek");
	assert(dayOfTheWeek(2000, 6, 25) == 7, "test_valid_dayOfTheWeek");
	assert(dayOfTheWeek(1878, 8, 19) == 1, "test_valid_dayOfTheWeek");
	assert(dayOfTheWeek(1900, 12, 31) == 1, "test_valid_dayOfTheWeek");
	assert(dayOfTheWeek(1960, 1, 1) == 5, "test_valid_dayOfTheWeek");
}

void test_dayOfTheWeek() {
	test_valid_dayOfTheWeek();
}

// Tests for Problem #5.
void test_valid_fibonnaci() {
	assert(fibonnaci(0) == 0, "test_valid_fibonnaci");
	assert(fibonnaci(1) == 1, "test_valid_fibonnaci");
	assert(fibonnaci(2) == 1, "test_valid_fibonnaci");
	assert(fibonnaci(5) == 5, "test_valid_fibonnaci");
	assert(fibonnaci(7) == 13, "test_valid_fibonnaci");
	assert(fibonnaci(10) == 55, "test_valid_fibonnaci");
	assert(fibonnaci(12) == 144, "test_valid_fibonnaci");
}

void test_fibonnaci() {
	test_valid_fibonnaci();
}

// Tests for Problem #6.
void test_valid_perfectNumbers() {
	for (int i = 30; i <= 496; i++) {
		assert(perfectNumbers(i) == 34, "test_valid_perfectNumbers");
	}

	assert(perfectNumbers(497) == 524, "test_valid_perfectNumbers");
	assert(perfectNumbers(5674) == 524, "test_valid_perfectNumbers");
	assert(perfectNumbers(7654) == 524, "test_valid_perfectNumbers");
	assert(perfectNumbers(8128) == 524, "test_valid_perfectNumbers");

	assert(perfectNumbers(8167) == 8624, "test_valid_perfectNumbers");
	assert(perfectNumbers(17567) == 8624, "test_valid_perfectNumbers");
}

void test_perfectNumbers() {
	test_valid_perfectNumbers();
}

// Tests for Problem #7.
void test_valid_primeDivisors() {
	assert(primeDivisors(0, 1) == 1, "test_valid_primeDivisors");
	assert(primeDivisors(30, 45) == 2, "test_valid_primeDivisors");
	assert(primeDivisors(5, 12) == 3, "test_valid_primeDivisors");
	assert(primeDivisors(10000, 23000) == 131, "test_valid_primeDivisors");
	assert(primeDivisors(100, 450) == 4, "test_valid_primeDivisors");
}

void test_primeDivisors() {
	test_valid_primeDivisors();
}


// Tests for problem #8.
void test_valid_primeTwins() {
	matrix mat = primeTwins(10, 2);
	printMatrix(mat);

	mat = primeTwins(3, 2);
	printMatrix(mat);
}

void test_primeTwins() {
	test_valid_primeTwins();
}

// Tests for Problem #9.
void test_valid_areOrderedFibonnaci() {
	vector v;

	v.length = 1;
	v.values[0] = 0;
	assert(areOrderedFibonnaci(v), "test_valid_areOrderedFibonnaci");

	v.length = 6;
	for (int i = 0; i < v.length; i++) {
		v.values[i] = fibonnaci(i);
	}

	assert(areOrderedFibonnaci(v), "test_valid_areOrderedFibonnaci");
}

void test_invalid_areOrderedFibonnaci() {
	vector v;
	v.length = 0;
	assert(!areOrderedFibonnaci(v), "test_invalid_areOrderedFibonnaci");


	v.length = 2;
	v.values[0] = 0;
	v.values[1] = 20;
	assert(!areOrderedFibonnaci(v), "test_invalid_areOrderedFibonnaci");


	v.length = 6;
	for (int i = 0; i < v.length; i++) {
		v.values[i] = fibonnaci(i);
	}
	v.values[3] = 40;
	assert(!areOrderedFibonnaci(v), "test_invalid_areOrderedFibonnaci");
}

void test_areOrderedFibonnaci() {
	test_valid_areOrderedFibonnaci();
	test_invalid_areOrderedFibonnaci();
}

// Tests for Problem #10.
void test_valid_equal_checkVectorInclude() {
	vector v;
	v.length = 3;
	v.values[0] = 1;
	v.values[1] = 2;
	v.values[2] = 3;
	vector v1;
	v1.length = 3;
	v1.values[0] = 3;
	v1.values[1] = 1;
	v1.values[2] = 2;

	assert(checkVectorInclude(v, v1) == 0, "test_valid_equal_checkVectorInclude");
}

void test_valid_included_checkVectorInclude() {
	vector v;
	v.length = 2;
	v.values[0] = 1;
	v.values[1] = 2;
	vector v1;
	v1.length = 3;
	v1.values[0] = 3;
	v1.values[1] = 1;
	v1.values[2] = 2;

	assert(checkVectorInclude(v, v1) == 1, "test_valid_included_checkVectorInclude");

	vector a;
	a.length = 3;
	a.values[0] = 2;
	a.values[1] = 1;
	a.values[2] = 2;
	vector b;
	b.length = 2;
	b.values[0] = 1;
	b.values[1] = 2;

	assert(checkVectorInclude(a, b) == 2, "test_valid_included_checkVectorInclude");
}

void test_notIncluded_checkVectorInclude() {
	vector a;
	a.length = 2;
	a.values[0] = 4;
	a.values[1] = 5;
	vector b;
	b.length = 3;
	b.values[0] = 1;
	b.values[1] = 2;
	b.values[2] = 3;

	assert(checkVectorInclude(a, b) == 3, "test_notIncluded_checkVectorInclude");
}

void test_checkVectorInclude() {
	test_valid_equal_checkVectorInclude();
	test_valid_included_checkVectorInclude();
	test_notIncluded_checkVectorInclude();
}

// Tests for Problem #11.
void test_valid_checkIsIn() {
	matrix m;
	m.lines = 3;
	m.columns = 3;
	m.values[0][0] = 1;
	m.values[0][1] = 2;
	m.values[0][2] = 3;
	m.values[1][0] = 3;
	m.values[1][1] = 4;
	m.values[1][2] = 5;
	m.values[2][0] = 6;
	m.values[2][1] = 7;
	m.values[2][2] = 8;

	vector v;
	v.length = 3;
	v.values[0] = 1;
	v.values[1] = 3;
	v.values[2] = 6;

	assert(checkIsIn(v, m), "test_valid_checkIsIn");
}

void test_invalid_checkIsIn() {
	matrix m;
	m.lines = 2;
	m.columns = 2;
	m.values[0][0] = 2;
	m.values[0][1] = 1;
	m.values[1][0] = 3;
	m.values[1][1] = 4;

	vector v;
	v.length = 3;

	assert(!checkIsIn(v, m), "test_valid_checkIsIn");

	vector c;
	c.length = 2;
	c.values[0] = 1;
	c.values[1] = 2;

	assert(!checkIsIn(c, m), "test_valid_checkIsIn");
}

void test_checkIsIn() {
	test_valid_checkIsIn();
	test_invalid_checkIsIn();
}


// Tests for problem #12.
void test_valid_rotate() {
	matrix a;
	a.lines = 4;
	a.columns = 4;
	int v = 1;
	for (unsigned i = 0; i < a.lines; i++) {
		for (unsigned int j = 0; j < a.columns; j++) {
			a.values[i][j] = v++;
		}
	}

	printMatrix(a);
	matrix c = rotate(a, 7, 10);
	printMatrix(c);

	matrix b;
	b.columns = 0;
	b.lines = 0;
	b = rotate(b, 12, 13);
	printMatrix(b);

	matrix m;
	m.lines = 2;
	m.columns = 2;
	m.values[0][0] = 1;
	m.values[0][1] = 2;
	m.values[1][0] = 3;
	m.values[1][1] = 4;
	printMatrix(m);
	m = rotate(m, 1, 0);
	printMatrix(m);

	matrix n;
	n.lines = 2;
	n.columns = 2;
	n.values[0][0] = 1;
	n.values[0][1] = 2;
	n.values[1][0] = 3;
	n.values[1][1] = 4;
	printMatrix(n);
	n = rotate(n, 0, 1);
	printMatrix(n);
}

void test_rotate() {
	test_valid_rotate();
}


// Tests for problem #13.
void test_valid_isPartOfFibonnaci() {
	vector a;
	a.length = 3;
	a.values[0] = 3;
	a.values[1] = 5;
	a.values[2] = 2;
	assert(isPartOfFibonnaci(a, 2), "test_valid_isPartOfFibonnaci");

	vector b;
	b.length = 6;
	b.values[0] = 55;
	b.values[1] = 13;
	b.values[2] = 21;
	b.values[3] = 34;
	b.values[4] = 8;
	b.values[5] = 5;
	assert(isPartOfFibonnaci(b, 5), "test_valid_isPartOfFibonnaci");
}

void test_invalid_isPartOfFibonnaci() {
	vector a;
	a.length = 3;
	a.values[0] = 3;
	a.values[1] = 4;
	a.values[2] = 2;
	assert(!isPartOfFibonnaci(a, 2), "test_invalid_isPartOfFibonnaci");

	vector b;
	b.length = 6;
	b.values[0] = 55;
	b.values[1] = 13;
	b.values[2] = 21;
	b.values[3] = 34;
	b.values[4] = 8;
	b.values[5] = 5;
	assert(!isPartOfFibonnaci(b, 13), "test_invalid_isPartOfFibonnaci");

	vector c;
	c.length = 2;
	c.values[0] = 2;
	c.values[1] = 8;
	assert(!isPartOfFibonnaci(c, 2), "test_invalid_isPartOfFibonnaci");
}

void test_isPartOfFibonnaci() {
	test_valid_isPartOfFibonnaci();
	test_invalid_isPartOfFibonnaci();
}

// Tests for problem #14.
void test_valid_setOperations() {
	long sets[] = { 1,2,3 };
	char operations[] = { 'U', '\\' };
	assert(setOperations(sets, operations, 3) == 0, "test_valid_setOperations");
}

void test_setOperations() {
	test_valid_setOperations();
}

// Tests for problem #15.
void test_valid_bitOperations() {
	long numbers[] = { 1,2,3 };
	char operations[] = { '>', '&' };
	assert(bitOperations(numbers, operations, 3) == 0, "test_valid_bitOperations");

	long numbers2[] = { 3,4,5,6,1 };
	char operations2[] = { '^', '&', '|', '<', };
	assert(bitOperations(numbers2, operations2, 5) == 14, "test_valid_bitOperations");
}

void test_bitOperations() {
	test_valid_bitOperations();
}

// Tests for Problem #16.
void test_valid_palindrom() {
	long a = 2147483646;
	long b = 3087007725;
	long c = 268435440;
	long d = 267390960;
	assert(palindrom(a), "test_valid_palindrom");
	assert(palindrom(b), "test_valid_palindrom");
	assert(palindrom(c), "test_valid_palindrom");
	assert(palindrom(d), "test_valid_palindrom");
}

void test_invalid_palindrom() {
	long a = 4;
	long b = 16;
	long c = 20;
	long d = 32;
	assert(!palindrom(a), "test_valid_palindrom");
	assert(!palindrom(b), "test_valid_palindrom");
	assert(!palindrom(c), "test_valid_palindrom");
	assert(!palindrom(d), "test_valid_palindrom");
}

void test_boundaries_palindrom() {
	long a = 0;
	long b = LONG_MAX;

	assert(palindrom(a), "test_boundaries_palindrom");
	assert(!palindrom(b), "test_boundaries_palindrom");
}

void test_palindrom() {
	test_valid_palindrom();
	test_invalid_palindrom();
	test_boundaries_palindrom();
}

// Tests for Problem #17.
void test_valid_fibonnaciSpirale() {
	matrix mat;
	mat.lines = 3;
	mat.columns = 3;
	mat.values[0][0] = 0;
	mat.values[0][1] = 1;
	mat.values[0][2] = 1;
	mat.values[1][0] = 13;
	mat.values[1][1] = 21;
	mat.values[1][2] = 2;
	mat.values[2][0] = 8;
	mat.values[2][1] = 5;
	mat.values[2][2] = 3;

	assert(fibonnaciSpirale(mat), "test_valid_fibonnaciSpirale");
}

void test_invalid_fibonnaciSpirale() {
	matrix mat;
	mat.lines = 2;
	mat.columns = 2;
	mat.values[0][0] = 0;
	mat.values[0][1] = 1;
	mat.values[1][0] = 1;
	mat.values[1][1] = 2;

	assert(!fibonnaciSpirale(mat), "test_invalid_fibonnaciSpirale");

	matrix a;
	a.lines = 0;
	a.columns = 0;
	assert(!fibonnaciSpirale(a), "test_invalid_fibonnaciSpirale");
}

void test_fibonnaciSpirale() {
	test_valid_fibonnaciSpirale();
	test_invalid_fibonnaciSpirale();
}

// Tests for problem #18.
void initializeMaze(smaze& maze) {
	for (unsigned int i = 0; i < maze.noOfRows; i++) {
		for (int j = 0; j < maze.noOfColumns; j++) {
			maze.maze[i][j] = 1;
		}
	}
}

void test_valid_minRouteLenght() {
	smaze maze;
	maze.noOfRows = 6;
	maze.noOfColumns = 5;
	maze.rowOfDeparture = 1;
	maze.columnOfDeparture = 1;
	maze.rowOfExit = 4;
	maze.columnOfExit = 4;

	initializeMaze(maze);

	maze.maze[2][1] = 0;
	maze.maze[3][1] = 0;
	maze.maze[4][1] = 0;
	maze.maze[4][2] = 0;
	maze.maze[4][3] = 0;
	maze.maze[4][4] = 0;
	maze.maze[5][1] = 0;
	maze.maze[5][2] = 0;
	maze.maze[5][3] = 0;
	maze.maze[5][4] = 0;

	cout << minRouteLength(maze) << endl;
}

void test_minRouteLength() {
	test_valid_minRouteLenght();
}

// Tests for Problem #19.
void printMatrix(char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG],
	unsigned int rows, unsigned int columns)
{
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			cout << (int)mat[i][j] << " ";
		}
		cout << endl;
	}
}

void test_valid_transformMatrix() {
	char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG] = { { 0,1,1 },
	{ 1,1,1 },
	{ 1,1,0 } };
	transformMatrix(mat, 3, 3);
	printMatrix(mat, 3, 3);
}

void test_transformMatrix() {
	test_valid_transformMatrix();
}


int main() {
	test_isPalindrom();          // Problem #1.  (Tests completed) 
	test_sumBinaryFigure();      // Problem #2.  (Tests completed) 
	test_isLeapYear();           // Problem #3.  (Tests completed) 
	test_dayOfTheWeek();         // Problem #4.  (Tests completed) 
	test_fibonnaci();            // Problem #5.  (Tests completed) 
	test_perfectNumbers();       // Problem #6.  (Tests completed) 
	test_primeDivisors();        // Problem #7.  (Tests completed) 
	test_primeTwins();           // Problem #8.  (Tests completed) 
	test_areOrderedFibonnaci();  // Problem #9.  (Tests completed) 
	test_checkVectorInclude();   // Problem #10. (Tests completed) 
	test_checkIsIn();            // Problem #11. (Tests completed) 
	test_rotate();               // Problem #12. (Tests completed) 
	test_isPartOfFibonnaci();    // Problem #13. (Tests completed) 
	test_setOperations();        // Problem #14. (Tests completed) 
	test_bitOperations();        // Problem #15. (Tests completed) 
	test_palindrom();            // Problem #16. (Tests completed) 
	test_fibonnaciSpirale();     // Problem #17. (Tests completed) 
								 // test_minRouteLength();       // Problem #18. (Tests completed) 
	test_transformMatrix();      // Problem #19. (Tests completed) 

	return 0;
}