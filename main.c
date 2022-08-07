#include <stdio.h>
#include <stdlib.h>

typedef struct Node sq;

//Using doubly linked list for Double-Ended Queue implementation

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
sq *front= NULL;
sq *rear= NULL;

void enqueue_front();
void enqueue_rear();
void dequeue_front();
void dequeue_rear();
void peek_front();
void peek_rear();
void display();


int main()
{

    int choice;
    printf("-----------------------------\n");
    printf("DE-QUEUE USING LINKED LIST\n");
    printf("-----------------------------\n");

    do{
    printf("____________________________");
    printf("\nQUEUE SORT OPERATIONS\n(1)INSERT\n(2)DELETE\n(3)PEEK\n(4)DISPLAY\n(5)EXIT\n");
    printf("____________________________");

    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:{
                printf("\n----------------------------");
                printf("\nCHOOSE A INSERTION OPERATION\n\n(1)INSERT FRONT\n(2)INSERT REAR\n(3)EXIT\n");
                printf("\n----------------------------");
                int option1;
                printf("\nENTER YOUR CHOICE :");
                scanf("%d",&option1);
                printf("\n----------------------------");
                switch(option1){
                    case 1: enqueue_front();
                            break;

                    case 2: enqueue_rear();
                            break;

                    case 3: printf("\nEXIT\n");
                            break;

                    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");
                }

            }
            break;

    case 2:{
                printf("\n----------------------------");
                printf("\nCHOOSE A DELETION OPERATION\n\n(1)DELETE FRONT\n(2)DELETE REAR\n(3)EXIT\n");
                printf("\n----------------------------");
                int option2;
                printf("\nENTER YOUR CHOICE :");
                scanf("%d",&option2);
                printf("\n----------------------------");
                switch(option2){
                    case 1: dequeue_front();
                            break;

                    case 2: dequeue_rear();
                            break;

                    case 3: printf("\nEXIT\n");
                            break;

                    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");
                }

            }
            break;

    case 3: {
                printf("\n----------------------------");
                printf("\nCHOOSE A PEEK OPERATION\n\n(1)PEEK FRONT\n(2)PEEK REAR\n(3)EXIT\n");
                printf("\n----------------------------");
                int option3;
                printf("\nENTER YOUR CHOICE :");
                scanf("%d",&option3);
                printf("\n----------------------------");
                switch(option3){
                    case 1: peek_front();
                            break;

                    case 2: peek_rear();
                            break;

                    case 3: printf("\nEXIT\n");
                            break;

                    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");
                }

            }
            break;

    case 4: display();
            break;

    case 5: printf("\nEXIT");
            break;

    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");

    }
  }while(choice!=5);

  getch();
  return 0;

}

//return queue status: Empty or Not

int isEmpty(){
    if(front==NULL&&rear==NULL) return 1;

    return 0;
}

//return queue status: Full or Not

int isFull(){
    sq *newnode = (sq*)malloc(sizeof(sq));
    if(newnode==NULL) return 1;

    return 0;
}

//enqueue_front() function add an element at the front position of the queue

void enqueue_front()
{
    if(isFull()){
        printf("\nQUEUE OVERFLOW!!!\n");
        return;
      }

      int x;
      printf("\nENTER AN ELEMENT TO INSERT IN THE QUEUE: ");
      scanf("%d",&x);

      sq *newnode;
      newnode = (sq*)malloc(sizeof(sq));
      newnode->data =x;
      newnode->next = NULL;
      newnode->prev = NULL;

      if(front==NULL && rear==NULL)
      {
          front=rear=newnode;
          printf("\nINSERTED ELEMENT IS THE QUEUE :%d\n", front->data);

      }
      else
      {
          newnode->next=front;
          front->prev = newnode;
          front = newnode;
          printf("\nINSERTED ELEMENT IS THE QUEUE :%d\n", front->data);

      }

}

//enqueue_rear() function add an element at the rear position of the queue

void enqueue_rear()
{
      if(isFull()){
        printf("\nQUEUE OVERFLOW!!!\n");
        return;
      }

      int x;
      printf("\nENTER AN ELEMENT TO INSERT IN THE QUEUE: ");
      scanf("%d",&x);

      sq *newnode;
      newnode = (sq*)malloc(sizeof(sq));
      newnode->data =x;
      newnode->next = NULL;

      if(front==NULL && rear==NULL)
      {
          front=rear=newnode;
          printf("\nINSERTED ELEMENT IS THE QUEUE :%d\n", rear->data);

      }
      else
      {
          rear->next = newnode;
          newnode->prev = rear;
          rear = newnode;
          printf("\nINSERTED ELEMENT IS THE QUEUE :%d\n", rear->data);

      }

}

//dequeue_front() function deletes the front element from the queue

void dequeue_front()
{

    if(isEmpty())
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }
    else
    {
       sq *temp;
       temp = front;
       printf("\nDELETED ELEMENT FROM THE QUEUE  :%d\n",front->data);

       if(front->next==NULL){
        front=rear=NULL;
        free(temp);
       }
       else{
        front->next->prev=NULL;
        front = front->next;
        free(temp);
       }

    }
}

//dequeue_rear() function deletes the rear element from the queue

void dequeue_rear()
{

    if(isEmpty())
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else
    {
       sq *temp;
       temp = rear;
       printf("\nDELETED ELEMENT FROM THE QUEUE  :%d\n",rear->data);
       if(front->next==NULL){
            front=rear=NULL;
            free(temp);
       }
       else{
            rear->prev->next = NULL;
            rear = rear->prev;
            free(temp);
       }

    }
}

//display() function print all the elements in the queue

void display()
{


    if(isEmpty())
   {
     printf("\nQUEUE UNDERFLOW!!!\n");

   }


    else
    {
        sq *temp;
        temp = front;
        printf("\nELEMENTS IN THE QUEUE :\n");
        while(temp!=NULL)
        {
            printf("%d \n",temp->data);
            temp = temp->next;
        }
    }

}

//peek_front() function return rear element of the queue

void peek_front()
{
    if(isEmpty())
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else
    {
        printf("\nFRONT ELEMENT OF THE QUEUE :%d\n",front->data);
    }
}

//peek_rear() function return front element of the queue

void peek_rear()
{
    if(isEmpty())
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }

    else
    {
        printf("\nREAR ELEMENT OF THE QUEUE :%d\n",rear->data);
    }
}

