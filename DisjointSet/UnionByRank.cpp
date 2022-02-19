	/*

		author: Ikhtiyor
		created: 2022/02/20

	*/


#include <bits/stdc++.h>

using namespace std;


// DisjointSeet Union by rank based on QUICK UNION technique;
class UnionByRank {
public:
	UnionByRank(int n) : root(n), rank(n) {
		for(int i = 0; i < n; i++) {
			root[i] = i;
			rank[i] = 1;
		}
	}

	int find (int x) {
       while(x != root[x])
       		x = root[x];

       	return x;
	}

	void unionSet(int x, int y) {
		int a = find(x);
		int b = find(y);
		// if they are not already in the same set
		if (a != b) {
			if (rank[a] > rank[b]) {
                root[b] = a;
			} else if(rank[a] < rank[b]) {
				root[a] = b;
			} else {
				root[b] = a;
				rank[a] += 1;
			}
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}
private:
	vector<int> root;
	vector<int> rank;
};

int main() {

   // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionByRank ur(10);
    // 1-2-5-6-7 3-8-9 4
    ur.unionSet(1, 2);
    ur.unionSet(2, 5);
    ur.unionSet(5, 6);
    ur.unionSet(6, 7);
    ur.unionSet(3, 8);
    ur.unionSet(8, 9);
    cout << ur.connected(1, 5) << endl;  // true
    cout << ur.connected(5, 7) << endl;  // true
    cout << ur.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    ur.unionSet(9, 4);
    cout << ur.connected(4, 9) << endl;  // true

    /*

	Time Complexity
	----------------------------------------------------------------------
	| 					Union-find Constructor	Find	Union	Connected |
	| Time Complexity	O(N)					O(logN)	O(logN)	O(logN)	  |	
	-----------------------------------------------------------------------
    */

	return 0;
}
