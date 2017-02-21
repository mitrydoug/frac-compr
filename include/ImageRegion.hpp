#ifndef IMAGE_REGION_H_
#define IMAGE_REGION_H_

#include <iostream>

#include "Region.hpp"
#include "types.hpp"

/* The following definitions facilitate the description of an abstraction of an
 * "Image".
 *
 *              (0,0)
 *                * -------------------------------------- *
 *                |                                        |
 *                |                                        |
 *                |   (400,500)<---------- ImagePixel      |
 *                |       * ----------- *                  |
 *                |       |             |             <----|--- Image
 *                |       |             |                  |
 *                |       |             |                  |
 *                |       |         <---|-- ImageRegion    |
 *            /---|-- 520 |             |                  |
 *           /    |       |             |                  |
 *          /     |       |             |                  |
 *   ImageOffset  |       |             |                  |
 *          \     |       |             |                  |
 *           \    |       * ----------- *                  |
 *            \---|--------- 600   (1000,1020)             |
 *                |                                        |
 *                |                                        |
 *                * -------------------------------------- *
 *                                                    (1980,1080)
 *
 */

/* An ImagePixel represents a pixel within an image; should be contained within
 * the dimensions of the relevant image.
 */
typedef CoordPair<pixel, Position> ImagePixel;


/* An ImageOffset represents a width/height or a dimension of an Image
 */
typedef CoordPair<pixel, Offset> ImageOffset;

/* An ImageRegion represents an area within an image. An appropritate
 * instance will be such that (topLeft + dimension) is a valid point within
 * the dimensions of the relevant image.
 */
typedef Region<pixel> ImageRegion;

inline std::ostream& operator<<(std::ostream& out, const ImagePixel &cp) {
    out << "ImagePixel(" << cp.xCoord << ", " << cp.yCoord << ")";
    return out;
}

inline std::ostream& operator<<(std::ostream& out, const ImageOffset &co) {
    out << "ImageOffset(" << co.xCoord << ", " << co.yCoord << ")";
    return out;
}

#endif // IMAGE_REGION_H_
