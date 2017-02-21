#ifndef REGION_H_
#define REGION_H_

/* The following definitions facilitate the description of an abstract region
 * within a 2-dimensional space.
 *
 *              (0,0)
 *                * -------------------------------------- .. >
 *                |                                        
 *                |                                        
 *                |   (1/5,1/5)<---------- Point           
 *                |       * ----------- *                  
 *                |       |             |             <------ Space
 *                |       |             |                  
 *                |       |             |                  
 *                |       |         <---|-- Region         
 *            /---|-|4/5| |             |                  
 *           /    |       |             |                  
 *          /     |       |             |                  
 *       Offset   |       |             |                  
 *          \     |       |             |                  
 *           \    |       * ----------- *                  
 *            \---|--------- |3/10| (1/2,4/5)              
 *                |                                        
 *                |                                        
 *                :                                       
 *                v                                         
 */

template<typename elemType, typename Space /* Tag */>
struct CoordPair {
    /* Default Constructor */
    CoordPair(elemType x, elemType y) : xCoord(x), yCoord(y) {}

    /* Copy Semantics */
    CoordPair(const CoordPair &rp) = default;
    CoordPair& operator=(const CoordPair &rp) = default;

    /* Move semantics */
    CoordPair(CoordPair &&rp) = default;
    CoordPair& operator=(CoordPair &&rp) = default;

    elemType xCoord;
    elemType yCoord;
};

struct Position;
struct Offset;

template<typename T>
inline CoordPair<T, Position> operator+(const CoordPair<T, Position> &cp,
                                        const CoordPair<T, Offset> &co) {
    return CoordPair<T, Position>(cp.xCoord + co.xCoord, cp.yCoord + co.yCoord);
}

template<typename T>
inline CoordPair<T, Offset> operator-(const CoordPair<T, Position> &cp1,
                                      const CoordPair<T, Position> &cp2) {
    return CoordPair<T, Offset>(cp1.xCoord - cp2.xCoord, cp1.yCoord - cp2.yCoord);
}

template<typename T>
struct Region {
    CoordPair<T, Position> topLeft;
    CoordPair<T, Offset> dimension; 
};

#endif // REGION_H
