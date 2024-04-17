char  buf[17];                                 
char* getFormattedMillisString(uint32_t msCount)
{
  uint16_t allSeconds   = msCount / 1000;          

  uint16_t hours            = allSeconds / 3600;    
  uint16_t secondsRemaining = allSeconds % 3600;   

  uint16_t minutes  = secondsRemaining / 60 ;     
  uint16_t seconds  = secondsRemaining % 60;       

  snprintf(buf, sizeof(buf),
           "%02d:"   //HH:
           "%02d:"   //MM:
           "%02d"   //SS.
           ,
           hours,
           minutes,
           seconds
          );

  return buf;

}
