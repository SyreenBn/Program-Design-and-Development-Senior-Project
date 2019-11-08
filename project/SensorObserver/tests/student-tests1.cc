/* STUDENTS: Write your own unit tests in this file.  Or, better yet,
   rename this file to something more meaningful and/or add additional
   files of tests to this directory to test your project code in
   whatever ways you see fit!
 */

#include <gtest/gtest.h>
#include "../src/arena.h"
#include "../src/sensor_touch.h"
#include "../src/sensor_proximity.h"
#include "../src/sensor_distress.h"
#include "../src/common.h"
#include "../src/event_collision.h"
#include "../src/sensor_entity_type.h"
//#include "../src/entity_type.h"
#include "../src/entity_type.h"



using namespace csci3081;

TEST(SensorTouch, Constructor) {
  SensorTouch st;
  bool val = std::is_base_of<csci3081::Sensor, csci3081::SensorTouch>::value;
  EXPECT_TRUE(val);
  EXPECT_EQ(st.sensed(), false);
  EXPECT_EQ(st.point_of_contact().x,  0.0);
  EXPECT_EQ(st.point_of_contact().y,  0.0);
    EXPECT_EQ(st.angle_of_contact(), 0.0);
}

TEST(SensorTouch, sensed) {
  csci3081::SensorTouch st;
  st.sensed(true);
  EXPECT_EQ(st.sensed(), true);
}

TEST(SensorTouch, point_of_contact) {
  csci3081::SensorTouch st;
  st.point_of_contact(Position(1.0, 1.0));
  EXPECT_EQ(st.point_of_contact().x,  1.0);
  EXPECT_EQ(st.point_of_contact().y,  1.0);
}

TEST(SensorTouch, angle_of_contact) {
  csci3081::SensorTouch st;
  st.angle_of_contact(30.0);
  EXPECT_EQ(st.angle_of_contact(), 30.0);
}


TEST(SensorTouch, Reset) {
  csci3081::SensorTouch st;
  st.sensed(true);
  st.angle_of_contact(30.0);
  st.point_of_contact(Position(1.0, 1.0));
  EXPECT_EQ(st.sensed(), true);
  EXPECT_EQ(st.point_of_contact().x,  1.0);
  EXPECT_EQ(st.point_of_contact().y,  1.0);
  EXPECT_DOUBLE_EQ(st.angle_of_contact(), 30.0);

  st.Reset();
  EXPECT_EQ(st.angle_of_contact(), 0.0);
  EXPECT_EQ(st.point_of_contact().x,  0.0);
  EXPECT_EQ(st.point_of_contact().y,  0.0);
  EXPECT_EQ(st.sensed(), false);
}

// TEST(SensorTouch, Accept) {
//   csci3081::SensorTouch st;
//   csci3081::EventCollision * e;
//   st.Accept(&e);
//   EXPECT_EQ(st.sensed(), true);
//   EXPECT_EQ(st.point_of_contact().x,  1.0);
//   EXPECT_EQ(st.point_of_contact().y,  1.0);
//   EXPECT_DOUBLE_EQ(st.angle_of_contact(), 30.0);
// }

// ******************************************************************************
// * End Test Cases - Sensor Touch -
// ******************************************************************************


// ******************************************************************************
// * Start Test Cases - Sensor Proximity -
// ******************************************************************************

TEST(SensorProximity, Constructor) {
 csci3081::SensorProximity sp;
 bool value = std::is_base_of<csci3081::Sensor, csci3081::SensorProximity>::value;
 EXPECT_TRUE(value);
 EXPECT_EQ(sp.sensed(), false);
 EXPECT_EQ(sp.output(), 0);
 EXPECT_EQ(sp.range(), 0.0);
 EXPECT_EQ(sp.field(), 0.0);
}

TEST(SensorProximity, Denstructor) {
 csci3081::SensorProximity sp;
 sp.~SensorProximity();
 EXPECT_EQ(sp.sensed(), NULL);
 EXPECT_EQ(sp.output(), NULL);
 EXPECT_EQ(sp.range(), NULL);
 EXPECT_EQ(sp.field(), NULL);
}

TEST(SensorProximity, Output) {
 csci3081::SensorProximity sp;
  sp.sensed(true);
 EXPECT_EQ(sp.sensed(), true);
 EXPECT_EQ(sp.output(), -1);
}

TEST(SensorProximity, Range) {
 csci3081::SensorProximity sp;
 sp.range(10.0);
 EXPECT_EQ(sp.range(), 10.0);
}

TEST(SensorProximity, Field) {
 csci3081::SensorProximity sp;
  EXPECT_EQ(sp.field(), 0.0);
 sp.field(10.0);
 EXPECT_EQ(sp.field(), 10.0);
}

// ******************************************************************************
// * End Test Cases - Sensor Proximity -
// ******************************************************************************

// ******************************************************************************
// * End Test Cases - Sensor Distress -
// ******************************************************************************

TEST(SensorDistress, Constructor) {
 csci3081::SensorDistress sd;
 bool value = std::is_base_of<csci3081::Sensor, csci3081::SensorDistress>::value;
 EXPECT_TRUE(value);
 EXPECT_EQ(sd.sensed(), false);
 EXPECT_EQ(sd.range(), 0.0);
 EXPECT_EQ(sd.output(), 0);
}

TEST(SensorDistress, Denstructor) {
 csci3081::SensorDistress sd;
 sd.~SensorDistress();
 EXPECT_EQ(sd.sensed(), NULL);
 EXPECT_EQ(sd.range(), NULL);
 EXPECT_EQ(sd.output(), NULL);
}

TEST(SensorDistress, Range) {
 csci3081::SensorDistress sd;
 EXPECT_EQ(sd.range(), 0.0);
 sd.range(100.0);
 EXPECT_EQ(sd.range(), 100.0);
}

TEST(SensorDistress, Output) {
 csci3081::SensorDistress sd;
 EXPECT_EQ(sd.sensed(), false);
 EXPECT_EQ(sd.output(), 0);
 sd.sensed(true);
 EXPECT_EQ(sd.sensed(), true);
 EXPECT_EQ(sd.output(), 1);
}

TEST(SensorDistress, Reset) {
 csci3081::SensorDistress sd;
 EXPECT_EQ(sd.range(), 0.0);
 sd.range(100.0);
 sd.sensed(true);
 sd.Reset();
 EXPECT_EQ(sd.sensed(), false);
 EXPECT_EQ(sd.range(), 0.0);
}
// ******************************************************************************
// * End Test Cases - Sensor Distress -
// ******************************************************************************

}



// ******************************************************************************
// * start Test Cases - Sensor Entity Type -
// ******************************************************************************

TEST(SensorEntityType, Constructor) {
 csci3081::SensorEntityType set;
 bool value = std::is_base_of<csci3081::Sensor, csci3081::SensorEntityType>::value;
 EXPECT_TRUE(value);
 EXPECT_EQ(set.sensed(), false);
 EXPECT_EQ(set.range(), 0.0);
}

TEST(SensorEntityType, Denstructor) {
 csci3081::SensorEntityType set;
 set.~SensorEntityType();
 EXPECT_EQ(set.sensed(), NULL);
 EXPECT_EQ(set.range(), NULL);
}

TEST(SensorEntityType, Range) {
 csci3081::SensorEntityType set;
 EXPECT_EQ(set.range(), 0.0);
 set.range(100.0);
 EXPECT_EQ(set.range(), 100.0);
}

TEST(SensorEntityType, Reset) {
 csci3081::SensorEntityType set;
 EXPECT_EQ(set.range(), 0.0);
 set.range(100.0);
 set.sensed(true);
 set.Reset();
 EXPECT_EQ(set.sensed(), false);
 EXPECT_EQ(set.range(), 0.0);
}

TEST(SensorEntityType, Output) {
 csci3081::SensorEntityType set;
 //set.output(kRobot);
 set.output();
 enum csci3081::entity_type a ;//= kRobot;
 // a = kRobot;
 set.output(a);
 EXPECT_EQ(set.output(), a);
}
// ******************************************************************************
// * End Test Cases - Sensor Distress -
// ******************************************************************************
