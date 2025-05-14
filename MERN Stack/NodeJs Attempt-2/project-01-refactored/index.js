const express = require("express");
const fs = require("fs");

const userRouter = require("./routes/user.js");
const { logReqRes } = require("./middlewares");

const { connectMongoDb } = require("./connection.js");
const users = require("./MOCK_DATA.json");
const router = require("./routes/user.js");
const { connect } = require("http2");

const app = express();
const PORT = 8000;

//Connection
connectMongoDb("mongodb://127.0.0.1:27017/youtube-app-1");

//Middlewares - Plugin

app.use(express.urlencoded({ extended: false }));

app.use(logReqRes("log.txt"));

//Routes
app.use("/users", userRouter);

app.listen(PORT, () => console.log("Server Started!"));

// app.get("/api/users/:id", (req, res) => {
//   const id = Number(req.params.id);
//   const user = users.find((user) => user.id === id);
//   return res.json(user);
// });

// app.patch("/api/users/:id", (req, res) => {
//   // TODO:Edit the user id
//   return res.json({ status: "pending" });
// });

// app.delete("/api/users/:id", (req, res) => {
//   // TODO:Edit the user id
//   return res.json({ status: "pending" });
// });
