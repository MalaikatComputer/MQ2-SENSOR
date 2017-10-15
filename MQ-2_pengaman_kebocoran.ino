/* MQ-2 membuat pengaman dari kebocoran 
   Methane,Butane, LPG, asap
   

-------------------------------------------
  "MALAIKAT COMPUTER"  
-------------------------------------------
                 
*/

#define RELAY_ON 0
#define RELAY_OFF 1
#define RELAY_1  20   // pin yang digunakan yaitu pin 12

int sensorValue = 0;

const int gasPin = A0; //Pin yang digunakan di pin analog A0
const int merah = 15;//pin yang digunakan
const int hijau = 14;//pin yang digunakan

void setup() {

  pinMode(merah, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, RELAY_OFF);
  
  Serial.begin(9600);
}
void loop() { 
  sensorValue = analogRead(A0);
  Serial.println(sensorValue, DEC); 
  if (sensorValue < 300) {
    digitalWrite(hijau,HIGH);  
    digitalWrite(merah,LOW);
    digitalWrite(RELAY_1, RELAY_OFF);
    }
  else{ 
    digitalWrite(hijau,LOW);
    digitalWrite(merah,HIGH);
    delay(100);
    
    digitalWrite(RELAY_1, RELAY_ON); 
	  delay(5000);//lampu menyala selama 5 detik
    digitalWrite(RELAY_1, RELAY_OFF);
	  delay(2000);//lampu mati selama 2 detik
    digitalWrite(merah,LOW);
    delay(100);   
  }
}
