#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 10
int list[MAX_SIZE];
int n;

int *point1,*point2;
void selectionSort(int list[], int n)
{ int i, j, least, temp;
for (i = 0; i < n - 1; i++)
{
least = i;
for (j = i + 1; j < n; j++)
{
if (list[j] < list[least])
least = j; //least에 몇번째인지를 저장해준다ᄋ
}

if (&list[i] == point1)
 point1 = &list[least];
if (&list[i] == point2)
 point2 = &list[least];
// 주소로 least를 이용해서.. 바꿔주기
SWAP(list[i],list[least],temp);
}
}
int main(void)
{ int i;
int same=0;

n=MAX_SIZE;
srand(time(NULL));
for (i=0;i<n;i++) //난수 생성 및 출력
list[i]=rand()%100;//난수 생성 범위 0-100
printf("** Selection Sort ** \n");
printf("Before Sorting\n");

point1=&list[0];//<<point1 에 먼저 첫번째 주소 저장
for(i=0;i<n-1;i++)
{if((*point1==list[i+1]))
{
 point2=&list[i+1];
 same=1;
 printf("point1 = %p , point2 = %p \n",point1,point2);
 break;
}
else point1=&list[i];
}

for(i=0;i<n;i++)
printf("%d ",list[i]);
printf("\n\n After Sorted\n");
selectionSort(list,n);
for(i=0;i<n;i++)
printf("%d ",list[i]);

if (same ==1)
{
printf("point1 = %p , point2 = %p \n",point1,point2);
 if (point2<point1)
 printf("position changed!");} 
printf("\n");
return 0;
}
