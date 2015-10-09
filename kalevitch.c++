//Irvin Gonzalez
//Kalevitch problem
//


#include <iostream>
#include <utility>
template <size_t rows, size_t cols>
bool look( char (&board)[rows][cols], const std::pair<int, int>& dir, std::pair<int, int> pos, bool worth) {
	if(pos.first < 8 && pos.second < 8 ) {
		if(board[pos.first][pos.second] == 'W') {
			return false;}

		if(board[pos.first][pos.second] == 'B') 
			return look(board, dir, std::pair<int, int> (pos.first+dir.first, pos.second+dir.second), true);
		else
			return look(board, dir, std::pair<int, int> (pos.first+dir.first, pos.second+dir.second), worth);}
	return worth;}

template <size_t rows, size_t cols> 
void paint( char (&board)[rows][cols],const std::pair<int, int>& dir, std::pair<int, int> pos) {
	//base
	if(pos.first < 8 && pos.second < 8){
		paint(board, dir, std::pair<int,int>(pos.first+dir.first, pos.second+dir.second));}
	board[pos.first][pos.second] = 'b';}

int main(){
	using namespace std;
	char board[8][8];
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j) {
			cin >> board[i][j];} }
	
	int count = 0;
	//columns
	std::pair<int, int> down(1,0);
	for(int y = 0 ; y < 8; ++y) {
		if(look(board, down, pair<int, int> (0, y), false)) {
			paint(board, down, pair<int, int> (0, y));
			++count;}}
	//rows
	std::pair<int, int> right(0,1);
	for(int x = 0; x < 8; ++x) {
		if(look(board, right, pair<int, int> (x, 0), false)) {
			paint(board, down, pair<int, int> (x, 0));
			++count;}} 
	cout << count; }


