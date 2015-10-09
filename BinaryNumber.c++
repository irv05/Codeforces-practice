//Irvin Gonzalez
//Binary Number
//


#include <iostream>
#include <string>
int count_zeroes(std::string& num) {
	int count = 0;
	int i = 0;
	while(num[i] != '1'){
		++i;}
	++i;
	return num.size() - i ; }

int count_ones(std::string& num){
	int count = 0;
	for(int x = 0; x < num.size(); ++x) {
		if(num[x] == '1') {
			++count;}}
	return count;}
		
int main(){
	using namespace std;

	 string num;
	 cin >> num;

	 int ops = 0;
	 int casc = num.size() -1;
	 while(casc >0) {
		 if(num[casc] == '1') {
			 int ones = 0;
			 while(casc >= 0 && num[casc]!='0') {
				 num[casc] = '0';
				 ++ones;
				 --casc;}
			 //cout << casc << endl;
			 if(casc < 0){
				 num = "1";
				 //cout << num << endl;
				 }
			 else{
				 num[casc] = '1';
			 	 //num = num.substr(0,casc);
				 }
	       		ops +=ones + 1;}
		 else{
			int zeroes = 0;
			while(num[casc] != '1') {
				++zeroes;
				--casc; }
			//num = num.substr(0,casc);
			ops += zeroes; } }
	 //ops += count_zeroes(num);
	 cout << ops;}
