let modeBtn = document.querySelector("#mode");
let currMode = "light";
let body = document.querySelector("body");

modeBtn.addEventListener("click", () => {
  if (currMode == "light") {
    currMode = "dark";
    // document.querySelector("body").style.background = "black";
    body.classList.add("dark")
    body.classList.remove("light")
  } else {
    currMode = "light";
    // document.querySelector("body").style.background = "white";
    body.classList.add("light");
    body.classList.remove("dark");
  }
  console.log(currMode);
});

// let btn1 = document.querySelector("#btn1");

// let a = 25;
// btn1.onclick = (e) => {
//   console.log(e)
//   console.log(e.target)
//   console.log(e.type)
//   console.log(e.clientX,e.clientY)
// };

// let div = document.querySelector("div")
// div.onmouseover = () => {
//   console.log("you are inside div")
// }

// btn1.addEventListener("click", (evt) => {
//   console.log("Button 1 was clicked - handler 1");
// });

// btn1.addEventListener("click", () => {
//   console.log("Button 1 was clicked - handler 2");
// });

// const handler3 = () => {
//   console.log("Button 1 was clicked - handler 2");
// };
// btn1.addEventListener("click", handler3);
// btn1.addEventListener("click", () => {
//   console.log("Button 1 was clicked - handler 4");
// });

// btn1.removeEventListener("click", handler3);

// let newBtn = document.createElement("button")
// newBtn.innerText = "click me!"
// newBtn.style.color = "white"
// newBtn.style.backgroundColor = "red"

// document.querySelector("body").prepend(newBtn)

// let para = document.querySelector("p")
// para.classList.add("newClass")

// let newHeading = document.createElement("h1");
// newHeading.innerHTML = "<i>Hi, I am new!</i>";

// document.querySelector("body").prepend(newHeading)

// let para = document.querySelector("p")
// para.remove()
// newHeading.remove()

// let newBtn = document.createElement("button")
// newBtn.innerText = "click me!"
// console.log(newBtn)

// let div = document.querySelector("div")
// div.after(newBtn)

// let div = document.querySelector("div");

// div.style.backgroundColor = "purple";
// div.style.fontSize = "20px";
// div.style.visibility = "hidden";

// let div = document.querySelector("div");
// console.log(div)

// let id = div.getAttribute("id")
// console.log(id)

// let name = div.getAttribute("name")
// console.log(name)

// let para = document.querySelector("p")
// console.log(para.getAttribute("class"))

// para.setAttribute("class","newClass")
// console.log(para.getAttribute("class"))

// let n = prompt("Enter a number : ");

// let arr = [];

// for (let i = 1; i <= n; i++) {
//   arr[i - 1] = i;
// }

// console.log(arr);

// let sum = arr.reduce((res, curr) => {
//   return res + curr;
// });

// let fact = arr.reduce((res, curr) => {
//   return res * curr;
// });

// console.log("Sum = ", sum);
// console.log("Factorial = ", fact);

// let marks = [87, 93, 64, 99, 86];

// let toppers = marks.filter((val) => {
//   return val > 90;
// });

// console.log(toppers);

/* let nums = [1, 2, 3, 4];

let newArr = nums.map((val) => {
  return val;
});

let newArr2 = nums.filter((val) => {
  return val > 2;
});

const output = nums.reduce((res, curr) => {
  return res + curr;
});

const output2 = nums.reduce((prev, curr) => {
  //largest value
  return prev > curr ? prev : curr;
});

console.log(output2); */

// let calcSquare = (num) => {
//   console.log(num * num);
// }

// nums.forEach(calcSquare);

// let arr = ["delhi","mumbai","bangalore"];

// arr.forEach((val, idx, arr) => { //Higher Order function
//   //value at each index
//   console.log(val.toUpperCase(), idx, arr);
// });

/*function countCapitals(str){
  let count = 0;
  for(const char of str){
    if(char>="A"&& char<="Z"){
      count++
    }
  }
  return count;
}

function countVowels(str){
  let count = 0;
  for(const char of str){
    if(char=='a'||char=='e'||char=='i'||char=='o'||char=='u'){
      count++
    }
  }
  return count;
}

console.log(countVowels("Shubham")); */

// const arrowSum = (a,b)=>{
//   console.log(a+b);
// };

// arrowSum(20,29);

// let arrowMul = (a,b)=>{
//   return a*b;
// };

// let student = {
//   name: "Shubham Das",
//   age: 20,
//   cgpa: 8.9,
//   isPass: true
// };

// //Template Literals
// let output = `the name is ${student["name"]} and age is ${student["age"]}`;

// output.toUpperCase();

//Strings are immutable in Javascript

// console.log(output);

// for(let i in student){
//   console.log("Key = ",i," value = ",student[i]);
// }

// const student = {
//   fullName: "Shubham",
//   age: 20,
//   cgpa: 9,
//   sem: 5,
// };

// student["age"]++;
// // student["age"] = student["age"] + 1;
// console.log(student.age);

// let variable = prompt("Say your name");
// console.log(variable);
