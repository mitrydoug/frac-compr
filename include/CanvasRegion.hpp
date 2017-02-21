#ifndef CANVAS_REGION_H_
#define CANVAS_REGION_H_

#include <iostream>
#include <boost/rational.hpp>

#include "Region.hpp"
#include "types.hpp"

/* The following definitions facilitate the description of an abstraction of an
 * "Image Canvas". This Canvas is the unit square in the rational plane rational
 *  plane:
 *
 *              (0,0)
 *                * -------------------------------------- *
 *                |                                        |
 *                |                                        |
 *                |   (1/5,1/5)<---------- CanvasPoint     |
 *                |       * ----------- *                  |
 *                |       |             |             <----|--- Canvas
 *                |       |             |                  |
 *                |       |             |                  |
 *                |       |         <---|-- CanvasRegion   |
 *            /---|-|4/5| |             |                  |
 *           /    |       |             |                  |
 *          /     |       |             |                  |
 *   CanvasOffset |       |             |                  |
 *          \     |       |             |                  |
 *           \    |       * ----------- *                  |
 *            \---|--------- |3/10| (1/2,4/5)              |
 *                |                                        |
 *                |                                        |
 *                * -------------------------------------- *
 *                                                       (1,1)
 *
 */

typedef boost::rational<pixel> rat;

/* A CanvasPoint represents a point within the Canvas; should be contained in
 * the unit square.
 */
typedef CoordPair<rat, Position> CanvasPoint;


/* A CanvasOffset represents a width/height or a dimension for a region in the
 * unit square.
 */
typedef CoordPair<rat, Offset> CanvasOffset;

/* A CanvasRegion represents an area within the unit square. An appropritate
 * instance will be such that (topLeft + dimension) is a valid point within
 * the unit square.
 */
typedef Region<rat> CanvasRegion;

inline std::ostream& operator<<(std::ostream& out, const CanvasPoint &cp) {
    out << "CanvasPoint(" << cp.xCoord << ", " << cp.yCoord << ")";
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const CanvasOffset &co) {
    out << "CanvasOffset(" << co.xCoord << ", " << co.yCoord << ")";
    return out;
}

#endif // CANVAS_REGION_H_
