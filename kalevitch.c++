/*
http://codeforces.com/problemset/problem/7/A
Kalevitch and Chess

A famous Berland's painter Kalevitch likes to shock the public. One of his last obsessions is chess. For more than a thousand years 
people have been playing this old game on uninteresting, monotonous boards. Kalevitch decided to put an end to this tradition
and to introduce a new attitude to chessboards.

As before, the chessboard is a square-checkered board with the squares arranged in a 8 × 8 grid, each square is painted black or 
white. Kalevitch suggests that chessboards should be painted in the following manner: there should be chosen a horizontal or a 
vertical line of 8 squares (i.e. a row or a column), and painted black. Initially the whole chessboard is white, and it can be 
painted in the above described way one or more times. It is allowed to paint a square many times, but after the first time it does 
not change its colour any more and remains black. Kalevitch paints chessboards neatly, and it is impossible to judge by an 
individual square if it was painted with a vertical or a horizontal stroke.

Kalevitch hopes that such chessboards will gain popularity, and he will be commissioned to paint chessboards, which will 
help him ensure a comfortable old age. The clients will inform him what chessboard they want to have, and the painter will
paint a white chessboard meeting the client's requirements.

It goes without saying that in such business one should economize on everything — for each commission he wants to know the 
minimum amount of strokes that he has to paint to fulfill the client's needs. You are asked to help Kalevitch with this task.

Input
The input file contains 8 lines, each of the lines contains 8 characters. The given matrix describes the client's requirements, 
W character stands for a white square, and B character — for a square painted black.

It is guaranteed that client's requirments can be fulfilled with a sequence of allowed strokes (vertical/column or horizontal/row).

Output
Output the only number — the minimum amount of rows and columns that Kalevitch has to paint on the white chessboard to 
meet the client's requirements.
*/

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


