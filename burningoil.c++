//Irvin Gonzalez
//Burning midnight oil.
//

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
