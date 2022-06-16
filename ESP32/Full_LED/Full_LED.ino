int pins[] = {19,18,17};
int rgb[] = {0,0,0};

void setup() {
  for (int i=0;i<=2;i++){
    ledcSetup(i,12800,8);
    ledcAttachPin(pins[i],i);
  }
}

void loop() {
  for (int n=0;n<=255;n++){
    rgb[0] = 255-n;
    rgb[1] = n;
    for (int i=0;i<=2;i++){
      ledcWrite(i,rgb[i]);
    }
    delay(10);
  }
  for (int n=0;n<=255;n++){
    rgb[1] = 255-n;
    rgb[2] = n;
    for (int i=0;i<=2;i++){
      ledcWrite(i,rgb[i]);
    }
    delay(10);
  }
  for (int n=0;n<=255;n++){ 
    rgb[2] = 255-n;
    rgb[0] = n;
    for (int i=0;i<=2;i++){
      ledcWrite(i,rgb[i]);
    }
    delay(10);
  }
}
