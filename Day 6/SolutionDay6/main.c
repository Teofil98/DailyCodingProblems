#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* both;
};

struct Node* getNext(struct Node* currNode, struct Node* prevAddress)
{
    return (struct Node*) ((int)currNode -> both ^ (int)prevAddress);
}

void add(struct Node** list,int element)
{


    //list empty
    if(*list == NULL)
    {
        *list = (struct Node*) malloc(sizeof(struct Node));
        (*list)->val = element;
       (*list)->both = NULL;
    }
    else
    {
        struct Node* prevAddress = 0;
        struct Node* prevAddressAux = 0;
        struct Node* currNode = *list;

        while(currNode->both != NULL)
        {

            prevAddress = currNode;
            currNode = getNext(currNode, prevAddressAux);
            prevAddressAux = prevAddress;

        }

        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode -> val = element;
        newNode -> both = NULL;
        currNode -> both = (struct Node*) ((int) prevAddress ^ (int)newNode);


    }
}

struct Node* get(struct Node* list,int index)
{
    int i = 0;

    struct Node* currNode = list;

     struct Node* prevAddress = 0;
     struct Node* prevAddressAux = 0;

    while(i != index && currNode != NULL)
    {
       prevAddress = currNode;
       currNode = getNext(currNode, prevAddressAux);
       prevAddressAux = prevAddress;
       i++;
    }

    return currNode;
};

int main()
{
    struct Node* XORList = NULL;

    add(&XORList, 2);
    add(&XORList, 3);
    add(&XORList, 5);

   int i;
   for(i = 0; i < 3; i++)
        printf("%d ",get(XORList,i)->val);

    return 0;
}
