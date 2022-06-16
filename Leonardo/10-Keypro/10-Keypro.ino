

int key_stats = 0;
int key_num[10] = {1,2,4,8,16,512,256,128,64,32};

void setup(){
  //ピンモードの設定
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
  //シリアル通信を開始
  Serial.begin(9600);
  delay(1000);
}


/*キーの状態を2進数法を使って返す
 *  [左手]
 *    ・小指    = 1
 *    ・薬指    = 2
 *    ・中指    = 4
 *    ・人差し指 = 8
 *    ・親指    = 16
 *  [右手]
 *    ・親指    = 32
 *    ・人差し指 = 64
 *    ・中指    = 128
 *    ・薬指    = 256
 *    ・小指    = 512
 */
 
int readkey(){
  int ans = 0;
  //左手
  digitalWrite(8,HIGH);
  for (int i=0;i<=4;i++){
    if (digitalRead(i+3)){
      ans = ans + key_num[i];
    }
  }
  digitalWrite(8,LOW);
  delay(25);
  //右手
  digitalWrite(9,HIGH);
  for (int i=5;i<=9;i++){
    if (digitalRead(i-2)){
      ans = ans + key_num[i];
    }
  }
  digitalWrite(9,LOW);
  delay(25);
  return ans;
}

void loop(){
  key_stats = readkey();
  delay(50);
  Serial.println(key_stats);
}
