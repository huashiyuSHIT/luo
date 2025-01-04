#include <stdio.h>
#include <math.h>//数学
#include <stdlib.h>//标准库，与下面连用获得随机数
#include <time.h>//随机时间
#include <stdbool.h>//bool,true,false,,
#include <string.h>
#include <limits.h>//搭配int max=INT_MIN,,是个很小的值
void getMaxAndMin(int arr[],int len,int *max,int *min){
    *max=arr[0];//获得数组首地址
    for(int i=1;i<len;i++){
        if(arr[i]>*max){
            *max=arr[i];
        }
    }
    * min=arr[0];
    for(int i=1;i<len;i++){
        if(arr[i]<*min){
            *min=arr[i];//指针寻找数组最大值，最小值
        }
    }
}
int compare(const void *a, const void *b) {//const void*指任意类型的的指针
    //return 时a在前升序
    // return (*(int *)a - *(int *)b);
      //返回负数代表第一个小于第二个,正值换位置
    long long int_a = *(const long long *)a;// const long long * 代表long long类型
    long long int_b = *(const long long *)b;//前面*解引用，指针指向a
    if (int_a < int_b) {
        return 1;  // 降序排列，较小的值返回1
    } else if (int_a > int_b) {
        return -1; // 较大的值返回-1
    } else {
        return 0;  // 相等时返回0
    }
    } // 降序
int compare_countries(const void *a, const void *b) {
    const char *country_a = *(const char **)a;
    const char *country_b = *(const char **)b;
    return strcmp(country_a, country_b);//国家名称，字符排序
}
int main(){
     long n;
    scanf("%ld", &n);
    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(long long), compare);
    long long min_diff = abs(arr[0] - arr[1]);
    for (int i = 1; i < n - 1; i++) {
        long long diff = abs(arr[i] - arr[i + 1]);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    printf("%lld\n", min_diff);


    const char *countries[] = {"China", "USA", "Japan", "India", "Russia"};
    int num_countries = sizeof(countries) / sizeof(countries);
    qsort(countries, num_countries, sizeof(countries), compare_countries);
    // 按照字母顺序输出排序后的国家名称
    for (int i = 0; i < num_countries; i++) {
        printf("%s ", countries[i]);
    }
    printf("\n");

    
    /*int n;//杨辉三角
    scanf("%d",&n);
    int triangle[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0||j==i){//每行第一个和最后一个为1
                triangle[i][j]=1;
            }else{
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
            }
            printf("%d ",triangle[i][j]);
        }
        printf("\n");
    }*/


    /*int T;//T张卷子，每张卷子一组数据，求出最大，最小
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d",&n);
        int arr[n];
        int max = INT_MIN,min = INT_MAX;//初始化定义
        for(int q=0;q<n;q++){
            scanf("%d",&arr[q]);
        }
        double fangcha,jicha,sum=0,avr;
        for(int j=1;j<=n;j++){
            sum+=arr[j-1];
            if(max<arr[j-1]){
                max=arr[j-1];
            }
            if(min>arr[j-1]){
                min=arr[j-1];
            }
        }
        avr=sum/n;
        jicha=max-min;
        fangcha= pow((arr[0]-avr),2);
        for ( int k=1; k<n; k++) {
            fangcha += pow((arr[k]-avr),2);
        }
        fangcha = fangcha/n;
        printf("%.f %.3lf\n", jicha, fangcha);
    }*/


    int arr[]={1,2,3,4,5,7,9,4};
    int len=sizeof(arr)/sizeof(int);
    int max=arr[0];
    int min=arr[0];
    getMaxAndMin(arr,len,&max,&min);//定义指针用法
    printf("%d %d\n",max,min);//利用指针寻找最大值
    
 /*int a, b, c, d, max;//找四个当中最大整数
    scanf("%d %d %d %d", &a, &b, &c, &d);
    max = a > b ? (a > c ? (a > d ? a : d) : (c > d ? c : d)) : (b > c ? (b > d ? b : d) : (c > d ? c : d));
    printf("%d\n", max);
    */

    /*int arr[10]={0};
    int len=sizeof(arr)/sizeof(int);
    srand(time(NULL));//生成随机数
    for(int i=0;i<len;){
        int num=rand()%100+1;//使得生成数范围为1——100
        int flag =0;
        for (int j=0;j<i;j++){
            if(arr[j]==num){//使生成随机数字且各不相等，如果相等跳出循环
                flag =1;
                break;//跳出内循环，开始外循环
            }
        }
        if(flag ==0){
         arr[i]=num;//储存在数组中
         i++;
        } 
    }
    int sum=0;
    for(int i=0;i<len;i++){
        printf("%d\n",arr[i]);
        sum+=arr[i];//求数组中所有数的和
    }
    printf("%d",sum);
    */

   int n;//数组中插入一个数,两个数组合并要注意剩余数据,依次输出
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    scanf("%d",&x);
    int input=0;
    if(n!=0){
    for(int i=0;i<n;i++){
        if(arr[0]>x&&!input){
            printf("%d ",x);
            input=1;
        }
         printf("%d ",arr[i]);
    if(!input&&((i<n-1&&arr[i]<=x&&arr[i+1]>=x)||(i==n-1&&x>=arr[n-1])||(i==0&&x<=arr[0]))){
            printf("%d ",x);
             input=1;
        }          
        }
    }else{
        printf("%d",x);
    }
   
      /*double a, b, r;
    char op;  //定义运算符
       while(scanf("%lf %c %lf", &a, &op, &b) == 3){  //循环三次 
        if (op == '+') {  
            r = a + b;  
            printf("%.4lf+%.4lf=%.4lf\n", a, b, r);  //保留四位小数
        }   
        else if (op == '-') {  
            r = a - b;  
            printf("%.4lf-%.4lf=%.4lf\n", a, b, r);  
        }  
        else if (op == '*') {  
            r = a * b;  
            printf("%.4lf*%.4lf=%.4lf\n", a, b, r);  
        }   
        else if (op == '/') {  
            if (b == 0.0) {  
                printf("Wrong!Division by zero!\n");  
            } else {  
                r = a / b;  
                printf("%.4lf/%.4lf=%.4lf\n", a, b, r);  
            }  
        }  
        else {  
            printf("Invalid operation!\n");  
        }  
}*/ 

   int k=arr[0];//数组向前平移一个
    for(int i=0;i<n;i++){
        
        if(i<n-1){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            printf("%d ",arr[i]);
        }else{
            arr[n-1]=k;
            printf("%d\n",arr[i]);
        }
    }
    
    int n;//火车上调座位并替换
        scanf("%d",&n);
    getchar();
    char s[n][6];
    for(int i=0;i<n;i++){
       scanf("%s",s[i]);
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(flag==0){
      for(int j=0;j<4&&flag==0;j++){
          if(s[i][j]==s[i][j+1]&&s[i][j]=='O'){
              s[i][j]='+';
              s[i][j+1]='+';
              flag=1;
              break;
          }
      }
        }
    }
    if(flag){
        printf("YES\n");
        for(int i=0;i<n;i++){
            printf("%s\n",s[i]);
        }
    }



    int n, m;
    scanf("%d %d", &n, &m);
    // 声明一个布尔数组，用于记录哪些数字已经出现
    bool exists[n];
    for (int i = 0; i < n; i++) {
        exists[i] = false;
    }
    int arr[m];
    for (int k = 0; k < m; k++) {
        scanf("%d", &arr[k]);
        if (arr[k] >= 0 && arr[k] < n) {
            exists[arr[k]] = true;
        }
    }


     /*char s[10001];//输出第一个没有重复的字符
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
   if (len > 0 && s[len - 1] == '\n') {
    s[len - 1] = '\0'; 
    len--;
   }
    int count[256] = {0};
    for (int i = 0; i < len; i++) {
        count[s[i]]++;
    }
    for (int i = 0; i < len; i++) {
        if (count[s[i]] == 1) {
            printf("%c", s[i]);
            return 0; 
        }
    }
    printf("-1");*/


    // 检查是否存在0到n-1之间的所有数字
    bool all = true;
    for (int i = 0; i < n; i++) {
        if (!exists[i]) {
            all = false;
            break;
        }
    }

    if (all) {
        printf("%d\n", n);
    } else {
        for (int i = 0; i < n; i++) {
            if (!exists[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    /*long n;
    scanf("%ld", &n);
    long arr[n];
    for(long i = 0; i < n; i++){
        scanf("%ld", &arr[i]);
    }
    bool flag=true;//定义布尔类型标记物
    long lastSwap, boundary;
    boundary = n - 1;  //边界
    for(long j = 0; j < n - 1&&flag; j++){///冒泡排序
        lastSwap = 0; 
        flag=false;//初始为true，循环为false
        for(long q = 0; q < boundary; q++){
            if(arr[q + 1] > arr[q]){
                long temp = arr[q];//从大到小
                arr[q] = arr[q + 1];
                arr[q + 1] = temp;//
                flag = true;//位置改变则成为true
                lastSwap = q;  //确认已经比较到q,跳转到q继续比较
            }
        }
        boundary = lastSwap;//确定lastSwap进行到哪一个并赋值给boundary
    //在一次循环中，flag变量发生改变，为true没有交换为false
    if判断flag状态，如果没有发生变化，已经排序完成
        if(!flag)
            break;//跳出循环  
    }
    for(int i=0;i<n;i++){
        printf("%ld",arr[i]);
    }


    int count = 1;//按照大小排序后查找重复的数字以及个数
    for (int i = 0; i <=n - 1; i++) {
        if (a[i] == a[i + 1]) {
            count++;
        } else {
            printf("%d-%d\n", a[i], count);
            count = 1;
        }
    }

     //直接进行从大到小计数
     int count[100001]={0};
     for(int i=0;i<n;i++){
     count[a[i]]++;
}
for(int i=10000;i>=1;i--){
    if(count[i]!=0){
    printf("%d-%d\n",i,count[i]);
}

    }

    int count = 1;//按照数字出现的次数找到出现最大
    int max_count = 1;
    int max_num = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        } else {
            count = 1;
        }
        if (count >= max_count) {
            max_count = count;
            max_num = a[i];
        }
    }

    //排序后进行去重
    int l=0;
	arr[0]=a[0];
	for(int j = 0; j < n-1; j++) {   
		if(a[j]!=a[j+1]){           
			arr[++l]=a[j+1];//新数组,如果前边和后边不相等输出后边
		}
	}
	printf("%d",arr[0]);
	for(int i=1;i<=l;i++){   
		printf(" %d",arr[i]);
	}
   */

    return 0;
}
    