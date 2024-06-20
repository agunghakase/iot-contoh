/*
   
   PROGRAM INI ADALAH CONTOH DARI ARDUINO MENGIRIM DATA DHT KE API
   ANDA HARUS MEMILIKI IP SERVER TERLEBIH DAHULU
   ANDA HARUS BERADA PADA JARINGAN YANG SAMA (WIFI) ANTARA ARDUINO, KOMPUTER/SERVER dan MOBILE APPS
   UNTUK MODUL SENSOR YANG LAIN SILAHKAN MEMBUAT FUNGSI SEPERTI readDHT, lalu MODIF di API
   
*/
#include <WiFi.h>          // Untuk ESP32. Untuk ESP8266 gunakan #include <ESP8266WiFi.h>
#include <HTTPClient.h>    //include modul http

#include <DHT.h>   //menggunakan DHT

// Pilih tipe sensor DHT
#define DHTTYPE DHT11   // atau DHT22 jika Anda menggunakan DHT22


const char* ssid = "YOUR_SSID";           //MASUKAN NAMA SSID WIFI misal: PolibatamWIFI
const char* password = "YOUR_PASSWORD";   //MASUKAN PASSWORD WIFI

// Struktur untuk menyimpan data suhu dan kelembaban
struct DHTData {
  float temperature;
  float humidity;
};

// Inisialisasi sensor DHT
DHT dht(0, DHTTYPE);

DHTData readDHT(int port) {
  dht.setup(port);  // Atur port input
  // Baca suhu dan kelembaban
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  // Periksa apakah ada kesalahan saat membaca sensor
  if (isnan(humidity) || isnan(temperature)) {
    return { NAN, NAN };  // Mengembalikan nilai NAN jika pembacaan gagal
  }
  // Mengembalikan nilai suhu dan kelembaban
  return { temperature, humidity };
}

// Fungsi untuk menghubungkan ke WiFi
void connectToWiFi(const char* ssid, const char* password) {
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to WiFi. IP address: ");
  Serial.println(WiFi.localIP());
}


// Fungsi untuk mengakses URL untuk Save Data ke Database via URL-API
void saveData(const char* url) {
  if (WiFi.status() == WL_CONNECTED) {  // Periksa apakah sudah terhubung ke WiFi
    HTTPClient http;
    http.begin(url);  // Inisialisasi HTTP client dengan URL
    int httpCode = http.GET();  // Lakukan HTTP GET request
    // Periksa hasil dari request
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Response:");
      Serial.println(payload);
    } else {
      Serial.print("Error on HTTP request: ");  //jika url ERROR
      Serial.println(httpCode);
    }
    http.end();  // Tutup koneksi
  } else {
    Serial.println("WiFi not connected");  //jika tidak ada wifi
  }
}

void setup() {
  Serial.begin(9600);
  // Hubungkan ke WiFi
  connectToWiFi(ssid, password); // Jika berhasil Connected to Wifi

}


void loop() {
  // Panggil fungsi readDHT dengan port input, misalnya port 2 

  DHTData data = readDHT(2);  //hasilnya bisa diakses --> data.humidity & data.temperature
  // MASUKAN SESUAI PORT Jika port 3 maka readDHT(3)
  // setelah dapat data save ke db dengan koneksi ke API-URL
  // misal: 192.168.1.12/api/save/{temperature}/{humidiy}
  url = "192.168.1.12/api/save/" + data.temperature + "/"+data.humidity;
  saveData(url)

  delay(2000);  // Setiap 2 detik mengirim data ke API
}
