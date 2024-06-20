UNTUK MEMBUAT API DAN INTERKONEKSI ARDUINO DENGAN SERVER

Lakukan langkah-langkah Berikut:
1. Buat Database, dan esekusi kode program yang ada di database.sql dengan menggunakan MYSQL
2. Install Nodejs untuk Windows
3. Lakukan Langkah langkah seperti yang ada di dalam instruksi server.js
4. Lakukan pengujian dengan browser apabila server.js berhasil dibuat.
5. Menguji API save : localhost:8080/api/save/28/67     (menggunakan Browser, bila temp 28 dan humid 67%)
6. Menguji API read : localhost:8008/read
7. Hubungan ke WIFI, dan cek IP server dengan melakukan ipconfig di commandprompt
8. Matikan FIREWALL windows agar ip bisa diakses dari device lainnya
   
JIKA SUDAH READY UNTUK SERVER BUATK KODE ARDUINO

8. Buat kode arduino seperti pada File arduino.c
9. Ubah ssid, password WIFI  (WIFI harus sama dengan server)
10. Ubah url pada line 86, ubah IP sesuai dengan IP server poin ke-7, dengan port :8080
11. Untuk contoh DHT ubah port DHT di arduino misal port 2, 3, atau 4.  Ubah di Line 82: readDHT( port )
12. Upload kode program ke arduino, lalu cek status wifi apakah terbuung
13. Pastikan DHT juga berfungsi dengan baik,
14. Jika berhasil maka setiap 2 detik arduino akan mengirim API
15. Cek di dalam database setiap 2 detik apakah ada data baru yang masuk
