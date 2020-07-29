// 입구 왼쪽 (도면 오른쪽)
#include<Servo.h>

void setup() {
  int angle = 0; // 서브모터 각도
  int anglePort = 5;// 서브모터 포트번호 5번으로 통일
  int ir_getH = 6;// 1차 적외선 입력(받는 적외선 신호) 2번이랑 세트
  int ir_getT = 3;// 2차 적외선 입력(받는 적외선 신호) 7번이랑 세트
  int R_openL = 4;// 라즈베리에서 보내는 open 신호 포트
  int R_closeL = 3;// 라즈베리에서 보내는 close 신호 포트
  Servo doorUp; // 위서브모터 이름
  Servo doorDown; // 아래서브모터 이름
  doorUp.attach(anglePort); // 위서브모터와 연결
  doorDown.attach(anglePort); // 아래서브모터와 연결
  pinMode(ir_getH, INPUT); // 오른쪽 1차 적외선 입력 포트
  pinMode(ir_getT, INPUT); // 오른쪽 2차 적외선 입력 포트

  digitalWrite(ir_getH, HIGH) // 1차 적외선센서를 초기화 시킨다
  digitalWrite(ir_getT, HIGH) // 2차 적외선센서를 초기화 시킨다
}

void loop() {

  if( digitalRead(ir_getH) == LOW ) // 오른쪽 1차 적외선에서 신호가 끊기면
  {

    if( digitalRead(R_openL) == HIGH) // 라즈베리에서 문열라는 신호가 오면
    {
      open(); // 문을 90도 꺽어서 문을 연다
    }
  }

  if( digitalRead(ir_getT) == LOW ) // 2차 적외선 센서에서 신호가 인식이 안되면
  {
      close(); // 문을 - 90도 꺽어서 문을 닫는다
  }
  
  digitalWrite(ir_getH, HIGH) // 1차 적외선센서를 초기화 시킨다
  digitalWrite(ir_getT, HIGH) // 2차 적외선 센서를 초기화 시킨다
}

void open (){ // 문  여는 함수
  for(int angle = 0; angle < 90; angle++)
  {
    doorUp.write(angle);
    doorDown.write(angle);
    delay(15);
  }
}

void close (){ // 문 닫는 함수
  for(int angle = 90; angle > 0; angle--)
  {
    doorUp.write(angle);
    doorDown.write(angle);
    delay(15);
  }
}
