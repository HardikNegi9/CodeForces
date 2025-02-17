#include<iostream>
#include<string>

using namespace std;

int solve(string& s, int left, int right, char remove) {
    int removals = 1;
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            if (s[left] == remove) {
                left++;
                removals++;
            } else if (s[right] == remove) {
                right--;
                removals++;
            } else {
                return -1;
            }
        }
    }
    return removals;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool isPalindrome = true;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }

        if (isPalindrome) {
            cout << 0 << endl;
            continue;
        }

        int removeLeft = solve(s, left + 1, right, s[left]);

        int removeRight = solve(s, left, right - 1, s[right]);

        if (removeLeft == -1 && removeRight == -1) {
            cout << -1 << endl;
        } else if (removeLeft == -1) {
            cout << removeRight << endl;
        } else if (removeRight == -1) {
            cout << removeLeft << endl;
        } else {
            cout << min(removeLeft, removeRight) << endl;
        }
    }
    return 0;
}