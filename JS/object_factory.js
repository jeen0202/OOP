function Person(name, f,s,t){
    this.name=name,
    this.first=f,
    this.second=s,
    this.third=t,
    this.sum= function(){
        return this.first+this.second+this.third;
    }
}

var kim = new Person('kim',20,10,30);
var lee = new Person('lee',10,10,20); 
console.log(kim.sum())
console.log(lee.sum())

let d1 = new Date('2020-02-06');
console.log('d1.getFullYear() : ',d1.getFullYear());
console.log('d1.getmonth() : ',d1.getMonth());
console.log('Data', Date);

console.log('Person()', Person());
//constructor = 생성자 
console.log('new Person()', new Person());