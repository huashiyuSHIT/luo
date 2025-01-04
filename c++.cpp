#include<bits/stdc++.h>
#include<string>
#include <cmath>
using namespace std;
string multiply(const string &num1, const string &num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> result(n1 + n2, 0);
    // 从右向左逐位相乘
    for (int i = n1 - 1; i >= 0; --i) {
        for (int j = n2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    // 去掉前导零
    int i = 0;
    while (i < result.size() && result[i] == 0) {
        ++i;
    }
    // 如果结果为空，返回"0"
    if (i == result.size()) {
        return "0";
    }
    string res;
    for (; i < result.size(); ++i) {
        res += to_string(result[i]);
    }
    return res;
}
string add(const string &num1, const string &num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    int carry = 0;
    string result;
    for (int i = n1 - 1, j = n2 - 1; i >= 0 || j >= 0 || carry; --i, --j) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += to_string(sum % 10);
    }
    reverse(result.begin(), result.end());
    //去除前置0；
    int pos = result.find_first_not_of('0');
    result.erase(0,pos);
    return result;
}

int compare(const void *a,const void *b){
    return(*(int *)a-*(int *)b);//排序
}
// 比较函数，用于std::sort，按照字符串长度从小到大排序
bool cmp(const string& a, const string& b) {
    return a.size() < b.size();
}
int compare(const void *a, const void *b) {
    const char **s1 = (const char **)a;
    const char **s2 = (const char **)b;
    return strlen(*s1) - strlen(*s2);
}

bool isPrime(long long n) {
    if(n<=1){
        return false;
    }
    if(n == 2||n==3){
        return true;
    }
    if(n%2==0||n%3==0){
        return false;
    }
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0){
            return false;
        }
    }
    return true;
}
void printFactors(long long n) {//输出因数
    bool first = true;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            if (!first) cout << " ";
            cout << i;
            first = false;
            if (i != n / i) {
                cout << " " << n / i;
            }
        }
    }
    cout << endl;
}
// void hanoi(int n, char source, char auxiliary, char destination) {
//     if (n == 1) {//移动最下边
//     cout << "1 " << source << "->" << destination << endl;
//         return;
//     }
//     hanoi(n - 1, source, destination, auxiliary);
//将上两个移动到辅助
//     cout <<  n << ":" << source << "->"<< destination <<endl;
//     hanoi(n - 1, auxiliary, source, destination);
//辅助移动到目标
// }
// int guess(int a,int b,int c,int n){
//     if(n==0){
//         return 1;
//     }
//     int num=0;
//         if(a>0){
//             num+=guess(a-1,b,c,n-1);
//             //选择a-1个A和b个B和c个C组成n-1个字符串
//             //继续递归a-2个A和b个B和c个C组成n-2个字符串
//             //如果a=0，在在这个a基础上选择bc
//         }
//     if(b>0){
//         num+=guess(a,b-1,c,n-1);
//     }
//     if(c>0){
//         num+=guess(a,b,c-1,n-1);
//     }
//     return num;
// }//字母组合成多种字符串
// int Factor(int n, int start) {
//     if (n == 1) return 0; 
//     int count = 0;
//     for (int i = start; i * i <= n; i++) {
//         if (n % i == 0) {
//             count += 1; 
//             count +=Factor(n / i, i);
//         }
//     }
//     return count;
// }//数字拆分为多种组合
int main() {
    string yuan = "ABCDEF";
    long long num =stoll(yuan, nullptr, 16);//yuan的进制
    cout  << setw(15)<<setfill(' ')<<num << endl;
    //十六进制转化为十进制
    long long change;
    stringstream ss;
    ss<<hex<<yuan;//将yuan十六进制转化为十进制
    ss>>change;
    cout<<change;
    
     cout<<"printf(\"Hello world!\\n\");"<<"\n";
   cout<<"cout << \"Hello world!\" << endl;";
   //注意是\" \"
    int num;
    cin >> num;
    double result = num / 100.0;
    // 使用round函数四舍五入
    result = round(result * 10) / 10.0;
    //小数点后一位保留
    cout << fixed << setprecision(1) << result <<endl;
    int j=ceil(num*0.1);//向上取整

     for(int i=0;i<26;i++){
        char c=i+'A';
        cout<<c;
    }

    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='a'&&a[i]<='z')
        a[i]=a[i]-'a'+'A';//小写转化为大写
        else if(a[i]>='A'&&a[i]<='Z')
        a[i]=a[i]-'A'+'a';//大写转化成小写
        cout<<a[i];
    }


     double result = num * 304.8;
    if (result == (int)result) {//如果是整数，直接输出
        cout<<(int)result<<endl;
    } else {
        cout<<fixed<<setprecision(1)<<result<<endl;
    }

    string sb;
    cin >> sb;
    // 使用 find 函数查找 "ab" 子字符串并删除
    size_t pos;//定义存储位置
    while ((pos = sb.find("ab")) != string::npos) {
        sb.erase(pos, 2);
    }
    if (sb.empty()) {//sb是空字符串
        cout << "Good";
    } else {
        cout << "Bad";
    }

    string line;
    while (getline(cin, line)) { // 读取每组数据
        if (line.empty()) continue; // 跳过空行

        vector<string> group;
        string word;
        stringstream ss(line);//将line字符串转换成流

        while (ss >> word) { // 读取每组数据中的每个字符串
            group.push_back(word);
        }
        sort(group.begin(), group.end());
        //数组是string则按照字典顺序，int大小顺序
        for (string str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    

    // 判断质数，并且输出因数
    /* cout<<"noprime"<<endl;
            for (long long j = 2; j <= sqrt(arr[i]); j++) {
                if (arr[i] % j == 0) {
                    cout << j << " ";
                    long long otherFactor = arr[i] / j;
                    if (j!= otherFactor) {
                        cout << otherFactor << " ";
                    }
                }
            }
            cout <<endl;*/

    long long t;
    cin >> t;  
    string original = to_string(t);
    //to_string函数将long long类型的变量t转换为string类型，并将结果存储

    // 构建回文数
    string reversed_part = original;  
    reverse(reversed_part.begin(), reversed_part.end());
    string palindrome = original + reversed_part.substr(1);  
    // 拼接回文数，去掉翻转部分的首字符
    // 转为数字
    long long palindrome_number = stoll(palindrome);//转化为long long



    long long n,r;
    cin>>n>>r;//转化为任意进制
    vector<char>shift;
    while(n>0){
        if(n%r<10){
        shift.push_back(n%r+'0');//数字转化为字符
    //     for (int i = 0; i < 12; i++) {
    //     if (arr[i]>='0'&&arr[i]<='9') {
    //         sum+=(arr[i] - '0')*j;//数字字符转化为数字
    //         j++;
    //     }
    // }
        }else{
            char temp='A'+n%r-10;
            shift.push_back(temp);
            //push.back()函数一直延伸数组,搭配容器
        }
        n/=r;
    }
    reverse(shift.begin(),shift.end());// //数组前后颠倒
    string s(shift.begin(), shift.end());//将vector中的元素组成字符串
    int num = stoi(s);//将字符串转化为数字
    for(char j:s){
        cout<<j;
    }

     string s;
    int sum = 0;//不知道多少组数据
    while (getline(cin, s)) {//不知道每组几个数据
        for (int i = 0; i < s.size(); i++) {
            if(s[i]>='0'&&s[i]<='9'){
            sum += s[i] - '0';//-'0'数字字符转化为数字
            }
        }
        cout << sum << endl;
        sum = 0;
    }


    string s;
    getline(cin,s);
    // 使用 unordered_set 来记录出现过的字符
    unordered_set<char> uniqueChars;
    for (char c : s) {
        uniqueChars.insert(c);
    }
    // 输出 uniqueChars 的大小，即不同字符的数量
    cout << uniqueChars.size() << endl;

    /*int n,k,m;
    cin>>n>>k>>m;
    vector<int> circle(n);//初始化一个数量为n，0，1，2依次递增的数组
  iota(circle.begin(), circle.end(), 0);
    int size = n; 
    int index = k; 
    while (size > 1) {
        index = (index + m - 1) % size;//超出后从头开始
        for (int j = index; j < size - 1; j++) {
            circle[j] = circle[j + 1];
        }
        size--;
    }
    cout << circle[0] << endl; 
    */

    string a,b;
   string mima,daan,c,d="";
    cin>>mima>>daan>>c;
    int zimu[27]={0};
    char zimu2[27]={0};
    for(int i=0;i<daan.size();i++){
        if(zimu[b[i]-'A']==0){
           zimu[b[i]-'A']=1; //字母用过
        }
    }
    for(int j=0;j<26;j++){
        if(zimu[j]==0){//26个字母出现
            cout<<"Failed";
            return 0;
        }
    }
    for(int i=0;i<mima.size();i++){
        if((zimu2[a[i]-'A']==0) || (zimu2[a[i]-'A']==b[i])){
            zimu2[a[i]-'A']=b[i];//还没有建立过映射关系，或者已经建立映射
        }else{
            cout<<"Failed";//建立不同的映射
            return 0; 
        }
        
    }
    for(int i=0;i<c.size();i++){
       d+=zimu2[c[i]-'A']; 
    }
    cout<<d;
    return 0;

    
     int rows, cols;
    cin >> rows >> cols;


    int base;//n进制加法
    string num1, num2;
    cin >> base >> num1 >> num2;
    //对齐
    while (num1.size() < num2.size()) {
        num1 = '0' + num1;
    }
    while (num2.size() < num1.size()) {
        num2 = '0' + num2;
    }
    string resultnum;
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i) {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = sum / base;
        resultnum += (sum % base) + '0';
    }
    // 如果最高位有进位，添加一位
    if (carry > 0) {
        resultnum += carry + '0';
    }
    reverse(resultnum.begin(), resultnum.end());
    cout << resultnum << endl;


    // 定义二维数组
    vector<vector<int>> rr(rows, vector<int>(cols));
    // 读取二维数组的值
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> rr[i][j];
        }
    }

    vector<pair<int, int>> points(n);//坐标定义
     for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
}
 double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; // 下一个点，最后一个点连接到第一个点
        area += points[i].first * points[j].second;
        area -= points[j].first * points[i].second;
    }
    area = abs(area) / 2.0;
    // 四舍五入输出结果
    cout << round(area) << endl;

    //寻找等差数列
     for(int i = 0;i < s.size();i++){
        if(s[i+1] - s[i] == s[i+2] - s[i+1]){
            while(s[i+1] - s[i] == s[i+2] - s[i+1]){
                cout << s[i]<<' ';
                i++;
            }
            cout << s[i]<<' '<< s[i+1]<<endl;
            i++;
        }
    }

    vector<int> nums={1,2,3,4,5,6,7,8};
    for(int i:nums){
       cout<<i<<" ";
   }
       cout<<endl;
   while(next_permutation(nums.begin(),nums.end())){
    //next_permutation函数用于生成下一个排列，从小到大
       for(int i:nums){
       cout<<i<<" ";
   }
       cout<<endl;
   }

     string expression;//计算加法乘法表达式
    cin >> expression;
    long long finalresult = 0;
    long long currentNumber = 0;
    long long tempProduct = 1;
    bool inMultiplication = false;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (isdigit(s[i])) {
            currentNumber = currentNumber * 10 + (s[i] - '0');
        } else {
            if (inMultiplication) {
                //如果是乘法
                tempProduct *= currentNumber;
                tempProduct %= 10000;
            } else {
                tempProduct = currentNumber;
            }
            currentNumber = 0;//重置当前数字

            if (s[i] == '+') {
                finalresult += tempProduct;
                finalresult %= 10000;
                inMultiplication = false;
            } else if (s[i] == '*') {
                inMultiplication = true;
            }
        }
    }

    // 处理最后一个数字
    if (inMultiplication) {
        tempProduct *= currentNumber;
        tempProduct %= 10000;
    } else {
        tempProduct = currentNumber;
    }
    finalresult += tempProduct;
    finalresult %= 10000;

    // Remove leading zeros from the result
    string resultStr = to_string(result);
    size_t nonZeroPos = resultStr.find_first_not_of('0');
    if (nonZeroPos != string::npos) {
        resultStr = resultStr.substr(nonZeroPos);
    } else {
        resultStr = "0";
    }

    cout << resultStr << endl;


    return 0;
}
