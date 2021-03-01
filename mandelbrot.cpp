/*
 * Copyright (C) 2007,2008   Alex Shulgin
 *
 * This file is part of png++ the C++ wrapper for libpng.  PNG++ is free
 * software; the exact copying conditions are as follows:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. The name of the author may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <png.hpp>
#include <complex>


int mandelbrot(std::complex<double> c) {
    int n = 0;
    std::complex<double> z = 0;
    while (std::abs(z) <= 2 && n < 80) {
        z = z * z + c;
        n++;
    }
    return n;
}

int main() {
    png::image< png::rgb_pixel > image(10800, 7200);
    double val_kezd = -2.0;
    double val_meret = 3.0;
    double im_kezd = -1;
    double im_meret = 2;
    for (size_t y = 0; y < image.get_height(); y++)
    {
        for (size_t x = 0; x < image.get_width(); x++)
        {

            std::complex<double> num(val_kezd + x*1.0 / image.get_width() * val_meret, im_kezd + y*1.0 / image.get_height() * im_meret);
            int szin = mandelbrot(num);
            image[y][x] = png::rgb_pixel(szin,szin,szin);
        }
    }
    image.write("mandelbrot.png");
}
