function getData(data) {
  return new Promise((resovle, reject) => {
    setTimeout(() => {
      console.log("Data : ", data);
      resovle("success");
    }, 3000);
  });
}

async function getAllData(){
  await getData(1);
  await getData(2);
  await getData(3);
}













// async function api() {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       console.log("Weather data");
//       resolve(200);
//     }, 2000);
//   });
// }

// async function getWeatherData(){
//   await api(); //1st
//   await api(); //2nd
// }

// function getData(data) {
//   return new Promise((resovle, reject) => {
//     setTimeout(() => {
//       console.log("Data : ", data);
//       resovle("success");
//     }, 3000);
//   });
// }

//Promise chain
// getData(1)
//   .then((res) => {
//     return getData(2);
//   })
//   .then((res) => {
//     return getData(3);
//   })
//   .then((res) => {
//     console.log(res);
//   });

// function asyncFunc1() {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       console.log("some data1");
//       resolve("success");
//     }, 4000);
//   });
// }
// function asyncFunc2() {
//   return new Promise((resolve, reject) => {
//     setTimeout(() => {
//       console.log("some data2");
//       resolve("success");
//     }, 4000);
//   });
// }
// //Promise chaining

// console.log("fetching data1....");
// asyncFunc1().then((res) => {
//   console.log(res);
//   console.log("fetching data2....");
//   asyncFunc2().then((res) => {});
// });

// const getPromise = () => {
//   return new Promise((resolve, reject) => {
//     console.log("I am a promise");
//     resolve("success");
//     // reject("network error");
//   });
// };

// let promise = getPromise();

// promise.then((res) => {
//   console.log("promise fulfilled : ", res);
// });
// promise.catch((err) => {
//   console.log("promise rejected : ", err);
// });

// let promise = new Promise((resovle, reject) => {
//   console.log("I am a promise.");
//   resovle("success");
//   // reject("some error occured")
// });

// function getData(data, getNextData) {
//   return new Promise((resovle, reject) => {
//     setTimeout(() => {
//       // console.log("Data : ", data);
//       // resovle("success");
//       reject("error occured")
//       if (getNextData) {
//         getNextData();
//       }
//     }, 5000);
//   });
// }

// function hellO() {
//   console.log("Hello");
// }

// setTimeout(hellO,2000);

// setTimeout(()=>{
//     console.log("hello 2 after 4s")
// },4000)

// function getData(data, getNextData) {
//   setTimeout(() => {
//     console.log("Data : ", data);
//     if (getNextData) {
//       getNextData();
//     }
//   }, 2000);
// }

// //Callback Hell
// getData(1, () => {
//   getData(2, () => {
//     getData(3);
//   });
// });
