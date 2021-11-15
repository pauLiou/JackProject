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
	

string randomGender(){
	string gender[] = {"Male", "Female", "Mental"};
	srand(time(NULL));
	return gender[rand() % 3];
}

class JackDude {
public:
	string name;
	string email;
	string gender;
};


int main() {

	JackDude Jack;
	string firstName = fullName[0];
	string surName = fullName[1];
	Jack.name = firstName + " " + surName;
	Jack.email = emailAddress(firstName, surName);
	Jack.gender = randomGender();
	


	cout << "The name is: " << Jack.name << endl;
	cout << "The email address is: " << Jack.email << endl;
	cout << "Gender: " << Jack.gender << endl;

	cin.get();
	return 0;
}