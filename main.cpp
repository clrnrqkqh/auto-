#include <iostream>
#include<vector>
#include<string>

using namespace std;

 //일반(단순)가상함수, 순수가상함수에 대한 기본적인 개념
 //출처: https://blockdmask.tistory.com/277 [개발자 지망생]
class Car
{
public:
    virtual void Drive()
    {
        //앞으로 간다.
        cout << "Drive()" << endl;
        return;
    }
    virtual void Stop()
    {
        //멈춘다
        cout << "Stop()" << endl;
        return;
    }
    virtual void Back()
    {
        //후진한다.
        cout << "Back()" << endl;
    }
 
    //자동차는 문이 열리고 닫혀야한다.
    //근데 문이 위로 열리는지 옆으로 열리는지 모르니까
    //상속받아서 해당 클래스에 맞게 선언, 구현해라.
    //근데, 이 기능이 없으면 자동차가 아니다.
    virtual void OpenDoor() = 0;    
    virtual void CloseDoor() = 0;
};

class SuperCar : public Car
{
public:
    virtual void OpenDoor() override
    {
        //위로 열린다.
        cout << "super - open()" << endl;
        return;
    }
    virtual void CloseDoor() override
    {
        //아래로 닫힌다.
        cout << "super - close()" << endl;
        return;
    }
};

class NormalCar : public Car
{
public:
    virtual void OpenDoor() override
    {
        //옆으로 열린다.
        cout << "normal - open()" << endl;
        return;
    }
    virtual void CloseDoor() override
    {
        //옆으로 닫힌다.
        cout << "normal - close()" << endl;
        return;
    }
};

/*auto는 부르는 사람에 따라서 조금씩 다르게 불리는데요.

이런식으로 불리곤 합니다.  "타입 추론", "데이터 타입 추론", "자동 데이터 추론", "초기화 값에 따라 알아서 데이터 타입을 정해주는 키워드"

auto 키워드는 선언한 변수나 람다식의 타입을 컴파일러에게 추론하도록 맡깁니다.
출처: https://blockdmask.tistory.com/384?category=249379 [개발자 지망생]
*/

int main() {
  // 시작
  std::cout << "Hello World!\n";
  //일반(단순)가상함수, 순수가상함수에 대한 기본적인 개념
  //출처: https://blockdmask.tistory.com/277 [개발자 지망생]

   cout << "1> 슈퍼카 클래스의 Drive와 OpenDoor" << endl;
    SuperCar* pSuper = new SuperCar;
    pSuper->Drive();
    pSuper->OpenDoor();
 
    cout << "2> 일반카 클래스의 Drive와 OpenDoor" << endl;
    NormalCar* pNormal = new NormalCar;
    pNormal->Drive();
    pNormal->OpenDoor();
 
    cout << "3> Car 부모 클래스의 포인터로 자식들의 객체를 가리킨다." << endl;
    Car* pCar = nullptr;
 
    pCar = dynamic_cast<Car*>(pSuper);
    pCar->Drive();
    pCar->OpenDoor();
    pCar = dynamic_cast<Car*>(pNormal);
    pCar->Drive();
    pCar->OpenDoor();
 
    pCar = nullptr;
    delete pSuper;
    delete pNormal;
    return 0;



}