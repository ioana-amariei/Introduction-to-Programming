#define MAX_ADN 35


/* (2p) Scrieți o funcție care codifica un număr întreg nrIntreg în reprezentarea ADN.
De exemplu, pentru nrIntreg = 27, funcția va returna sirADN = “GTT”. */

void codificareADN(long long nrIntreg, char sirADN[MAX_ADN]);


/* (1p) Scrieți o funcție care decodifica un șir ADN într - un număr întreg, de tip long.
De exemplu, pentru sirADN = ”GTT” funcția va returna 27. */

long long decodificareADN(char sirADN[MAX_ADN]);

/* (1p) Scrieți o funcție care adună două șiruri ADN, rezultatul fiind reprezentarea în ADN
a sumei celor două numere, reprezentate de primulSir și alDoileaSir.
De exemplu, pentru primulSir = ”GTT” și alDoileaSir = ”C”, funcţia va obține suma = ”GTA”. */

void adunareADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char suma[MAX_ADN]);


/* (1p) Scrieți o funcție care scade două șiruri ADN, rezultatul fiind reprezentarea în ADN a diferentei
celor două numere, reprezentate de primulSir și alDoileaSir.
De exemplu, pentru primulSir = ”GTA” și alDoileaSir = ”C”, funcţia va obține diferenta = ”GTT”.
*/

void scadereADN(char primulSir[MAX_ADN], char alDoileaSir[MAX_ADN], char diferenta[MAX_ADN]);


