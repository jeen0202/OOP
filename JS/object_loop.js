//JS 에서 Object는 Key(name) : value로 구분된다.
memberObject = {
    manager : 'sejing',
    developer : 'suhyun',
    designer : 'jieun',
    publisher : '05'
}
//object의 key과 loop를 사용하면 object를 간단하게 출력할 수 있다.
console.group('object loop');
for (let key in memberObject){
    console.log(key, memberObject[key]);
}
console.groupEnd('object loop');