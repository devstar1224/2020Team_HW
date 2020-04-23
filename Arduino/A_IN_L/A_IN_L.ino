// 입구 왼쪽
#include<Servo.h>

void setup() {
  int angle = 0; // 서브모터 각도
  int anglePort = 5;// 서브모터 포트번호 5번으로 통일
  int ir_sendH = 2;// 1차 적외선 출력(보내는 적외선 신호) 6번이랑 세트
  int ir_sendT = 7;// 2차 적외선 출력(보내는 적외선 신호) 3번이랑 세트
  Servo door;
  pinMode(ir_sendH, OUTPUT); // 1차 적외선 출력 포트
  pinMode(ir_sendT, OUTPUT); // 2차 적외선 출력 포트
}

void loop() {

  door.attach(anglePort); // 서브모터와 연결

  if() // 라즈베리에서 신호가 오면
  {
    open(); // 문을 90도 꺽여서 문을 연다
  }

  if() // 2차 적외선 센서에서 신호가 인식이 안되면
  {
      close(); // 문을 - 90도 꺽어서 문을 닫는다
      // 1차 적외선센서를 초기화 시킨다
  }

  // 2차 적외선 센서를 초기화 시킨다
      
}

void open (){ // 문  여는 함수
  angle +=90; // 문 여는 각도 +90도 설정
  door.write(angle);// 문 연다
}

void close (){ // 문 닫는 함수
  angle -=90; // 문 닫는 각도 -90도 설정
  door.write(angle); // 문 닫는다
}
