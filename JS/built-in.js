//JS에는 다양한 내장 객체 존재한다.
//EX) 수학적인 연산을 저장하고 있는 Math 객체
console.log("Math.PI ",Math.PI);
console.log("Math.random() ", Math.random());
console.log("Math.floor(3,9) ", Math.floor(3.9));

let Mymath = {
    PI : Math.PI,
    // 객체에 소속되어 있는 함수를 method라고 한다.
    random : ()=>{
        return Math.random();
    },
    floor: (val) => {
        return Math.floor(val);
    }
}
console.log(Mymath.random());
console.log(Mymath.floor(4.3));
