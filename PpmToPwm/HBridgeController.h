#ifndef HBridgeController_h
#define HBridgeController_h


#define pwmScaleMax 255

/* It is contani the chanel settings */
struct HBridgeConfig
{     /* The pwm pin which is connected to the H-Bridge */
  int PwmPin, 
      /* The pwm directional which is connected to the H-Bridge */
      DirectionalPin, 
      /* If the write value more that this value then is it a forward move, elre reverse */
      directionalTresshold;
};

/* It is controll a H-bridge channel */
class HBridgeController
{
  public:
    /* IO init and defaults */
    static void begin(HBridgeConfig);
  
    /* 
     *  Set the channel value.                                 
     *  \par1: The channel settings.
     *  \par2: The PWM value.                                
     *  \par3: The motor direction. (0=forward, 1=reverse).                       
     */
    static void write(HBridgeConfig, int, int);
};

void HBridgeController::begin(HBridgeConfig config)
{
  /* Set the outputs */
  pinMode(config.PwmPin, OUTPUT);
  pinMode(config.DirectionalPin, OUTPUT);

  /* Set the default state (not move) */
  analogWrite(config.PwmPin, 0);
  digitalWrite(config.DirectionalPin, LOW);
}

void HBridgeController::write(HBridgeConfig config, int pwm = -1, int isReverse = -1)
{
  if(pwm < 0)
  {
    pwm = config.directionalTresshold;
  }
  if(isReverse < 0)
  {
     if(pwm < config.directionalTresshold)
     {
        pwm = pwmScaleMax - pwm;
        isReverse = 1;
     }
     else
     {
        pwm = pwm - pwmScaleMax;
        isReverse = 0;
     }
  }
  bool direction = isReverse == 0 ? LOW : HIGH;
  analogWrite(config.PwmPin, pwm);
  digitalWrite(config.DirectionalPin, direction);
  Serial.print(" PWM: " + String(pwm) + " isReverse: " + String(isReverse) + " ");
}

#endif
