#ifndef RQUADTREE_HPP_
#define RQUADTREE_HPP_

#include <iostream>
#include <vector>

using namespace std;

// point
struct Point
{
    float x,y;
    Point(){
        x = y = 0.0f;
    }
    Point(float _x, float _y):x(_x), y(_y){}
};

// bounding box
struct boundingBox
{
    float x, y, width, height;

    boundingBox(){};
    boundingBox(float _x, float _y, float _w, float _h):
                x(_x), y(_y), width(_w), height(_h){}

    int getQuadrant(float _x, float _y){
        if (_x < x && _y > y) return 0; // top left
        if (_x > x && _y > y) return 1; // top right
        if (_x < x && _y < y) return 2; // bottom left
        if (_x > x && _y < y) return 3; // bottom right
    }

    boundingBox getQuadAABB(int _quadrant){
        switch (_quadrant)
        {
        case 0: // top left aabb
            return boundingBox(x - (width/2),y + (height/2), width/2, height/2);
            break;
        case 1: // top right aabb
            return boundingBox(x + (width/2),y + (height/2), width/2, height/2);
            break;
        case 2: // bottom left aabb
            return boundingBox(x - (width/2),y - (height/2), width/2, height/2);
            break;
        case 3: // bottom right aabb
            return boundingBox(x + (width/2),y - (height/2), width/2, height/2);
            break;
        default:
            return boundingBox();
            break;
        }
    }
    void printInfo(){
        cout << "Point(x,y): " << x << " " << y << endl;
        cout << "Size(width,height) " << width << " " << height << endl;

    }
};


class rQuadtree
{
private:
    struct rQTNode
    {
        boundingBox area;
        bool isLeaf = true;
        int level = 0;
        int pointCounter = 0;
        /*
            using z-order
            0 = top left
            1 = top right
            2 = bottom left
            3 = bottom right
        */
        rQTNode *childNode[4] = {nullptr};
        
        rQTNode(){}
        rQTNode(boundingBox _area, int _level):
                            area(_area), level(_level),pointCounter(0){}
    };

    boundingBox totalArea;
    size_t depth;
    rQTNode * root;
    
public:
    rQuadtree(boundingBox& _totalArea, size_t _depth);
    void build(const vector<Point>& _data);
    void insertPoint(rQTNode * &_node, const Point & _point);
    ~rQuadtree();

    void insert(double _x, double _y);
    void deleteTree(rQTNode * &_node);
};

#endif  // RQUADTREE_HPP_