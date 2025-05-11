#include <iostream>
#include <cstring>

template <typename K, typename V>

class Map {
private:
	struct element {
		K key;
		V value;
		int index;
	};
	int nr = 0;
	element a[100];

public:

	void Set(const K& key, const V& value) {

		// Cauta daca exista cheia, daca exista ii modifica valoarea
		int ok = 0;
		for (int i = 0; i < nr && ok == 0; i++)
			if (a[i].key == key)
			{
				a[i].value = value;
				ok = 1;
			}
		if(!ok) a[nr] = { key, value, nr };
		nr++;
		return;
	}

	bool Get(const K& key, V& value) {
		
		//Cauta cheia, daca o gaseste returneaza valoarea prin referinta + true, altfel false
		for (int i = 0; i < nr; i++)
			if (a[i].key == key) {
				value = a[i].value;
				return true;
			}
		return false;
	}

	int Count() {
		return nr;
	}

	void Clear() {
		nr = 0;
	}

	bool Delete(const K& key) {

		// Sterge o cheie

		for (int i = 0; i < nr;i++)
			if (a[i].key == key) {
				for (int j = i + 1; j < nr; j++)
					a[j - 1] = a[j];
				nr--;
				return true;
			}
		return false;
	}

	bool Includes(const Map<K, V>& map) {

		// Verifica daca toate cheile din mapa mea exista in mapa "map"
		for (int i = 0;i < nr;i++)
		{
			int value = 0;
			if (!map.Get(a[i].key, value)) return false;
		}
		return true;
	}

	V& operator[](const K& key)
	{

		// Daca cheia exista, returneaza referinta la valoarea ei, daca nuu o adauga 

		for (int i = 0; i < nr; i++)
			if (a[i].key == key)
				return a[i].value;

		a[nr] = { key, V(), nr };
		nr++;
		return a[nr - 1].value;
	}

	// Pentru folosirea buclei for din main
	const element* begin() const {

		// Pointer catre inceputul datelor
		return &a[0];
	}
	const element* end() const {

		// Pointer catre finalul datelor
		return &a[nr];
	}

	bool operator!= (Map<K, V> map)
	{
		if (nr != map.nr)
			return false;
		for (int i = 0; i < nr; i++) {
			if (a[i].key != map.a[i].key)
				return false;
			if (a[i].value != map.a[i].value)
				return false;
		}
	}
	
};
int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";

	//structured bindings permite sa destructurezi un obiect cu mai multe campuri
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	std::cout << std::endl;
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}
