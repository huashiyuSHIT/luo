#include <bits/stdc++.h>
using namespace std; 
const double pi=3.14;
class againadd{
    public:
    againadd(){};
    againadd(int a,int b){
        this->m_A=a;
        this->m_B=b;
    }
againadd operator+(const againadd& p){//成员函数重载
           againadd temp;
           temp.m_A=this->m_A+p.m_A;
           temp.m_B=this->m_B+p.m_B;
           return temp;
        }
    int m_A;
    int m_B;
};
againadd operator+(againadd &p1,againadd &p2){
    //全局函数重载
    againadd temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}
void testagainadd(){
    againadd p1(10,20);
    
    againadd p2(30,40);
   
    againadd p3=p1+p2;
};
class Box {
private:
    int length;
    int width;
    int height;
public:
    // 构造函数，初始化长、宽、高
    Box(int l, int w, int h) : length(l), width(w), height(h) {}

    // 成员函数，计算体积
    int volume() {
        return length * width * height;
    }
};
class Student{
    public:
    string Name;
    int id;
    void show(){
        cout<<Name<<" "<<id<<endl;
    }
    void setname(string name){
        Name=name;
    }
    void setid(int Id){
        id=Id;
    }
};
class Person{
    public:
    Person(int a,int b):age(a),m_age(b) {}//初始化
    void show(){
        cout<<age<<" "<<m_age<<endl;
    }
    // Person(){
    //     cout<<"Person无参函数"<<endl;
    // }
    // Person(int a){
    //     age=a;
    //     cout<<"Person有参函数"<<endl;
    // }
    // ~Person(){
    //     cout<<"Person析构函数"<<endl;
    // }
    // Person(Person &p){
    //     age=p.age;
    //     cout<<"Person拷贝构造函数"<<endl;
    // }
    int age,m_age;
};
class Time{
    private:
    int hour,min,second;
    public:
    Time(int hour=0,int min=0,int second=0):hour(hour),min(min),second(second){}
    //有参函数，提供参数创建初始化变量
        void show(){
        cout<<setw(2)<<setfill('0')<<hour<<":";
        cout<<setw(2)<<setfill('0')<<min<<":";
        cout<<setw(2)<<setfill('0')<<second;
    }
    void settime(){
        cin>>hour>>min>>second;
    }
};

struct student{
    string name;
    int heigh;
    int programming;
    int totalScore;
};
bool compareStudents( student a, student b) {
    if (a.totalScore != b.totalScore) {
        return a.totalScore > b.totalScore; ////>就是总分降序
    }
    if (a.programming != b.programming) {
        return a.programming > b.programming; // 编程成绩降序
    }
    return false; // 输入顺序不变
}


class animal{
    public:
    int m_Age;
};//虚拟继承
class sheep:virtual public animal{
    public:
    int m_Age;
};
class goat:virtual public animal{
    public:
    int m_Age;
};
class shee:public sheep,public goat{
    public:
    int m_Age;
};
void testage(){
    shee a;
    a.sheep::m_Age=100;
    a.goat::m_Age=200;
    cout<<"a.m_Age="<<a.m_Age<<endl;
}


class base{
    public:
    static int m_A;
};
int base::m_A=100;
class base1{
    public:
    base1(){
        m_A=200;
        m_B=300;
    }
    int m_A;
    int m_B;
};
class Son:public base,public base1{
    public:
    Son(){
        m_C=300;
        m_D=500;
    }
    int m_C;
    int m_D;
    static int m_A;
};
int Son::m_A=200;
void testson(){
    Son a;
    cout<<"Son m_A="<<a.m_A<<endl;
    cout<<"Son m_B="<<a.m_B<<endl;
    //同名加上作用域区分
    cout<<"base m_A="<<a.base::m_A<<endl;
    cout<<"base1 m_A="<<a.base1::m_A<<endl;
}

void testguess(){
    Son a;
    //域名访问
    cout<<"base::m_A="<<base::m_A<<endl;
    cout<<"Son::m_A="<<Son::m_A<<endl;
    //通过对象访问
    cout<<"Son m_A="<<a.m_A<<endl;
    cout<<"base m_A="<<a.base::m_A<<endl;

};


class shape{
    private:
    int x,y;
    public:
    shape(int x,int y):x(x),y(y){}
};
class Rectangle:public shape{
    private :
    int x1,y1;
    public:
    Rectangle(int x,int y,int z,int g):shape(x,y),x1(z),y1(g){}
    int get(){
        return x1*y1;
    }
};
class Circle:public shape{
    private :
    double r;
    public:
    Circle( int x2,int y2,double z):shape(x2,y2),r(z){}
    ~Circle() {//析构函数逆序销毁
        cout << "Circle destructor called" << endl;
    }
    double get1(){
        return r*r*pi;
    }
};
class square:public shape{
    private :
    int l;
    public:
    square(int x3,int y3,int z3):shape(x3,y3),l(z3){}
    int get2(){
        return l*l;
    }
};

class Animal{
    public:
    virtual void print(){//多态
        cout<<"animal"<<endl;
    }
};
class dog:public Animal{
    public://父类纯虚函数子类重写
    void print(){
        cout<<"dog"<<endl;
    }
};
void Dospeak(Animal &a){
    a.print();
}
void testdog(){
    dog d;
    Dospeak(d);
}
class calculator{
    public:
    virtual int getresult(){
        return 0;
    }
    int num1,num2;
};
class add:public calculator{
    public:
    int getresult(){
        return num1+num2;
    }
};
void testadd(){
    calculator *p=new add;
    cin>>p->num1>>p->num2;
    cout<<p->getresult()<<endl;
    delete p;

    add guess;//直接调用
    cin>>guess.num1>>guess.num2;
    cout<<guess.getresult()<<endl;
}

class abstractdrink{
    public:
    virtual void boil()=0;//纯虚函数，不做实现
    virtual void put()=0;
    void make(){
        boil();
        put();
    }
};
class coco:public abstractdrink{
    public:
    virtual void boil(){
        cout<<"水"<<endl;
    }
    virtual void put(){
        cout<<"倒入"<<endl;
    }
};
void makedrink(){
    coco c;
    c.make();
}

class cpu{
    public:
    virtual void calculate()=0;
};
class Intelcpu:public cpu{
    public:
    virtual void calculate(){
        cout<<"intelcpu"<<endl;
    };
};
class card{
    public:
    virtual void display()=0;
};
class Intelcard:public card{
    virtual void display(){
        cout<<"intelcard"<<endl;
    }
};

class computer{
    public:
    computer(cpu *cpu,card *card){
        m_cpu=cpu;
        m_card=card;
    }
    void work(){
        m_cpu->calculate();
        m_card->display();
    }
    ~computer(){
        if(m_cpu!=NULL){
            delete m_cpu;
        }
        if(m_card!=NULL){
            delete m_card;
        }
    }
    private:
    cpu *m_cpu;
    card *m_card;
};
void tesrcomputer(){
    cpu *intelcpu=new Intelcpu;
    card *intelcard=new Intelcard;
    computer *mycomputer=new computer(intelcpu,intelcard);
    mycomputer->work();
    delete mycomputer;
}


class Car;//先进行声明
class Boat {
private:
    int weight;
public:
    Boat(int w) : weight(w) {}
    friend int getTotalWeight( Boat boat, Car car);
    //Boat boat,Car car
};
// 定义 Car 类
class Car {
private:
    int weight;
public:
    Car(int w) : weight(w) {}
    friend int getTotalWeight( Boat boat,  Car car);
};
// 定义友元函数 getTotalWeight
int getTotalWeight( Boat boat,  Car car) {
    return boat.weight + car.weight;
}


class Building;
 class GoodGay{
    public:
    GoodGay();
     void visit();
  private:
  Building *building;
 };
 class GoodGay1{
    public:
    GoodGay1();
     void visit();
  private:
  Building *building;
 };
 class GoodGay2 {//2是个类
public:
    GoodGay2(Building* building);
    void visit();
private:
    Building* building;
};

class Building{
    friend void GoodGay::visit();//成员友元函数访问私有成员
    friend class GoodGay1;//友元函数访问私有成员
    friend void GoodGay2::visit();
    public:
    Building();
    public:
    string m_SittingRoom;
    private:
    string m_BedRoom;
};
Building::Building(){//构造函数
    this-> m_SittingRoom="客厅";
    this-> m_BedRoom="卧室";
};
GoodGay::GoodGay(){//构造函数
    building=new Building;
}
GoodGay1::GoodGay1(){//构造函数
    building=new Building;
}

GoodGay2::GoodGay2(Building* building) { // 构造函数
    this->building = building;
}

void GoodGay::visit(){
    cout<<"好基友0正在访问"<<building->m_SittingRoom<<endl;
    cout<<"好基友0正在访问"<<building->m_BedRoom<<endl;
}
void GoodGay1::visit(){
    cout<<"好基友1正在访问"<<building->m_SittingRoom<<endl;
    cout<<"好基友1正在访问"<<building->m_BedRoom<<endl;
}
void GoodGay2::visit(){
    cout<<"好基友2正在访问"<<building->m_SittingRoom<<endl;
    cout<<"好基友2正在访问"<<building->m_BedRoom<<endl;
}
void test01() {
    GoodGay gg0;
    gg0.visit();
}

void test02() {
    Building b;
    GoodGay2 gg2(&b);
    gg2.visit();
}

void test03() {
    GoodGay1 gg1;
    gg1.visit();
}

int main(){
    int l, w, h;
    cin >> l >> w >> h;
    // 创建Box对象
    Box box(l, w, h);
    // 输出体积
    cout << box.volume() << endl;

     Time guess;
    guess.settime();
    guess.show();

    int rectLength, rectWidth;
    cin >> rectLength >> rectWidth;
    Rectangle rect(0, 0, rectLength, rectWidth);

    Student stu1;
    stu1.setname("zhangsan");
    stu1.setid(1);
    stu1.show();


    int n;
    cin>>n;
    vector<student>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].name>>arr[i].heigh;
    }
    sort(arr.begin(),arr.end(),compareStudents);
    cout<<arr[0].name<<' '<<arr[0].heigh<<endl;
    return 0;
}