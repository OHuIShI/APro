int m1stp = 5;  //첫벗째 스텝모터의 stp를 5번핀에 연결합니다.
int m1dir = 4;  //첫번째 스텝모터의 dir를 4번핀에 연결합니다.
int m2stp = 6;  //두번째 스텝모터의 stp를 6번핀에 연결합니다.
int m2dir = 7;  //두번째 스텝모터의 dir을 7번핀에 연결합니다.
int a = 0;      //a라는 변수를 통해 스텝을 카운트 합니다.
int d;//d라는 변수를 선언하여 임의의 딜레이 값으로 활용합니다. 

void setup() 
{    

  d = 1;  // d의 초기값을 1로 설정하여 1밀리초만큼의 대기시간으로 회전합니다
  Serial.begin(9600);//시리얼통신을 시작합니다.
  pinMode(m1stp, OUTPUT);//m1stp를 출력으로 설정합니다.
  pinMode(m1dir, OUTPUT);//m1dir을 출력으로 설정합니다.    
  pinMode(m2stp, OUTPUT);//m2stp를 출력으로 설정합니다.
  pinMode(m2dir, OUTPUT);//m2dir을 출력으로 설정합니다.
}

void loop() 


{
  if (Serial.available()){
    d = Serial.read() - 48;// 입력된 문자값을 읽고 -48을 빼준값을 d(딜레이)값으로 사용합니다.
    Serial.println(d);//시리얼 모니터에 d값을 출력합니다.
  }



  if (a <  1000)  //만약 a가 1000보다 작을때, 
  {
    a++;//a의 값을 계속 증가시키고,
    digitalWrite(m1stp, HIGH);  //각각의 stp를 HIGH로 합니다,
    digitalWrite(m2stp, HIGH); 
    delay(d);               //d밀리초만큼 대기한뒤
    digitalWrite(m1stp, LOW);  // stp를 LOW로 합니다.
    digitalWrite(m2stp, LOW); 
    delay(d); // d밀리초만큼 대기합니다.
  } else     //아닐경우,
  {
    digitalWrite(m1dir, HIGH);//dir을 HIGH로 출력하고,
    digitalWrite(m2dir, HIGH);
    a++;//a값을 증가시킵니다.
    digitalWrite(m1stp, HIGH);//stp를 HIGH로 출력하고,
    digitalWrite(m2stp, HIGH);  
    delay(d);               //d밀리초 만큼 대기한뒤,
    digitalWrite(m1stp, LOW);//stp를 LOW로 출력합니다.
    digitalWrite(m2stp, LOW); 
    delay(d);//d밀리초만큼 대기합니다.

    if (a>2000)  //a가 2000보다 커지면,
    {
      a = 0;//초기화를 합니다.
      digitalWrite(m1dir, LOW);
      digitalWrite(m2dir, LOW);
    }
  }
}
/*int M1dirpin = 4;
int M1steppin = 5;
int M2dirpin = 7;
int M2steppin = 6;
void setup()
{
  pinMode(M1dirpin,OUTPUT);
  pinMode(M1steppin,OUTPUT);
  pinMode(M2dirpin,OUTPUT);
  pinMode(M2steppin,OUTPUT);
}
void loop()
{
  int j;
  delayMicroseconds(2);
  digitalWrite(M1dirpin,LOW);
  digitalWrite(M2dirpin,LOW);
  for(j=0;j<=5000;j++){
    digitalWrite(M1steppin,LOW);
    digitalWrite(M2steppin,LOW);
    delayMicroseconds(2);
    digitalWrite(M1steppin,HIGH);
    digitalWrite(M2steppin,HIGH);
    delay(1);
  }
}*/
