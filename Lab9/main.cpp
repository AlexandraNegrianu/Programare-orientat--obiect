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
		int ok = 0;
		for (int i = 0; i < nr && ok == 0; i++)
			if (a[i].key == key)
			{
				a[i].value = value;
				ok = 1;
			}
		a[nr] = { key, value, nr };
		nr++;
		return;
	}

	bool Get(const K& key, V& value) {
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
		for (int i = 0;i < nr;i++)
		{
			int value = 0;
			if (!map.Get(a[i].key, value)) return false;
		}
		return true;
	}

	V& operator[](const K& key)
	{
		for (int i = 0; i < nr; i++)
			if (a[i].key == key)
				return a[i].value;

		a[nr] = { key, V(), nr };
		nr++;
		return a[nr - 1].value;
	}
	const element* begin() const {
		return &a[0];
	}
	const element* end() const {
		return &a[nr];
	}

	
};
int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}
	return 0;
}
