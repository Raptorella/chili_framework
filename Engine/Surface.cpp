#include "Surface.h"
#include "ChiliWin.h"
#include <cassert>
#include <fstream>

Surface::Surface(const std::string& filename)
{
    // TODO: onemli bak incele burayi. sprite drawing tutoryali. 10. dk sonrasi
    std::ifstream file(filename, std::ios::binary);
    BITMAPFILEHEADER bmFileHeader;
    file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));
    // TODO 13.dk
}

Surface::Surface(int width_in, int height_in)
    :
    width(width_in),
    height(height_in),
    pPixels( new Color[width * height])
{
}

Surface::Surface(const Surface& rhs)
    :
    Surface(rhs.width, rhs.height)
{
    const int nPixels = width * height;
    for (int i = 0; i < nPixels; i++)
    {
        pPixels[i] = rhs.pPixels[i];
    }
}

Surface::~Surface()
{
    delete[] pPixels;
    pPixels = nullptr;
}

Surface& Surface::operator=(const Surface& rhs)
{
    width = rhs.width;
    height = rhs.height;

    delete[] pPixels;
    pPixels = new Color[width * height];

    const int nPixels = width * height;
    for (int i = 0; i < nPixels; i++)
    {
        pPixels[i] = rhs.pPixels[i];
    }
    return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
    assert( x >= 0 );
    assert( x < width );
    assert( y >= 0 );
    assert( y < height );
    pPixels[y * width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
    assert(x >= 0);
    assert(x < width);
    assert(y >= 0);
    assert(y < height);
    return pPixels[y * width + x];
}

int Surface::GetWidth() const
{
    return width;
}

int Surface::GetHeight() const
{
    return height;
}
