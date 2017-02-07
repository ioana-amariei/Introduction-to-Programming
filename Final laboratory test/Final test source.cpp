#include<iostream>
#include<fstream>
using namespace std;

#define N 100

struct matrix {
	int values[N][N];
	int rows;
	int cols;
};

void readFile(ifstream& ifs, matrix& A) {
	ifs >> A.rows;
	ifs >> A.cols;

	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++) {
			ifs >> A.values[i][j];
		}
	}
	ifs.close();
}

void print(ofstream& ofs, const matrix& A) {
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++) {
			ofs << A.values[i][j] << " ";
		}
		ofs << endl;
	}
}

void swap(int& first, int& second) {
	first ^= second;
	second ^= first;
	first ^= second;
}

void sortLine(matrix& A, int line) {
	for (int i = 0; i < A.cols; i++) {
		for (int j = i+1; j < A.cols; j++) {
			if (A.values[line][i] > A.values[line][j]) {
				swap(A.values[line][i], A.values[line][j]);
			}
		}
	}
}

void sortColumn(matrix& A, int column) {
	for (int i = 0; i < A.rows; i++) {
		for (int j = i + 1; j < A.rows; j++) {
			if (A.values[i][column] > A.values[j][column]) {
				swap(A.values[i][column], A.values[j][column]);
			}
		}
	}
}

void sortMatrixLines(matrix& A) {
	for (int i = 0; i < A.rows; i++) {
		sortLine(A, i);
	}
}

void sortMatrixColumns(matrix& A) {
	for (int j = 0; j < A.cols; j++) {
		sortColumn(A, j);
	}
}

bool sortable(matrix& A) {
	if (A.rows == 0 || A.cols == 0) {
		return false;
	}
	if (A.rows == 1 && A.cols == 1) {
		return false;
	}

	return true;
}

void sortMatrix(matrix& A) {
	sortMatrixLines(A);
	sortMatrixColumns(A);
}

int main() {
	ifstream ifs("matrix.in");
	ofstream ofs("matrix.out");

	matrix A;

	readFile(ifs, A);

	ofs << "Can matrix be sorted? : ";
	if (sortable(A)) {
		ofs << "Yes" << endl << endl;

		ofs << "Initial matrix:" << endl;
		print(ofs, A);
		ofs << endl;

		sortMatrix(A);
		ofs << "Sorted matrix:" << endl;
		print(ofs, A);
	}
	else {
		ofs << "No" << endl;
	}

	ofs.close();

	return 0;
}