UNTUK MEMBUAT API DAN INTERKONEKSI ARDUINO DENGAN SERVER

Lakukan langkah-langkah Berikut:
1. Buat Database, dan esekusi kode program yang ada di database.sql dengan menggunakan MYSQL
2. Install Nodejs untuk Windows
3. Lakukan Langkah langkah seperti yang ada di dalam instruksi server.js
4. Lakukan pengujian dengan browser apabila server.js berhasil dibuat.
5. Menguji API save : localhost:8080/api/save/28/67     (menggunakan Browser, bila temp 28 dan humid 67%)
6. Menguji API read : localhost:8008/read
7. Hubungan ke WIFI, dan cek IP server dengan melakukan ipconfig di commandprompt
   
JIKA SUDAH READY UNTUK SERVER BUATK KODE ARDUINO

8. Buat kode arduino seperti pada File arduino.c
9. Ubah ssid, password WIFI  (WIFI harus sama dengan server)
10. Ubah url pada line 86, ubah IP sesuai dengan IP server poin ke-7, dengan port :8080
