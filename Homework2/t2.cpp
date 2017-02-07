#include"t2.h"

//  A=0, C=1, G=2, iar T=-1.
char codificaCaracterADN(long cifra) {
	if (cifra == -1) {
		return 'T';
	}
	else if (cifra == 0) {
		return 'A';
	}
	else if (cifra == 1) {
		return 'C';
	}
	else if (cifra == 2) {
		return 'G';
	}
}

void interschimba(char& a, char& b) {
	char aux = a;
	a = b;
	b = aux;
}

void intoarce(char sir[MAX_ADN], int dim) {
	int stang = 0;
	int drept = dim - 1;
	while (stang < drept) {
		interschimba(sir[stang++], sir[drept--]);
	}
}

void codificareADN(long long nrIntreg, char sirADN[MAX_ADN]) {
	int i = 0;
	while (nrIntreg != 0) {
		/* rest = 3 */
		if (nrIntreg % 4 == 3) {
			sirADN[i++] = codificaCaracterADN(-1);
			nrIntreg = (nrIntreg / 4) + 1;
		}
		/* rest = -2 */
		else if (nrIntreg % 4 == -2) {
			sirADN[i++] = codificaCaracterADN(2);
			nrIntreg = (nrIntreg / 4) - 1;
		}
		/* rest = -3 */
		else if (nrIntreg % 4 == -3) {
			sirADN[i++] = codificaCaracterADN(1);
			nrIntreg = (nrIntreg / 4) - 1;
		}
		else {
			sirADN[i++] = codificaCaracterADN(nrIntreg % 4);
			nrIntreg = nrIntreg / 4;
		}
	}
	intoarce(sirADN, i);
}

long ridicarePutere(int n, int p) {
	long result = 1;
	for (int i = 1; i <= p; i++) {
		result *= n;
	}
	return result;
}

long decodificaCaracterADN(char caracter) {
	if (caracter == 'T') {
		return -1;
	}
	else if (caracter == 'A') {
		return 0;
	}
	else if (caracter == 'C') {
		return 1;
	}
	else if (caracter == 'G') {
		return 2;
	}
}

int identificarePutere(char sirADN[MAX_ADN]) {
	int i = 0;
	while (sirADN[i] == 'T' || sirADN[i] == 'A' || sirADN[i] == 'C' || sirADN[i] == 'G') {
		i++;
	}
	return i - 1;
}

long long decodificareADN(char sirADN[MAX_ADN]) {
	long long numar = 0;
	int putere = identificarePutere(sirADN);
	int i = 0;
	while (putere >= 0) {
		numar += decodificaCaracterADN(sirADN[i]) * ridicarePutere(4, putere);
		i++;
		putere--;
	}
	return numar;
}

void adunareADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char suma[MAX_ADN]) {
	long long first = decodificareADN(primulSir);
	long long second = decodificareADN(alDoileaSir);

	codificareADN(first + second, suma);
}

void scadereADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char diferenta[MAX_ADN]) {
	long long first = decodificareADN(primulSir);
	long long second = decodificareADN(alDoileaSir);

	codificareADN(first - second, diferenta);
}