/**
 * @file RotationSource.h
 * @author sujoy
 *
 *
 */
 
#ifndef ROTATIONSOURCE_H
#define ROTATIONSOURCE_H

class IRotationSink;

/**
 * Class for Rotation Source
 */
class RotationSource {
private:
 /// Vector containing the rotation sinks
 std::vector<std::shared_ptr<IRotationSink>> mSinks;



public:
 /// Copy constructor (disabled)
 RotationSource(const RotationSource &) = delete;

 /// Assignment operator (disabled)
 void operator=(const RotationSource &) = delete;


 RotationSource() = default;


 void SetRotation(double angle);

 void AddSink(std::shared_ptr<IRotationSink> sink);

};



#endif //ROTATIONSOURCE_H
