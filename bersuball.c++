/*
http://codeforces.com/problemset/problem/489/B
berSU ball


The Berland State University is hosting a ballroom dance in celebration of its 100500-th anniversary! n boys and m girls are already 
busy rehearsing waltz, minuet, polonaise and quadrille moves.

We know that several boy&girl pairs are going to be invited to the ball. However, the partners' dancing skill in each pair must differ 
by at most one.

For each boy, we know his dancing skills. Similarly, for each girl we know her dancing skills. Write a code that can determine the 
largest possible number of pairs that can be formed from n boys and m girls.

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of boys. The second line contains sequence a1, a2, ..., 
an (1 ≤ ai ≤ 100), where ai is the i-th boy's dancing skill.

Similarly, the third line contains an integer m (1 ≤ m ≤ 100) — the number of girls. The fourth line contains sequence 
b1, b2, ..., bm (1 ≤ bj ≤ 100), where bj is the j-th girl's dancing skill.

Output
Print a single number — the required maximum possible number of pairs.
*/

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







