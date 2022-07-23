#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9+7;
void constructSegmentTree(vector<int> & arr, vector<int> & segTree, int low, int high, int pos) {
	 if (low == high) {
		 segTree[pos] = arr[low]; 
		 return;
	 }
	 int mid = (low + high) / 2;
	 constructSegmentTree(arr, segTree, low, mid, 2 * pos + 1);
	 constructSegmentTree(arr, segTree, mid + 1, high, 2 * pos + 2);
	 
	 segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos  + 2]);
 }
 
int rangeMinQuery(int start, int end, int low, int high, int pos, vector<int> & segTree) {

 
    if (start  <= low && end >= high) { // total overlap 
		return segTree[pos];
	} else if ( high < start || end < low ) {
		return INF;
	}
	int mid = (low + high) / 2;
	return min(rangeMinQuery(start, end, low, mid, 2 * pos + 1, segTree),
			rangeMinQuery(start, end, mid+1, high, 2 * pos + 2, segTree));
	
	

}

int main () {
	
	vector<int> arr = {-1, 2, 4, 0};
	int n  = arr.size();
	vector<int> segTree(n * 2 - 1, INF);
	
	constructSegmentTree(arr,segTree, 0, n-1, 0);
	//for(int & x: segTree) cout << x << " ";
	cout << rangeMinQuery(1, 3, 0, n-1, 0, segTree) << "\n";
	cout << rangeMinQuery(1, 2, 0, n-1, 0, segTree) << "\n";
	cout << rangeMinQuery(0, 1, 0, n-1, 0, segTree) << "\n";
	cout << rangeMinQuery(2, 2, 0, n-1, 0, segTree) << "\n";
	
	return 0;
}
