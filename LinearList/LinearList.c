#include "lib/ADT_List.h"

int main(){
    
    int* newlist = InitList();

    for(int i = 0; i < LISTLEN; i++)
	newlist[i] = i;

    ShowList(newlist);

    return EXIT_SUCCESS;
}
