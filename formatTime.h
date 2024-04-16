char  formattedMillisBuffer[17];                                 // global char buffer for the printing of milliseconds in formatted time
char* getFormattedMillisString(uint32_t msCount)
{
  uint16_t allSeconds   = msCount / 1000;           // total number of seconds to calculate remaining values

  uint16_t hours            = allSeconds / 3600;    // convert seconds to hours
  uint16_t secondsRemaining = allSeconds % 3600;    // seconds left over

  uint16_t minutes  = secondsRemaining / 60 ;       // convert seconds left over to minutes
  uint16_t seconds  = secondsRemaining % 60;        // seconds left over

  snprintf(formattedMillisBuffer, sizeof(formattedMillisBuffer),           // "prints" formatted output to a char array (string)
           "%02d:"   //HH:
           "%02d:"   //MM:
           "%02d"   //SS.
           ,
           hours,
           minutes,
           seconds
          );

  return formattedMillisBuffer;

}