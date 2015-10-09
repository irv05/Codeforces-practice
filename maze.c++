//Irvin Gonzalez
//Maze


#include <iostream>
#include <stack>
#include <utility>

/*int count_r(char **maze, int x, int y , std::stack<std::pair<int, int> >& path) {
	if(maze[y][x] != '.') {
		return 0; }
	
	maze[y][x] = ',';
	path.push(std::pair<int, int>(x, y));

	int total = 1 + count_r(maze, x, y+1, path) + count_r(maze, x, y-1, path) + count_r(maze, x+1, y, path) + count_r(maze, x-1, y, path);
	return total;
}
int count(char **maze, int x, int y) {
	std::stack<std::pair<int, int> > path;
	int ret = count_r(maze, x, y, path);

	while(!path.empty()) {
		int i = path.top().first;
		int j = path.top().second;
		path.pop();
		maze[j][i] = '.'; }
	return ret;} 


void next_dot(char **maze, int& x, int& y, int& r, int& c){
	++x;
	if(x > c-1){
		x = 1;
		++y;
       		if(y > r-1) return;}
	while(maze[y][x] != '.'){
		++x;
		if(x > c-1){
			x = 1;
			++y;
			if(y > r-1) return; }}}*/
int main() {
	using namespace std;
	int r;
	int c;
	int k;
	cin >> r;
	cin >> c;
	cin >> k;
	//populate maze
	
	r+=2;
	c+=2;
	char maze[r][c];
	int total = 0;
	int i = -1;
	int j = 0;
	for(int ii= 0; ii < r; ++ii) {
		for(int jj = 0; jj < c; ++jj) {
			if(ii == 0 || ii == r-1 || jj == 0 || jj == c-1) {
				maze[ii][jj] = '#'; }
			else {
				cin >> maze[ii][jj];
		       		if(maze[ii][jj] == '.'){
				       if(i == -1) {
				       		i = ii;
				 		j = jj;}
						++total; } }
			}
	}

	//int i = 1;
	//int j = 1;
	//if(maze[j][i] != '.') {
		//next_dot(maze, i, j, r, c);}

	//create a path:
	int p_tot = total - k;
	int p_cur = 0;
	stack<pair<int, int> > paths;
	paths.push(pair<int, int>(i, j));
	while(k!=0) {
		while(maze[paths.top().second][paths.top().first] != '.') {
			paths.pop(); }
		int x = paths.top().first;
		int y = paths.top().second;
		paths.pop();

		if(p_cur == p_tot) {
			maze[y][x] = 'X';
			--k; }
		else {
			maze[y][x] = ',';
			++p_cur;}

		if(maze[y+1][x] == '.') paths.push(pair<int, int>(x, y+1));
		if(maze[y-1][x] == '.') paths.push(pair<int, int>(x, y-1));
		if(maze[y][x+1] == '.') paths.push(pair<int, int>(x+1, y));
		if(maze[y][x-1] == '.') paths.push(pair<int, int>(x-1, y));
	}
	/*while(k!=0) {
		next_dot(maze, i , j, r, c);
		maze[j][i] = 'X';
		--k;}*/

	
	for(int i= 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			if(i != 0 && i != r-1 && j != 0 && j != c-1){ 
				if(maze[i][j] == ',') cout << '.';
				else cout << maze[i][j]; } }
       		cout << endl; }
	
	//for (int i=0; i<r; i++)
    	//	delete [] maze[i];
	//delete [] maze;
	return 0;
}
/*	OTHER IDEAS:
 *	int cnt = 0;
		//maze[y][x] = 'X';
		stack<pair<int, int> > paths;
		stack<pair<int, int> > dump;
		paths.push(pair<int,int>(i,j));
		
		while(k != 0){
			pair<int,int> cur = paths.top();
			paths.pop();
			int x = cur.first;
			int y = cur.second;
			if(maze[y][x] == '.') {
				maze[y][x] = 'X';
				dump.push(cur);
				--k;
				--total;

				if(maze[y+1][x] == '.') { 
					paths.push(pair<int,int>(x, y+1));}
				if(maze[y-1][x] == '.') { 
					paths.push(pair<int,int>(x, y-1));}
				if(maze[y][x+1] == '.') { 
					paths.push(pair<int,int>(x+1, y));}
				if(maze[y][x-1] == '.') { 
					paths.push(pair<int,int>(x-1, y));}
				if(pahts.empty) {
					next_dot(maze, x, y,r, c);
					if(y>r-1) {

					paths.push(pair<int,int>(x,y));
					}}
			if(k==0){
				while(paths.top() != '.'){
					paths.pop();}
				int count = count(maze, paths.top().first, paths.top().second);
				if(count!= total) {
					maze[y][x]}}

		cout << "k: " << k << endl;
		if(k!=0) {
			//flush
			while(!dump.empty()){
				int x = dump.top().first;
				int y = dump.top().second;
				dump.pop();
				maze[y][x] = '.';
				++k;
				++total; }
			next_dot(maze, i , j , r, c);	}
		else {
			int ci = 1;
			int cj = 1;
			if(maze[cj][ci] != '.') {
				next_dot(maze, ci, cj, r, c); }
			cout << "after count" <<endl;
			int cnt_2 = count(maze, ci, cj);
			for(int f= 0; f < r; ++f) {
				for(int g = 0; g < c; ++g) {
					if(f != 0 && f != r-1 && g != 0 && g != c-1){ 
						cout << maze[f][g]; } }
       		cout << endl; }
			cout << "total: " << total << ", cnt_2: " << cnt_2 << endl;
			if(cnt_2 != total) {
				//flush
				while(!dump.empty()){
					int x = dump.top().first;
					int y = dump.top().second;
					dump.pop();
					maze[y][x] = '.';
					++k;
					++total; }
				next_dot(maze, i , j , r, c);}}
		//cout << "after while" << endl;





		cout << "run: " << endl;
		cout << k << endl;
		cout << "y: " << y << endl;
		cout << "x: " << x << endl;
		cout << maze[y][x] << endl;*/
		
		/* FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFUUUUUUUUUUuuuuuuck
		
		int cnt = 0;
		maze[y][x] = 'X';
		
		int d_e = 0;
		int xx;
		int yy;
		bool pathblock = true;
		if(maze[y+1][x] == '.') { 
			++d_e;
			xx = 2;
			yy = 3;}
		if(maze[y-1][x] == '.') { 
			++d_e;
			xx = 2;
			yy = 1;}
		if(maze[y][x+1] == '.') { 
			++d_e;
			xx = 3;
			yy = 2;}
		if(maze[y][x-1] == '.') { 
			++d_e;
			xx = 1;
			yy = 2;}
		int babycnt = 0;
		if(d_e == 1) pathblock = false;
		else{	
			//cout << "here1" << endl;
			char **babymaze;
			babymaze = new char *[5];
			for(int i= 0; i < 5; ++i) {
				babymaze[i] = new char[5];
				for(int j = 0; j < 5; ++j) {
					if(i == 0 || i == 4 || j == 0 || j == 4) {
						babymaze[i][j] = '#'; }
					else {
						babymaze[i][j] = maze[y-2+i][x-2+j];} } }
			babycnt = count(babymaze, xx, yy);
			if(d_e == 2){
				if(babycnt >= 3) pathblock = false; }
			if(d_e == 3) {
				if(babycnt >= 5) pathblock = false; }
			if(d_e == 4) {
				if(babycnt >= 7) pathblock = false; }
			//cout << "here2" << endl;
	       		for (int i=0; i<5; i++)
    				delete [] babymaze[i];
			delete [] babymaze;
	       		}
			

		if(pathblock) {
			//cout << "d_e: "<< d_e << endl;
			//cout << "babycnt: " << babycnt << endl;
			if(maze[y+1][x] == '.') { 
				cnt = count(maze, x, y+1);}
			else if(maze[y-1][x] == '.') { 
				cnt = count(maze, x, y-1);}
			else if(maze[y][x+1] == '.') { 
				cnt = count(maze, x+1, y);}
			else if(maze[y][x-1] == '.') { 
				cnt = count(maze, x-1, y);} }

		//cout << "total: " << total << endl;
		//cout << "cnt: " << cnt << endl;
		if(!pathblock) {
			--k;
			--total;}
		else if(cnt != total) {
			//cout << y << " " << x << endl;
			maze[y][x] = '.'; }
		else{
			--k;
			--total;}
			
		//cout << k << endl;	
		if(k!=0) {	
			next_dot(maze, x, y, r, c);
	       		if(y > r -1) {
				x = 1;
				y = 1;
				next_dot(maze, x, y, r, c);}}
		} */

