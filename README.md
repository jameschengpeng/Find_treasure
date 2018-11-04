# Find_treasure
Find treasure
Where is the treasure?
Maximum number of files: 1
Type of work: Individual work
In a game there is a map showing the location of various treasures featured in the gameplay. Each treasure is depicted by a square black-and-white pictogram represented as a grid of pixel values. Each pixel value is either 0 (representing a black pixel), or 1 (representing a white pixel).  The treasures are of various dimensions. 

The map is also represented as a square grid of black-and-white pixels.  As above, the cell in the top left corner of the grid has (x,y) coordinates (0,0).

 

A treasure may appear in one of four possible orientations in the map: rotated clockwise through 0, 90, 180 or 270 degrees from the orientation of its stored representation. 

 

You are given the dimensions of a treasure and a series of digits (0 or 1 only) representing its pictogram. You are also given the dimensions of a game map and a series of digits (0 or 1 only) representing the map. It is guaranteed that the given treasure appears exactly once in the map, however it may be in any one of the four orientations described above.

 

Write a program to find the map coordinates of the treasure’s location.  Report the map coordinates of the top left corner cell of the treasure as it appears in the map. (Note that the coordinates of the location are not affected by the orientation of the treasure.)

Assumptions:

·         Treasures do not overlap with other treasures or with other features in the map.

·         No treasure appears as part of the representation of any other treasure.
