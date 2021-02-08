function Person(name,first,second){
    this.name = name;
    this.first = first;
    this.second = second;
}
Person.prototype.sum = function(){
    return this.first+this.second;
}
//class에서의 super()와 같은 역할을 call()이 한다.
function PersonPlus(name,first,second,third){    
    Person.call(this,name,first,second)
    this.third = third;

}
//자식 method의 proto link를 부모 method의 prototype에 연결한다.
//PersonPlus.prototype.__proto__ = Person.prototype;
//함수와 함수의 prototype은 상호 참조 관계이므로 prototype의 생성자는 함수를 가르키게 된다.
//아래처럼 동작하면 자식 함수의 prototype이 부모 함수의 prototype을 가르키게 된다.
PersonPlus.prototype = Object.create(Person.prototype);
PersonPlus.prototype.constructor = PersonPlus;
//순서를 변경하면 prototype이 덮어지면서 지워질 수 있다.
PersonPlus.prototype.avg = function(){
    return (this.first+this.second+this.third)/3;
}

var kim = new PersonPlus('kim',10,20,30);
console.log(`kim.sum() ${kim.sum()}`)
console.log(`kim.avg() ${kim.avg()}`)
console.log(`kim.constructor ${kim.constructor}`)