Study for Object Oriented Programming

# C++

### 복사 생성자
Class의 복사가 이루어질때 호출되는 생성자
스스로의 Class type 참조변수를 parameter로 가지며, overloading 될 수 없다.
객체의 복사시에 호출되어 동적할당된 메모리를 공유하지 않고 복제하는 Deep copy를 가능하게 해준다.

### friend Keyword
Class에서의 접근제한에 관여하는 Keyword Clas내부 어느곳에서나 선언 가능
Class, Function에 friend 속성을 부여해준다.
friend Class는 friend로 선정해준 class의 private 변수나 함수에 접근 가능
friend function은 외부 Class의 function을 본인의 function처럼 사용할 수 있게 해준다.

### Class에서의 Static Keyword
Class에서 static Keyword가 사용되어 static member 변수와 static member 함수로 사용 될 수 있다.
static member 변수는 같은 Class 끼리 공유하는 전역변수와 같이 사용되며 프로그램 실행시 최초 1번만 선언된다.
static member 변수의 초기화는 Class 외부에서 수행되어야 한다.
데이터 은닉의 법칙을 위배하는 Global 변수보다 Class 내부의 static member 변수의 사용이 권장된다.
static member 함수는 private으로 선언된 static member 변수에 접근하기 위해 사용되는 함수이다.
스스로를 호출하는 this->를 사용할 수 없는 함수이며 객체에 소속되어 있지 않고 Class 자체에 속해있다.
'ObjectName.FuncName()'의 형태가 아닌 'ClassName.FuncName()'의 형태로 사용해야 한다.