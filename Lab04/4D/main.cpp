#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

#define SIZE 100000

int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    // ====================== */

    string s;
    char c;
    int stack[SIZE];
    int top = -1;

    int sign, t;

    getline(cin, s);

    //cout << s.length() << "\n\n";

    for (int i = 0; i < s.length(); ++i) {
        sign = 1;

        c = s[i];
        if (c == ' ') {
            continue;
        }
        else if (c == '-' && i < s.length() - 1 && s[i+1] >= '0' && s[i+1] <= '9') {
            sign = -1;
        }
        else if (c >= '0' && c <= '9') {
            top++;
            stack[top] = (c - '0') * sign;
        }
        else if (c == '+') {
            t = stack[top-1] + stack[top];
            top--;
            stack[top] = t;
        }
        else if (c == '-') {
            t = stack[top-1] - stack[top];
            top--;
            stack[top] = t;
        }
        else {
            t = stack[top-1] * stack[top];
            top--;
            stack[top] = t;
        }

        //cout << stack[top] << "\n";
    }

    cout << stack[0];
    return 0;
}