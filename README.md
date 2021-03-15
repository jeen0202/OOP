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
