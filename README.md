Region Quadtree implementation, subdivides a given space until certain depth has been reached, leaf nodes count how many points are inserted in that region. This structure can be used to visualize heatmaps.

Compile: g++-11 rQuadtree.cpp main.cpp
Execution: ./a.out "depth of tree" "number of points" "canvas size"
Example: ./a.out 4 1000 100
This will produce a region quadtree with maximum depth of 4, will insert 1000 random points inside a 100 x 100 canvas.
