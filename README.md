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



## initialize our inventories

캐릭터에 인벤토리컴포넌트 선언 후 정의



## update the ui

델리게이트가 가능하도록 인벤토리컴포넌트에 정의

UI에 인벤토리가 업데이트된 걸 전파하기 위하여



## define my inventory component

2개의 함수와 4개의 변수 정의

아이템 추가, 제거 함수

기본아이템들, 용량, 델리게이트, 인벤토리현재아이템들 변수

틱컴포넌트는 인벤토리 컴포넌트 필요없어 제거



## create an implementation of the add item

생성자 기본 용량 20

## look over all of the default items

비긴플레이시 디폴트아이템들을 추가하는 코드 구현

아이템 추가함수 조건과 소유 인벤토리와 월드에 알려주고

델리게이트 함

## add one more variable

아이템 헤더파일에 월드 변수 추가하고

월드 변수 관련 함수 추가

아이템 제거 함수도 거의 정반대로 구현

부울로 아이템이 성공적으로 추가, 제거 되었는지 확인 가능

## click on the local windows debugger

## start off by making a food item

블루프린트로 파생이 되지 않는 문제 발생

해결: 클래스 지정자에 Blueprintable을 추가하지 않아 블루프린트 생성이 가능한 베이스 클래스로 노출이 되지 않았음. 



에디터에서 FoodItem, Item 클래스에서 파생된 블루프린트
빵, 헬멧, 조끼 생성
클래스 디테일에 Action Text, 썸네일, 이름, 설명 설정.
이미 만들어 놓은 WBP_InventoryItem 위젯 블루프린트에서

변수 Item 레퍼런스를 갖는 Item 추가. 인스턴스 편집가능, 스폰 시 노출



## set the thumbnail

에디터에서 WBP_InventoryItem 연다.
Item 클래스 타입의 변수 Item 추가
블루프린트 변수 Thumbnail과 ItemName을
Item 클래스 타입의 멤버 변수를 이용하여 
세팅하는 것을 Construct 이벤트에 추가

Use버튼 클리시 이벤트에
소유중인 플레이어 폰을 받아와
삼인칭캐릭터로 형변환 후 그 클래스에 정의된
UseItem을 호출하여 로컬 변수 Item 사용하게 노드 배치



## add the thumbnail

WBP_InventoryItem 에디터에서
디자이너->계층구조->Use Button->디테일->비헤이비어->Tool Tip Text->바인드->바인딩 생성
함수 이름 GetTooltip으로 변경. 포멧텍스트 생성. 
각포맷에 맞는 로컬 Item클래스의 UseAction, Item Display Name, Item Description 연결

## refresh the inventory

WBP_Inventory 에디터에서
Initialize Inventory 커스텀 이벤트 추가, 컨스트럭트 이벤트 추가, Refresh Inventory 커스텀 이벤트 추가
컨스트럭트에 소유중인 플레이어 폰을 삼인칭 캐릭터로 형변환하는 노드 추가
삼인칭 캐릭터의 Inventory Component를 얻고 이것을 변수로 승격시켜 블루프린트 변수로 저장
Inventory에서 On Inventory Updated 이벤트 바인딩 노드 배치

바인딩을 Refresh Inventory에 해줌. 다음 실행핀에는 Initialize Inventory 커스텀 이벤트를 호출.
Initialize Inventory에서 입력->새 입력 아규먼트를 생성하고 타입을 InventotyComponent 레퍼런스로하고 이름은 Inventory 함.
Refresh Inventory 다음 실행에 Initialize Inventory 호출하고 로컬 Inventory 컴포넌트 변수 할당

## refreshing the inventory

InventoryBox 변수는 디자이너->계층구조에 배치 되어있는 WrapBox이다. 변수여부 체크되어있다.
이 변수의 ClearChildren 노드를 Initialize Inventory 실행핀 다음에 배치
인벤토리 컴포넌트에서 Items들의 배열을 꺼내  ForEachLoop로 그 배열 수 만큼 InventoryItem 위젯을 생성

## add it to the inventory box

위젯 생성 다음 노드에 Add Child to Wrap Box 노드를 생성하여
타깃은 Inventory Box로 Content는 생성한 위젯의 Return Value를 링크
Close버튼의 클릭시 이벤트를 형성하여 부모를 없애고 마우스 커서를 안보이고
입력모드를 게임으로 바꾸는 노드를 생성하여 링크

## show the mouse cursor

리디렉터가 잘못됬는지 C++ 클래스가 틱이벤트 동작하지가 않아
C++ 인벤토리캐릭터 시스템을 부모로 같는 블루프린트를 새로 만들고 설정을 똑같이 해줌

삼인칭 캐릭터 블루프린트로 이동
탭키 누를 시 인벤토리 위젯이 형성하여 뷰포트에 뜨게 하고 마우스 커서를 보이기
UI 입력모드로 전환, 틱 이벤트에 현재 체력을 뜨게 함

UI 제대로 동작하지 않는 문제 발생:
인벤토리 위젯에서 컨스트럭트 이벤트 끝에 
이니셜라이즈 인벤토리에 인벤토리 컴포넌트 인자를 전달하지않아 생긴 문제
해결: 인벤토리 컴포넌트 인자를 제대로 연결



## plug the inventory into the inventory

아이템 헤더 파일 
함수 USE 뒤에  순수 가상함수 나타내는 PURE_VIRTUAL(UItem, ) 제거
item.cpp 에서 use 정의하는 구현코드 추가
테스트하기 위해 빵 힐량 20으로 늘림

## add a couple of skeletal meshes

캐릭터 블루프린트에서 몇개의 스켈레탈 메시를 추가
헬멧과 조끼 스켈레탈 메시 추가하고 메시가 부모가 되게 하고
위치나 회전은 전부 0으로 해줌.

컨스트럭션 스크립트로 이동해
Set Leader Pose Component(4때는 Master) 노드 생성
타깃에 조끼와 헬멧으로 
New Leader Bone Component는 메시로 지정

BP_Clothing_Helmet 블루프린트로 이동하여
함수에서 OnUse를 오버라이드하여 이벤트 생성
캐릭터 핀을 당겨 삼인칭 캐릭터로 형변환 
플립플랍을 이용해 A에는 헬멧 스켈레탈메시에셋을 스켈레탈메시컴포넌트에 셋 
B에는 None 스켈레탈메시에셋을 스켈레탈메시컴포넌트에 셋 

퓨어 버추얼 Use 함수를 안지우고 정의도 안해서 문제 생김
순수가상함수 선언을 지우고 정의를 해서 문제 해결

## drag this mesh onto the mesh

조끼도 헬멧처럼 똑같이 진행
먹으면 빵이 사라지게 하기 위해
푸드아이템 소스코드 use 함수 정의 부분에서
인벤토리에 소유중이면 
현재 소유중인 인벤토리에서 먹은 아이템 제거함수 호출.

## attach a little bit of blueprint logic to any item

추가로 헬멧 블루프린트에서 뒤 실행핀에 폭발 이미터 세팅하는 기능 추가