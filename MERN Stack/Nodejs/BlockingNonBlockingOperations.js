const fs = require("fs");
const os = require("os");

console.log(os.cpus().length);

console.log("1");
// //Blocking
const result = fs.readFileSync("./contacts.txt", "utf-8");
console.log(result)

//Non-Blocking
// const result = fs.readFile("./contacts.txt", "utf-8", (err, result) => {
//   console.log(result);
// });


console.log("2");
console.log("3");
console.log("4");
console.log("5");
