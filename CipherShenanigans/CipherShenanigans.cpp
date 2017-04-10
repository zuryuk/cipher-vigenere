// CipherShenanigans.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using std::cout; using std::cin; using std::endl; using std::string;
const char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char space = char(32);
const char dot = char(46);

string cipher(string key, string msg);
string decipher(string key, string cipher);
float friedman(string cipher);

int main()
{
	string msg = "HELLO THIS IS ME. JOONAS YOUR FAVOURITE FRIEND";
	string key = "WEASEL";

	string ciphered = cipher(key, msg);
	cout << "Ciphered message: " << ciphered << endl;
	cout << "Cipher key: " << key << endl;
	cin.get();
	cin.clear();
	string deciphered = decipher(key, ciphered);
	cout << "Message: " << deciphered << endl;
	cin.get();
    return 0;
}


string cipher(string key, string msg) {
	string cipher;

	while (key.length() < msg.length()) {
		key += key;
	}

	char keyarray[1024];
	char msgarray[1024];

	strcpy(keyarray, key.c_str());
	strcpy(msgarray, msg.c_str());

	for (int i = 0; i < msg.length(); i++) {
		if (msgarray[i] == space) {
			cipher += " ";
		}
		else if(msgarray[i] == dot){
			cipher += ".";
		}
		else {
			int coded = msgarray[i] - keyarray[i];
			if (coded < 0) {
				 coded += 26;
			}

			char a = alphabets[coded];
			cipher += a;
		}
	}
	return cipher;
}

string decipher(string key, string msg) {
	string message;
	while (key.length() < msg.length()) {
		key += key;
	}

	char keyarray[1024];
	char msgarray[1024];

	strcpy(keyarray, key.c_str());
	strcpy(msgarray, msg.c_str());
	
	for (int i = 0; i < msg.length(); i++) {
		if (msgarray[i] == space) {
			message += " ";
		}
		else if (msgarray[i] == dot) {
			message += ".";
		}
		else {
			int coded = msgarray[i] + keyarray[i] - 130;
			if (coded > 25) {
				coded -= 26;
			}
			char a = alphabets[coded];
			message += a;
		}
	}
	return message;
}

float friedman(string cipher) {
	float friedman;
	return 0;
}