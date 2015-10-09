//Irvin Gonzalez
//Kitayuta's Gift
//

#include <iostream>
#include <string>
bool palcheck(std::string& word){
	int b = 0;
	int e = word.size() - 1;

	while(b < e ) {
		if(word[b] != word[e]) {
			return false;}
		++b;
		--e; }
	return true;
}
int main() {
	using namespace std;
	string word;
	cin >> word;
	if(word.size() == 1) {
		word.insert(word.begin(),word[0]); 
		cout << word;
		return 0; }
	if(palcheck(word) && (word.size()%2 == 0)) {
		word.insert(word.size()/2, "a"); }
	//else if(palcheck(word)) {
		//cout << "NA";
		//return 0; }
	else {
		int pos = 0;
		string word2(word);
		char r = word2[0];
		word2.erase(word2.begin() + pos);
		while(!palcheck(word2)){
			word2.insert(word2.begin() + pos, r);
			++pos;
			if(pos >= word2.size()) {
				cout << "NA";
				return 0;}
			r = word2[pos];
			word2.erase(word2.begin() + pos);
		}
		if(pos > word.size()/2) ++pos;
		word.insert(word.end() - pos, r); 
	}
	cout << word;
	return 0;}

