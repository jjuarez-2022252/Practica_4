/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: keypad
   alumno: Jose Javier Juarez Rivera
   Carnet: 2022252
*/
#define led 2
#define Encendido(pin) digitalWrite(pin, HIGH)
#define Apagado(pin) digitalWrite(pin, LOW)
void configPinesInput(void);
void configpinesOutput(void);
int contador_display(int a, int b, int c, int d, int e, int f, int g, int B);
int trig = 11;
int echo = 12;
int duracion;
int distancia;
int contador=0;

void setup() {
  Serial.begin(9600);
   pinMode(echo, INPUT);
   pinMode(led, OUTPUT);
     pinMode(trig, OUTPUT);  
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT);
     pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delay(10);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia= duracion*0.034/2;    
  Serial.print(String(distancia));
  Serial.println(" cm");
  delay(400);

  if(distancia>=6 && distancia<=10)
  {
    digitalWrite(led, HIGH);
    contador++;
     Serial.println("contador");
     delay(1000);
    }
  else
  {
    digitalWrite(led, LOW);
    }

    contador_display(3,4,5,6,7,8,9,10);    
}

int contador_display(int a, int b, int c, int d, int e, int f, int g, int B){
switch(contador){
         
          case(0):
            Apagado(a); Apagado(b); Apagado(c); Apagado(d); Apagado(e); Apagado(f);
            Encendido(g); 
         break;
          case(1):
            Apagado(b); Apagado(c);
            Encendido(a); Apagado(d); Encendido(e); Encendido(f); Encendido(g);
            
         break;
           case(2):
            Apagado(a); Apagado(b); Apagado(d); Encendido(e); Apagado(g);
            Encendido(c); Encendido(f); 
         break;
          case(3):
            Apagado(a); Apagado(b); Apagado(c); Apagado(d); Apagado(g);
            Encendido(e); Encendido(f); 
         break;
          case(4):
            Apagado(b); Apagado(c); Apagado(f); Apagado(g);
            Encendido(a); Encendido(d); Encendido(e); 
         break;                
          case(5):
            Apagado(a); Apagado(c); Apagado(d); Apagado(f); Apagado(g);
            Encendido(b); Encendido(e);
         break;      
          case(6):
            Encendido(a); Apagado(c); Apagado(d); Encendido(e); Apagado(f); Apagado(g);
            Encendido(b); 
         break;        
          case(7):
            Apagado(a); Apagado(b); Apagado(c);
            Encendido(d); Encendido(e); Encendido(f); Encendido(g);
         break;
          case(8):
            Apagado(a); Apagado(b); Apagado(c); Apagado(d);
            Encendido(e); Apagado(f); Apagado(g); 
         break;
           case(9):
            Apagado(a); Apagado(b); Apagado(c); Apagado(f); Apagado(g);
            Encendido(d); Encendido(e); 
            digitalWrite(2, HIGH);
            contador=9;
         break;
           
    }
 
}
