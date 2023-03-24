/*
#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>

class Point {
private:
    double x {0.0};
    double y {0.0};

public:
    // construtor default
    Point() = default; 
    // construtor com dois argumentos
    Point(double x, double y) 
    { 
        this->x = x;
        this->y = y;
        std::cout << "construtor com 2 args foi invocado" << std::endl;
    }
    // copy constructor
    Point(const Point& point) 
        : x{ point.x }, y{ point.y }
    {
        std::cout << "construtor de cópia foi invocado" << std::endl;
    }
    // Destrutor
    ~Point() {
        std::cout << "Ponto (" << x << "," << y << ") destruido" << std::endl;
    }
    // retorna a coordenada x
    double getX() {
        return x;
    }
    // retorna a coordenada y
    double getY() {
        return y;
    }
    // modifica o valor da coordenada x
    void setX(double newX) {
        x = newX;
    }
    // modifica o valor da coordenada y
    void setY(double y) {
        this->y = y;
    }
    // retorna a distancia entre o ponto p e o ponto
    // que chamar essa funcao-membro
    double distancia(const Point& p) {
        double dx = (p.x - this->x) * (p.x - this->x);
        double dy = (p.y - this->y) * (p.y - this->y);
        return sqrt( dx + dy );
    }
};

#endif
*/


#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>

class Point {

private:
    double x{0.0};
    double y{0.0};

public:
    Point() = default;
    Point(double x = 1.0, double y = 1.0) {
        this -> x = x;
        this -> y = y;
        std::cout << "O constructor com dois argumentos foi invocado" << std::endl; 
    }
    
    Point(const Point& point) 
        : x{ point.x }, y{ point.y }
    {
        std::cout << "construtor de cópia foi invocado" << std::endl;
    }

    /*
    Point(const Point& point) 
        : x{ point.x }, y{ point.y } }
    {
        std::cout << "O constructor de copy foi invocado" << std::endl;
    }
    */

    ~Point() { 
        //std::cout << "O ponto (" << x <<  "," << y") destruido" << std::endl;
        std::cout << "Ponto (" << x << "," << y << ") destruido" << std::endl;
    }
    double getX() {
        return x;
    }
    void setX(double newx) {
        this -> x = newx;
    }
    double getY() {
        return y;
    }
    void setY(double newy) {
        this -> y = newy;
    }
    double distancia(const Point& p) {
        double dx = (p.x - this->x) * (p.x - this->x);
        double dy = (p.y - this->y) * (p.y - this->y);
        return sqrt( dx + dy );
    }
    /*
    double distancia(const Point& p) {
        double dx = (p.x - p.x) * (p.x - p.x);
        double dy = (p.y - p.y) * (p.y - p.y);
        return sqrt(dx + dy);
    }
    */
};

#endif
