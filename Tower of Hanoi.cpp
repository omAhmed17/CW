#include <iostream> 
#include <cmath> 
using namespace std;
void Restricted_Hanoi(int n, char A, char B, char C) {
	if (n == 0) return;
	Restricted_Hanoi(n - 1, A, B, C);
	cout << "Move disk " << n << " from " << A << " to " << B << endl;
	Restricted_Hanoi(n - 1, C, B, A);
	cout << "Move disk " << n << " from " << B << " to " << C << endl;
	Restricted_Hanoi(n - 1, A, B, C);
}
int main() {
	int n;
	cout << "Enter number of disks: ";
	cin >> n;
	cout << "\nSequence of moves:\n";
	Restricted_Hanoi(n, 'A', 'B', 'C');
	int total_moves = 3 * pow(2, n - 1) - 2;
	cout << "\nTotal moves (Restricted): " << total_moves << endl;
	return 0;
}
