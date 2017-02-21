#include <iostream>
#include <boost/program_options.hpp>

#include "CanvasRegion.hpp"
#include "ImageRegion.hpp"

namespace po = boost::program_options;
using namespace std;

int main(int argc, char *argv[]) {

    CanvasPoint x(rat(1, 2), rat(1, 2));
    cout << x << endl;
    CanvasPoint y(rat(3, 4), rat(1, 2));
    cout << y << endl;
    CanvasOffset z = y - x;
    cout << z << endl;

    ImagePixel px(1200, 1400);
    ImageOffset off(200, -100);
    cout << (px + off) << endl;
    return -1;

    bool compress, decompress;

    /* Define command-line options */
    po::options_description desc("Fractal Compressor Options");
    desc.add_options()
        ("help", "produce help message")
        ("compress,c", po::bool_switch(&compress)->default_value(false),
            "invoke compression")
        ("decompress,d", po::bool_switch(&decompress)->default_value(false),
            "invoke decompression");

    /* Parse command-line options */
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (compress)
    {
        cout << "Compression was set" << endl;
    }

    if (decompress)
    {
        cout << "Decompression was set" << endl;
    }
}
