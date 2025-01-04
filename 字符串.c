#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
typedef struct{//结构体
    char name[100];
    int attack;
    int defense;
    int blood;
}M;//字符串另命名

struct Message{
    char phone[12];
    char mail[100];
};
struct Student{
   char name[100];
   int age;
   char gender;
   double height;
   struct Message message;
};
void decimalToBinary(int n, char *binaryStr) {
    int index = 0;
    char temp[32];
    // 十进制转换为二进制并逆序存储
    while(n>0){
        temp[index++] = (n % 2) + '0';//将数字转为字符
        n /= 2;
    }
    // 将逆序的二进制字符串转正序存储
    int j = 0;
    for (int i = index - 1; i >= 0; i--) {
        binaryStr[j++] = temp[i];
    }
    binaryStr[j] = '\0'; // 添加字符串结束符
}
// 将二进制字符串转换为十进制整数
int binaryToDecimal(char *binaryStr) {//char类型的指针数组
    int result = 0;
    for (int i = 0; binaryStr[i] != '\0'; i++) {
        result = result * 2 + (binaryStr[i] - '0');
    }
    return result;
}

struct spot{
    char name[100];//字符串要求多输入一个/0
    int count;
};

// 判断一个字符串是否为回文串
int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start]!= s[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int main(){
    int A, B;
    char binaryStrA[32], binaryStrB[32], concatenatedBinary[64];
    scanf("%d", &A);
    scanf("%d", &B);

    // 获取 A 和 B 的二进制字符串表示
    decimalToBinary(A, binaryStrA);
    decimalToBinary(B, binaryStrB);
    printf("A 的二进制表示是: %s\n", binaryStrA);
    printf("B 的二进制表示是: %s\n", binaryStrB);

    // 拼接 A 和 B 的二进制字符串
    strcpy(concatenatedBinary, binaryStrA);//把concet变得与A相同
    strcat(concatenatedBinary, binaryStrB);//将B复制到concaten末尾

    // 将拼接后的二进制字符串转换为十进制，比如二进制10，11，
    int result = binaryToDecimal(concatenatedBinary);
    printf("拼接后的二进制表示的十进制结果是: %d\n", result);

    
    /*int width = 10;
    char *str = "Hello";//字符指针
    printf("%*s\n", width, str);//左对齐，共10个字符，hello占5个，前边五个空格

     char str[]="hello"
     printf("%*s\n", width, str)//效果相同
*/

int n;////判断一个字符串是不是由两个回文字符串组成
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        char str[1000];
        fgets(str, sizeof(str), stdin);
        int len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }
        int flag = 0;
        for (int j = 1; j < len - 1; j++) {
            if (isPalindrome(str, 0, j - 1) && isPalindrome(str, j, len - 1) && j >= 2 && len - j >= 2) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }


char str1[1000], str2[1000];
    // 使用fgets读取字符串并处理换行符
    gets(str1);//键盘录入方法三,可以录入空格

    getchar();//清除空格，搭配fgets,统计字符数量时不用
    fgets(str1, sizeof(str1), stdin);//键盘录入方法一
    size_t len1 = strlen(str1);
    if (len1 > 0 && str1[len1 - 1] == '\n') {
        str1[len1 - 1] = '\0';//去掉换行和结束
    }
    fgets(str2, sizeof(str2), stdin);
    size_t len2 = strlen(str2);
    if (len2 > 0 && str2[len2 - 1] == '\n') {
        str2[len2 - 1] = '\0';
    }//找出录入的字符数量
    
    // 直接利用strcspn函数找到换行符位置并替换为'\0'
    str1[strcspn(str1, "\n")] = '\0';//键盘录入方法二
    str2[strcspn(str2, "\n")] = '\0';
    
    strcat(str1, str2);//把2拼接到1后面
    printf("%s", str1);


   /*char strArr[3][100]={
    "zhangsan",
    "lisi",
    "wangwu"
   };
   for(int i=0;i<3;i++){
    char *str=strArr[i];
    printf("%s\n",str);
   }*/


   char a[303],b[101],c[101];
    fgets(a,sizeof(a),stdin);
    int len1=strlen(a);
    if(len1>0&&a[len1-1]=='\n'){
        a[len1-1]='\0';
        len1--;
    }//删去换行符
    fgets(b,sizeof(b),stdin);
    int len2=strlen(b);
    if(len2>0&&b[len2-1]=='\n'){
        b[len2-1]='\0';
        len2--;
    }
    fgets(c,sizeof(c),stdin);
    int len3=strlen(c);
    if(len3>0&&b[len3-1]=='\n'){
        c[len3-1]='\0';
        len3--;
    }
    int count1=0,count2=0,count3=0,count4=0,count5=0;
    strcat(b,c);
    strcat(a,b);
    int len=strlen(a);//三个字符串进行拼接
     if(len>0&&a[len-1]=='\n'){
        a[len-1]='\0';
        len--;
    }
    for(int i=0;i<len;i++){
        if(a[i]>='A'&&a[i]<='Z'){
            count1++;//判断大写字符
        }else if(a[i]>='a'&&a[i]<='z'){
            count2++;//判断小写字符
        }else if(a[i]>='0'&&a[i]<='9'){
            count3++;//判断数字
        }else if(a[i]==' '){
            count4++;//判断空格
        }else {
            count5++;//判断其他字符
        }


   /*char str[100];
    int char_count[256] = {0};  // 初始化字符计数数组
    int unique_count = 0;
    scanf("%s", str);//C语言&获取地址
    // 遍历字符串并记录每个字符的出现情况
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        if (char_count[ch] == 0) {  // ch意义只读取ASCII表中的字母
            unique_count++;
        }
        char_count[ch]++; 
    }
    printf("不同字符的数量是: %d\n", unique_count);*/
    

    /*M taro={"泰罗",100,90,500};//函数
    M reou={"雷欧",100,90,500};
    M aidi={"艾迪",100,90,500};
    M arr[3]={taro,reou,aidi};

    M bb;//键盘录入
    fget(&bb.name,100,stdin);
    scanf("%d",&bb.attack);)
    scanf("%d",&bb.defense);
    scanf("%d",&bb.blood);
    printf("名字%s,攻击%d,防御%d,体力%d\n",bb.name,bb.attack,bb.defense,bb.blood);


    for(int i=0;i<3;i++){
        M temp=arr[i];
        printf("名字%s,攻击%d,防御%d,体力%d\n",temp.name,temp.attack,temp.defense,temp.blood);
    }*/

    /*int n, m;
    scanf("%d %d", &n, &m);
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]); //利用字符串输入，防止录入空格
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '*') {
                printf("*");
            } else {
                int num = 0; 
                for (int q1 = -1; q1 <= 1; q1++) {
                    for (int q2 = -1; q2 <= 1; q2++) {
                        if (q1 == 0 && q2 == 0) continue;
                        if (i+q1>= 0 &&i+q1 < n && j+q2>= 0 &&j+q2< m && arr[i+q1][j+q2] == '*') {
                            num++;//判断周围九宫格
                        }
                    }
                }
                printf("%d", num); 
            }//扫雷，将周围的*的个数
        }
        printf("\n"); 
    }*/



    struct Student stu;//结构体初始化
    strcpy(stu.name,"zhangsan");
    stu.age="23";
    stu.gender="M";
    stu.height=1.78;
    strcpy(stu.message.phone,"123456");
    strcpy(stu.message.mail,"123456@qq.com");
    printf("%s\n",stu.name);
    printf("%d\n",stu.age);
    printf("%c\n",stu.gender);
    printf("%lf\n",stu.height);
    printf("%s\n",stu.message.phone);
    printf("%s\n",stu.message.mail);
    //批量命名且结构体嵌套
    struct Student stu2={"lisi",24,"f",1.65,{"123456","123456@qq.com"}};


//景点随机投票，找到票数最大的地点及票数
    struct spot arr[4]={{"A",0},{"B",0},{"C",0},{"D",0}};
    srand(time(NULL));
    for(int i=0;i<80;i++){
        int choose=rand()%4;
        arr[choose].count++;
    }
    int max=arr[0].count;//找到最大值
    for(int i=0;i<4;i++){
        struct spot temp=arr[i];
        if(temp.count>max){
            max=temp.count;
        }
    }
    for(int i=0;i<4;i++){
        struct spot temp=arr[i];
        if(temp.count==max){
           printf("%s %d\n",temp.name,temp.count);
           break;//找到最大值地点和票数
        }
    }


     /*int n;//判断全是小写字母的的长度
    //abccb中abb1个acc一个
    scanf("%d", &n);
    char arr[n + 1];
    scanf("%s", arr);
    long long count = 0;
    int left_count[26] = {0};
    int right_count[26] = {0};
    for (int i = 0; i < n; i++) {
        right_count[arr[i] - 'a']++;
    }//每个字母的数量

    // 遍历每个字符作为中间字符
    for (int j = 0; j < n; j++) {
        // 移动当前字符到左侧
        right_count[arr[j] - 'a']--;
        for (int c = 0; c < 26; c++) {//从a，b，c
            if (c != arr[j] - 'a') {//即arr[i] != arr[j]，c是中间值
                count += left_count[c] * right_count[arr[j] - 'a'];
            }
        }

        // 更新左侧字符频次
        left_count[arr[j] - 'a']++;
    }

    printf("%lld\n", count);*/


    return 0;
}
