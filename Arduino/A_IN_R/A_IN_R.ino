// 입구 오른쪽 (도면 왼쪽)
#include<Servo.h> 

void setup() {
  int angle = 0; // 서브모터 각도
  int anglePort = 5;// 서브모터 포트번호 5번으로 통일
  int ir_sendH = 2;// 1차 적외선 출력(보내는 적외선 신호) 6번이랑 세트
  int ir_sendT = 7;// 2차 적외선 출력(보내는 적외선 신호) 3번이랑 세트
  int R_openR = 8;// 라즈베리에서 보내는 open 신호 포트
  int R_closeR = 9;// 라즈베리에서 보내는 close 신호 포트
  int A_R = 10;// 라즈베리랑 아두이노 연결하는 포트 10번
  Servo doorUp; // 위서브모터 이름
  Servo doorDown; // 아래서브모터 이름
  doorUp.attach(anglePort); // 위서브모터와 연결
  doorDown.attach(anglePort); // 아래서브모터와 연결
  pinMode(ir_sendH, OUTPUT); // 왼쪽 1차 적외선 출력 포트
  pinMode(ir_sendT, OUTPUT); // 왼쪽 2차 적외선 출력 포트

  digitalWrite(ir_sendH, HIGH) // 1차 적외선센서를 초기화 시킨다
  digitalWrite(ir_sendT, HIGH) // 2차 적외선 센서를 초기화 시킨다
}

void loop() {

  if( digitalRead(ir_sendH == LOW) // 1차 적외선 센서에서 신호가 인식이 안되면
  {
    digitalWrite( A_R, HIGH); // RFID에 신호를 보내서 작동시키고
    
    if( digitalRead(R_openR) == HIGH ) // 라즈베리에서 문 열라는신호가 오면
    {
      open(); // 문을 90도 꺽여서 문을 연다
    }
  }

  if( digitalRead(ir_sendT == LOW) // 2차 적외선 센서에서 신호가 인식이 안되면
  {
    close(); // 문을 - 90도 꺽어서 문을 닫는다
  }

  digitalWrite(ir_sendH, HIGH) // 1차 적외선센서를 초기화 시킨다
  digitalWrite(ir_sendT, HIGH) // 2차 적외선 센서를 초기화 시킨다
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
