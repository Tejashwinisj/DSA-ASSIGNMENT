#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct customer
{
    char name[10];
    int age;
    char destination[100];
    int a_id;
    int price;
    struct customer *next;

}*c;


struct aeroplane
{
    char name[100];
    int id;
    char destination[100];
    char timing[100];
    int price;
    struct aeroplane *next;
}*front,*rear;




void enque()
{
   struct aeroplane *temp;

    temp = (struct aeroplane*)malloc(sizeof(struct aeroplane));
    printf("Enter Aeroplnae Name \n");
    scanf("%s",temp->name);

    printf("Enter Aeroplane Id\n");
    scanf("%d",&temp->id);

    printf("Enter Destination\n");
    scanf("%s",temp->destination);

    printf("Enter Timing\n");
    scanf("%s",temp->timing);

    printf("Enter Price\n");
    scanf("%d",&temp->price);

    temp->next = NULL;
    if (rear  ==  NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}




void deque(c head)
{

  struct aeroplane *temp;

    temp = front;
    if (front == NULL)
    {
        printf("queue is empty \n");
        front = rear = NULL;
    }
    else
    {
    printf("------------------------------------------------------------------------------");
    printf("\n");
    printf("Aeroplane Details That took off\n");

    printf(" Aeroplnae Name \n");
    printf(" %s",front->name);
    printf("\n\n");
    printf(" Aeroplane Id\n");
    printf(" %d",front->id);
    printf("\n\n");
    printf(" Destination\n");
    printf(" %s",front->destination);
    printf("\n\n");
    printf(" Timing\n");
    printf(" %s",front->timing);
    printf("\n\n");
    printf(" Price\n");
    printf(" %d",front->price);
    printf("\n\n");


    c temp1=head;
    printf("Customers who took this flight Their Details\n");

    while(temp1!=NULL)
    {
        if(front->id==temp1->a_id)
        {
        printf("%s %d %s %d %d",temp1->name,temp1->age,temp1->destination,temp1->a_id,temp1->price);
        printf("\n");
        temp1=temp1->next;
        }
        else
        temp1=temp1->next;
    }


        front = front->next;
        free(temp);
    }


}


void display()
{
    struct aeroplane *temp;
    temp = front;
    printf("------------------------------------------------------------------------------"); printf("\n");
    printf("Aeroplne Details\n");
    while(temp!=NULL)
    {
    printf(" Aeroplnae Name \n");
    printf(" %s",temp->name);
    printf("\n\n");
    printf(" Aeroplane Id\n");
    printf(" %d",temp->id);
    printf("\n\n");
    printf(" Destination\n");
    printf(" %s",temp->destination);
    printf("\n\n");
    printf(" Timing\n");
    printf(" %s",temp->timing);
    printf("\n\n");
    printf(" Price\n");
    printf(" %d",temp->price);
    printf("\n\n");
    temp=temp->next;

    }
}




c getcus()
{
   c ob1;
   int flag=0;
   ob1=(struct customer * )malloc(sizeof(struct customer));

   if(ob1==NULL)
   {
       printf("Error\n");
       exit(0);
   }

    printf("Enter The Customer  Details\n");

    printf("\n Enter Customer Name\n");
    scanf("%s",ob1->name);

    printf("\n Enter Customer Age\n");
    scanf("%d",&ob1->age);

    printf("\n Enter Id of Aeroplane\n");
    scanf("%d",&ob1->a_id);


    struct aeroplane *temp;
    temp=front;

    while(temp!=NULL)
    {

    if(ob1->a_id==temp->id)
     {  flag=1;
         strcpy(ob1->destination,temp->destination);
         ob1->price = temp->price;
         break;

     }
       temp=temp->next;
    }

     if(flag==0)
     {
         printf("no flight today\n");
         free(ob1);
         return NULL;
     }


ob1->next=NULL;

return ob1;


}


c addCus(c head)
{
   c ob;
   ob=getcus();


   if(ob==NULL)
   {
       printf("Sorry,No flight For your Destination\n");
       free(ob);
       return head;
   }

   if(head==NULL)
   {
       head = ob;
       head->next=NULL;
       return head;
   }

   else

   {
       c cur=head;

       while(cur->next!=NULL)
       {
           cur=cur->next;
       }

       cur->next = ob;
       ob->next = NULL;
       return head;
   }


}

void displayC(c head)
{
    c temp=head;
    printf("------------------------------------------------------------------------------"); printf("\n");
    printf("Customer Details\n");
    while(temp!=NULL)
    {
        printf("%s %d %s %d %d",temp->name,temp->age,temp->destination,temp->a_id,temp->price);
        printf("\n");
        temp=temp->next;
    }
}






int main()
{
   enque();
   enque();
   enque();
   enque();
   enque();

   c head=NULL;

   int choice;

   while(1)
   {
       printf("Enter Choice\n");
       printf("1.For Add Customer\n2.For Display Customer Details\n3.For Adding Aeroplane\n4.For Aeroplane Details\n5.For Dequing Aeroplane\n6.For exit\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:head=addCus(head);
                  break;

           case 2:displayC(head);
                  break;

           case 3:enque();
                  break;

            case 4:display();
                  break;

           case 5:deque(head);
                  break;

            case 6:exit(0);
                  break;

            default:printf("Invalid choice\n");

       }
   }

}
