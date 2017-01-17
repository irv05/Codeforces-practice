/*******
Irvin Gonzalez
24 Game

Little X used to play a card game called "24 Game", but recently he has found it too easy. So he invented a new game.

Initially you have a sequence of n integers: 1, 2, ..., n. In a single step, you can pick two of them, let's denote them a and b, 
erase them from the sequence, and append to the sequence either a + b, or a - b, or a × b.

After n - 1 steps there is only one number left. Can you make this number equal to 24?

Input
The first line contains a single integer n (1 ≤ n ≤ 105).

Output
If it's possible, print "YES" in the first line. Otherwise, print "NO" (without the quotes).

If there is a way to obtain 24 as the result number, in the following n - 1 lines print the required operations an operation per line. 
Each operation should be in form: "a op b = c". Where a and b are the numbers you've picked at this operation; op is either "+", 
or "-", or "*"; c is the result of corresponding operation. Note, that the absolute value of c mustn't be greater than 1018. 
The result of the last operation must be equal to 24. Separate operator sign and equality sign from numbers with spaces.

If there are multiple valid answers, you may print any of them.

********/
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






