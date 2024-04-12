#include <stdio.h>

int main(){
	int T, c, z;
	unsigned long long x;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%llu", &x);
		int high = 2000000, low = 0;
		while(low <= high){
			int mid = (high + low)/2;
			unsigned long long c = (unsigned long long) mid*(mid+1)*(2*mid+1)/6, cz = (unsigned long long) (mid-1)*mid*(2*(mid-1)+1)/6;
			if(c >= x && cz < x){
				z = mid;
				break;
			}
			else if(c > x){
				high = mid - 1;
			}
			else{
				low = mid + 1;
			}
		}
		printf("Case #%d: %d\n", i+1, z);
	}
}
