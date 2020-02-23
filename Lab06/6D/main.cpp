#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

#include <queue>
#include <map>

using namespace std;

class Quack {

    const int M = 65536;
    queue<uint16_t> q;

public:

    uint16_t  get() {
        uint16_t  t = q.front();
        q.pop();
        return t;
    }

    void put(int v) {
        q.push((uint16_t) (v % M));

    }

};


int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);
    // ====================== */

    /*/ ======================
    freopen("C:\\D\\Projects\\C++\\CLine\\Labs1\\in.txt", "r", stdin);
    freopen("C:\\D\\Projects\\C++\\CLine\\Labs1\\out.txt", "w", stdout);
    // ====================== */


    vector<string> program;

    string t;
    while (getline(cin, t)) {
        program.push_back(t);
    }


    Quack q;
    map<string, uint16_t> labels;
    uint16_t  regs[26];

    for (int i = 0; i < 26; ++i) {
        regs[i] = 0;
    }

    int i = -1;
    for (string s : program) {
        i++;
        if (s[0] == ':') {
            labels[s.substr(1)] = i;
        }
    }


    uint16_t x = 0;
    uint16_t y = 0;

    for (int i = 0; i < program.size(); ++i) {

        string c = program[i];
        switch(c[0]) {
            case '+':
                x = q.get();
                y = q.get();
                q.put(x + y);
                break;
            case '-':
                x = q.get();
                y = q.get();
                q.put(x - y);
                break;
            case '*':
                x = q.get();
                y = q.get();
                q.put(x * y);
                break;
            case '/':
                x = q.get();
                y = q.get();
                q.put(y != 0 ? x / y : 0);
                break;
            case '%':
                x = q.get();
                y = q.get();
                q.put(y != 0 ? x % y : 0);
                break;
            case '>':
                regs[c[1] - 'a'] = q.get();
                break;
            case '<':
                q.put(regs[c[1] - 'a']);
                break;
            case 'P':
                if (c.length() == 1) {
                    cout << q.get() << "\n";
                } else {
                    cout << regs[c[1] - 'a'] << "\n";
                }
                break;
            case 'C':
                if (c.length() == 1) {
                    cout << (unsigned char) q.get();
                }
                else {
                    cout << (unsigned char) regs[c[1] - 'a'];
                }
                break;
            case ':':
                break;
            case 'J':
                i = labels[c.substr(1)];
                break;
            case 'Z':
                if (regs[c[1] - 'a'] == 0) {
                    i = labels[c.substr(2)];
                }
                break;
            case 'E':
                if (regs[c[1] - 'a'] == regs[c[2] - 'a']) {
                    i = labels[c.substr(3)];
                }
                break;
            case 'G':
                if (regs[c[1] - 'a'] > regs[c[2] - 'a']) {
                    i = labels[c.substr(3)];
                }
                break;
            case 'Q':
                i = program.size();
                break;
            default:
                q.put(stoi(c));
                break;

        }

    }


    return 0;
}