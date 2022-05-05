#include "rQuadtree.hpp"

rQuadtree::rQuadtree(boundingBox& _totalArea, size_t _depth)
{
    root = new rQTNode();
    
    root->area.x = _totalArea.x;
    root->area.y = _totalArea.y;
    root->area.width = _totalArea.width;
    root->area.height = _totalArea.height;
    
    depth = _depth;
}

void rQuadtree::build(const vector<Point>& _data)
{
    for (size_t i = 0; i < _data.size(); i++)
    {
        insertPoint(root, _data[i]);
    }
    cout << "points inserted: " << root->pointCounter << endl;
}

void rQuadtree::insertPoint(rQTNode * &_node, const Point & _point)
{
    cout << "inserting point(x,y): " << _point.x << " " << _point.y << endl;
    
    if (_node->level < depth-1)
    {
        int quadrant = _node->area.getQuadrant(_point.x, _point.y);
        cout << "quadrant for current point at level(" << _node->level << "): " << quadrant << endl;
        if (_node->isLeaf) // first time visiting node
        {
            _node->isLeaf = false;
            for (int i = 0; i < 4; i++)
                _node->childNode[i] = new rQTNode(_node->area.getQuadAABB(i), _node->level+1);
            cout << "children[4] created at level:" << _node->level+1 << " from parent at quadrant: " << quadrant << endl;     
        }
        // until point has reached a leaf node
        insertPoint(_node->childNode[quadrant], _point);
        _node->pointCounter++;
    }
    else
    {
        cout << "leaf node reached, incrementing point counter("<< _node->pointCounter 
             <<") at level: " << _node->level
             << " in quadrant: " <<  _node->area.getQuadrant(_point.x, _point.y) << endl;
        _node->pointCounter++;
    }
    cout << endl;
}

void rQuadtree::deleteTree(rQTNode * &_node)
{
    if (_node == nullptr) return;
    deleteTree(_node->childNode[0]);
    deleteTree(_node->childNode[1]);
    deleteTree(_node->childNode[2]);
    deleteTree(_node->childNode[3]);
    for (size_t i = 0; i < 4; i++)
        delete _node->childNode[i];
    
}

rQuadtree::~rQuadtree()
{   
    deleteTree(root);
    delete root;
    cout << "tree deleted" << endl;
}
