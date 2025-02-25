const int ledPin = 32;    // ขาที่ใช้ควบคุม LED
const int ledChannel = 0; // เลือกช่อง PWM
const int resolution = 8; // ความละเอียดของ PWM (8-bit = 0-255)
int freqList[] = {1, 2, 5, 10, 25}; // รายการค่าความถี่ที่ต้องการทดสอบ

void setup() {
  Serial.begin(115200);
  ledcAttachPin(ledPin, ledChannel); // ผูกขา LED กับ PWM Channel 0
}

void loop() {
  for (int i = 0; i < 5; i++) {
    int freq = freqList[i]; // เลือกค่าความถี่จากรายการ
    ledcSetup(ledChannel, freq, resolution); // ตั้งค่าความถี่ของ PWM
    Serial.print("PWM Frequency Set to: ");
    Serial.print(freq);
    Serial.println(" Hz");

    ledcWrite(ledChannel, 128); // ตั้งค่า Duty Cycle ที่ 50% (128 จาก 255)
    delay(5000); // รอ 3 วินาทีเพื่อสังเกตผล
  }
}
