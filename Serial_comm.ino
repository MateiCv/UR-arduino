String message = "";
String nom = "Arduino";
char drive_direction[100], drive_speed[100], drive_mode[100];

int enA = 9;
int in1 = 6;
int in2 = 7;

int enB=10;
int in3=4;
int in4=5;

void setup () {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);

}

void loop() {
  message = readSerialPort();
  if (message != "") {
    Serial.print("got it");
    getdata();
  }

//  getdata();
//  Serial.print(drive_mode);
//  if(strcmp(drive_mode,"auto")==0){
//  motor1back();
//  motor2back();
//  }
//  else 
//    turnoff();
    
  //motor1back();
  //motor2back();
  //speedm1(255);
  //speedm2(255);
  //delay(2000);
  turnoff();
  
}

void getdata(){
  Serial.print("hey");
  char msg[2000]="";
  char *p;
  char *m[4];
  int i=0;
  strcpy(msg, message.c_str());
  p=strtok(msg,";");
  
  while(p!=NULL){
    Serial.print(p);
    m[i]=p;
    i++;
    p=strtok(NULL,";");
  }
  strcpy(drive_mode,m[0]);
  strcpy(drive_direction,m[1]);
  strcpy(drive_speed,m[2]);
  
}

void motor1fow(){
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
}
void motor1back(){
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
}
void motor2fow(){
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}
void motor2back(){
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}
void turnoff(){
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(enA, 0);
analogWrite(enB, 0);

}

void stopm1(){
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
analogWrite(enA, 0);
}
void stopm2(){
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(enB, 0);
}

void speedm1(int speed){
  analogWrite(enA, speed);
}
void speedm2(int speed){
  analogWrite(enB, speed);
}

String readSerialPort(){
  String msg="";
  if(Serial.available()){
    delay(10);
    while(Serial.available()>0){
      msg+= (char) Serial.read();  
    }  
    Serial.flush();
  }
  return msg;
}

void sendData() {
  Serial.print(nom);
  Serial.print(" received : ");
  Serial.print(message);
}
