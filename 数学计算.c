#include <stdio.h>
#include <math.h>//数学
#include <ctype.h>//大写字母转化为小写字母
#include <stdlib.h>//标准库，与下面连用获得随机数
#include <time.h>//随机时间
/*void sum(int num1,int num2){
    int sum=num1+num2;
    printf("%d",sum);//函数值不返回
}*/
/*
int sum(int num1,int num2){//返回函数值
    int sum=num1+num2;
    return sum;
}
*/
long long gcd(long long a, long long b) {//求出最大公约数
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long LCM(long long a,long long b) //计算最小公倍数
{
    return (a*(b/gcd(a,b)));
}

int isPrime(long long int n) {//判断大数字是不是质数
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

void conserve(int n){//十进制转换二进制
    int binary[32];
    int num=0;
    while(n>0){
        binary[num++]=n%2;
        n/=2;
    }
    for(int i=num-1;i>=0;i++){
        printf("%d",binary[i]);
    }
    printf("\n");
}
void splitIntoPowersOfTwo(int num) {//将数字拆分为2的次方相加
    int result[32];
    int index = 0;
    for (int power = 30; power >= 0; power--) {//从大到小
        int powerOfTwo = 1 << power; //二进制左移001左移2 100成为十进制4
        if (num >= powerOfTwo) {
            result[index++] = powerOfTwo; // 保存当前的2的幂
            num -= powerOfTwo;
        }
    }
    if (num != 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < index; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}
int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    conserve(num1);//搭配函数,转换十进制为二进制
    conserve(num2);


    int a=1234;
    printf("%#o %#X",a,a);
    //八进制和十六进制

    
    /*int score1=sum(93,10);//调用函数并返回函数值
    int score2=sum(80,20);
    if(score1!=score2){
        printf("good\n")
    }*/

    /*double vectotlength(double x,double y,double z);
    double sumofsquares=pow(x,2)+pow(y,2)+pow(z,2);//分别求x,y,z平方
    return sqrt(sumofsquares);//开根
    2<<3,
   
        double x=3.0;
        double y=4.0;
        double z=5.0;
*/

   /*double rest1 =ceil(12.3);//向上取整
   double rest2 =floor(12.3);//向下取整
   int rest5 =abs(-13);//绝对值
   printf("%e",num)输出指数形式*/


    /*int a, b, c, d, max;//找四个当中最大整数
    scanf("%d %d %d %d", &a, &b, &c, &d);
    max = a > b ? (a > c ? (a > d ? a : d) : (c > d ? c : d)) : (b > c ? (b > d ? b : d) : (c > d ? c : d));

    printf("%d\n", max);*/
    

    long long A, B;//求出最大公约数
    scanf("%lld", &A);
    scanf("%lld", &B);
    printf("%lld\n", gcd(A, B));//搭配函数

     float a = 0;
    float b = 0;
    float c = 0;
    while(scanf("%f %f %f",&a, &b, &c)!= EOF ){
        if(a == 0){
            printf("Not quadratic equation\n");
        }else{
            float t = b*b - 4*a*c;            
            if(t==0){
                float mp = -b + sqrt(t);
                //导致出现-0.00
                if(mp == 0){
                    printf("x1=x2=%.2f\n",mp);
                }else{
                    printf("x1=x2=%.2f\n",(-b+sqrt(t))/2.0/a);
                }
            }else if(t > 0){
                printf("x1=%.2f;x2=%.2f\n",(-b-sqrt(t))/2.0/a,(-b+sqrt(t))/2.0/a);
            }else{
                float xu = sqrt(-t)/2.0/a;
                if(xu < 0) {
                    xu = -xu;
                }
                printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n",-b/2/a,xu,-b/2/a,xu);
            }
        }
    }


      
     /*int n;
   scanf("%d",&n);
   char BIG='A'+n-1;
   printf("%c",'A'+n-1);//输入1——26的数字对应相应大写字母
    printf("%c\n",96+n);//输入1——26序号输出小写
    char c;
    scanf("%c\n",&c);
    printf("%d\n",c);//字符转ASCII码表
    char ch = 'A';//大写转化为小写
    printf("The lowercase of '%c' is '%c'.\n", ch, tolower(ch));
    
    char ch = 'a';//小写转化大写
    printf("The uppercase of '%c' is '%c'.\n", ch, toupper(ch));
*/
    int n;//判断是不是质数
   scanf("%d",&n);
   int num=isPrime(n);//搭配函数
   if(num==0){
       printf("no");
   }else{
       printf("yes");
   }

    /*long k = 0;一组数据 3^0,3^1,3^0+3^1,3^2,3^0+3^1,3^0+3^1
    long n = 0;
    scanf("%ld %ld",&k,&n);
    int a = 0;
    long int sum = 0;
    for(int i = 0 ; n != 0; i++)
    {
        a = n % 2;//快速幂
        sum += pow(k,i)*a;
        n /= 2;
    }
    printf("%ld" , sum);*/
    
    long long n;//找出一堆筷子中落单的
    scanf("%lld", &n);
    long long result = 0;
    for (long long i = 0; i < n; i++) {
        long long num;
        scanf("%lld", &num);
        result ^= num;//异或运算，二进制运算，每一位分别运算，相等就是0，不相等1
    }//每个数字和0异或运算时还是原来，相同的数进行异或运算为0
    printf("%lld\n", result);

    return 0;
}