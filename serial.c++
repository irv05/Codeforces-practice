//Irvin Gonzalez
//Serial Time!
//


#include <iostream>
#include <vector>
#include <stack>
int main(){
	using namespace std;

	int m;
	int n; 
	int k;

	cin >> k;
	cin >> n;
	cin >> m;
	k+=2;
	n+=2;
	m+=2;

	//make plate
	char plate[k][n][m];
	for(int z = 0; z< k; ++z) {
		for(int y = 0; y< n; ++y) {
			for(int x = 0; x < m; ++x) {
				if(z == 0 || z == k-1 || y == 0 || y == n -1 || x == 0 || x == m-1) {
					plate[z][y][x] = '#';}
				else
					cin >> plate[z][y][x]; }}}
	//traverse
	int x;
	int y;
	int z = 1;
	cin >> y;
	cin >> x;

	plate[z][y][x] = ',';
	int dx[6] = {0,1,0,-1,0,0};	
	int dy[6] = {1,0,-1,0,0,0};
	int dz[6] = {0,0,0,0,1,-1};
	stack<vector<int> > fill;
	vector<int> temp;
	temp.push_back(x);
	temp.push_back(y);
	temp.push_back(z);
	fill.push(temp);
	int time = 0;
	while(!fill.empty()){
		++time;
		int xx = fill.top()[0];
		int yy = fill.top()[1];
		int zz = fill.top()[2];
		//cout << "coords: " << xx << yy << zz << endl;
		fill.pop();
		for(int di = 0; di < 6; ++di){
			if(plate[zz+dz[di]][yy+dy[di]][xx+dx[di]] == '.') {
				plate[zz+dz[di]][yy+dy[di]][xx+dx[di]] = ',';
				vector<int> temp2;
				temp2.push_back(xx + dx[di]);
				temp2.push_back(yy + dy[di]);
				temp2.push_back(zz + dz[di]);
				fill.push(temp2); } } }

	cout << time;}
















	
