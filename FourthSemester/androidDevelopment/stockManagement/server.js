'use strict';

const express = require('express'); // Constants
const PORT = 3000;
const app = express();

app.use(express.static('public'));
//make way for some custom css, js and images
app.use('/css', express.static(__dirname + '/public/bootstrap'));
app.use('/js', express.static(__dirname + '/public/js'));
app.use('/images', express.static(__dirname + '/public/img'));

let server = app.listen(PORT);
console.log('Server started at http://localhost:' + PORT);
