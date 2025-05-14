const express = require("express");
const fs = require("fs");
const mongoose = require("mongoose");

const { type } = require("os");
const { timeStamp } = require("console");

const app = express();
const PORT = 8000;

// Connection
mongoose
  .connect("mongodb://127.0.0.1:27017/shubham-app-1")
  .then(() => console.log("MongoDB connected"))
  .catch((err) => console.log("Mongo Error", err));

//Schema
const userSchema = new mongoose.Schema(
  {
    first_name: {
      type: String,
      required: true,
    },
    last_name: {
      type: String,
      required: false,
    },
    email: {
      type: String,
      required: true,
      unique: true,
    },
    job_title: {
      type: String,
    },
    gender: {
      type: String,
    },
  },
  { timestamps: true }
);

// Model
const User = mongoose.model("user", userSchema);

//Middleware - Plugin
app.use(express.urlencoded({ extended: false }));

// app.use((req, res, next) => {
//   console.log("Hello from middleware 1");
//   // req.myUserName = "shubhamdas.dev";
//   next();
// });

// app.use((req, res, next) => {
//   fs.appendFile(
//     "log.txt",
//     `\n${Date.now()}:${req.ip} ${req.method}: ${req.path}`,
//     (err, data) => {
//       next();
//     }
//   );
// });

//Routes
app.get("/api/users", async (req, res) => {
  const allDbUsers = await User.find({});

  // res.setHeader("X-MyName", "Shubham Das"); //Custom header
  // //Always add X to custom header
  // console.log(req.headers);

  return res.json(allDbUsers);
});

app
  .route("/api/users/:id")
  .get(async (req, res) => {
    const user = await User.findById(req.params.id);
    if (!user) return res.status(404).json({ error: "user not found" });
    return res.json(user);
  })
  .patch(async (req, res) => {
    await User.findByIdAndUpdate(req.params.id, { last_name: "Changed" });
    return res.json({ status: "Success" });

    // const id = Number(req.params.id);
    // const updates = req.query;
    // // console.log(updates);
    // const newUsers = users.map((user) => {
    //   if (user.id === id) {
    //     return { ...user, ...updates };
    //   } else {
    //     return user;
    //   }
    // });
    // fs.writeFile("./MOCK_DATA.json", JSON.stringify(newUsers), (err, data) => {
    //   return res.json({ status: "successfully edited user", id });
    // });
  })
  .delete(async (req, res) => {
    await User.findByIdAndDelete(req.params.id);
    return res.json({ status: "Success" });

    // const id = Number(req.params.id);
    // const userIndex = users.findIndex((user) => {
    //   user.id == id;
    // });
    // users.splice(userIndex, 1);
    // const newArr = users.filter((item) => item.id != id);
    // fs.writeFile("./MOCK_DATA.json", JSON.stringify(newArr), (err, data) => {
    //   return res.send({ status: "Successfully removed id : ", id });
    // });
  });

app.get("/users", async (req, res) => {
  const allDbUsers = await User.find({});
  const html = `
    <ul>
        ${allDbUsers
          .map((user) => `<li>${user.first_name} - ${user.email}</li>`)
          .join(" ")}
    </ul>
    `;
  res.send(html);
});

app.post("/api/users", async (req, res) => {
  const body = req.body;
  if (
    !body ||
    !body.first_name ||
    !body.last_name ||
    !body.email ||
    !body.gender ||
    !body.job_title
  ) {
    // 400 - bad request
    return res.status(400).json({ msg: "All fields are required." });
  }

  const result = await User.create({
    first_name: body.first_name,
    last_name: body.last_name,
    email: body.email,
    gender: body.gender,
    job_title: body.job_title,
  });

  return res.status(201).json({ msg: "Success" });
});

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
