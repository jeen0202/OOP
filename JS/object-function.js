var kim = {name:'kim', first:10, second:20}
var lee = {name:'lee', first:10, second:10}
function sum(prefix){
    return prefix+(this.first+this.second);
}
//call
sum.call(kim); // call을 통해서 this를 지정(context를 변경)해 줄 수 있다.
console.log(`sum.call(kim)  ${sum.call(kim,'=> ')}`) //apply도 비슷하게 사용가능
console.log(`sum.call(lee)  ${sum.call(lee,' : ')}`)
//bind로 method에 지정되어있는 context를 고정할 수 있다.
var kimSum = sum.bind(kim,'-> ');
console.log(`kimSum() ${kimSum()}`);