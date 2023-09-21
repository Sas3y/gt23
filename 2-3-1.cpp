#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<vector<int>>& grafas, vector<int>& S, int pradine_virsune, int komponentes_nr) {
    stack<int> stekas;
    stekas.push(pradine_virsune);
    while (!stekas.empty()) {
        int virsune = stekas.top();
        stekas.pop();
        if (S[virsune] == 0) {
            S[virsune] = komponentes_nr;
            for (int kaimynas : grafas[virsune]) {
                if (S[kaimynas] == 0) {
                    stekas.push(kaimynas);
                }
            }
        }
    }
}

int main() {
    int p = 0; // Jungiųjų komponenčių skaičius
    vector<vector<int>> grafas{{1,2},{1,6},{2,3},{2,7},{4,8},{4,9},{6,7}};
    int n = 9; // Viršūnių skaičius
    vector<int> S(n + 1, 0); // Sąrašas, kuris nusako, kurioms jungiųjų komponentėms priklauso viršūnės

    for (int i = 1; i <= n; i++) {
        if (S[i] == 0) {
            // Radome viršūnę, kuri nepriklauso jokiai jungiajai komponentei
            p++;
            DFS(grafas, S, i, p);
        }
    }
	
	for (int jungiosKomponentesNumeris : S) {
		cout << jungiosKomponentesNumeris << " ";
	}

    return 0;
}
