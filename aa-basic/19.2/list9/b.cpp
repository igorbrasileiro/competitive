#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
   
    int res, res1, inter;
    res = 0;
    res1 = 0;
    inter = 0;
    for(int i = 0; i < s1.size(); i++) {
        if (s1[i] == '+') {
            res++;
        } else {
            res--;
        }
       
        if (s2[i] == '+') {
            res1++;
        } else if (s2[i] == '-') {
            res1--;
        } else {
            inter++;
        }
    }
   
    int diff = res - res1;
    double result;
    if ((diff + inter) % 2 != 0 || inter < abs(diff)) { // nao tem como chegar ao final
        result = 0;
    } else {
        int comb = 1;
        int d = (inter + abs(diff)) / 2;
        // calcular combs que precisam para atingir a diff dado a qtd de interrogacoes
        // c('?', diffs) / 2^('?')
        for (int i = 0; i < d; i++) {
            comb *= inter - i;
        }
        for (int i = 2; i <= d; i++) {
            comb /= i;
        }

        result = (double) comb / (1 << inter);
    }

    printf("%.12f\n", result);
   
    return EXIT_SUCCESS;
}