const fs = require("fs");

// // Synchronous...Blocking operation
// fs.writeFileSync("./test.txt ", "Hey There");

// // Async.. Non-Blocking
// fs.writeFile("./test.txt ", "Hello World Async", (err) => {});



// const result = fs.readFileSync("./contacts.txt", "utf-8");
// console.log(result);

// fs.readFile("./contacts.txt", "utf-8", (err, result) => {
//   if (err) {
//     console.log("Error", err);
//   } else {
//     console.log(result);
//   }
// });

// fs.appendFileSync("./test.txt ", `${Date.now()} Hey There\n`);

// fs.cpSync("./test.txt ", "./copy.txt");

// fs.unlinkSync("./copy.txt");
// console.log(fs.statSync("./test.txt"));
// fs.mkdirSync("./my-docs/a/b", { recursive: true });

const os = require("os")
console.log(os.cpus().length);