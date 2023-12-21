//MAXIMUM SUBARRAY SUM O(n2) approach
#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int arr[n];
		for(int h=0;h<n;h++){
			cin>>arr[h];
		}
		int max_so_far=0;
		for(int j=0;j<n;j++){
			int max_curr=0;
			for(int k=j;k<n;k++){
				max_curr+=arr[k];
				if (max_curr>max_so_far){
					max_so_far=max_curr;
				}

			}
		}
		cout<<max_so_far<<endl;
	}
	return 0;
}
