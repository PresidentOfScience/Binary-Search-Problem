#include <stdio.h>

long long max(long long a, long long b){
	if(a > b) return a;
	else return b;
}

void solve(){
	long long N, M, sum = 0;
	scanf("%lld", &N);
	long long A[N+1], maxlen = -1, lo = 0;
	for(int i=0; i<N; i++){
		scanf("%lld", &A[i]);
	}
	int Q;
	scanf("%d", &Q);
	for(int i=1; i<=Q; i++){
		sum = 0, lo = 0, maxlen = -1;
		scanf("%lld", &M);
		for (int j=0; j<N; j++){
			sum += A[j];
			if(sum <= M){
				maxlen = max(maxlen, j-lo+1);
			}
			else{
				while(sum > M){
					sum -= A[lo++];
				}
				if(sum <= M && sum > 0){
					maxlen = max(maxlen, j-lo+1);
				}
			}
		}
		printf("Case #%d: %lld\n", i, maxlen);
	}
}

int main(){
	int T = 3;
	solve();

	return 0;
}
