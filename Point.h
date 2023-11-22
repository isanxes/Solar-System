
#define POINT_H

class Point {
public:
  Point(double x, double y,double z);
  double getX();
  double getY();
  double getZ();
  void setX(double x);
  void setY(double y);
  void setZ(double z);

  double x;
  double y;
  double z;
};


