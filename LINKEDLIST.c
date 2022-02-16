#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*link;
};
struct node*head;

void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void display();

int main()
{
  int choice;
  printf("\n\n MAIN MENU \n\n");
  printf("\n OPERATIONS \n");
  printf("\n1.  Display\n2. Insert at Beginning\n3. Insert at End\n4. Insert at a specified position\n5. Delete from Beginning\n6. Delete from End\n7. Delete from a Specified Position\n8. EXIT\n");
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
         insertbeg();
         break;
        }
      case 3:
        {
         insertend();
         break;
        }
      case 4:
        {
          insertpos();
          break;
        }
      case 5:
        {
          deletebeg();
          break;
        }
      case 6:
        {
          deleteend();
          break;
        }
      case 7:
        {
          deletepos();
          break;
        }
    
      case 8:
        {
          printf("EXIT");
          break;
        }
      default:
        printf("Invalid Choice!");
    }
  }
    while(choice!=8);
    return 0;
}
void display()
  {
    struct node*p;
    p=head;
    if(p==NULL)
    {
      printf("UNDER FLOW");
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

  void insertbeg()
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
  void insertend()
  {
    struct node*ptr,*temp;
    int item;
    temp=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    printf("Enter the Data :");
    scanf("%d",&item);
    
    while(ptr->link!=NULL)
    {
      ptr=ptr->link;
    }
      ptr->link=temp;
      temp->data=item;
  }
  void insertpos()
  {
    int key,item;
    struct node*temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the Key :");
    scanf("%d",&key);
    ptr=head;
    while((ptr->data!=key)&&(ptr->link!=NULL))
    {
      //traverse the list until you reach the key node
      ptr=ptr->link;
    }
    if(ptr->link==NULL)
    {
      printf("SEARCH FAILS");
    }
    else
     {
       printf("Enter the data :");
       scanf("%d",&item);
       temp->data=item;
       temp->link=ptr->link;
       ptr->link=temp;
     }
  }
 void deletebeg()
 {
   struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->link;
        free(ptr);
        printf("\nSuccessfully Deleted!");
    }
 }
  void deleteend()
  {
    struct node*ptr,*temp;
    if(head->link==NULL)
    {
      ptr=head;
      head=NULL;
      free(ptr);
      printf("\nSuccessfully Deleted!");
      return;
    }
    else
    {
       temp=head;
       temp=head->link;
    
       while(temp->link!=NULL)
      {
        ptr=temp;
        temp=temp->link;
      }
        ptr->link=NULL;
        free(temp);
        printf("\nSuccessfully Deleted!");
    }
  }
  void deletepos()
  {
    int key;
    struct node*ptr,*temp;
    printf("Enter the Value :");
    scanf("%d",&key);
    ptr=head;
    if(head==NULL)
    {
      printf("UNDER FLOW");
      return;
    }
    else{
    temp=ptr;
    while(ptr!=NULL)
    {
      if(ptr->data==key)
      {
        temp->link=ptr->link;
        free(ptr);
        printf("\nSuccessfully Deleted!");
        return;
      }
      else
      {
      temp=ptr;
      ptr=ptr->link;
    }}
   }
  }