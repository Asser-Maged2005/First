# include <Wire.h>

void requestEvent() {
  Wire.write("312"); 
}

void setup() {
  Wire.begin(8); 
  Wire.onRequest(requestEvent); 
}
void loop () {
  delay (100) ;
}