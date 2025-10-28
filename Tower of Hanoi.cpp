#include <iostream>
using namespace std;

int total_moves = 0; 

void Restricted_Hanoi(int n, char A, char B, char C) {
    if (n == 0) return;

    Restricted_Hanoi(n - 1, A, B, C);
    cout << "Move disk " << n << " from " << A << " to " << B << endl;
    total_moves++;

    Restricted_Hanoi(n - 1, C, B, A);
    cout << "Move disk " << n << " from " << B << " to " << C << endl;
    total_moves++;

    Restricted_Hanoi(n - 1, A, B, C);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    cout << "\nSequence of moves:\n";
    Restricted_Hanoi(n, 'A', 'B', 'C');
    cout << "\nTotal moves: " << total_moves << endl;
    return 0;
}
