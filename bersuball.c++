//Irvin Gonzalez
//berSU ball
//

#include <iostream>
#include <algorithm>

int main(){
	using namespace std;

	int n;
	cin >> n;
	int boys[n];
	for(int i = 0; i < n; ++i) { 
		cin >> boys[i]; }
	int m;
	cin >> m;
	int girls[m];
	for(int i = 0; i < m; ++i) {
		cin >> girls[i]; }

	sort(boys, boys + n);
	sort(girls, girls + m);


	int i = 0;//boys index
	int j = 0;//girls index
	int pairs = 0;

	while(i < n && j < m) {
		if(boys[i] <= girls[j]) {
			if((girls[j] - boys[i]) > 1) ++i;
			else {
				++i;
				++j;
				++pairs;} }
		else {
			if((boys[i] - girls[j]) > 1) ++j;
			else {
				++i;
				++j;
				++pairs;}} }
	cout << pairs; }	







