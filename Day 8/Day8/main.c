#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
};

void readTree(struct Node** node)
{


    int val;

    scanf("%d",&val);

    if (val < 0)
        (*node) = NULL;
    else
    {
        *node = (struct Node*) malloc (sizeof (struct Node));
        (*node) -> val = val;
        readTree(&(*node)->left);
        readTree(&(*node)->right);
    }
}

void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

bool isUnival(struct Node* root)
{
    if(root == NULL)
        return true;

    if(isUnival(root -> left) && isUnival(root -> right))
    {
        if(root -> left != NULL)
            if(root -> left -> val != root -> val)
                return false;

        if(root -> right != NULL)
            if(root -> right -> val != root -> val)
                return false;

        return true;
    }

    return false;
}

int countUnival(struct Node* root)
{
    if(root == NULL)
        return 0;

    if(isUnival(root))
        return 1 + countUnival(root->left) + countUnival(root->right);

    return countUnival(root->left) + countUnival(root->right);
}

int main()
{
    struct Node* root = NULL;

    readTree(&root);

    //preorder traversal for checking the correctness of the inputed tree
    preorder(root);

    printf("\nNumber of unival subtrees: %d\n",countUnival(root));
    return 0;
}
