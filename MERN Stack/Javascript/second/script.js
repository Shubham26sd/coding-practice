// const student = {
//   fullName: "Shubham Das",
//   marks: 94.6,
//   printMarks: function () {
//     console.log("Marks : ", this.marks);
//   },
// };

// const employee = {
//   calcTax() {
//     console.log("tax rate is 10%");
//   },
// };

// const karanArjun = {
//   salary: 50000,
//   calcTax() {
//     console.log("tax rate is 0%");
//   },
// };

// karanArjun.__proto__ = employee;

class ToyotaCar{
    constructor(){
        console.log("creating new object");
    }

    start(){
        console.log("start");
    }
    stop(){
        console.log("stop");
    }
}

let fortuner = new ToyotaCar();