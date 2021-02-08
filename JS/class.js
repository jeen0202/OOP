class Person{
    constructor(name, f, s){
        console.log('constructor');
        this.name = name;
        this.first=f,
        this.second=s        
    }
    //prototype과 같은 역할을 해준다.
    sum(){
        return (this.first+this.second);
    }
    
}
//extends 키워드를 통해 다른 Class를 상속받아 사용할 수 있다.
class PersonPlus extends Person{
    constructor(name,f,s,t){
        super(name,f,s);
        this.third=t;
        console.log(this)
    }
    sum(){        
        return super.sum()+this.third;
    }
    avg(){
        return (this.sum())/3;
    }
}
let go = new PersonPlus('go',15,15,15);
console.log('go.sum() : ',go.sum());
console.log('go.avg() : ',go.avg());