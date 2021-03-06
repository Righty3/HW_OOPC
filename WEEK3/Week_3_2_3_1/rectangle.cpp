// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"
#include "window.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end, bool filled ):
   drawable( w, start, end - start ),
   start (start),
   end( end ),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) ),
   filled (filled)
{}

/// \brief
/// draw the lines and fill
void rectangle::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
   if (filled) {
       for (int i = start.x; i <= end.x; i++) {
           for (int j = start.y; j < end.y; j++ ) {
               w.draw(vector(i,j));
           }
       }
   }
}

