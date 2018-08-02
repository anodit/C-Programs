#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
        int data;
        struct treeNode *left, *right;
};
struct treeNode *root = NULL;

struct treeNode* createNode(int data)
{
        struct treeNode *newNode;
        newNode = (struct treeNode *) malloc(sizeof(struct treeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return(newNode);
}


void insertion(struct treeNode **node, int data)
{
        if (*node == NULL)
        {
            *node = createNode(data);
        }
        else if (data < (*node)->data)
        {
            insertion(&(*node)->left, data);
        }
        else if (data > (*node)->data)
        {
            insertion(&(*node)->right, data);
        }
  }

struct treeNode *findmin(struct treeNode *tree)
{
    if(tree==NULL || tree->left==NULL)
    {
        return tree;
    }
    if(tree->left!=NULL)
        return(findmin(tree->left));
}

struct treeNode* del(struct treeNode *tree,int val)
{
    if(tree==NULL)
    {
        printf("\n\tValue doesn't exit.");
        return(tree);
    }
    if(val<tree->data)
        tree->left=del(tree->left,val);
    else if(val>tree->data)
        tree->right=del(tree->right,val);
    else
    {
        if(tree->left==NULL && tree->right==NULL)
        {
            free(tree);
            tree=NULL;
        }

        else if(tree->left==NULL)
        {
            struct treeNode *temp=tree;
            tree=tree->right;
            free(temp);
        }

        else if(tree->right==NULL)
        {
            struct treeNode *temp=tree;
            tree=tree->left;
            free(temp);
        }

        else
        {
            struct treeNode *temp=findmin(tree->right);
            tree->data=temp->data;
            tree->right=del(tree->right,tree->data);
        }
    }
return tree;
}

int search(struct treeNode*root,int data)
{
    if(root==NULL)
        return 0;
    else if(data==root->data)
        return 1;
    else if(data<=root->data)
        return search(root->left,data);
    else if(data>=root->data)
        return search(root->right,data);
}

void pre_traverse(struct treeNode *node)
{
        if (node != NULL)
        {
            printf("%3d", node->data);
            pre_traverse(node->left);
            pre_traverse(node->right);
        }
}

void in_traverse(struct treeNode *node)
{
        if (node != NULL)
        {
            in_traverse(node->left);
            printf("%3d", node->data);
            in_traverse(node->right);
        }
}

void post_traverse(struct treeNode *node)
{
      if(node!=NULL)
      {
          post_traverse(node->left);
          post_traverse(node->right);
          printf("%3d", node->data);
      }
}

int main()
{
        int data, ch;
        while (1)
         {
                printf("\n\n\t|-----------------  MENU --------------------|");
                printf("\n\t|    *****   Binary_Search_Tree   *****      |\n");
                printf("\n\t| 1. Insertion in Binary Search Tree         |");
                printf("\n\n\t| 2. Deletion in Binary Search Tree          |");
                printf("\n\n\t| 3. Search Element in Binary Search Tree    |");
                printf("\n\n\t| 4. Preorder traversal using recursion      |");
                printf("\n\n\t| 5. Inorder traversal using recursion       |");
                printf("\n\n\t| 6. Postorder traversal using recursion     |");
                printf("\n\n\t| 7. Exit                                    |");
                printf("\n\n\t|--------------------------------------------|");
                printf("\n\n\tEnter your choice : ");
                scanf("%d", &ch);
                switch (ch)
                {
                        case 1:
                                while (1)
                                {
                                    printf("\n\tEnter the data to be inserted : ");
                                    scanf("%d", &data);
                                    insertion(&root, data);
                                    printf("\n\tContinue Insertion(0/1) : ");
                                    scanf("%d", &ch);
                                    if (!ch)
                                        break;
                                }
                                break;
                        case 2:
                                printf("\n\tEnter the value that you want to delete : ");
                                scanf("%d", &data);
                                del(root, data);
                                break;
                        case 3:
                                printf("\n\tEnter the value that you want to search : ");
                                scanf("%d", &data);
                                if(search(root,data)==1)
                                    printf("\n\tElement found i.e Search successful");
                                else
                                    printf("\n\tElement not found i.e Search Unsuccessful");
                                break;
                        case 4:
                                printf("\n\tPreorder Traversal :\t");
                                pre_traverse(root);
                                printf("\n");
                                break;
                        case 5:
                                printf("\n\tInorder Traversal :\t");
                                in_traverse(root);
                                printf("\n");
                                break;
                        case 6:
                                printf("\n\tPostorder Traversal :\t");
                                post_traverse(root);
                                printf("\n");
                                break;
                        case 7:
                                exit(0);
                        default:
                                printf("\n\tYou have entered wrong option\n");
                                break;
                }
        }
        return 0;
}
