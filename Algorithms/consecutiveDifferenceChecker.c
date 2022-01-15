#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int N[n];
    for(int i = 0; i<n; i++) {
        scanf("%d", &N[i]);
    }

    int diff = (N[n-1] - N[0])/n;
    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high) {
        mid = (low + high)/2;
        if(mid - 1 >= 0 && N[mid] - N[mid-1] != diff) {
            printf("%d", N[mid - 1] + diff);
            break;
        }

        if(mid + 1 < n && N[mid + 1] - N[mid] != diff) {
            printf("%d", N[mid+1] - diff);
            break;
        }

        if(N[mid] != N[0] + mid*diff ) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }

    }

    return 0;
}

