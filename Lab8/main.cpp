#include <iostream>
#include <fstream>
#include <map>
#include<queue>
#include <string>
using namespace std;
ifstream f("file.in");

struct cmp {
	int nr;
	string cuv;

	bool operator < (const cmp& x)const {
		if (nr < x.nr) return true; // Cuv cu frecv mai mica trece mai jos
		if (nr == x.nr) return cuv > x.cuv; // Daca cuv sunt egale le ordonam alfabetic 
		return false;
	}
};
void transformare(string& s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
}

int main() {
	string s;
	map <string, int> map;
	getline(f, s);

	transformare(s);

	auto separatoare = s.find_first_of(" ,.?!"); // Cauta primul separator

	while (!s.empty()) {
		// string::npos este o constanta, arata ca "nu s-a gasit nimic" sau "poz invalida"
		if (separatoare != string::npos) {
			if (separatoare > 0)
				map[s.substr(0, separatoare)]++;

			s = s.substr(separatoare + 1);
			separatoare = s.find_first_of(" ,.?!");
		}
		else {
			// Tratam ultimul cuvant 
			if (!s.empty())
				map[s]++;
			break;
		}
	}

	
	priority_queue <cmp> q;
	for (auto i : map) {
		cmp element;
		element.nr = i.second;
		element.cuv = i.first;
		q.push(element);
	}

	while (!q.empty()) {
		cout << q.top().cuv << " => ";
		cout << q.top().nr << endl;
		q.pop();
	}
	return 0;
}