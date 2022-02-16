#include<stdio.h>
void Enqueue(void);
void Dequeue(void);
void Display(void);
int a[100],n,item;
int rear=-1;
int front=-1;
int main()
{
  int choice;
  
  printf("Enter the size::");
  scanf("%d",&n);
  do
  {
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
    printf("Enter the choice::");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        {
        Enqueue();
        break;
        }
      case 2:
        {
        Dequeue();
        break;
        }
      case 3:
        {
        Display();
        break;
        }
      case 4:
        {
        printf("\n EXIT");
        break;
        }
      default:
        {
        printf("Enter valid choice!");
        }
    } 
  }
  while(choice!=4);
  return 0;
}
void Enqueue()
{
  //Enter first value
  if(front==-1 && rear==-1)
  {
    front=0;
    rear=0;
    printf("value to inserted:");
    scanf("%d",&item);
    a[rear]=item;
  }
  else if(front==(rear+1)%n)
  {
    printf("Overflow");
  }
  else
  {
    rear=(rear+1)%n;
    printf("enter value to insert:");
    scanf("%d",&item);
    a[rear]=item;
  }
}
void Dequeue()
{
  if(front==-1 && rear==-1)
  {
    printf("Underflow");
  }
  else if(front==rear)
  {
    
    printf("value to be deleted:%d",a[front]);
    
    front=-1;
    rear=-1;
  }
  else
  {
   
    printf("value to be deleted:%d",a[front]);
    
    front=(front+1)%n;
  }
}
void Display()
{
  
  int j=front;
  if(front==-1 && rear==-1)
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("Queue is:\n");
    while(j!=rear)
    {
      printf("%d\n",a[j]);
      j=(j+1)%n;
    }
    printf("%d",a[rear]);
  }
}
