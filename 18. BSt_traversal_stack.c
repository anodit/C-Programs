#include<stdlib.h>
#include<stdio.h>

struct node
{
   int info;
   struct node *left;
   struct node *right;
};

struct node *temp,*temp1,*temp2,*ptr,*root=NULL;


int st[20],top;

void push(struct node* item)
{
    st[++top]=item;
}

struct node* pop()
{
   temp2=st[top];
   top--;
   return temp2;
}

void insert(struct node* root, struct node* ptr)
{
    if(root==NULL)
	root=ptr;
    else
    {
	 if(ptr->info<root->info)
	 {
	    if(root->left!=NULL)
	       insert(root->left,ptr);
	    else
		root->left=ptr;
	 }

	if(ptr->info>root->info)
	{
	    if(root->right!=NULL)
		insert(root->right,ptr);
	    else
		root->right=ptr;
	}
    }

}

struct node* del(struct node* root, int item)
{
    if (root == NULL)
	return root;

    if (item < root->info)
	root->left = del(root->left, item);

    else if (item > root->info)
	root->right = del(root->right, item);

    else
    {
	if (root->left == NULL)
	{
	    temp = root->right;
	    free(root);
	    return temp;
	}
	else if (root->right == NULL)
	{
	    temp = root->left;
	    free(root);
	    return temp;
	}

	temp2 = root->right;
	while(temp2->left!=NULL)
	    temp2=temp2->left;
	root->info = temp2->info;

	root->right = del(root->right, temp2->info);
    }
    return root;
}

void preorder(struct node *temp)
{
    temp=root;
    top=0;
    st[top]=NULL;
    while(temp!=NULL)
    {
    while(temp!=NULL)
    {

        printf("%d ->", temp->info);
        temp1=temp->right;
        if(temp1!=NULL)
            push(temp1);
        temp=temp->left;
    }

    temp=pop();
    }
}


void inorder(struct node *temp)
{
    temp=root;
    top=0;
    st[top]=NULL;

  while(1)
  {
    while(temp!=NULL)
    {
      push(temp);
      temp=temp->left;
    }

    temp1=pop();
    if(temp1==NULL)
       break;
    printf("%d ->", temp1->info);
    temp2=temp1->right;
    if(temp2!=NULL)
      temp=temp2;

  }
}


void postorder(struct node *temp)
{
    temp=root;
    top=0;
    st[top]=NULL;
    while(1)
    {
	while(temp!=NULL)
	{
	temp1=temp->right;
	push(temp);
	if(temp1!=NULL)
	  {
	     temp1->info*=(-1);
	     push(temp1);
	  }
	temp=temp->left;
	}
	temp2=pop();
	if(temp2==NULL)
	    break;

	else if(temp2->info>0)
	{
        printf("%d ->", temp2->info);
        }
        else
        {
            temp2->info*=(-1);
            temp=temp2;
        }

    }
}

struct node* search(struct node* temp, int item)
{
    if (temp == NULL || temp->info == item)
       return temp;
    if (temp->info < item)
       return search(temp->right, item);
    else
       return search(temp->left, item);
}


void main()
{
    int a;


    while(1)
    {

	printf("\n\n\t***** Menu *****\n\n\t1.Insert\n\t2.Delete\n\t3.Search\n\t4.Traverse using stack\n\t5.Exit\n\n\tEnter your choice:");
	scanf("%d", &a);
	switch(a)
	{
	    case 1:{
		    ptr=(struct node*)malloc(sizeof(struct node));
		    printf("\n\tEnter the value : ");
		    scanf("%d", &ptr->info);
		    ptr->left=NULL;
		    ptr->right=NULL;
		    if(root==NULL)
			root=ptr;
		    else
		    {
			insert(root,ptr);
		    }
		    break;
		   }

	    case 2:{
                int item;
                if(root==NULL)
		  {
		    printf("\n\tEmpty");

		  }
		else{
		     printf("\n\tEnter info to be deleted:");
		     scanf("%d", &item);
		     root= del(root,item);
		    }
		break;
		   }

	    case 3:{
		    int item;
		    if(root==NULL)
			printf("Empty");
		    else
		    {
			printf("\n\tEnter info to be searched:");
			scanf("%d", &item);
			temp=root;
			temp1=search(temp,item);
			if(temp1==NULL)
			    printf("\n\tNot found!");
			else
                printf("\n\t%d found", temp1->info);

		    }

		    break;
		   }

	    case 4:{    int b;

			printf("\n\t\t1.Preorder\n\t\t2.Inorder\n\t\t3.Postorder\n\n\tEnter your choice:");
			scanf("%d", &b);
			if (root == NULL)
			{
			   printf("\n\tNo elements in the tree");

			}
			else{
			   temp=root;
			   switch(b)
			   {
				case 1: preorder(temp);

					break;

				case 2:inorder(temp);

					break;

				case 3:postorder(temp);

					break;

				default:printf("\n\tInvalid");

					break;
			   };
			}
			break;
		   }

	    case 5:exit(0);

	    default: printf("\n\tInvalid");
		     break;
	};
    }

}
