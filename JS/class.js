class Person{
    constructor(name, f, s, t){
        console.log('constructor');
        this.name = name;
        this.first=f,
        this.second=s,
        this.third=t
    }
    //prototype과 같은 역할을 해준다.
    sum(){
        return 'prototype : ' +(this.first+this.second+this.third);
    }
}
//JavaScript의 class는 method의 연장선

var kim = new Person('kim',10,20,30);
var lee = new Person('lee',10,10,20); 
kim.sum = function(){
    return 'this : '+(this.first+this.second+this.third);
}
console.log(kim.sum())
console.log(lee.sum())