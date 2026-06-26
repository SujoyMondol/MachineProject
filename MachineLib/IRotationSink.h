/**
 * @file IRotationSink.h
 * @author sujoy
 *
 *
 */
 
#ifndef IROTATIONSINK_H
#define IROTATIONSINK_H


/**
 * Interface class for rotation sink
 */
class IRotationSink {
private:

public:
 /**
  * Update the rotation sink angle
  * @param angle angle to update the sink
  */
 virtual void UpdateRotation(double angle) = 0;

};



#endif //IROTATIONSINK_H
