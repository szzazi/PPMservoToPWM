#ifndef servoReader_h
#define servoReader_h

struct servoConfig
{
  int pin, min, max, scaleMin, scaleMax;
};


class servoReader
{
  public:
    static void begin(servoConfig);
    static int read(servoConfig);
};

void servoReader::begin(servoConfig config)
{
  pinMode(config.pin, INPUT);
}

int servoReader::read(servoConfig config)
{
  int val = pulseIn(config.pin, HIGH);
  Serial.print(" RAW: " + String(val) + " ");
  if(val < config.min) return config.scaleMin-1;
  if(val > config.max) return config.scaleMin-2;
  return(int)(((((double)val-config.min)/(config.max-config.min))*(config.scaleMax-config.scaleMin))+config.scaleMin);
}

#endif
