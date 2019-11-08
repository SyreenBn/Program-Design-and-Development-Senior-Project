/**
 * @file subject_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SUBJECT_BASE_H_
#define SRC_SUBJECT_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief
 */
class SubjectBase{

public:
  SubjectBase(void) : max_range(0){}
  virtual void RegisterObservers(Robot * robot);
  virtual void RemoveSensor(Robot * robot);
  virtual void ChangeOfState(EventBaseClass * event_);
  virtual void SendNotification(EventBaseClass * event_);
  std::vector<class Robot*> robots_observer(void);
private:
  std::vector<class Robot*> observers_;
  int max_range;

};



/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif /* SRC_SUBJECT_BASE_H_ */
