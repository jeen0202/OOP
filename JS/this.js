var kim ={
    name : 'kim',
    job : 'developer',
    first : 10,
    second : 20,
    sum(){
        //화살표 함수의 this는 window만을 가르키므로 지양하자
        return this.first+this.second;
    }
    
}
console.log(kim.sum())