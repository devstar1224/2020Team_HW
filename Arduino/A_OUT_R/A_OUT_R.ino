// 입구 오른쪽 
#include<Servo.h> 

void setup() {
  int angle = 0; // 서브모터 각도
  int anglePort = 5;// 서브모터 포트번호 5번으로 통일
  int ir_sendH = 2;// 1차 적외선 출력(보내는 적외선 신호) 6번이랑 세트
  int ir_sendT = 7;// 2차 적외선 출력(보내는 적외선 신호) 3번이랑 세트
  Servo doorUp; // 위서브모터 이름
  Servo doorDown; // 아래서브모터 이름
  doorUp.attach(anglePort); // 위서브모터와 연결
  doorDown.attach(anglePort); // 아래서브모터와 연결
  pinMode(ir_sendH, OUTPUT); // 왼쪽 1차 적외선 출력 포트
  pinMode(ir_sendT, OUTPUT); // 왼쪽 2차 적외선 출력 포트
}

void loop() {

  if() // 1차 적외선 센서에서 신호가 인식이 안되면
  {
    digitalWrite( , HIGH);
    // RFID에 신호를 보내서 작동시키고
    if( digitalRead() == HIGH ) // 라즈베리에서 신호가 오면
    {
      open(); // 문을 90도 꺽여서 문을 연다
    }
    
    if( digitalRead() == HIGH ) // 2차 적외선 센서에서 신호가 인식이 되면
    {
      close(); // 문을 -90도 꺽어서 문을 닫는다
      digitalRead() == LOW // 1차 적외선센서를 초기화 시킨다
    }
    
    digitalRead() == LOW // 2차 적외선센서를 초기화 시킨다
  }
  
}

void open (){ // 문  여는 함수
  for(angle = 0; angle < 90; angle++)
  {
    doorUp.write(angle);
    doorDown.write(angle);
    delay(15);
  }
}

void close (){ // 문 닫는 함수
  for(angle = 0; angle < 90; angle++)
  {
    doorUp.write(angle);
    doorDown.write(angle);
    delay(15);
  }
}
