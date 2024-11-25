#include<stdio.h>
#include<conio.h>
struct node
{
 int data;
 struct node*left;
 struct node*right;
};
struct node*createnode(int data)
{
 struct node*newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->left=newnode->right=NULL;
 return newnode;
}
struct node*insert(struct node*root,int data)
{
 if(root==NULL)
 {
  return createnode(data);
 }
 if(data<root->data)
 {
  root->left=insert(root->left,data);
 }
 else if(data>root->data)
 {
  root->right=insert(root->right,data);
 }
 return root;
}
struct node*search(struct node*root,int data)
{
 if(root==NULL)
 {
  return 0;
 }
else if(data==root->data)
 {
  return 1;
 }
else if(data<root->data)
{
 return search(root->left,data) ;
}
else
{
 return search(root->right,data);
}
}
struct node*findmin(struct node*root)
{
 while(root->left!=NULL)
 {
  root=root->left;
 }
 return root;
}
struct node*delete(struct node*root,int data)

{
 struct node*temp=findmin(root->right);
 if(root==NULL)
 {
  return root;
 }
 if(data<root->data)
 {
    root->left=delete(root->left,data);
 }
 else if(data>root->data)
 {
   root->right=delete(root->right,data);
 }
 else
 {
  if(root->left==NULL)
  {
   struct node*temp=root->right;
   free(root);
   return temp;
  }
  else if(root->right==NULL)
  {
    struct node*temp=root->left;
    free(root);
    return temp;
  }
root->data=temp->data;
root->right=delete(root->right,temp->data);
}
return root;
}
void displaytree(struct node*root,int space)
{
 int i;
 if(root==NULL)
 {
  return;
 }
 space+=10;
 displaytree(root->right,space);
 printf("\n");
 for(i=10;i<space;i++)
 {
  printf(" ");
 }
 printf("%d\n",root->data);
 displaytree(root->left,space);
}

void main()
{
 struct node*root=NULL;
 int choice,data;
 clrscr();
 while(1)
 {
  printf("\n1.insert \n2.delete \n3.display tree \n4.search \n5.exit");
  printf("\n enter your choice");
  scanf("%d",&choice);
   switch(choice)
   {
    case 1:
	  printf("enter the data to insert");
	  scanf("%d",&data);
	  root=insert(root,data);
	  printf("%d inserted \n",data);
	  break;
    case 2:
	  printf("enter data delete");
	  scanf("%d",&data);
	  root=delete(root,data);
	  break;
    case 3:
	 displaytree(root,0);
	 break;
    case 4:
	  printf("enter data to search");
	  scanf("%d",&data);
	  if(search(root,data))
	  {
	   printf("%d found in tree",data);
	  }
	  else
	   {
	    printf("%d not found in tree",data);
	   }
	  break;
    case 5:
	  exit();
	  break;
    default:
	  printf("invalid choice");

   }
   getch();
 }

}