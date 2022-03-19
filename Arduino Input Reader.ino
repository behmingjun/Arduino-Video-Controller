int sPin = A0;
float sVal0 = 0;
float sVal1;
int vol;
float volSend = 0;
const float pycawUnit = 0.6525;
const float sliderUnit = 10.23;

int pPin = A5;
float pVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sPin, INPUT);
  pinMode(pPin, INPUT);
  sVal0 = analogRead(sPin); 
  vol = (sVal0 / sliderUnit);
  volSend = -65.25 + (vol * pycawUnit);

  Serial.write("Volume: ");
  Serial.println(volSend);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.read() == "Start"){
    setup();  
  }
  
  sVal1 = analogRead(sPin);
  pVal = analogRead(pPin);

//  Serial.println(sVal1);
//  delay(800);
  
  if (pVal > 0){
    Serial.write("Pause/Play\n");
    delay(150);
  }

  if (sVal1 > sVal0 + 10 || sVal1 < sVal0 - 10){
    vol = sVal1 / sliderUnit;
    volSend = -65.25 + (vol * pycawUnit);
    Serial.write("Volume: ");
    Serial.println(volSend);
    sVal0 = sVal1;
    delay(100);    
  }
}
