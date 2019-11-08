/**
 * @file subject_base.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/subject_base.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 void SubjectBase::RegisterObservers(Robot * robot){
     observers_.push_back(robot);
     printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n" );
   }

   /**
    * Romove an observer
    * robot observer object to be registered
    */
   void SubjectBase::RemoveSensor(Robot * robot) {
   // find the observer
   auto iterator = std::find(observers_.begin(),
                              observers_.end(), robot);
   if (iterator != observers_.end()) {  //  observer found
     observers_.erase(iterator);  //  remove the observer
   }
   }

void SubjectBase::SendNotification(EventBaseClass * event_){
  for (auto obs : observers_){
  //  obs -> Accept(event_);
  }
}
void SubjectBase::ChangeOfState(EventBaseClass * event_){
  printf("RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR  in call" );
  SendNotification(event_);
}

std::vector<Robot*> SubjectBase::robots_observer(void) {
  return observers_;
  }

/*! Namespaces End */
NAMESPACE_END(csci3081);
