/*The three motors are continuously getting V1,V2,V3 required to drive bot in forward direction.That command i will include in the code later.
This code deals only with response from the ICU and the related corrections so that bot moves in a straight line.
Also the gyro calibration code is not included in this ,by tommorow i'll include it.*/
/***** x=??? denotes that value of x will be set after testing *****/
/**** also i don't know about sabertooth connections now,so wherever it is written that V1=a; means sabertooth is given command to apply voltage V1 in addition ****/
#include<Wire.h>
const int MPU_addr=0x68;  /* I2C address of the MPU-6050 */

 /* defining variables to be used */
int AcX,AcY,AcZ,GyX,GyY,GyZ;
int t_initial,t_final,temp_time=0;
int iterator=0;
double angle=0,x_pos=0,Vel,Acc,initial_velocity_x=0;
double a_fixed=???,w_fixed=???,t_total=???,V1,V2,V3;         /* i have explained this later in the code,t_total is in milliseconds */

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  /* PWR_MGMT_1 register */
  Wire.write(0);     /* set to zero (wakes up the MPU-6050) */
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  /* starting with register 0x3B (ACCEL_XOUT_H) */
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  /* request a total of 14 registers */
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read(); 
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read(); 
  GyZ=Wire.read()<<8|Wire.read();
  
if(iterator<1000)
/* waiting for 1000 loops to run because we should have something significant to apply correction upon */
{ 
  t_initial = temp_time;
  t_final = millis();
  temp_time = t_final;
  angle += GyZ * (t_final-t_initial) * 0.001;/* theta = omega*time */
  x_pos += initial_velocity_x * (t_final-t_initial) * 0.001  +  0.5 * AcX * (t_final-t_initial) * 0.001 * (t_final-t_initial) * 0.001;/* s=u*t+1/2*a*t^2 */
  initial_velocity_x += AcX * (t_final-t_initial) * 0.001;   /* our this final velocity will serve as initial velocity fr the next loop */
  iterator++;
 }
 
 /* Now,in this else loop there are a few things i have not fixed till yet. 
  For example,t_total,it is the time in which we want our bot to come to Vx=0 and theta=0 state,we can fixed it anything based on  
  testing.It is the time taken for correction of position and angle.
  Similarly,we have a_fixed which is the angular acceleration we want our bot to come to equilibrium position,and w_fixed which determines the angular velocity.
  Note that t_total, a_fixed and w_fixed are dependent on each other.
  */
  else{
    iterator = 0;
    Vel = ?;  /*we can calculate , i'll put the expression from the notebook*/
    Acc = ?;  /*we can calculate , i'll put the expression from the notebook*/
    t_initial = millis();
    while ( millis() - t_initial < t_total ) 
    {t_final=millis();
     V1 = V1_angularVelocity (w_fixed - a_fixed * (t_final-t_initial) * 0.001) + V1_velocity (Vel - Acc * (t_final-t_initial) * 0.001) ; /****  Using functions defined below  ****/
     V2 = V2_angularVelocity (w_fixed - a_fixed * (t_final-t_initial) * 0.001) + V2_velocity (Vel - Acc * (t_final-t_initial) * 0.001) ; /****  Using functions defined below  ****/
     V3 = V3_angularVelocity (w_fixed - a_fixed * (t_final-t_initial) * 0.001) + V3_velocity (Vel - Acc * (t_final-t_initial) * 0.001) ; /****  Using functions defined below  ****/
     delay(50);
    }
  }
}
/* Functions to be determined through testing */
/* Takes input as w (angular velocity of THE BOT and not the wheels,different from what we would get from encoders if we had used them ) and return respective additional voltages required */
double V1_angularVelocity (double w) {
  
}
double V2_angularVelocity (double w) {
  
}
double V3_angularVelocity (double w) {
  
}
/*Takes input as Vx(x-component of bot's velocity) and return respective additional voltages required*/
/*****bot is moving in the y-direction*****/
double V1_velocity (double Vx) {
  
}
double V2_velocity (double Vx) {
  
}
double V3_velocity (double Vx) {
  
}
/*Now the problem is that how to determine these functions.It can be approximated by the use of encoders but it was decided in the meeting that we will firstly try to do it without encoders.
 So,for this,firstly,lets consider the angular velocity one.What we will do is that we will experimentally find values of V1,V2 and V3 for a given omega. V1,V2 and V3 will be given through sabertooth
 and, angular velocity,  we'll find using MPU.After getting sufficient values we will graph them online and find the required functions.*/
