/*
  KODE PROGRAM INI UNTUK MEMBUAT SERVER API DENGAN MUDAH/CEPAT MENGGUNAKAN NODEJS
  1. Install Nodejs di windows,
  2. Buat database dengan schema di file samping
  3. Pada folder yang sama dengan file ini, menggunakan command line di Visual Code ketik
     npm init -y
     npm install express
     npm install mysql2
  4. Untuk menjalankan server pada file ini, menggunakan command line di Visual Code ketik
     node server.js
  5. Untuk mengecek SERVER berjalan ketik di browser localhost:8080/   (localhost diganti IP komputer)
  6. Untuk mengecek API-save dan load berjalan ketik di browser  
*/

const express = require('express');
const app = express();
const port = 8080;

// Middleware untuk parsing JSON
app.use(express.json());

// Endpoint GET
app.get('/', (req, res) => {
  res.send('API siap digunakan');
});



// API Endpoint untuk simpan data dari ARDUINO
app.get('/api/save/:temp/:humid', async (req, res) => {
  const temp = req.params.temp;
  const humid = req.params.humid;

  const ssql = "INSERT INTO tbldata (temp, humid) VALUES (?, ?)";
  const dt = [temp, humid];
  await runQuery(ssql, dt); //save kedalam database
  res.json({ success: true, data: {temp,humid} });  //report berhasil
});

// API Endpoint untuk membaca data dari database, dipanggil oleh MOBILE/ANDROID
app.get('/api/read', async (req, res) => {   //berjalan asyncron
    const ssql = "SELECT temp, humid FROM tbldata ORDER BY id DESC LIMIT 1"; //mengirimkan 1 data terakhir
    const dt = [];
    hasil = await runQuery(ssql, dt); //save kedalam database (await menunggu promise data didapatkan)

    //kembalikan temp dan humid ke json
    if (hasil.length > 0) { //jika ada datanya maka return hasil
        res.json({ success: true, data: hasil[0] });
      } else {  //jika tidak ada data not found
        res.json({ success: false, message: 'No data found' });
    }

  });


// Jalankan server
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});




function runQuery(qr, dt) {
    return new Promise((resolve, reject) => {
        let mysql= require('mysql2');
        var con = mysql.createConnection({
            host: "localhost",
                            user: "root",
                            password: "",
                            database: "dbarduino",  //ubah nama database sesuai dbarduino
        });
        try{
        con.query(qr, dt, function(err, result) {
             if (err) {
                  con.end();
                 reject(err);
             } else {
                 con.end();
                 resolve(result);
             }
         })
        }catch(err){return;}
    }) 
  }


