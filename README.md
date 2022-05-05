Region Quadtree implementation, subdivides a given space until certain depth has been reached, leaf nodes count how many points are inserted in that region. This structure can be used to visualize heatmaps.

Compile:

>g++-11 rQuadtree.cpp main.cpp

Execution: 

>./a.out "depth of tree" "number of points" "canvas size"

Example: 

>./a.out 4 1000 100

This will produce a region quadtree with maximum depth of 4, will insert 1000 random points inside a 100 x 100 canvas.

![Captura de Pantalla 2022-05-05 a la(s) 17 11 58](https://user-images.githubusercontent.com/5533202/167033862-3ccf6ea1-4b5a-4508-8bfe-d52de893f0ac.png)
![Captura de Pantalla 2022-05-05 a la(s) 17 12 16](https://user-images.githubusercontent.com/5533202/167033869-10d8eca0-73c9-40b5-8d59-e91ed7673fb4.png)
