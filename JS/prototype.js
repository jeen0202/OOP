/*prototype
재사용성을 높힐 수 있다.
*/ 

function Person(name, f,s,t){
    this.name=name,
    this.first=f,
    this.second=s,
    this.third=t

}
//prototype을 사용하면 멤버함수와는 다르게 객체 생성시마다 메모리를 할당받지 않게된다.
//prototype으로 선언된 함수를 같은 메소드끼리 공유한다.
//prototype으로 선언된 함수를 이후 각 객체에서 새로 생성할 경우는 대체된다.
Person.prototype.sum= function(){
    return 'prototype : ' +(this.first+this.second+this.third);
}
var kim = new Person('kim',20,10,30);
kim.sum= function(){
    return 'this : ' +(this.first+this.second+this.third);
}
var lee = new Person('lee',10,10,20); 
console.log(kim.sum())
console.log(lee.sum())