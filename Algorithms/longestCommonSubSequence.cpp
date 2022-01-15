#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b, int c) 
{
	if(a >= b && a >= c) {
		return a;
	}	
	else if(b >= a && b >= c) {
		return b;
	}
	else {
		return c;
	}
}

int lcs(char s1[], char s2[], int i1, int i2) {
	if(i1 == strlen(s1) || i2 == strlen(s2)) {
		return 0;
	}
	int c3 = 0;
	
	if(s1[i1] == s2[i2]) {
		c3 = 1 + lcs(s1, s2, i1+1, i2+1);
	}
	int c2 = lcs(s1, s2, i1+1, i2);
	int c1 = lcs(s1, s2, i1, i2+1);
	
	return max(c1, c2, c3);
}

int main()
{
	char s1[] = "houdini";
	char s2[] = "hdupti";
	
	int len = lcs(s1, s2, 0, 0);
	printf("Longest common subsequence length: %d", len);
 		
	return 0;
}
