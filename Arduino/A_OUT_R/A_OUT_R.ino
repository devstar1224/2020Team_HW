// 입구 오른쪽 
#include<Servo.h> 

void setup() {
  int angle = 0; // 서브모터 각도
  int anglePort = 5;// 서브모터 포트번호 5번으로 통일
  int ir_getH = 6;// 1차 적외선 입력(받는 적외선 신호) 2번이랑 세트
  int ir_getT = 3;// 2차 적외선 입력(받는 적외선 신호) 7번이랑 세트
  Servo door; // 서브모터 이름
  pinMode(ir_getH, INPUT); // 오른쪽 2차 적외선 입력 포트
  pinMode(ir_getT, INPUT); // 오른쪽 2차 적외선 입력 포트
}

void loop() {
door.attach(anglePort); // 서브모터와 연결

  if() // 1차 적외선 센서에서 신호가 인식이 안되면
  {
    digitalWrite(ir_getH, HIGH);
    // RFID에 신호를 보내서 작동시키고
    if( digitalRead() == HIGH ) // 라즈베리에서 신호가 오면
    {
      open(); // 문을 90도 꺽여서 문을 연다
    }
    
    if() // 2차 적외선 센서에서 신호가 인식이 안되면
    {
      close(); // 문을 -90도 꺽어서 문을 닫는다
      digitalRead() == LOW // 1차 적외선센서를 초기화 시킨다
    }
    
    digitalRead() == LOW // 2차 적외선센서를 초기화 시킨다
  }
  
}

void open (){ // 문  여는 함수
  angle +=90; // 문 여는 각도 90도 설정
  door.write(angle);// 문 연다
}

void close (){ // 문 닫는 함수
  angle -=90; // 문 닫는 각도 90도 설정
  door.write(angle); // 문 닫는다
}
