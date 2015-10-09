//Irvin Gonzalez
//24 game
//

#include <iostream>

int main() {
	using namespace std;
	int n;
	cin >> n;

	if(n<4) {
		cout << "NO";}

	if(n >=4) { cout << "YES" << endl; }
	if(n == 4) {
		cout << "1 * 2 = 2" << endl;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl; }
	if(n == 5) {
		cout << "4 - 2 = 2" << endl;
		cout << "2 + 3 = 5" << endl;
		cout << "5 * 5 = 25" << endl;
		cout << "25 - 1 = 24" << endl; }
	if(n == 6) {
		cout << "6 - 3 = 3" << endl;
		cout << "4 - 2 = 2" << endl;
		cout << "2 + 3 = 5" << endl;
		cout << "5 * 5 = 25" << endl;
		cout << "25 - 1 = 24" << endl; }
	if(n == 7) {
		cout << "1 + 3 = 4" << endl;
		cout << "4 + 4 = 8" << endl;
		cout << "8 + 5 = 13" << endl;
		cout << "13 + 6 = 19" << endl;
		cout << "7 - 2 = 5" << endl;
		cout << "19 + 5 = 24" << endl;}
	
	bool odd = false;
	if(n%2 != 0) odd = true;
	if(n >= 8) {
		int countones = 0;
		while(n>9) {
			int first = n;
			--n;
			int second = n;
			--n;
			cout << first << " - " << second << " = 1" << endl;
			++countones; }
		if(!odd){
			cout << "8 * 7 = 56" << endl;
			cout << "6 * 5 = 30" << endl;
			cout << "4 - 3 = 1" << endl;
			cout << "2 - 1 = 1" << endl; }
		else{
			cout << "8 * 7 = 56" << endl;
			cout << "6 * 5 = 30" << endl;
			cout << "2 * 3 = 6" << endl;
			cout << "6 + 4 = 10" << endl;
			cout << "10 - 9 = 1" << endl; }
		while(countones != 0) {
			cout << "1 * 1 = 1" << endl;
			--countones;}
		cout << "30 + 1 = 31" << endl;
		cout << "56 - 31 = 25" << endl;
		cout << "25 - 1 = 24" << endl; }} 






