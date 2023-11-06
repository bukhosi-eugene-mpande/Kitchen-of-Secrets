const path = require("path");
module.exports = {
    entry: "./src/index.js",
    output: {
        path: path.resolve("public"),
        filename: "bundle.js"
    },
    mode: "development",
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: {
                    loader: "babel-loader"
                }
            }, {
                test: /\.css$/,
                use: ['style-loader', 'css-loader'],
              }
        ]
    }
}