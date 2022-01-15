#include<stdio.h>
#include<stdlib.h>

struct Set {
	int n;
	int index;
	int* arr;
};

struct Set* createSet(int size) {
	struct Set* set = (struct Set*)malloc(sizeof(struct Set));
	set->n = size;
	set->index = 0;
	set->arr = (int *)malloc(size * sizeof(int));
	
	return set;
}

struct Set* createDisjoint(int size) {
	struct Set* sets = (struct Set*)malloc(size * sizeof(struct Set));
	int i;
	for(i = 0; i<=size; i++) {
		sets[i].arr = (int *)malloc(size * sizeof(int));
		sets[i].n = size;
		sets[i].index = 0;
		sets[i].arr[0] = i;
	}
	
	return sets;
}

int findSet(struct Set* sets, int ele, int n) {
	int i,j,l;
	for(i = 0; i<=n; i++) {
		l = sets[i].n;
		for(j = 0; j<=l; j++) {
			if(sets[i].arr[j] == ele) {
				return sets[i].arr[0];
				break;
			}
		}
	}
	
	return -1;
}

void setUnion(struct Set* sets, int n1, int n2, int n) {
	int i, j;
	int r1 = findSet(sets, n1, n);
	int r2 = findSet(sets, n2, n);
	if(r1 == r2) {
		return;
	}
	else {
		if(r1 > r2) {
			int l = sets[r1].index;
			for(i = 0; i<l; i++) {
				sets[r2].arr[sets[r2].index + i + 1] = sets[r1].arr[i];
			}
		}
		else {
			int l = sets[r2].n;
			for(i = 0; i<l; i++) {
				sets[r1].arr[sets[r1].index + i + 1] = sets[r2].arr[i];
			}
		}
	}
}

int main()
{
	struct Set* ds = createDisjoint(5);
	printf("FS 3: %d\n", findSet(ds, 3, 5));
	
	printf("2 union 3: ");
	setUnion(ds, 2, 3, 5);
	printf("FS 3: %d\n", findSet(ds, 3, 5));
	
	printf("2 union 4");
	setUnion(ds, 2, 4, 5);
	printf("FS 4: %d\n", findSet(ds, 4, 5));
	
	printf("FS 5: %d\n", findSet(ds, 5, 5));
	
	return 0;
}
