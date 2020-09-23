#include "SqList.h"

int main(){

	SqList List;
	system("clear");
	printf("============= SqList =============\n\n");
	{
		printf("Initialization List ...\n\n");
		InitList(&List);
	}
	{
		printf("Q: Whether the list is empty ? \n");
		if(ListEmpty(List) == TRUE){
			printf("\033[36mA: List is Empty!\n");
		}else{
			printf("\033[34m List is not Empty!\n");
		}
		printf("%d\n",ListLength(&List));
	}


	getchar();

	return EXIT_SUCCESS;
}