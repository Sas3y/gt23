#include <iostream>
#include <vector>

using namespace std;

int main() {
	
    vector<pair<int, int>> briaunos{{2,3},{7,6},{1,2},{2,7},{1,6},{4,9},{4,8}};
    int n = 9; // Viršūnių skaičius
    vector<int> S(n + 1);
    int p = n;

    for (int i = 1; i <= n; i++) {
        S[i] = i;
    }

    for (const auto& briauna : briaunos) {
        int k = briauna.first;
        int l = briauna.second;

        if (S[k] != S[l]) {
            p--;
            int u = S[k];
            int v = S[l];

            for (int i = 1; i <= n; i++) {
                if (S[i] == v) {
                    S[i] = u;
                }
            }
        }
    }

    vector<int> temp(n + 1);
    int t = 0;
    for (int i = 1; i <= n; i++) {
        temp[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (temp[i] == 0) {
            t++;
            int k = S[i];
            for (int l = i; l <= n; l++) {
                if (S[l] == k) {
                    temp[l] = 1;
                    S[l] = t;
                }
            }
        }
    }
    
    for(const int jungiosKomponentesNumeris : S){
        cout << jungiosKomponentesNumeris << " ";
    }

    return 0;
}
