/*
http://codeforces.com/problemset/problem/165/B
Burning midnight oil.

One day a highly important task was commissioned to Vasya — writing a program in a night. The program consists of n lines of code. 
Vasya is already exhausted, so he works like that: first he writes v lines of code, drinks a cup of tea, then he writes as much as  
v/k lines, drinks another cup of tea, then he writes v/(k^2) lines and so on: v/(k^3), v/(k^4), v/(k^5), ...

The expression a/b is regarded as the integral part from dividing number a by number b.

The moment the current value v/(k^p) equals 0, Vasya immediately falls asleep and he wakes up only in the morning, when the program should 
already be finished.

Vasya is wondering, what minimum allowable value v can take to let him write not less than n lines of code before he falls asleep.

Input
The input consists of two integers n and k, separated by spaces — the size of the program in lines and the productivity reduction
coefficient, 1 ≤ n ≤ 109, 2 ≤ k ≤ 10.

Output
Print the only integer — the minimum value of v that lets Vasya write the program in one night.
*/

#include <iostream>
bool solve(const int& n, const int& v, const int& k) {
	int work = v;
	int curk = k;
	if(work >= n)	return true; 
	while((v/curk)!= 0) {
		//std::cout << "    work: " << work << " k: " << k << std::endl;
		work += (v/curk);
		if(work >= n) return true;
		curk *= k; }
	return false;
}
int main() {
	using namespace std;

	int n;
	int k;
	cin >> n;
	cin >> k;

	int low = 0;
	int high = n;

	while(low != high) {
		int mid = (high/2 + low /2);
		if(high%2 != 0 || low%2 != 0) ++mid;
		//cout << "low: " << low << "   high: " << high << "    mid: " << mid << endl;
	       	if(mid == high) low = mid;	
		else if(solve(n, mid, k)) high = mid; 
		else low = mid;}
	cout << low << endl; }
