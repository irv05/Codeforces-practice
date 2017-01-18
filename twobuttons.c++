/*
http://codeforces.com/problemset/problem/520/B
Two Buttons

Vasya has found a strange device. On the front panel of a device there are: a red button, a blue button and a display showing 
some positive integer. After clicking the red button, device multiplies the displayed number by two. After clicking the blue 
button, device subtracts one from the number on the display. If at some point the number stops being positive, the device breaks 
down. The display can show arbitrarily large numbers. Initially, the display shows number n.

Bob wants to get number m on the display. What minimum number of clicks he has to make in order to achieve this result?

Input
The first and the only line of the input contains two distinct integers n and m (1 ≤ n, m ≤ 10^4), separated by a space .

Output
Print a single number — the minimum number of times one needs to push the button required to get the number m out of number n.

Examples
*/
#include <iostream>

int main() {
	using namespace std;
	int n;
	int m;
	cin >> n;
	cin >> m;

	int clicks = 0;
	while(m != n) {
		if(n > m) {
			++m;
			++clicks;}
		else {
			if(m%2 !=0){
				++m;
		       		++clicks; }
			else{
				m = m/2;
				++clicks;}
		}
	}
	cout << clicks;
	return 0;
}


