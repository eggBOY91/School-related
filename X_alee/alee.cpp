/*
fisierdeintrare.ro:

8 6

2 7
3 3
4 6
5 4
7 3
7 5

1 1 8 8
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
struct Position {int lin, col;};

/////////////////////
// ps - pozitia initiala
// pc - pozitia finala
// p  - prim (coada)
// v  - ultim (coada)
// C - "coada" (coada in matrice, nu o coada adevarata; ce trist...)
/////////////////////
Position ps, pc, p, v, C[100];

//////////////////
// nrDir - numar directii
//////////////////
int k = 0, prim = 0, ultim = 0, nrDir = 4;

v.lin = 0;
v.col = 0;

int dl[4] = {-1, 0, 1, 0}; // vector de pozitie (linie)
int dc[4] = {0, 1, 0, -1}; // vector de pozitie (coloana)
//////////////////////////////////

ifstream f("fisierdeintrare.ro");

/*
- trebuie 100x100 ca sa nu dea crash;
- initializam matricea cu 0, pentru ca nu
o citim din fiser;
*/
int L[100][100] {};

int unused; // marimea matricei, dar nu o folosim
int catiCopaciSunt_DE_ATATEA_ORI_SUGI_PULA; // nume interesant

f >> unused >> catiCopaciSunt_DE_ATATEA_ORI_SUGI_PULA;

int cLin, cCol; // copac linie, copac coloana

for(int i = 0; i < catiCopaciSunt_DE_ATATEA_ORI_SUGI_PULA; i++)
{
    f >> cLin >> cCol;
    L[cLin][cCol] = -1;
}

f >> ps.lin >> ps.col >> pc.lin >> pc.col;

// adaptare la matrice care incepe cu 0, si nu cu 1
ps.lin -= 1; ps.col -= 1;
pc.lin -= 1; pc.col -= 1;
//////////////////////////////

C[0] = ps;

L[ps.lin][ps.col] = 1;

if(L[pc.lin][pc.col] != 0) // daca ai ajuns aici, esti prost... rau :(
{
    cout << "esti cam prost...";
    return 0;
}

while (prim <= ultim && L[pc.lin][pc.col] == 0)
{
    p=C[prim];
    prim++;

    for(k = 0; k < nrDir; k++)
    {
        v.lin = p.lin + dl[k];
        v.col = p.col + dc[k];

        if(L[v.lin][v.col] == 0)
        {
            L[v.lin][v.col] = L[p.lin][p.col] + 1;
            ultim++;
            C[ultim] = v;
        }

    }
}

if(L[pc.lin][pc.col] == 0) // daca pozitia finala nu a fost vizitata (este inca 0)
    cout << "Nu prea merge..";
else
    cout << "Ai mers vreo " << L[pc.lin][pc.col] << " pasi si ai ajuns.";
return 0;
}
