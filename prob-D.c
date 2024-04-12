#include <stdio.h>

long long max(long long a, long long b){
	if(a > b) return a;
	else return b;
}

void solve(int caseIndex){
	long long N, M, sum = 0;
	scanf("%lld %lld", &N, &M);
	long long A[N+1], maxlen = -1, lo = 0;
	for(int i=0; i<N; i++){
		scanf("%lld", &A[i]);
		sum += A[i];
		if(sum <= M){
			maxlen = max(maxlen, i-lo+1);
		}
		else{
			while(sum > M){
				sum -= A[lo++];
			}
			if(sum <= M && sum > 0){
				maxlen = max(maxlen, i-lo+1);
			}
		}
	}
	printf("Case #%d: %lld\n", caseIndex, maxlen);
}

int main(){
	int T = 3;
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		solve(i);
	}

	return 0;
}
