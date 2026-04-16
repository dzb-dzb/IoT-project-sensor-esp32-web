const express = require("express");
const cors = require("cors");
const app = express();

app.use(cors());
app.use(express.json());

let data = {
  temperature: 0,
  humidity: 0,
  time: "--:--:--",
};
let history = [];

app.get("/data", (req, res) => {
  res.send(data);
});

app.get("/history", (req, res) => {
  res.send(history);
});

app.post("/update", (req, res) => {
  data = req.body;
  history.push(data);

  if (history.length > 4) {
    history.shift();
  }

  console.log(history);
});

app.listen(3000, () => {
  console.log("server run on port 3000");
});
