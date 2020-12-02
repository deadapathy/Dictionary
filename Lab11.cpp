
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

class Dictionary
{
    map <string, string> words;

public:
	void add(string word);
	string search(string word);
	void remove(string word);
	void print();

};


void Dictionary::add(string word)
{
	words[word];
}

string Dictionary::search(string word)
{
	auto it = words.find(word);
	if (it != words.end()) {
		return it->first;
	}
	else return "\nThis word doesn't exist yet\n";
}

void Dictionary::remove(string word)
{
	auto it = words.find(word);
}

void Dictionary::print()
{
	for_each(words.begin(), words.end(), [](pair<string, string> p) {cout << "word: " << p.first << endl; });	
}


int main()
{
	ifstream in("words.txt");
	int choice;
	Dictionary d;
	string word;

	while (!in.eof()) {
		getline(in, word);
		d.add(word);
	}

	while (true) {
		cout << "1 - Add new word" << endl;
		cout << "2 - Search word" << endl;
		cout << "3 - Delete word" << endl;
		cout << "4 - Show all words" << endl;
		cout << "0 - exit" << endl;
		cin >> choice;
		if (!choice) break;

		switch (choice)
		{
		case 1:
			cout << "Enter word: " << endl;
			cin >> word;
			d.add(word);
			break;
		case 2:
			cout << "Enter search word: " << endl;
			cin >> word;
			cout << d.search(word) << endl;
			break;
		case 3:
			cout << "Enter word for delete: " << endl;
			cin >> word;
			d.remove(word);
			break;
		case 4:
			d.print();
			break;

		default:
			cout << "Ashibka" << endl;
			break;
		}

	}
}