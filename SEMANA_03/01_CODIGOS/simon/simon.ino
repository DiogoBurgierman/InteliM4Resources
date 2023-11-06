int gabarito[10];
int respostas[10];
int i = 0;
bool gabaritoGerado = false;
int holder = 100;
int level = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(15, INPUT);
  pinMode(4, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(13, INPUT);
  pinMode(14, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(25, OUTPUT);
  digitalWrite(14, LOW);
  digitalWrite(27, LOW);
  digitalWrite(26, LOW);
  digitalWrite(25, LOW);
}

void loop()
{
  if(level==7){
    digitalWrite(14, HIGH);
    delay(600);
    digitalWrite(14, LOW);
    digitalWrite(27, HIGH);
    delay(600);
    digitalWrite(27, LOW);
    digitalWrite(26, HIGH);
    delay(600);
    digitalWrite(26, LOW);
    digitalWrite(25, HIGH);
    delay(600);
    digitalWrite(25, LOW);
    delay(600);
    reset(1);
  }
  if(gabaritoGerado == false){
    Serial.print("gabarito");
    for (int j=0; j<10; j++){
      gabarito[j] = random(1,5);
      Serial.print("gabarito");
      Serial.print(gabarito[j]);
      Serial.print("\n");
    }
    gabaritoGerado = true;
  }
  if(holder!=level){
    display(level);
  }
  holder=level;

  if (digitalRead(15) == HIGH)
  {
    respostas[i] = 1;
    Serial.print(respostas[i]);
    Serial.print("\n");
    i++;
    delay(300);
  }
  if (digitalRead(4) == HIGH)
  {
    respostas[i] = 2;
    Serial.print(respostas[i]);
    Serial.print("\n");
    i++;
    delay(300);
  }
  if (digitalRead(17) == HIGH)
  {
    respostas[i] = 3;
    Serial.print(respostas[i]);
    Serial.print("\n");
    i++;
    delay(300);
  }
  if (digitalRead(18) == HIGH)
  {
    respostas[i] = 4;
    Serial.print(respostas[i]);
    Serial.print("\n");
    i++;
    delay(300);
  }

  if(digitalRead(13)==HIGH){
    Serial.print("twe");
    Serial.print("\n");
    reset(1);
  }
  if(i==level){
    for(int c =0; c<level; c++){
      if(gabarito[c]!=respostas[c]){
        reset(0);
      }
    }

    level++;
  }
}

void reset(int valor){
  i = 0;
  level=valor;
  gabaritoGerado = false;
  holder = 100;
  digitalWrite(14, HIGH);
  digitalWrite(27, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(25, HIGH);
  delay(1000);
  digitalWrite(14, LOW);
  digitalWrite(27, LOW);
  digitalWrite(26, LOW);
  digitalWrite(25, LOW);
}

void display(int index){
  i=0;
  for(int k = 0;k<=index-1;k++){
    delay(1000);
    if(gabarito[k]==1){
      digitalWrite(14,  HIGH);
      delay(1000);
      digitalWrite(14,  LOW);
    }
    if(gabarito[k]==2){
      digitalWrite(27,  HIGH);
      delay(1000);
      digitalWrite(27,  LOW);
    }
    if(gabarito[k]==3){
      digitalWrite(26,  HIGH);
      delay(1000);
      digitalWrite(26,  LOW);
    }
    if(gabarito[k]==4){
      digitalWrite(25,  HIGH);
      delay(1000);
      digitalWrite(25,  LOW);
    }
    
  }
}


