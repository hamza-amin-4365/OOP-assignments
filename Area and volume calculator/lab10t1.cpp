#include<iostream>
using namespace std;
class Shape{
protected:
    int area;
    int volume;
public:
    virtual double getArea(){};

    virtual double getVolume(){};
    
    virtual void showInfo() = 0;
};
class  Point : public Shape{
protected:
    int x , y;
    public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    // setter for x
    void setX(int x ){
        this->x = x;
    }
    // setter for y
    void setY(int y){
        this ->y = y;
    }
    // getter for x
    int getX(){
        return x;
    }
    // getter for y
    int getY(){
        return y;
    }
    // virtual function in derived class
    double getArea(){
        return 0;
    }
    // virtual function in derived class
    double getVolume(){
        return 0;
    }
    // virtual function in derived class
    void showInfo(){
        cout<<"Position of x = "<<x<<" and y = "<<y<<endl;
    }
};
class Circle : public Point{
protected:
    int radius;
public:
    Circle(){
        radius = 32;
    }
    Circle(int x , int y , int radius): Point( x , y){
        this->radius = radius;
    }
    // setter of radius
    void setRadius(int radius){
        this->radius = radius;
    }
    // getter for radius
    int getRadius(){
        return radius;
    }
    // overridden function
    double getArea(){
        return (3.14 * radius * radius);
    }
    // overridden function
   double getVolume(){
        return 0;
    }
    // overridden function
    void showInfo(){
        cout <<  "Position of x = "<<x<<" y = "<<y<<endl;
        cout << "RADIUS OF CIRCLE " << radius <<endl;
        cout << "AREA OF CIRCLE "<< getArea() <<endl;
    }
};
class Cylinder : public Circle{
protected:
    int height;
public:
    Cylinder(){
        height = 23;
    }
    Cylinder(int x , int y , int radius, int height): Circle(x,y,radius){
        this->height = height;
    }
    // setter for height
    void setHeight(int height){
        this->height = height;
    }
    // getter for height
    int getHeight(){
        return height;
    }
    // overridden function
    double getArea(){
    }
    // overridden function
   double getVolume(){
        return (3.14 * ((radius * radius) * height));
    }
    // overridden function
    void showInfo(){
        cout << "Position of x = "<<x<<" y = "<<y<<endl;
        cout << "HEIGHT OF CYLINDER IS " << height <<endl;
        cout << "RADIUS OF CYLINDER IS " << radius <<endl;
        cout << "VOLUME OF CYLINDER IS "<< getVolume() <<endl;
        cout << "Area of cylinder does not exist in mathematics"<<endl;
        cout << "AREA OF CYLINDER IS " << getArea() <<endl;
        }

};
int main(){
    Cylinder cl(34 , 56 , 2 , 4);
    cl.showInfo();
    cout<<endl;
    
    Circle c(10, 5, 32);
    c.showInfo();
   
return 0;
}