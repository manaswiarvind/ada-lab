#include<stdio.h>
#include<time.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int low,int high,int a[]){
    int i=low;
    int j=high+1;
    int pivot=a[low];
    while(i<j){
        do{
        i=i+1;
        }while( pivot>=a[i]);
        do{
        j=j-1;
        }while (pivot<a[j]);
        if(i<j){
        swap(&a[i],&a[j]);
        }
    }
    swap(&a[low],&a[j]);
    return j;
}

void quicksort(int low,int high,int a[]){
    if(low<high){
        int j=partition(low,high,a);
        quicksort(low,j-1,a);
        quicksort(j+1,high,a);
    }
}

int main(){
int a[100000],n;
clock_t start,end;
printf("enter number of elements\n");
scanf("%d",&n);
for(int i=0;i<n;i++){
       // printf("enter number of elements %d ",i+1);
       // scanf("%d",&a[i]);
   a[i]=rand()%1000000;
}
int low=0;
int high=n-1;
start=clock();
quicksort(low,high,a);
end=clock();
double time=((double)(end-start)*1000.0)/CLOCKS_PER_SEC;
//for(int i=0;i<n;i++){
   // printf("%d ",a[i]);
//}
printf("time taken %f",time);
}
