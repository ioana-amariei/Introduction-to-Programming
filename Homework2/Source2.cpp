#include<iostream>
#include<cassert>
#include"t2.h"

using namespace std;

void afiseazaSir(char sir[MAX_ADN], int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		cout << sir[i];
	}
	cout << endl;
}

// Tests for "codificareADN" 
void test_valid_codificareADN() {
	char sir[MAX_ADN];
	long nr = 27;

	codificareADN(nr, sir);
	afiseazaSir(sir, 3);

	nr = 84;
	codificareADN(nr, sir);
	afiseazaSir(sir, 4);

	nr = -6;
	codificareADN(nr, sir);
	afiseazaSir(sir, 3);

	nr = -27;
	codificareADN(nr, sir);
	afiseazaSir(sir, 4);

	nr = 54;
	codificareADN(nr, sir);
	afiseazaSir(sir, 4);
}

void test_codificareADN() {
	test_valid_codificareADN();
}

// Tests for "decodificareADN"
void test_valid_decodificareADN() {
	char sir[] = "GTT";
	assert(decodificareADN(sir) == 27 && "test_valid_decodificareADN");

	char sir2[] = "CTCG";
	assert(decodificareADN(sir2) == 54 && "test_valid_decodificareADN");

	char sir3[] = "TGG";
	assert(decodificareADN(sir3) == -6 && "test_valid_decodificareADN");

	char sir4[10];
	codificareADN(124, sir4);
	afiseazaSir(sir4, 10);
	cout << decodificareADN(sir4) << endl;
	assert(decodificareADN(sir4) == 124 && "test_valid_decodificareADN");
}

void test_decodificareADN() {
	test_valid_decodificareADN();
}

// Tests for "adunareADN"
void test_valid_adunareADN() {
	char first[] = "GTT";
	char second[] = "C";
	char sum[MAX_ADN];

	adunareADN(first, second, sum);
	afiseazaSir(sum, 3);
}

void test_adunareADN() {
	test_valid_adunareADN();
}

// Test for "scadereADN"
void test_valid_scadereADN() {
	char first[] = "GTA";
	char second[] = "C";
	char difference[MAX_ADN];

	scadereADN(first, second, difference);
	afiseazaSir(difference, 3);
}

void test_scadereADN() {
	test_valid_scadereADN();
}

int main() {

	test_codificareADN();
	test_decodificareADN();
	test_adunareADN();
	test_scadereADN();

	return 0;
}