// server.js
const express = require('express');
const cors = require('cors');
const mysql = require('mysql2');

const app = express();
const PORT = 3001;

// --- Middleware ---
// 1. CORS: Allows your frontend (e.g., localhost:5173) to talk to the backend.
app.use(cors());
// 2. Body Parser: Allows Express to read JSON data sent from the frontend.
app.use(express.json());
// ------------------

// --- Database Configuration (UPDATE THESE!) ---
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'akshat',
    database: 'react_app_db'
});

db.connect(err => {
    if (err) {
        console.error('Error connecting to MySQL:', err.message);
        return;
    }
    console.log('Successfully connected to MySQL Database.');
});
// ----------------------------------------------

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});