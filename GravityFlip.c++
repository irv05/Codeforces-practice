//Gravity Flip
//Irvin Gonzalez
//
//
#include <algorithm>
#include <iostream>

int main() {
	using namespace std;
	int col;
	cin >> col;
	int box[col];
	for(int i = 0; i < col; ++i){
		cin >> box[i]; }
	sort(box, box+col);

	for(int i = 0; i < col; ++i){
		cout << box[i] << " ";}

	return 0;}

