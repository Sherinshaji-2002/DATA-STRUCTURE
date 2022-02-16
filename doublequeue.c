#include<stdio.h>
int a[100],n,i;
void insertrear();
void insertfront();
void deletefront();
void deleterear();
void display();
int rear=-1,front=-1;

int main()
{
  int choice;
  printf("Enter the size:");
    scanf("%d",&n);
  do
  {
    printf("\nEnter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        insertrear();
        break;
      case 2:
        insertfront();
        break;
      case 3:
        deleterear();
        break;
      case 4:
        deletefront();
        break;
      case 5:
        display();
        break;
      case 6:
        printf("\nEXIT");
        break;
      default:
        break;
    }
  }
  while(choice!=6);
  return 0;
}
void insertrear()
{
  if(front==-1&&rear==-1)
  {
    front=rear=0;
    printf("enter the element to insert");
    scanf("%d",&a[rear]);
  if((rear==n-1)||(front==rear+1))
 {
    printf("\nOVERFLOW");
  }
  }
  else
  {
    rear=rear+1;
    printf("\nenter the element to insert :");
    scanf("%d",&a[rear]);
    if(front==-1)
    {
      front=0;
    }
  }
}
void insertfront()
{
  if(front==-1&&rear==-1)
  {front=rear=0;
  if((front==rear+1)||(rear==n-1))
  {
    printf("OVERFLOW");
  }}
  else
  {
    if(front==0)
    {
      front=n-1;
      printf("\nenter the element to insert :");
      scanf("%d",&a[front]);
    }
    else
    {
    front=front-1;
    printf("\nenter the element to insert :");
    scanf("%d",&a[front]);
  }
  }
}
void deleterear()
{
  if((front==-1)&&(rear==-1))
  {
    printf("UNDERFLOW");
  }
  else{
    
   //single element
    if(rear==front)
    {
      printf("element deleted :%d",a[rear]);
      front=-1;
      rear=-1;
    }
    else
    {
      printf("element deleted :%d",a[rear]);
      rear=rear+1;
    }
   
  }
  }

void deletefront()
{
  if((front==-1)&&(rear==-1))
  {
    printf("UNDERFLOW");
  }
  else
  {
    
   //single element case
    if(front==rear)
    {
      printf("the element deleted :%d",a[front]);
      front=-1;
      rear=-1;
    }
    else
    {
      printf("the element deleted :%d",a[front]);
      front=front+1;
    }
  }
}
void display()
{
  i=front;
  printf("Elements in double ended queue");
  while(i!=rear)
  {
    printf("%d",a[i]);
    i=(i+1);
  }
  printf("%d",a[rear]);
}