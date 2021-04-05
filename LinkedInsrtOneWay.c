#include<stdio.h>
#include<stdlib.h>

typedef struct insertion{
	int data;
	struct insertion *next;
}INSRT;

INSRT *createNode();

void traverse();
void enterArray(INSRT **, int);
void insertionSort(INSRT **, int);

int main(){
	
	INSRT *root = (INSRT*)malloc(sizeof(INSRT));
	int n;
	
	printf("How many numbers do you want to create an array: ");
	scanf("%d", &n);
	
	enterArray(&root,n);
	traverse(&root);
	
	printf("\nSorted array with insertion:\n");
	insertionSort(&root,n);
	traverse(&root);
		
	free(root);
	return 0;
}

void enterArray(INSRT **proot, int n)
{
	INSRT *node = createNode();
	*proot = node;
	
	int i;
	while(i<n-1){
		node->next = createNode();
		node = node->next;
		i++;
	}
}

void traverse(INSRT **proot)
{
	INSRT *node = *proot;
	while(node != NULL){
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void insertionSort(INSRT **proot, int n)
{
	INSRT *tmp = *proot, *prev, *bas, *ara;
	int i, j, k, p, tur=1;
	
	for(p=0; p<n-1; p++){
		tmp = *proot;
		for(i=0; i<tur; i++){
			prev=tmp;
			tmp = prev->next;
		}
		j=0;
		bas = *proot;
		while(j<tur && bas->data < tmp->data){
			ara = bas;
			bas = bas->next;
			j++;
		}
		if(j<tur){
			prev->next = tmp->next;
			tmp->next = bas;
			
			//baþa yerleþecek demektir
			if(j==0){
				*proot = tmp;
			}
			else{
				ara->next = tmp;
			}
		}
		tur++;
	}
}

INSRT *createNode()
{
	INSRT *node = (INSRT*)malloc(sizeof(INSRT));
	int d;
	printf("num: ");
	scanf("%d", &d);	
	node->data = d;
	node->next = NULL;
	return node;
	
}
