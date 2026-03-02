int startpin = 2;
int endpin = 10;
int duration = 300;
char toPrint[] = "Hello Vaughn";

void setup() {
  // put your setup code here, to run once:
  for (int i = startpin; i < endpin; i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  parseText();
}

void parseText(){
  for(int i = 0; i < sizeof(toPrint);i++){
    char toCheck = (char)tolower(toPrint[i]);
    switch(toCheck){
      case 'a':
        A();
      break;
      case 'b':
        B();
      break;
      case 'c':
        C();
      break;
      case 'd':
        D();
      break;
      case 'e':
        E();
      break;
      case 'f':
        eF();
      break;
      case 'g':
        G();
      break;
      case 'h':
        H();
      break;
      case 'i':
        I();
      break;
      case 'j':
        J();
      break;
      case 'k':
        K();
      break;
      case 'l':
        L();
      break;
      case 'm':
        M();
      break;
      case 'n':
        N();
      break;
      case 'o':
        O();
      break;
      case 'p':
        P();
      break;
      case 'q':
        Q();
      break;
      case 'r':
        R();
      break;
      case 's':
        S();
      break;
      case 't':
        T();
      break;
      case 'u':
        U();
      break;
      case 'v':
        Ve();
      break;
      case 'w':
        W();
      break;
      case 'x':
        X();
      break;
      case 'y':
        Y();
      break;
      case 'z':
        Z();
      break;
      case ' ':
        delay(duration);
      break;
      default:
      break;
    }
    delay(duration);
    clear();
  }
  digitalWrite(2,HIGH);
  delay(duration);
  clear();
}

void clear(){
  for (int i = startpin; i < endpin; i++){
    digitalWrite(i,LOW);
  }
}

void A(){
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void B(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void C(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void D(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(9,HIGH);
}
void E(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void eF(){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void G(){
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void H(){
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(9,HIGH);
}
void I(){
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
}
void J(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
}
void K(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}
void L(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
}
void M(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void N(){
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
}
void O(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void P(){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void Q(){
  digitalWrite(3,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}
void R(){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
}
void S(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void T(){
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
}
void U(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(9,HIGH);
}
void V(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
}
void Ve(){
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
}
void W(){
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
}
void X(){
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(9,HIGH);
}
void Y(){
  digitalWrite(3,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(9,HIGH);
}
void Z(){
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
}