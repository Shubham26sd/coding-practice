const express = require("express");
const { connectMongoDb } = require("./connection");

const { logReqRes } = require("./middlewares");
const userRouter = require("./routes/user");

const app = express();
const PORT = 8000;

// Connection
connectMongoDb("mongodb://127.0.0.1:27017/shubham-app-1").then(() =>
  console.log("Mongodb connected!")
);

//Middleware - Plugin
app.use(express.urlencoded({ extended: false }));

app.use(logReqRes("log.txt"));

// Routes
app.use("/api/users", userRouter);

app.listen(PORT, () => {
  console.log(`Server Started! at PORT:${PORT}`);
});

// app.patch("/api/users/:id", (req,res)=>{
//     //To do: Edit the user with id
//     return res.json({status: "pending"});
// })

// app.delete("/api/users/:id", (req,res)=>{
//     //To do: Delete the user with id
//     return res.json({status: "pending"});
// })
