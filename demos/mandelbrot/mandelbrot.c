/*
    ChibiOS/GFX - Copyright (C) 2012
                 Joel Bodenmann aka Tectu <joel@unormal.org>

    This file is part of ChibiOS/GFX.

    ChibiOS/GFX is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/GFX is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ch.h"
#include "hal.h"
#include "gdisp.h"

int count = 0;
float mag = 1;
float offsetx = -0.756423894274328;
float offsety = 0.064179410646170;
static float width, height;
static uint16_t iterations, screen_off_x, screen_off_y;
static uint16_t *FrameBuffer;

static int generateColor(int count, int base) {
	int r,g,b;
	int d = (count % base) * 256 / base;
	int m = (int)(d / 42.667);
 
	switch(m) {
		case 0: r=0; g=6*d; b=255; break;
		case 1: r=0; g=255; b=255-6*(d-43); break;
		case 2: r=6*(d-86); g=255; b=0; break;
		case 3: r=255; g=255-6*(d-129); b=0; break;
		case 4: r=255; g=0; b=6*(d-171); break;
		case 5: r=255-6*(d-214); g=0; b=255; break;
		default: r=0; g=0; b=0; break;
	}
 
	return (((r >> 3) & 0x1f) << 11) | (((g >> 2) & 0x3f) << 5) | ((b >> 3) & 0x1f);
}
 
static void complex_mult(float ar,float ai,float br,float bi, float *cr,float *ci) {
	// C = A * B
	*cr = ar * br - ai * bi;
	*ci = ar * bi + ai * br;
}
 
static float complex_abs2(float r,float i) {
	float ar,ai;
	complex_mult(r,i,r,-i,&ar,&ai);

	return ar;
}

void mandelbrotInit(uint16_t mandel_width, uint16_t mandel_height, uint16_t mandel_iterations) {
	const char *msg = "ChibiOS/GFX";

	width = (float)mandel_width;
	height = (float)mandel_height;
	iterations = mandel_iterations;

	FrameBuffer = chHeapAlloc(NULL, width * height * sizeof(uint16_t));	
	if(FrameBuffer == NULL)
		return;

	screen_off_x = (gdispGetWidth() - width) / 2;
	screen_off_y = (gdispGetHeight() - height) / 2;

	gdispClear(Black);
	gdispDrawString((gdispGetWidth() - gdispGetStringWidth(msg, &fontUI2Double)) / 2, 5, "ChibiOS/GFX", &fontUI2Double, White);

	while(TRUE) {
		mandelbrotLoop();
	}
}

void mandelbrotLoop() {
	int x, y;
    int pos = 0;
 
	for(y = 0; y < height; y++) {
		for(x = 0; x < width; x++) {
			float cr = (x - width/2.) / (width/2.) / mag + offsetx;
			float ci = (y - width/2.) / (width/2.) / mag + offsety;
			float zr = 0;
			float zi = 0;
			int t;

			for(t = 0; t < iterations; t++) {
				if(complex_abs2(zr,zi) > 4) 
					break;
				complex_mult(zr,zi,zr,zi,&zr,&zi);
				zr += cr;
				zi += ci;
			}

			FrameBuffer[pos++] = generateColor(t, 64);
		}
	}
 
	gdispBlitArea(screen_off_x, screen_off_y, width, height, FrameBuffer);

	// magnification
	mag = mag * 1.2;

	// panning 
	//offsety += 0.001;
	//offsetx += 0.0016;
 
	if(count++ > 80)  {
		offsetx = -0.756423894274328;
		offsety = 0.064179410646170;
		mag = 1;
		count = 0;
	}
}
