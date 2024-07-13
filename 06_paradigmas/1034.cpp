#include <bits/stdc++.h>
using namespace std;

/*
The algorithm used to solve the problem is the same as that used for the coin change problem,
which uses the dynamic programming paradigm to minimize the number of coins to return change.
In the ice statue problem, it is basically verified which blocks of ice make up the solutions
optimal values starting from length 1 to the desired length, so that at each value, the
block size that would be adequate to reach that fulfillment, replacing more blocks with that one.
This way, this block minimizes the total number of blocks.
*/

int min_blocks(vector<int>& a, int M) {
    vector<int> quant_blocks(1, 0);

    for (int j = 1; j <= M; ++j) {
        int min_val = INT_MAX;

        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] <= j && 1 + quant_blocks[j - a[i]] < min_val) {
                min_val = 1 + quant_blocks[j - a[i]];
            }
        }

        quant_blocks.push_back(min_val);
    }

    return quant_blocks[M];
}

int main() {

    vector<string> all_rows;
    string line;
    while (getline(cin, line)) {
        all_rows.push_back(line);
    }

    int T = atoi(all_rows[0].c_str());
    int count_instances = 0;

    while (count_instances / 2 < T) {
        istringstream iss(all_rows[count_instances + 1]);
        int N, M;
        iss >> N >> M;

        istringstream iss2(all_rows[count_instances + 2]);
        vector<int> a;
        int num;
        while (iss2 >> num) {
            a.push_back(num);
        }

        cout << min_blocks(a, M) << endl;

        count_instances += 2;
    }

    return 0;
}

