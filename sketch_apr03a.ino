const int SENSOR_PIN = A0; // 조도센서가 연결된 아날로그 핀 번호
const int LED_PIN = 2; // LED가 연결된 디지털 핀 번호

void setup() {
  pinMode(2, OUTPUT); // LED 핀을 출력으로 설정
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  int sensorValue = analogRead(SENSOR_PIN); // 조도센서에서 값 읽기
  Serial.println(sensorValue); // 값 출력

  if (sensorValue < 500) { // 조도 값이 일정 수준 이하일 때
    digitalWrite(2, HIGH); // LED 켜기
  } else {
    digitalWrite(2, LOW); // LED 끄기
  }

  delay(1000); // 1초 지연
}
