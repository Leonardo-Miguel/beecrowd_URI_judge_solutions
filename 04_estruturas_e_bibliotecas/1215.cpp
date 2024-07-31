#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;

string convert_to_lower(const string &str) {
    string lower_str = str;
    for (char &c : lower_str) {
        c = tolower(c);
    }
    return lower_str;
}

vector<string> find_words(const string &merged_inputs) {
    vector<string> sep_words;
    string word;
    bool in_word = false;

    for (char current_character : merged_inputs) {
        if (isalpha(current_character)) {
            word += current_character;
            in_word = true;
        } else {
            if (in_word) {
                sep_words.push_back(convert_to_lower(word));
                word.clear();
                in_word = false;
            }
        }
    }

    if (in_word) {
        sep_words.push_back(convert_to_lower(word));
    }

    sort(sep_words.begin(), sep_words.end());
    return sep_words;
}

void drop_duplicates(const vector<string> &sep_words) {
    set<string> set_words(sep_words.begin(), sep_words.end());
    // exibição das palavras, já sem duplicação
    for (const auto &unique_word : set_words) {
        cout << unique_word << endl;
    }
}

int main() {
    string merged_inputs;
    string line;

    while (getline(cin, line)) {
        if (!merged_inputs.empty()) {
            merged_inputs += " "; //importante! a adição desse caracetere entre cada linha evita a junção da ultima palavra de uma linha com a primeira da próxima
        }
        merged_inputs += line;
    }

    vector<string> sep_words = find_words(merged_inputs);
    drop_duplicates(sep_words);

    return 0;
}

