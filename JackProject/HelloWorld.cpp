#include <iostream>
#include <string>
#include <random>
#include <tuple>
#include <sstream>

using namespace std;


string randomName(const int timeR) {
	int i = 0;
	std::string c;
	c.reserve();
	//std::string 
	char vowel[] = { 'a','e','i','o','u' };
	int r;
	int x = rand() % (12 - 2 + 1) + 2;
	int y;
	
	
	srand(time(NULL)+timeR);
	for (i = 0; i < x; i++) {
		y = rand() % (4 - 0 + 1) + 0;
		r = rand() % 26;
		c += 97 + r;
		if (i == 0 && timeR != 3) {
			c[i] = toupper(c[i]);
		}
		else if (i % 2 == 1){
			c[i] = vowel[y];
		}
		
	}
	return c;
}

string fullName[2] = {randomName(1),randomName(2)};
string s1;
string s2;


string emailAddress(string s1, string s2) {

	stringstream ss(s2);
	string newString = s1 + "." + ss.str() + "@" + randomName(3) + ".com";

	return newString;
}
	
	



int main() {

	
	

	cout << "The first name is: " << fullName[0] << endl;
	cout << "The surname is: " << fullName[1] << endl;


	cout << "The email address is: " << emailAddress(fullName[0],fullName[1]) << endl;

	return 0;
}