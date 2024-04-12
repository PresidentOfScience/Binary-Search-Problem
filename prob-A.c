#include <stdio.h>

int search(int arr[], int size, int find){
	int index = -2, left = 0, right = size-1, mid;
	while(left <= right){
		mid = (left+right)/2;
		if(arr[mid] < find) left = mid+1;
		else{
			if(arr[mid] == find){
				index = mid;
			}
			right = mid-1;
		}
	}
	return index+1;
}

int main(){
	int N, M, Q[120000], A[120000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	for(int i=0; i<M; i++){
		scanf("%d", &Q[i]);
	}
	for(int i=0; i<M; i++){
		int result = search(A, N, Q[i]);
		printf("%d\n", result);
	}
	
	return 0;
}
