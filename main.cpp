#include "rQuadtree.hpp"
#include "helper.hpp"

// argv[1] is depth of tree
// argv[2] is number of points
// argv[3] is canvas size
int main(int argc, char *argv[]) 
{
    if (argc != 4) {
        puts ("Not enough arguments!");
        return 1;
    }
    const size_t depth = strtoul(argv[1],NULL,0); 
    const float canvas_size = atof(argv[3]) + 0.0;
    cout << "Depth of tree: " << depth << endl;
    cout << "Number of points to be inserted: " << stoi(argv[2]) << endl;
    cout << "Canvas size: " << canvas_size << " x " << canvas_size << endl; 

    RNG rand;

    // gen random Points(>0) for testing
    vector<Point> pointVec;
    Point tempPoint;
    for (int i = 0; i < stoi(argv[2]); i++)
    {
        //tempPoint.x = rand.getRandom_float(-500.0,500.0);
        //tempPoint.y = rand.getRandom_float(-500.0,500.0);
        tempPoint.x = rand.getRandom_float(-(canvas_size/2),canvas_size/2);
        tempPoint.y = rand.getRandom_float(-(canvas_size/2),canvas_size/2);
        pointVec.push_back(tempPoint);
    }
    for (size_t i = 0; i < pointVec.size(); i++)
    {
        cout << "point[" << i << "](x,y): " << pointVec[i].x << " " << pointVec[i].y << endl;
    }
    
    // canvas
    //boundingBox limits(0.0f,0.0f,500.0,500.0); // 1000.0 x 1000.0
    boundingBox limits(0.0f,0.0f,canvas_size/2,canvas_size/2);
    limits.printInfo();
    // create quadTree
    rQuadtree qdt(limits, depth);

    qdt.build(pointVec);


    return 0;
}