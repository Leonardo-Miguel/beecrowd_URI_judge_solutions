#include <bits/stdc++.h>
using namespace std;

/*
É usada uma abordagem de busca binária para determinar o tempo mínimo necessário para que todos os sacos
de pipoca sejam esvaziados. É simulado o consumo de pipoca pelos competidores para verificar se todos
os sacos podem ser esvaziados dentro de cada instante de tempo, ajustando os limites da busca binária de
acordo com os resultados da simulação.
*/

int calculate_time(int n_sacks, int competitors, int popcorn_rate, const vector<int>& popcorn_sacks) {
    int low = 0;
    int high = accumulate(popcorn_sacks.begin(), popcorn_sacks.end(), 0) / popcorn_rate + 1;

    while (low < high) {
        int mid = (low + high) / 2;

        int sack = 0;
        vector<int> remaining_sacks = popcorn_sacks;
        for (int competitor = 0; competitor < competitors; ++competitor) {
            int n_popcorn_in_time = mid * popcorn_rate;
            while (sack < n_sacks && n_popcorn_in_time >= remaining_sacks[sack]) {
                n_popcorn_in_time -= remaining_sacks[sack];
                remaining_sacks[sack] = 0;
                ++sack;
            }
        }

        if (sack == n_sacks) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {

    vector<string> all_rows;
    string line;
    while (getline(cin, line)) {
        all_rows.push_back(line);
    }

    istringstream iss(all_rows[0]);
    int n_sacks, competitors, popcorn_rate;
    iss >> n_sacks >> competitors >> popcorn_rate;

    istringstream iss2(all_rows[1]);
    vector<int> popcorn_sacks;
    int value;
    while (iss2 >> value) {
        popcorn_sacks.push_back(value);
    }

    if (competitors > n_sacks) {
        competitors = n_sacks;
    }

    int result = calculate_time(n_sacks, competitors, popcorn_rate, popcorn_sacks);
    cout << result << endl;

    return 0;
}

