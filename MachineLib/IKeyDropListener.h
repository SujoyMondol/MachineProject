/**
 * @file IKeyDropListener.h
 * @author sujoy
 *
 *
 */
 
#ifndef IKEYDROPLISTENER_H
#define IKEYDROPLISTENER_H


/**
 * Interface for key drop listeners
 */
class IKeyDropListener {
private:

public:
  ///Abstract fucntion to act on key drops
  virtual void KeyDropTriggered() = 0;

};



#endif //IKEYDROPLISTENER_H
