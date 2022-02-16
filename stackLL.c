#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*link;
};
struct node*head;
void push();
void pop();
void display();
int main()
{
  int choice;
  printf("\n\n MAIN MENU \n\n");
  printf("\n OPERATIONS \n");
  printf("\n1. DISPLAY\n2. INSERT AT FRONT\n3. DELETE FROM FRONT\n4. EXIT");
  do
  {
    printf("\nEnter the choice :");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
         {
            display();
            break;
         }
        case 2:
         {
           push();
           break;
         }
         case 3:
         {
           pop();
           break;
         }
         case 4:
         {
           printf("Exit\n");
           break;
         } 
         default:
         {
           printf("Enter a vaild choice\n");
         }
     }
  }
     while(choice!=4);
     return 0;
}
//for displaying elements in the stack
void display()
  {
    struct node*p;
    p=head;
    if(p==NULL)
    {
      printf("UNDER FLOW\n");
    }
    else
    {
      while(p!=NULL)
      {
        printf("%d\n",p->data);
        p=p->link;
      }
    }
  }

 //for inserting element into the stack
 void push()
 {
   struct node*temp;
    int item;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
      printf("\nOVER FLOW");
    }
    else
    {
      printf("Enter the Data :");
      scanf("%d",&item);
      temp->data=item;
      temp->link=head;
      head=temp;
  }
 }
//for deleting elemnts from stack
void pop()
{
  struct node *ptr;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->link;
        printf("Deleted data is %d\n",ptr->data);
        free(ptr);
        printf("Successfully Deleted!\n");
    }
}