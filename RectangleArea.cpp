/*
 * 223 Rectangle Area
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 * Assume that the total area is never beyond the maximum possible value of int.
 * */

#include <iostream>
#include <algorithm>

using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int total = (C - A) * (D - B) + (G - E) * (H - F);
    if (A >= G || C<=E || B >= H || D <= F)
        return total;
    int x[4] = {A, C, E, G};
    int y[4] = {B, D, F, H};

    sort(x, x+4);
    sort(y, y+4);

    return total -  (x[2] - x[1]) * (y[2] - y[1]);

}

int main()
{
    cout << computeArea(-3,0,3,4,0,-1,9,2) << endl;
}
