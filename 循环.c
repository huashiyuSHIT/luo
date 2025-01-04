#include <stdio.h>
#include <string.h>
int guess(int num) {//判断是否含有3或者7
    while (num > 0) {
        if (num % 10 == 3 || num % 10 == 7) {
            return 1;
            break;
        }
        num /= 10;
    }
    return 0;
}
int max(int a,int b){
    return a>b?a:b;
}
int main(){     
    /*char a[10], b[10]; //输入
    int count = 0;//判断%s字符串，%c用于字符
    while (scanf("%s %s", &a[count], &b[count]) == 2) {//scanf扫描一次后返回值==1，现在一直循环
        count++;                 
    }
    for (int i = 0; i < count; i++) {
        if(strcmp(a,"admin")==0&&strcmp(b,"admin")==0){//strcmp比较两个字符串==返回0’大于返回1‘小于返回-1
            printf("Login Success!\n");
        }else{
            printf("Login Fail!\n");
        }
    }*/

   
   /*
   int a,b;//双彩球
    int aa[2];
    int bb[2];
    int count=0;
    scanf("%d %d",&a,&b);
   aa[0]=a/10;
    aa[1]=a%10;
    bb[0]=b/10;
    bb[1]=b%10;
    if(a==b){
        printf("100\n");
        return 0;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
             if(aa[i]==bb[j]){
                count++;
                break;
            }
        }
           
    }
    if (count == 2) {
        printf("20\n"); 
    } else if (count == 1) {
        printf("2\n"); 
    } else {
        printf("0\n");  
    }
    */

    /*
    int x;//反向输出数字，while循环12345输出54321
    scanf("%d",&x);
    int dight;
    int ret=0;
    while(x>0){

        dight=x%10;
       printf("%d\n",dight);
        ret =ret*10+dight;
        //printf("x=%d,dight=%d,ret=%d\n",x,dight,ret);//dight为尾数
        x/=10;
    }
    printf("%d",ret);//输出翻转后的数字
    */


    /*
    int n;//输入n
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);//接下来n个数字
    }
        for(int j=0;j<n;j++){
            int num=0;
            int count=0;
           while(arr[j]>0){
               count=arr[j]%10;
               num=num+count;
               arr[j]/=10;//while循环求出数字各个位数
               }
             if(num%7==0){
                   printf("Yes\n");
               }else{
                   printf("No\n");
           }
        }

   
     /*int n;//阶乘求和
    scanf("%d",&n);
    int arr[n];
    int count=0;
    for(int i=1;i<=n;i++){
        arr[i-1]=1;
        for(int j=1;j<=i;j++){
            arr[i-1]*=j;
        }count+=arr[i-1];
    }
    printf("%d",count);

    /*
    int num1,num2;//输出有系列数字以及相应次数，求两个数范围内能被6，8整除的数字及其个数
    printf("输入两个整数\n");
    scanf("%d %d",&num1,num2);
    int min=num1<num2?num1:num2;
    int max=num1>num2?num1:num2;
    int count=0;
    for (int i=min;i<=max;i++){
        if(i%6==0&&i%8==0){
            printf("%d\n",i);
            count++;
        }
    }
    printf("一共有%d个数字\n",count);
    */

   int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == (n - i - 1)) {//输出图案X
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n"); 
    }


   int n;
   scanf("%d",&n);//打印金字塔式字母表
    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            printf(" ");
        }for(int q=1;q<=2*i-1;q++){
            printf("%c",'A'+i-1);
        }
       printf("\n");
    }


    int n;//打印出菱形
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 1; i++) {
        // 判断当前行是上半部还是下半部
        int lineLen = i <= n ? i : 2 * n - i;
        // 打印前置空格
        printf("%*s", n - lineLen, "");//*占位符，表示指定宽度，n-linelen表示宽度,""没有字符会用空格
        for (int j = 1; j <= lineLen; j++) {
            printf("* ");
        }
        printf("\n");
    }

     int n;//打印弓
    scanf("%d",&n);
    for(int i=1;i<=2*n+1;i++){
        int line =i<=n+1?i:2*n-i+2;
        printf("%*s",2*(n-line+1),"");
        for(int j=1;j<=line;j++){
            printf("*");
        }
        printf("\n");
    }


     int array[1001][1001] = { 0 };
    int n = 0;//蛇形矩阵输出
    scanf("%d",&n);
    int i = 1, j = 1, k = 0,pos = 1; //pos代表方向移动   1代表右上   -1代表左下
    array[i][j] = 1;
    for (k = 2; k <= n*n; k++)
    {
        if (i == 1 && j <n && pos ==1) //碰到上边界,列增加1,行不变     此后行增,列减
        {
            array[i][++j] = k;
            pos = -1;                 //方向注意
        }
        else if(j==1 && i<n && pos == -1)//碰到左边界,行增加1,列不变     此后行减,列增
        {
            array[++i][j] = k;
            pos = 1;                     //方向注意               
        }
        else if (j == n && pos==1) //碰到左边界,行增加1,列不变     此后行增,列减
        {
            array[++i][j] = k;
            pos = -1;                     //方向注意
        }
        else if (i == n && pos ==-1) //碰到右边界,列增加1,行不变    此后行减,列增
        {
            array[i][++j] = k;
            pos = 1;
        }
        else if (pos == 1)  
        {
            array[--i][++j] = k;
        }
        else if(pos == -1)
        {
            array[++i][--j] = k;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }


    /*int x,y,z,n,m;//公鸡母鸡小鸡问题
    scanf("%d %d %d %d %d",&x,&y,&z,&n,&m);
    int count=0;
    for(int i=0;i<=n/x;i++){
        for(int j=0;j<+(n-i*x)/y;j++){
            int chicken=m-i-j;
            if(chicken>=0&&chicken%z==0&&i*x+j*y+chicken/z==n){
                count++;
            }
        }
    }printf("%d\n",count);*/
    
    /*
    for(int i=1;i<=9;i++){//九九乘法表，，循环嵌套
        for(int j=1;j<=i;j++){
            printf("%d*%d =%d\t",j,i,j*i);//\t表示制表符，可以保持长度，使整体为8的倍数
        }
        
        printf("\n");
    }
    */
      
      /* int T;//利用数组T行共
    scanf("%d",&T);
    for(int i=0;i<T;i++){
         int sum=0;
        for(int j=1;j<=4;j++){
            int arr[4];
            scanf("%d",&arr[j]);
            sum+=arr[j];
        }
        printf("%d\n",sum);
    }
    */

   /*for (int i = 0; i <= 1000; i++) {//输出0到1000内数字和为15，如69
        int sum = 0;
        int temp = i;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == 15) {
            printf("%d\n", i);
        }
    }
    */
    int r;//找出三角形金字塔的最长路径
    scanf("%d",&r);
    int a[1009][1009];
    int b[1009][1009];
     
    for(int i=1;i<=r;++i)
        for(int j=1;j<=i;++j)
        {
            scanf("%d",&a[i][j]);
        }
    for(int j=1;j<=r;++j)
    {
        b[r][j]=a[r][j];
    }
     
    for(int i=r;i>=0;--i)
    {
        for(int j=1;j<=i;++j)
        {//max函数为二者较大值,函数
            b[i][j] = a[i][j]+max(b[i+1][j],b[i+1][j+1]);
            //b数组依次为a数组相应数值找到上一行较大数值
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    printf("%d",b[1][1]);

   
   /*int r, l, k;//判断r到l之间k的整数次方
    scanf("%d %d %d", &r, &l, &k);
    for (int power = 1; power <= l; power *= k) {
        if (power >= r) {
            printf("%d\n", power);
        }
    }*/

    int N;//将一个整数分解为三个数字且每个数字不相同，上边函数
    scanf("%d", &N);
    int count = 0;
    for (int j = 1; j < N - j; j++) {
        for (int k = 1; k <N - j - 1; k++) { 
            int num1 = N - j - k;
            if (guess(j) == 0 && guess(k) == 0 && guess(num1) == 0&&k>j&&num1>k) {
                count++;
            }
        }
    }
    printf("%d\n", count);


    return 0;
}