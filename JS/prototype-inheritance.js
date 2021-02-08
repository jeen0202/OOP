var superObj = {superVal:'super'};
/*prototype link 지정을 통해 상속
var subObj ={subVal:'sub'};
subObj.__proto__ = superObj; //prototype과 __proto__ 의 구분 필요
*/
//Object.create() 메소드를 사용하여 상속
var subObj = Object.create(superObj);
subObj.subVal = 'sub';
// console.log(`subObj.subVal => ${subObj.subVal}`);
// console.log(`subObj.superVal => ${subObj.superVal}`);
subObj.superVal = 'sub';
//link하여 상속받은 부분을 변경하여도 원형은 변하지 않는다.
// console.log(`superObj.superVal => ${superObj.superVal}`);


var kim ={
    name:'kim',
    first : 10, second :20,
    sum:function(){return this.first+this.second;}
}
var lee = Object.create(kim);
lee.name = 'Lee'
lee.first = 10;
lee.second = 10;
lee.avg = function(){
    return (this.first+this.second)/2;    
}
// var lee ={
//     name:'lee',
//     first:10,second:10,
//     avg:function(){
//         return (this.first+this.second)/2;
//     }
// }
// lee.__proto__ =kim;
console.log(`lee.sum => ${lee.sum()}`)
console.log(`lee.avg => ${lee.avg()}`)