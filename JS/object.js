let memberArr=['sejing','Fredy','suhyun']
console.log(memberArr[1]);

let memberObject ={
    manager : 'sejing',
    developer : 'suhyun',
    designer : 'Fredy'
}
memberObject.designer = '05';
console.log("manager : ",memberObject.manager);
console.log("developer : ",memberObject['developer']);
console.log('designer : ', memberObject.designer);

delete memberObject.manager
console.log('after delete : ', memberObject.manager);