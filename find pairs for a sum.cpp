#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include <iostream>
#include <typeinfo>
#include <unordered_map>
using namespace std;

//                               i 
//                3, 7, 2, 5, 6, 4
//theOtherElem                   
//hash                  2  5    
//paris           (7,3)       (4,6)

struct Pair
{
	int first;
	int second;
};


vector<Pair> findPairs(vector<int> a, int sum)
{
	vector<Pair> pairs;
	unordered_map<int, bool> hash;

	if (a.size() == 0)
		return pairs;

	for (auto n : a) {
		// can't find theOtherElem in the hash.
		int theOtherElem = sum - n;
		if (hash.find(theOtherElem) == hash.end())
			hash.insert({ n, true });
		// if there is the other number in the hash.
		else {
			hash.erase(theOtherElem);
			pairs.push_back({ n, theOtherElem });
		}
	}

	return pairs;
}

void main()
{
	vector<int> a = { 3, 7, 2, 5, 6, 4 };
	vector<Pair> out;
	out = findPairs(a, 10);

	for (auto p : out)
		cout << p.first << " " << p.second << endl;
}




