
int segmentPins[]={2,3,4,5,6,7,9};


 byte digits[10][7]={
 {1,1,1,1,1,0,1}, //0
 {0,1,1,0,0,0,0},//1
 {1,1,0,1,1,1,0}, //2
 {1,1,1,1,0,1,0}, //3
 {0,1,1,0,0,1,1}, //4
 {1,0,1,1,0,1,1}, //5
 {1,0,1,1,1,1,1},//6
 {1,1,1,0,0,0,0},//7
 {1,1,1,1,1,1,1},//8
 {1,1,1,1,0,1,1},//9
 };
 int buzzerpin=8;
int numSegments=7;

 void showDigit(int n){
  if(n<0||n>9)
  return;
for(int i=0;i<numSegments;i++){
  digitalWrite(segmentPins[i],digits[n][i]);
}
 }
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(buzzerpin,OUTPUT);

for(int i=0;i<numSegments;i++){
  pinMode(segmentPins[i],OUTPUT);
}
Serial.println("--Starting beeping countdown--");
 int count=9;
 while(count>=1){
  Serial.println("Counting" );
  Serial.println(count);

  showDigit(count);
  tone(buzzerpin,1000,200);
  delay(2000);
  count=count-1;
  showDigit(0);
  tone(buzzerpin,1500,1000);

  Serial.println("Countdown complete");
 } 

}



void loop() {
  // put your main code here, to run repeatedly:

  
}





