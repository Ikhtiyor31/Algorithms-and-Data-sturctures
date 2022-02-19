
		/*

			author: Ikhtiyor
			created: 2022/02/20

		*/


#include <bits/stdc++.h>

using namespace std;

	
class UnionFind {

public:
	UnionFind(int n) : root(n) {
		for(int i = 0; i < n;  i++) {
			root[i] = i;
		}
	}

	// find 
	int find(int x) {
		return root[x];
	}

	// union of two elem
	void unionSet(int x, int y) {
		int a = find(x);
		int b = find(y);

		if(a != b) {
			for(int i = 0; i < root.size(); i++) {
				if (root[i] == b) 
					root[i] = a;
			}
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}

private:
	vector<int> root;
};


class UnionFind2 {

public:
	UnionFind2(int sz) : root(sz) {
		for(int i = 0; i < sz; i++) {
			root[i] = i;
		}
 	}

 	int find(int x) {

 		while(x != root[x]) {
 			x = root[x];
 		}

 		return x;
 	}

 	void unionSet(int x, int y) {
 		int rootX = find(x);
 		int rootY = find(y);
 		if (rootX != rootY) {
 			root[rootX] = rootY;
 		}
 	}
 	bool connected(int x, int y) {

 		return find(x) == find(y);
 	}

private: 
	vector<int> root;
};

int main() {
	// for displaying booleans as literal strings, instead of 0 and 1
	cout << boolalpha;
	// QUICK FIND 
	UnionFind uf(10);

	uf.unionSet(0, 1);
	uf.unionSet(0, 2);
	uf.unionSet(1, 3);
	uf.unionSet(4, 8);
	uf.unionSet(5, 6);
	uf.unionSet(5, 7);


	cout << uf.connected(0, 3) << "\n";
	cout << uf.connected(1, 5) << "\n";
	cout << uf.connected(7, 8) << "\n";

	uf.unionSet(3, 9);

	cout << uf.connected(2, 9) << "\n";
	//Time Complexity
	//					Union-find Constructor	Find	Union	Connected
	//Time Complexity	O(N)					O(1)	O(N)	O(1)

    /// QUICK UNION 
	UnionFind2 uf2(10);
    // 1-2-5-6-7 3-8-9 4
    uf2.unionSet(1, 2);
    uf2.unionSet(2, 5);
    uf2.unionSet(5, 6);
    uf2.unionSet(6, 7);
    uf2.unionSet(3, 8);
    uf2.unionSet(8, 9);
    cout << uf2.connected(1, 5) << endl;  // true
    cout << uf2.connected(5, 7) << endl;  // true
    cout << uf2.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf2.connected(4, 9) << endl;  // true

    /*

	Time Complexity
	----------------------------------------------------------------------
	| 					Union-find Constructor	Find	Union	Connected |
	| Time Complexity	O(N)					O(N)	O(N)	O(N)	  |	
	-----------------------------------------------------------------------
    */



	return 0;
}
