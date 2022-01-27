#include <EEPROM.h>

/* - set how many data will make. ex: 99999. you must set 5 data array and set address EEPROM 
   - if you don't lose data while running program, you must set different every address EEPROM 
*/
int addr_jumlah[] ={1,2,3,4,5}; 
int nilai =123;

int z[] = {121,21,3,4}; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(" nilai awal = ");
  Serial.println( nilai );

delay(3000);

//  Serial.print(" size = ");
//  Serial.println( sizeof (z) / sizeof(z[0]));

  // set data EEprom 
setDataEEProm(addr_jumlah,sizeof (addr_jumlah) / sizeof(addr_jumlah[0]), nilai);

  //get data EEPRom
int result = getDataEEProm(addr_jumlah,sizeof (addr_jumlah) / sizeof(addr_jumlah[0]));

result = result +100;

  Serial.print(" nilai EEPROM + 100 = ");
  Serial.println( result );


}

void setDataEEProm(int address[],int arrSize, int data){
//  Serial.print( "size set = ");
//  Serial.println(arrSize);
  String dat = String(data);
  int len = dat.length();
for(int x = arrSize-1; x>=0; x--){  
 len--;
  if(len>=0){
    
      // Serial.println( dat[len]);
      EEPROM.write(address[x], dat[len]);
      
  }else{
     EEPROM.write(address[x], 'X');
  }

  
}

}


int getDataEEProm(int address[], int arrSize){
  String data;
//  Serial.print( "size get = ");
//  Serial.println(arrSize);
for(int x =0;  x<arrSize; x++){
 char dat = EEPROM.read(address[x]);
 if (dat != 'X'){
  data = data + dat;
 }
}

Serial.print("baca EEPROM = ");
Serial.println(data);

return data.toInt();
}
