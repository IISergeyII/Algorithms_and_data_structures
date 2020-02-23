#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

#define SIZE 100000

int main() {
    ios_base::sync_with_stdio(false);
    // ======================
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    // ====================== */

    string s;
    char c;
    char stack[SIZE];
    int top;
    bool is_valid;

    while (cin >> s) {

        top = -1;
        is_valid = true;


        for (int i = 0; i < s.length(); ++i) {
            c = s[i];
            if (c == '(' || c == '[') {
                top++;
                stack[top] = c;
            } else if (top == -1) {
                is_valid = false;
                break;
            } else if (c == ')') {

                if (stack[top] != '(') {
                    is_valid = false;
                    break;
                } else {
                    top--;
                }

            } else {

                if (stack[top] != '[') {
                    is_valid = false;
                    break;
                } else {
                    top--;
                }

            }
        }
        cout << (is_valid && top == -1 ? "YES\n" : "NO\n");
    }

    return 0;
}