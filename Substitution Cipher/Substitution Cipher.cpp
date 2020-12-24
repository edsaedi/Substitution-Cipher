#include <iostream>
#include<string.h>
#include <vector>
#include <ctime>
#include<cstdlib>

using namespace std;

string newAlphabet(string oldAlphabet, char toDelete)
{
	string newAlphabet = "";
	for (size_t i = 0; i < oldAlphabet.length(); i++)
	{
		if (oldAlphabet[i] != toDelete)
		{
			newAlphabet += oldAlphabet[i];
		}
	}

	return newAlphabet;
}

string GetKey()
{
	srand(std::time(nullptr));
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string key = "";

	string oldAlphabet = alphabet;
	for (size_t i = 26; i > 0; i--)
	{
		int random = rand() % i;
		key += oldAlphabet[random];
		oldAlphabet = newAlphabet(oldAlphabet, oldAlphabet[random]);
	}

	return key;
}

int alphabetIndex(char character)
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (size_t i = 0; i < alphabet.length(); i++)
	{
		if (alphabet[i] == character)
		{
			return i;
		}
	}

	return -1;
}

string Encryption(string key, string plaintext)
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string encrypted = "";

	for (size_t i = 0; i < plaintext.length(); i++)
	{
		auto temp = alphabetIndex(plaintext[i]);
		if (temp == -1)
		{
			encrypted += plaintext[i];
		}
		else
		{
			encrypted += key[temp];
		}
	}
	return encrypted;
}

int main()
{
	//cout << GetKey();
	std::string plaintext = "Marry had a little lamb";
	cout << Encryption(GetKey(), plaintext);
}


