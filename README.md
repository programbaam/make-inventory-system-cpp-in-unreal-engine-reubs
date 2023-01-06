# How to make an Inventory System with C++ in Unreal Engine



[![How to make an Inventory System with C++ in Unreal Engine](https://img.youtube.com/vi/-WNwo-riV1Y/0.jpg)](https://youtu.be/-WNwo-riV1Y)

출처 : reubs | How to make an Inventory System with C++ in Unreal Engine



라이더와 언리얼엔진 5.1.0 으로 진행

## download the inventory system template project in the description

유튜브 영상 더보기에 나와있는 주소를 이용하여 인벤토리 시스템 템플릿 다운



## generate visual studio project files

uproject 파일 버젼을 바꾸어 준다. 비주얼 스튜디오 프로젝트 파일 생성

솔루션 열어 빌드를 해준다.



## toggle between equipping the vest off

## add an actor component

ActorComponent를 부모로 갖는 c++ 클래스 생성 



## put this in our items folder

아이템 클래스는 Object 클래스로 생성. 데이터 클래스



아이템 클래스에 클래스 지정자 추가

```c++
UCLASS(Abstract, BlueprintType, EditInlineNew, DefaultToInstanced)
```

클래스 지정자

Abstract 추상 지정자. 

BlueprintType 클래스를 블루프린트에서 변수로 사용할 수 있는 유형으로 노출

EditInlineNew 이 클래스의 오브젝트는 기존 애셋에서 참조되는 것과 반대로, 언리얼 에디터 프로퍼티 창에서 생성할 수 있음을 나타냅니다. 기본 작동방식은, 기존 오브젝트로의 레퍼런스만 프로퍼티 창을 통해 할당할 수 있습니다. 이 지정자는 모든 자식 클래스에 전파되며, 자식 클래스에서는 NotEditInlineNew 지정자로 덮어쓸 수 있습니다.

DefaultToInstanced 이 클래스의 모든 인스턴스는 "Instanced"로 간주. 인스턴스드 클래스는 생성 시 복제됨. 이 지정자는 서브클래스에 상속 됨.

<https://docs.unrealengine.com/4.27/ko/ProgrammingAndScripting/GameplayArchitecture/Classes/Specifiers/>



아이템 헤더파일에 동작글, 이름, 메시, 썸네일, 설명, 무게, 인벤토리컴포넌트 선언

```c++
virtual void Use(class AInventorySystemCharacter* Character) PURE_VIRTUAL(UItem, );
```

도 선언

추상 클래스 이기에 추상 함수를 만든것이라고 생각한다.

추상클래스에서 use를 호출하는 것이 아닌? 자식 클래스에서 사용하기 위해서? 그래서 순수한 가상을 갖는다.



여기까지 한것을 빌드하면 에러 발생

![unreal-engine-rider-uitem-constructor-build-fail](https://user-images.githubusercontent.com/96612703/210723828-1c791286-4929-4e66-b942-09c656ec1d2b.png)

생성자 정의를 안해서 생긴 문제

cpp에서 UItem::UItem 정의



## using a blueprint implement event

블루프린트에서 사용할 수 있는 함수 선언
Item 파생 c++ 클래스 푸드아이템 생성
Use함수 오버라이드
인벤토리스시스템캐릭터에 체력 추가
체력회복 변수 선언, 사용 함수 정의
아이템 생성자의 기본값 정의

## create an implementation

인벤토리시스템캐릭터.h, cpp 에 아이템 사용 함수를 선언, 정의

## include the heater file

Item.h 파일 추가

