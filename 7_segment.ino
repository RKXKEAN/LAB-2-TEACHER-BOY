const int DG[2] = {27, 14};  
const int segMentPin[7] = {4, 0, 17, 16, 23, 19, 18};  
const int dot = 20; 
int digit = 0;  

const byte numbers[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    // ...
};

hw_timer_t *timer = NULL;  

void IRAM_ATTR onTimer() {
    if (digit == 0) {
        displayNumber(1, 0);  
        digit = 1;
    } else {
        displayNumber(2, 1);  
        digit = 0;
    }
}

void displayNumber(int num, int pos) {
    digitalWrite(DG[0], HIGH);
    digitalWrite(DG[1], HIGH);
    
    for (int i = 0; i < 7; i++) {
        digitalWrite(segMentPin[i], numbers[num][i]);  
    }

    digitalWrite(DG[pos], LOW);  
}

void setup() {
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 1000, true); // ลองเปลี่ยนค่าที่นี่
    timerAlarmEnable(timer);

    for (int i = 0; i < 2; i++) {
        pinMode(DG[i], OUTPUT);
        digitalWrite(DG[i], HIGH);
    }
    for (int i = 0; i < 7; i++) {
        pinMode(segMentPin[i], OUTPUT);
        digitalWrite(segMentPin[i], LOW);
    }
    pinMode(dot, OUTPUT);
    digitalWrite(dot, LOW);
}

void loop() {
    delay(100); // ดีเลย์เพื่อให้เห็นการเปลี่ยนแปลง
}