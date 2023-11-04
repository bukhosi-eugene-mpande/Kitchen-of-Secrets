const express = require("express");

const app = express();

app.use(express.static("public"));

app.listen(1337, () => {
    console.log("Listening on localhost:1337");
});
