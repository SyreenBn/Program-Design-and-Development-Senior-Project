#include <iostream>
/* out put is
robot1 information
Radius : 20
Speed : 200
Color : 65280
__________________________________________________
Setting Robot1 speed to 45
speed: 45
__________________________________________________

robot2 information with normal setter and getter
I can not print the inforamtion
 of robot2 because it is const and the function is not const
__________________________________________________
robot2 information with  const int constGet...
I can not print the inforamtion
 of robot2 if the function is const int constGet...
__________________________________________________
robot2 information with is int const constGet...
I can not print the inforamtion
 of robot2 if the function is  int const constGet...
__________________________________________________
robot2 information with int const constGet...() const
Radius : 250
Speed : 50
Color : 16711680
__________________________________________________
robot2.setSpeed(250):
changing the speed of the const robot will not compile
 because the robot is const 45
__________________________________________________
robot2.constSetSpeed(250): 250
__________________________________________________
 */

class Robot {
	private:
		const int radius;
		const int color;
		int speed;
	public:
		Robot() : radius(50), color(0xFF0000) {speed = 250;}
    Robot(int r, int c, int s) : radius(r), color(c){speed = s;}
    // we can not create consturctor and pass const value without initilize them
		// Robot(int r, int c, int s) {
		// 	// radius=r;
		// 	// color=c;
		// 	speed=s;
    // }
		void setSpeed(int inS) {speed = inS;}
		//void setColor (int inC) {color = inC;}
		int getSpeed() { return speed; }
		int getRadius() { return radius; }
		int getColor() { return color; }

    int const constSetSpeed(int inS) const { return speed; }
     int const constGetSpeed() const { return speed; }
		 int const constGetRadius() const { return radius; }
		 int const constGetColor() const { return color; }
};
int main() {
	Robot robot1(20, 0x00FF00, 200);
  std::cout << "robot1 information" << std::endl;
  std::cout << "Radius : " <<  robot1.getRadius() << std::endl;
  std::cout << "Speed : " <<  robot1.getSpeed() << std::endl;
  std::cout << "Color : " <<  robot1.getColor() << std::endl;
  std::cout << "__________________________________________________"<< std::endl;

  std::cout << "Setting Robot1 speed to 45" << std::endl;
	robot1.setSpeed(45);
  int s = robot1.getSpeed();
  std::cout << "speed: " << s << std::endl;
  std::cout << "__________________________________________________"<< std::endl;
  std::cout << "__________________________________________________"<< std::endl;
  std::cout << "__________________________________________________"<< std::endl;

	const Robot robot2;
   std::cout << "robot2 information with normal setter and getter" << std::endl;
   std::cout << "I can not print the inforamtion \n of robot2 because it is const and the function is not const" << std::endl;
   std::cout << "__________________________________________________"<< std::endl;
  // std::cout << "Radius : " <<  robot2.getRadius() << std::endl;
  // std::cout << "Speed : " <<  robot2.getSpeed() << std::endl;
  // std::cout << "Color : " <<  robot2.getColor() << std::endl;

  std::cout << "robot2 information with  const int constGet..." << std::endl;
  std::cout << "I can not print the inforamtion \n of robot2 if the function is const int constGet..." << std::endl;
  std::cout << "__________________________________________________"<< std::endl;

  std::cout << "robot2 information with is int const constGet..." << std::endl;
  std::cout << "I can not print the inforamtion \n of robot2 if the function is  int const constGet..." << std::endl;
  std::cout << "__________________________________________________"<< std::endl;

  std::cout << "robot2 information with int const constGet...() const " << std::endl;
  std::cout << "Radius : " <<  robot2.constGetSpeed() << std::endl;
  std::cout << "Speed : " <<  robot2.constGetRadius() << std::endl;
  std::cout << "Color : " <<  robot2.constGetColor() << std::endl;
  std::cout << "__________________________________________________"<< std::endl;

  // robot2.setSpeed(250);
  // int s2 = robot2.getSpeed();
   std::cout << "robot2.setSpeed(250): " << std::endl;
  std::cout << "changing the speed of the const robot will not compile \n because the robot is const " << s << std::endl;
  std::cout << "__________________________________________________"<< std::endl;

  robot2.constSetSpeed(250);
  int s2 = robot2.constGetSpeed();
  std::cout << "robot2.constSetSpeed(250): " << s2 << std::endl;
  std::cout << "__________________________________________________"<< std::endl;

}
