#include <stdio.h>
#include <stdlib.h>

int s1 = 1;
int arr[10];
int ind=-1;
void producer(){
    --s1;
    int x = rand()%10;
    ind++;
    arr[ind]=x;
    printf("Number Produced %d\n",x);
   
    ++s1;
}

void consumer(){
    --s1;
    int x = arr[ind];
    printf("Number Produced %d\n",x);
     ind--;
    ++s1;
}

int main(){
    while(1)
    {
        int n=0;
        printf("1. Enter data:\n2.Reomve data:\n3.Exit");
        scanf("%d",&n);
        if(n==1)
        {
            if(ind<9)
            {
                producer();
            }else{
                printf("Buffer is full\n");
            }
        }else if(n==2)
        {
            if(ind>=0)
            {
                consumer();
            }else{
                printf("Buffer is empty\n");
            }
        }else if(n==3)
        {
            break;
        }else{
            printf("Enter correct Option\n");
        }
    }
}
