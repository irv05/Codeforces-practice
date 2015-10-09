//Irvin Gonzalez
//Two Buttons

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


