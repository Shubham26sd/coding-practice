require("dotenv").config();

const express = require("express");
const path = require("path");
const mongoose = require("mongoose");
const cookieParser = require("cookie-parser");

const Blog = require("./models/blog");

const app = express();
const PORT = process.env.PORT || 8000;

//"mongodb://127.0.0.1:27017/blogify"
mongoose
  .connect(process.env.MONGO_URL)
  .then((e) => console.log("MongoDB connected"));

const userRouter = require("./routes/user");
const blogRouter = require("./routes/blog");

const {
  checkForAuthenticationCookie,
} = require("./middlewares/authentication");

app.set("view engine", "ejs");
app.set("views", path.resolve("./views"));

app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(checkForAuthenticationCookie("token"));
app.use(express.static(path.resolve("./public")));

app.get("/", async (req, res) => {
  const allBlogs = await Blog.find({});
  res.render("home", {
    user: req.user,
    blogs: allBlogs,
  });
});

app.use("/user", userRouter);
app.use("/blog", blogRouter);

app.listen(PORT, () => {
  console.log(`Server started at port ${PORT}`);
});
