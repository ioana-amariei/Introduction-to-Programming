#include"t1.h"

int NUMBER_DIRECTIONS = 4;
int rowDirections[4] = { -1,0,1,0 };
int columnDirections[4] = { 0,1,0,-1 };

/* Helper functions */

inline bool isEven(int number) {
	return (number & 1) == 0;
}


/*
-----------
PROBLEM 1.
-----------
*/
bool isPalindrom(int vec[], int dim) {

	int left = 0;
	int right = dim - 1;

	while (left < right) {
		if (vec[left++] != vec[right--]) {
			return false;
		}
	}

	return true;
}

bool isPalindrom(unsigned long long number) {
	if (number < 10) {
		return true;
	}

	int newNumber[32] = { 0 };

	int i = 0;
	while (number) {
		newNumber[i] = number % 10;
		number = number / 10;
		i++;
	}

	int dimension = i;

	return isPalindrom(newNumber, dimension);

}

/*
-----------
PROBLEM 2.
-----------
*/
unsigned char sumBinaryFigure(unsigned long long number) {
	unsigned char sum = 0;
	while (number > 0) {
		sum += (number & 1);
		number >>= 1;
	}
	return sum;
}

/*
-----------
PROBLEM 3.
-----------
*/
bool isLeapYear(unsigned short year) {
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false;
	}
	else {
		return true;
	}
}

/*
-----------
PROBLEM 4.
-----------
*/
unsigned char dayOfTheWeek(unsigned short year, unsigned char month, unsigned char day) {
	int Day = day;
	int Month = month;
	int Year = year;

	if (month <= 2) {
		Month += 12;
		Year = Year - 1;
	}

	int Zeller = (Day + ((13 * (Month + 1)) / 5) + Year + (Year / 4) - (Year / 100) + (Year / 400)) % 7;
	int theDay = ((Zeller + 5) % 7) + 1;

	return theDay;
}

/*
-----------
PROBLEM 5.
-----------
*/
unsigned int fibonnaci(int index) {
	if (index == 0) {
		return 0;
	}
	else if (index == 1 || index == 2) {
		return 1;
	}
	else {
		unsigned int fibonnaci1 = 1;
		unsigned int fibonnaci2 = 1;
		unsigned int fibonnaci = 0;

		for (int i = 3; i <= index; i++) {
			fibonnaci = fibonnaci1 + fibonnaci2;
			fibonnaci1 = fibonnaci2;
			fibonnaci2 = fibonnaci;
		}
		return fibonnaci2;
	}
}

/*
-----------
PROBLEM 6.
-----------
*/
bool isPerfect(unsigned int number) {
	unsigned int sum = 0;

	for (int i = number >> 1; i >= 1; i--) {
		if (number%i == 0) {
			sum += i;
			if (sum > number) {
				return false;
			}
		}
	}
	return (sum == number);
}

/* returneaza cel mai mare numar perfect mai mic decat parametrul furnizat */
unsigned int biggestPerfectNumberSmallerThan(unsigned int number) {
	for (unsigned int i = number - 1; i >= 1; i--) {
		if (isPerfect(i)) {
			return i;
		}
	}
}

unsigned long perfectNumbers(unsigned int number) {
	unsigned long first = biggestPerfectNumberSmallerThan(number);
	unsigned long second = biggestPerfectNumberSmallerThan(first);

	return first + second;
}

/*
-----------
PROBLEM 7.
-----------
*/
/* returneaza true daca number este prim, false in caz contrar */
bool isPrime(unsigned int number) {
	if (number < 2) {
		return false;
	}
	if (number == 2) {
		return true;
	}
	if (isEven(number)) {
		return false;
	}
	for (unsigned int i = 3; i*i <= number; i += 2) {
		if (number%i == 0) {
			return false;
		}
	}
	return true;
}

unsigned int numberPrimeDivisors(unsigned int number) {
	unsigned int numberPrimeDivisors = 0;
	unsigned int limit = number;

	if (isEven(number)) {
		numberPrimeDivisors += 1;
		limit = number >> 1;
	}

	for (unsigned int i = 3; i <= limit; i += 2) {
		if ((number%i) == 0 && isPrime(i)) {
			numberPrimeDivisors += 1;
		}
	}

	return numberPrimeDivisors;
}

unsigned short primeDivisors(unsigned int left, unsigned int right) {
	unsigned int dimension = (right - left) + 1;
	unsigned int * vec = new unsigned int[dimension];

	unsigned int j = 0;
	for (unsigned int i = left; i <= right; i++) {
		vec[j++] = numberPrimeDivisors(i);
	}

	unsigned int max = vec[0];
	for (unsigned int i = 1; i < dimension; i++) {
		if (max < vec[i]) {
			max = vec[i];
		}
	}

	unsigned short maxNrPrimeDivisors = 0;
	for (unsigned int i = 0; i < dimension; i++) {
		if (vec[i] == max) {
			maxNrPrimeDivisors += 1;
		}
	}
	delete[] vec;

	return maxNrPrimeDivisors;
}


/*
-----------
PROBLEM 8.
-----------
*/
bool twinPrimes(int first, int second) {
	return isPrime(first) && isPrime(second);
}

matrix primeTwins(unsigned int count, unsigned int lowerBound) {
	matrix mat;
	mat.columns = 2;
	mat.lines = count;
	unsigned int i = 0; // line index
	unsigned int pairs = 0;

	if (lowerBound < 3 && pairs < count) {
		mat.values[i][0] = 3;
		mat.values[i][1] = 5;
		pairs++;
		i++;
	}

	unsigned int p = lowerBound + 2;
	while (p % 6 != 0) {
		p++;
	}

	while (pairs < count) {
		if (twinPrimes(p - 1, p + 1)) {
			mat.values[i][0] = p - 1;
			mat.values[i][1] = p + 1;
			pairs++;
			i++;
		}
		p += 6;
	}

	return mat;
}



/*
-----------
PROBLEM 9.
-----------
*/
bool areOrderedFibonnaci(int a[], unsigned int n) {
	if (n == 0) {
		return false;
	}

	if (n > 0) {
		if (a[0] != 0) {
			return false;
		}
	}

	if (n > 1) {
		if (a[1] != 1) {
			return false;
		}
	}

	for (unsigned int index = 2; index < n; index++) {
		if (a[index] != (a[index - 2] + a[index - 1])) {
			return false;
		}
	}

	return true;
}

bool areOrderedFibonnaci(vector vec) {
	return areOrderedFibonnaci(vec.values, vec.length);
}


/*
-----------
PROBLEM 10.
-----------
*/
void merge(vector & a, unsigned int left, unsigned int middle, unsigned int right) {
	unsigned int dim = (right - left) + 1;
	vector * c = new vector[dim];
	c->length = dim;

	unsigned int i = left;
	unsigned int j = middle + 1;
	unsigned int k = 0;

	while (i <= middle && j <= right) {
		if (a.values[i] < a.values[j]) {
			c->values[k++] = a.values[i++];
		}
		else {
			c->values[k++] = a.values[j++];
		}
	}

	while (i <= middle) {
		c->values[k++] = a.values[i++];
	}

	while (j <= right) {
		c->values[k++] = a.values[j++];
	}

	/* k <= dim - 1 */
	for (k = 0; k <= (right - left); k++) {
		a.values[left + k] = c->values[k];
	}
	delete[] c;
}

void mergeSort(vector & a, unsigned int left, unsigned int right) {
	if (left < right) {
		unsigned int middle = left + (right - left) / 2;
		mergeSort(a, left, middle);
		mergeSort(a, middle + 1, right);
		merge(a, left, middle, right);
	}
}

bool haveSameValues(vector one, vector two) {
	int aux = 0;
	for (unsigned int i = 0; i < one.length; i++) {
		aux ^= one.values[i] ^ two.values[i];
	}
	if (aux == 0) {
		return true;
	}
	return false;
}

unsigned char checkVectorInclude(vector vecOne, vector vecTwo) {
	if (vecOne.length == vecTwo.length) {
		if (haveSameValues(vecOne, vecTwo)) {
			return 0;
		}
		else {
			return 3;
		}
	}
	else if (vecOne.length < vecTwo.length) {
		mergeSort(vecTwo, 0, vecTwo.length - 1);
		if (haveSameValues(vecOne, vecTwo)) {
			return 1;
		}
		else {
			return 3;
		}
	}
	else if (vecTwo.length < vecOne.length) {
		mergeSort(vecOne, 0, vecOne.length - 1);
		if (haveSameValues(vecTwo, vecOne)) {
			return 2;
		}
		else {
			return 3;
		}
	}
}


/*
------------
PROBLEM 11.
------------
*/
bool equalLine(matrix mat, vector vec, unsigned int line) {
	for (unsigned int j = 0; j < vec.length; j++) {
		if (vec.values[j] != mat.values[line][j]) {
			return false;
		}
	}
	return true;
}
bool checkOnLines(vector vec, matrix mat) {
	for (unsigned int i = 0; i < mat.lines; i++) {
		if (equalLine(mat, vec, i)) {
			return true;
		}
	}
	return false;
}

bool equalColumn(matrix mat, vector vec, unsigned int column) {
	for (unsigned int i = 0; i < vec.length; i++) {
		if (vec.values[i] != mat.values[i][column]) {
			return false;
		}
	}
	return true;
}

bool checkOnColumns(vector vec, matrix mat) {
	for (unsigned int j = 0; j < mat.columns; j++) {
		if (equalColumn(mat, vec, j)) {
			return true;
		}
	}
	return false;
}

bool checkIsIn(vector vec, matrix mat) {
	if (vec.length == mat.columns) {
		if (checkOnColumns(vec, mat)) {
			return true;
		}
	}

	if (vec.length == mat.lines) {
		if (checkOnLines(vec, mat)) {
			return true;
		}
	}

	return false;
}


/*
------------
PROBLEM 12.
------------
*/

void swapElements(matrix & mat, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
	mat.values[a][b] ^= mat.values[c][d];
	mat.values[c][d] ^= mat.values[a][b];
	mat.values[a][b] ^= mat.values[c][d];
}

void rotateRight(matrix & mat, int rot) {
	while (rot-- > 0) {
		/* rotesc centurile matricii pe rand incepand dinspre exterior spre interior  */
		for (unsigned int c = 0; c < mat.columns / 2; c++) {
			for (unsigned int i = c; i < mat.lines - 1 - c; i++) {
				swapElements(mat, i, c, mat.lines - 1 - c, i);
			}

			for (unsigned int j = c; j < mat.columns - 1 - c; j++) {
				swapElements(mat, mat.lines - 1 - c, j, mat.lines - 1 - j, mat.columns - 1 - c);
			}

			for (unsigned int i = mat.lines - 1 - c; i > c; i--) {
				swapElements(mat, i, mat.columns - 1 - c, c, i);
			}
		}
	}
}

void rotateLeft(matrix & mat, int rot) {
	if (rot == 1) {
		rotateRight(mat, 3);
	}
	else if (rot == 2) {
		rotateRight(mat, 2);
	}
	else if (rot == 3) {
		rotateRight(mat, 1);
	}
}

int abs(int number) {
	return ((number < 0) ? -number : number);
}

matrix rotate(matrix mat, unsigned int rotLeft, unsigned int rotRight) {
	unsigned int left = rotLeft % 4;
	unsigned int right = rotRight % 4;
	int diff = right - left;

	if (diff > 0) {
		rotateRight(mat, diff);
	}
	else if (diff < 0) {
		rotateLeft(mat, abs(diff));
	}

	return mat;
}


/*
------------
PROBLEM 13.
------------
*/
bool isPerfectSquare(int number) {
	int p = 0;
	while (p * p < number) {
		p++;
	}
	return p * p == number;
}

bool isFibonnaci(int number) {
	int first = (5 * number * number) + 4;
	int second = (5 * number * number) - 4;

	return (isPerfectSquare(first) || isPerfectSquare(second));
}

bool consecutiveFibonnaci(int a, int b) {
	if (isFibonnaci(a) && isFibonnaci(b)) {
		return isFibonnaci(b - a);
	}
	return false;
}

bool areOrdFibonnaci(vector vec) {
	if (consecutiveFibonnaci(vec.values[0], vec.values[1])) {
		for (unsigned int i = 2; i < vec.length; i++) {
			if (vec.values[i] != (vec.values[i - 2] + vec.values[i - 1])) {
				return false;
			}
		}
	}
	else {
		return false;
	}

	return true;
}

int searchIndex(vector vec, unsigned int start) {
	for (unsigned int i = 0; i < vec.length; i++) {
		if (vec.values[i] == start) {
			return i;
		}
	}
}

bool isPartOfFibonnaci(vector vec, unsigned int startingNumber) {
	if (vec.length == 0) {
		return false;
	}

	if (vec.length == 1) {
		if (isFibonnaci(vec.values[0])) {
			return true;
		}
	}

	mergeSort(vec, 0, vec.length - 1);

	if (searchIndex(vec, startingNumber) == 0) {
		if (areOrdFibonnaci(vec)) {
			return true;
		}
	}
	return false;
}


/*
------------
PROBLEM 14.
------------
*/
inline long reunion(long a, long b) {
	return a | b;
}

inline long intersection(long a, long b) {
	return a & b;
}

inline long substraction(long a, long b) {
	return (a | b) ^ b;
}

unsigned long setOperations(long sets[], char operations[], unsigned int x) {
	long result = sets[0];

	for (unsigned int i = 1; i < x; i++) {
		if (operations[i - 1] == 'U') {
			result = reunion(result, sets[i]);
		}
		else if (operations[i - 1] == 'A') {
			result = intersection(result, sets[i]);
		}
		else if (operations[i - 1] == '\\') {
			result = substraction(result, sets[i]);
		}
		else if (operations[i - 1] == '/') {
			result = substraction(sets[i], result);
		}
	}

	return (unsigned long)result;
}


/*
------------
PROBLEM 15.
------------
*/
unsigned long bitOperations(long numbers[], char operations[], unsigned int x) {
	long result = numbers[0];

	for (unsigned int i = 1; i < x; i++) {
		if (operations[i - 1] == '<') {
			result = result << numbers[i];
		}
		else if (operations[i - 1] == '>') {
			result = result >> numbers[i];
		}
		else if (operations[i - 1] == '^') {
			result = result ^ numbers[i];
		}
		else if (operations[i - 1] == '|') {
			result = result | numbers[i];
		}
		else if (operations[i - 1] == '&') {
			result = result & numbers[i];
		}
	}
	return (unsigned long)result;
}


/*
------------
PROBLEM 16.
------------
*/
bool palindrom(long number) {
	int binary[32] = { 0 };
	long one = 1;

	for (int i = 0; i < 32; i++) {
		if (number & (one << i)) {
			binary[i] = 1;
		}
	}

	return isPalindrom(binary, 32);
}

/*
------------
PROBLEM 17.
------------
*/
bool fibonnaciSpirale(matrix mat) {
	if (mat.lines == 0) {
		return false;
	}
	if (mat.columns == 0) {
		return false;
	}

	unsigned int startRow = 0;
	unsigned int startCol = 0;

	unsigned int fib = 0;
	unsigned int dim = mat.columns * mat.lines;
	int * vec = new int[dim];

	while (startRow < mat.lines && startCol < mat.columns) {

		/* Go through the first row from the remaining rows */
		for (unsigned int j = startCol; j < mat.columns; j++) {
			vec[fib++] = mat.values[startRow][j];
		}
		startRow++;

		/* Go through the last column from the remaining columns */
		for (unsigned int i = startRow; i < mat.lines; i++) {
			vec[fib++] = mat.values[i][mat.columns - 1];
		}
		mat.columns--;

		/* Go through the last row from the remaining rows */
		if (startRow < mat.lines) {
			for (long long j = mat.columns - 1; j >= startCol; j--) {
				vec[fib++] = mat.values[mat.lines - 1][j];
			}
			mat.lines--;
		}

		/* Go through the first column from the remaining columns */
		if (startCol < mat.columns) {
			for (long long i = mat.lines - 1; i >= startRow; i--) {
				vec[fib++] = mat.values[i][startCol];
			}
			startCol++;
		}
	}

	return areOrderedFibonnaci(vec, dim);
}


/*
------------
PROBLEM 18.
------------
*/
bool emptyQueue(unsigned int size) {
	return size == 0;
}

void add(unsigned int * vector, unsigned int& size, unsigned int element) {
	vector[size++] = element;
}

unsigned int remove(unsigned int vec[], unsigned int& size) {
	unsigned int element = vec[0];

	for (unsigned int i = 1; i < size; i++) {
		vec[i - 1] = vec[i];
	}
	--size;

	return element;
}

void initializeMatrix(unsigned int ** matrix, unsigned int rows, unsigned int columns) {
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			matrix[i][j] = 0;
		}
	}
}

bool positionInMaze(unsigned int rowIndex, unsigned int columnIndex, unsigned int noRows, int noColumns) {
	return (0 <= rowIndex && rowIndex < noRows && 0 <= columnIndex && columnIndex < noColumns);
}

void deallocate(unsigned int ** visited, unsigned int numberRows) {
	for (unsigned int i = 0; i < numberRows; ++i)
		delete[] visited[i];
	delete[] visited;
}

unsigned int minRouteLength(smaze maze) {
	unsigned int dimension = maze.noOfRows * maze.noOfColumns;
	unsigned int * rowsQueue = new unsigned int[dimension];
	unsigned int * columnsQueue = new unsigned int[dimension];

	/* create visited matrix for counting minimum length and check if a position was already visited */
	unsigned int ** visited = new unsigned int*[maze.noOfRows];
	for (unsigned int i = 0; i < maze.noOfRows; i++) {
		visited[i] = new unsigned int[maze.noOfColumns];
	}

	initializeMatrix(visited, maze.noOfRows, maze.noOfColumns);
	visited[maze.rowOfDeparture][maze.columnOfDeparture] = 1;

	unsigned int rowsQueueSize = 0;
	unsigned int columnsQueueSize = 0;
	add(rowsQueue, rowsQueueSize, maze.rowOfDeparture);
	add(columnsQueue, columnsQueueSize, maze.columnOfDeparture);

	unsigned int rowIndex = maze.rowOfDeparture;
	unsigned int columnIndex = maze.columnOfDeparture;

	while (!emptyQueue(rowsQueueSize) && !emptyQueue(columnsQueueSize)) {
		rowIndex = remove(rowsQueue, rowsQueueSize);
		columnIndex = remove(columnsQueue, columnsQueueSize);

		if (rowIndex == maze.rowOfExit && columnIndex == maze.columnOfExit) {
			unsigned int length = visited[rowIndex][columnIndex];
			unsigned int numberRows = maze.noOfRows;
			delete[] rowsQueue;
			delete[] columnsQueue;

			deallocate(visited, numberRows);

			return length - 1;
		}

		for (int d = 0; d < NUMBER_DIRECTIONS; d++) {
			unsigned int n = rowIndex + rowDirections[d];
			unsigned int m = columnIndex + columnDirections[d];
			if (positionInMaze(n, m, maze.noOfRows, maze.noOfColumns)) {
				if (maze.maze[n][m] == 0 && visited[n][m] == 0) {
					add(rowsQueue, rowsQueueSize, n);
					add(columnsQueue, columnsQueueSize, m);
					visited[n][m] = 1 + visited[rowIndex][columnIndex];
				}
			}
		}
	}
}


/*
------------
PROBLEM 19.
------------
*/
void updateRow(char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG],
	unsigned int row, unsigned int columns)
{
	for (unsigned int j = 0; j < columns; j++) {
		if (mat[row][j] != 0) {
			mat[row][j] = 2;
		}
	}
}

void updateColumn(char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG],
	unsigned int rows, unsigned int column)
{
	for (unsigned int i = 0; i < rows; i++) {
		if (mat[i][column] != 0) {
			mat[i][column] = 2;
		}
	}
}

void transformMatrix(char mat[MAX_ARRAY_LENGTH_LONG][MAX_ARRAY_LENGTH_LONG],
	unsigned int rows, unsigned int columns)
{
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			if (mat[i][j] == 0) {
				updateRow(mat, i, columns);
				updateColumn(mat, rows, j);
			}
		}
	}

	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < columns; j++) {
			if (mat[i][j] == 2) {
				mat[i][j] = 0;
			}
		}
	}
}
