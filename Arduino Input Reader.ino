
// pressure pad variables
int pPin = A5;
float pValue = 0;

// slider variables
int sPin = A0;
float initialSValue;
float sValue = 0;
int initialVolume;
float sValDiff;
int counter;

void setup() {
  // put your setup code here, to run once:
  pinMode(sPin, INPUT);
  pinMode(pPin, INPUT);
  Serial.begin(9600);

//  // initialise the volume
  initialSValue = analogRead(sPin);
//  initialVolume = initialSValue / 20.48;
//  Serial.write(initialVolume);
//  Serial.write("\n");
//  for (int i = 0; i < 50; i++){
//    Serial.write("Volume Down\n");
//  }
//  for (int i = 0; i < initialSValue; i++){
//    Serial.write("Volume Up\n");
//  }
}

void loop() {
  // put your main code here, to run repeatedly:
//  if (Serial.available()){
//    if (Serial.readString() == "Start"){
//      setup();      
//    }
//  }
  
  sValue = analogRead(sPin);
  pValue = analogRead(pPin);
  
  if (pValue > 0){
    Serial.write("Pause/Play\n");
    delay(50);
  }

  if (initialSValue > sValue){
    sValDiff = initialSValue - sValue;
    counter = int(sValDiff / 20.46);
    for (int i = 0; i < counter; i++){
      Serial.write("Volume Down\n");
    }
    initialSValue = sValue;
    delay(100);
  }
  
  else if (initialSValue < sValue){
    sValDiff = sValue - initialSValue;
    counter = int(sValDiff / 20.48);
    for (int i = 0; i < counter; i++){
      Serial.write("Volume Up\n");
    }
    initialSValue = sValue;
    delay(100);
  }
  
  delay(100);
  
//  Serial.print("Value of slider | pressure pad: ");
//  Serial.print(sValue);
//  Serial.print(" | ");
//  Serial.println(pValue);
}
