// Hello World for PSP
// Created 2005.04.30  by nem 


#include "pg.h"

#include "bitmap.c"



int xmain(void)
{
	unsigned long fc;
	unsigned long r,g,b,rgb;
	
	pgInit();
	pgScreenFrame(2,0);

	pgFillvram(0);
	pgBitBlt(160,40,80,80,2,image_seclogo);
	pgScreenFlipV();
	pgWaitVn(100);

	pgFillvram(0);
	pgPrint4(4,7,0xffff,"Presents");
	pgBitBlt(160,40,80,80,2,image_seclogo);
	pgScreenFlipV();
	pgWaitVn(200);

	pgFillvram(0);
	pgPrint4(2,1,0xffff,"Produced by");
	pgBitBlt(60,100,80,80,2,image_nem);
	pgBitBlt(260,100,80,80,2,image_sampu);
	pgScreenFlipV();
	pgWaitVn(250);

	pgFillvram(0);
	pgPrint4(0,1,0xffff,"Special Thanks");
	pgScreenFlipV();
	pgWaitVn(50);

	pgFillvram(0);
	pgPrint4(0,1,0xffff,"Special Thanks");
	pgPrint4(4,2,0xffff,"to:     ");
	pgScreenFlipV();
	pgWaitVn(50);

	pgFillvram(0);
	pgPrint4(0,1,0xffff,"Special Thanks");
	pgPrint4(4,2,0xffff,"to:     ");
	pgBitBlt(160,110,80,80,2,image_gelabo);
	pgScreenFlipV();
	pgWaitVn(160);

	pgFillvram(0);
	pgPrint4(0,1,0xffff,"Special Thanks");
	pgPrint4(4,2,0xffff,"to:     ");
	pgPrint4(2,5,0xffff,"ps2dev.org");
	pgPrint4(3,6,0xffff,"and     ");
	pgPrint4(4,7,0xffff,"fellows!");
	pgScreenFlipV();
	pgWaitVn(160);

	pgFillvram(0);
	pgScreenFlipV();
	pgWaitVn(100);

	pgFillvram(0x1880);
	pgPrint(18,32,0xffff,"by nem / sampu-syokunin");
	pgBitBlt(200,160,80,80,1,image_seclogo);
	pgScreenFlipV();

	pgFillvram(0x1880);
	pgPrint(18,32,0xffff,"by nem / sampu-syokunin");
	pgBitBlt(200,160,80,80,1,image_seclogo);
	pgScreenFlipV();

	fc=0;
	while (1) {
		fc++;
		if (fc>=1536) fc=0;
		
		if (fc<256) {
			r=255;		g=0;		b=fc;
		} else if (fc<512) {
			r=511-fc;	g=0;		b=255;
		} else if (fc<768) {
			r=0;		g=fc-512;	b=255;
		} else if (fc<1024) {
			r=0;		g=255;		b=1023-fc;
		} else if (fc<1280) {
			r=fc-1024;	g=255;		b=0;
		} else {
			r=255;		g=1535-fc;	b=0;
		}
		r=r/8;
		g=g/8;
		b=b/8;
		rgb=(b<<10)+(g<<5)+(r<<0)+0x8000;

		pgPrint2(4,3,rgb,"Hello World,");
		pgPrint4(6,3,rgb,"P S P !  ");

		pgScreenFlipV();
	}

	return 0;
}
