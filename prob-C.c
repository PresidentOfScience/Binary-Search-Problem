#include <stdio.h>

int main(){
	int N, Q;
	scanf("%d", &N);
	long long int A[N+1], x;
	A[0] = 0;
	for(int i=0; i<N; i++){
		scanf("%lld", &x);
		if(!i) A[i] = x;
		else A[i] = A[i-1] + x;
	}
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		scanf("%lld", &x);
		int pos;
		if(A[0] > x){
			pos = -2;
		}
		else if(A[N-1] <= x){
			pos = N-1;
		}
		else{
			int lo = 0, hi = N-1;
			while(lo <= hi){
				int mid = (hi+lo)/2;
				if(A[mid] <= x && A[mid+1] > x){
					pos = mid;
					break;
				}
				else if(A[mid] <= x){
					lo = mid + 1;
				}
				else{
					hi = mid - 1;
				}
			}
		}
		printf("Case #%d: %d\n", i, pos+1);
	}

	return 0;
}
