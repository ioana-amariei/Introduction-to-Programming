#include"t3.h"

ArbBin* insereaza(ArbBin* nod, int element) {
	// nu exista un arbore
	if (nod == nullptr) {
		return nod;
	}

	if (element < nod->val) {
		nod->st = insereaza(nod->st, element);
	}
	else {
		nod->dr = insereaza(nod->dr, element);
	}

	return nod;
}

bool estePar(int element) {
	return (element % 2 == 0);
}

bool esteSpecial(ArbBin* nod) {
	if (nod == nullptr) {
		return false;
	}

	if (nod->st != nullptr && nod->dr != nullptr) {
		int stang = nod->st->val;
		int drept = nod->dr->val;
		return (estePar(stang) && estePar(drept));
	}
}

ArbBin* creeazaArbore(int vectorNoduri[MAX_NODURI], int nrNoduri) {
	if (nrNoduri == 1) {
		return nullptr;
	}

	ArbBin* arboreCautare = new ArbBin;

	for (int i = 0; i < nrNoduri; i++) {
		insereaza(arboreCautare, vectorNoduri[i]);
	}

	return arboreCautare;
}

int nrNoduriSpeciale(ArbBin* nod) {
	if (nod == nullptr) {
		return 0;
	}

}

int nrNoduriSpeciale(int vectorNoduri[MAX_NODURI], int nrNoduri) {

}