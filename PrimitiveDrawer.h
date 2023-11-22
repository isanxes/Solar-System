#ifndef PRIMITIVEDRAWER_H
#define PRIMITIVEDRAWER_H

class PrimitiveDrawer {
public:
	PrimitiveDrawer();
	void DrawPoint(Point point);
	void DrawLine(Point start, Point end);
	void DrawTriangle(Point v1, Point v2, Point v3);
	void DrawQuad(Point v1, Point v2, Point v3, Point v4);
	void DrawSphere(double r,double lats,double longs,float rightLift,float upDown,float red,float g,float b);
	void DrawCircle(float size,float right,float left,float red,float green,float blue);
};

#endif
