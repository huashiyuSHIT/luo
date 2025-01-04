#include <stdio.h>//利用函数遍历出数组
void printArr(int arr[],int len)//函数中的arr表示变量，记录数组的首地址，sizeof记录变量的大小，，定义处的arr表示完整的数组
{
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);//在函数中对数组进行遍历，将数组长度传递
    }
}
void swap(void *p1,void *p2,int len){//void类型可以类型交换，int，long，，无法获取数据，不能进行计算
    char *pc1=p1;//void转化为char类型指针,,char占用一个字节
    char *pc2=p2;
    char temp=0;
    for(int i=0;i<len;i++){//len为步长
        temp=*pc1;
        *pc1=*pc2;
        *pc2=temp;
        pc1++;
        pc2++;
    }
}
int add(int num1,int num2){
    return num1+num2;
}
int subtract(int num1,int num2){
    return num1-num2;
}
int multiply(int num1,int num2){
    return num1*num2;
}
int divide(int num1,int num2){
    return num1/num2;
}
int main()
{
     /*int (*p)(int,int)=add;//函数指针
    int num=p(10,20);
    printf("%d",num);
    int (*arr[4])(int,int)={add,subtract,multiply,divide};//定义指针数组，数组代表数字
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    int choose;
    scanf("%d",&choose);
    int result=(arr[choose-1])(num1,num2);
    printf("%d\n",result);*/


    /*int c=100;
    int d=200;
    swap(&c,&d,4);//int类型步长为4搭配上边函数
    printf("%d %d\n",c,d);//数据交换
*/

    /*int arr[]={10,20,30};
      int *p1=arr;
      printf("%d %d",*p1,*(p1+1));//*代表解引用*p1为首地址 *(p1+1)为第二个*/


    /*int arr[]={1,2,3,4,5,6};
   int len=sizeof(arr)/sizeof(int);
    printArr(arr,len);//对数组进行遍历方法一（函数）*/
    
    /*int arr[]={1,2,3,4,5,6};
   int len=sizeof(arr)/sizeof(int);
    int *p1=arr;//指针获得数组首地址
    for(int i=0;i<len;i++){//利用指针遍历数组方法二（指针）
        printf("%d\n",*p1);
        p1++;//加1为4个字节，在数组中连续
    }
*/

    /*
    int arr[3][5]={//遍历二维数组方法1，每行数据数量相同
        {1,2,3,4,5},
        {11,22,33,44,55},
        {111,222,333,444,555}
    };
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
    */


   /*int arr1[3]={1,2,3};//遍历数组
   int arr2[5]={1,2,3,4,5};
   int arr3[7]={1,2,3,4,5,6,7};
   int len1=sizeof(arr1)/sizeof(int);
   int len2=sizeof(arr2)/sizeof(int);
   int len3=sizeof(arr3)/sizeof(int);//仅该例子为数据，其他退化为指针
   int lenArr[3]={len1,len2,len3};
   int *arr[3]={arr1,arr2,arr3};//11111
   //定义二维不相等数组（内部arr为内存地址，利用指针）
  for(int i=0;i<3;i++){
    for(int j=0;j<lenArr[i];j++){
        printf("%d ",arr[i][j]);
    }
    printf("\n");
  }


  int arr1[5]={1,2,3,4,5};
   int arr2[5]={11,22,33,44,55};
   int arr3[5]={111,222,333,444,555};
   int len1=sizeof(arr1)/sizeof(int);
   int len2=sizeof(arr2)/sizeof(int);
   int len3=sizeof(arr3)/sizeof(int);
   int lenArr[3]={len1,len2,len3};
   int *arr[3]={arr1,arr2,arr3};
    int **p=arr;
  for(int i=0;i<3;i++){
    for(int j=0;j<lenArr[i];j++){
        printf("%d ",*(*p+j));//222222
    }
    printf("\n");
    p++;
  }
  */

 
    /*
    int arr[3][5]={
        {1,2,3,4,5},
        {11,22,33,44,55},
        {111,222,333,444,555}
    };
    int (*p)[5]=arr;//指针p指向5个数据的数组，p指向arr数组每一行
    for(int i=0;i<3;i++){//
        for(int j=0;j<5;j++){
            printf("%d ",*(*p+j));
    //指针p初始二维数组的第一个数组的首地址，
    *p为指向的数组，*(*p+j)为数组的数据
        }printf("\n");
        p++;//第二行
    }*/
   

    return 0;
     
}