// const math = require("./math");

// console.log(math);
// console.log("Math add value is : ", math.add(2, 5));
// console.log("Math sub value is : ", math.sub(2, 5));

const { add, sub } = require("./math");  //Destructuring

console.log("Math add value is : ", add(2, 5));
console.log("Math sub value is : ", sub(2, 5));
