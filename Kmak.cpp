#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM_COLORS 256

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03

int height= 320;
int width= 200;
int ff();
#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char byte;

byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x,y,c) *(VGA+(x)+(y)+height)=c
#define GETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define TARGPIX(targx,targy,c) *(VGA+(targx)+(targy)*320)=c

//#define MAX(x,y) ((x) > (y) ? (x) : (y))
//#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int i,k,l,c,o,z,p;
  int xtrig=100;
  int ytrig=100;
  int r;
  int ol=0;
int x=100;
int  y=150;
int targx;
int targy;
int null=100;
int key;
int re;
int co=1;
void set_mode(byte mode)
{
   union REGS regs;
  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86( VIDEO_INT, &regs, &regs );
}

int ballx[]={1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4};
int bally[]={1,2,3,3,3,3,5,5,9,9,1,1,3,4,5,6,7,7,9,9,1,1,3,4,5,6,7,7,9,9,1,2,3,3,3,3,5,5,9,9,};
int charax[]={1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4};
int charay[]={2,3,3,4,5,5,6,4,9,9,1,1,1,4,5,6,7,7,7,7,1,1,1,4,5,6,7,7,7,7,2,3,3,5,5,6,4,4,9,9,};



int charac[]={3,3,3,3,3,3,3,3,3,3,4,2,2,2,2,2,2,2,2,4,4,2,2,2,2,2,2,2,2,4,3,3,3,3,3,3,3,3,3,3};
void put_pixels(){

 union REGS regs;
  regs.h.ah = 0x0c;
  regs.h.al = 4;
  regs.x.cx = x;
  regs.x.dx = y;
  int86( VIDEO_INT, &regs, &regs );



}



int snd(void)
{
   int snu;
   for (snu=0;snu<20000;snu++){

   sound(snu);
 }
 //  delay(1);
 //  nosound();
   return 0;
}
void default_scene()
		       {
	   for (l=0;l<40;l++){


	     TARGPIX(xtrig+ballx[l],ytrig+bally[l],3+co);



	   //   charax[l]=charax[l]+0.1;

	    //  charay[l]=charay[l]+0.1;



			      }


}
void chara()
		       {
	   for (l=0;l<40;l++){

		GETPIX( charax[l]+x, charay[l]+y, charac[l] );

	   //   charax[l]=charax[l]+0.1;

	    //  charay[l]=charay[l]+0.1;

	      charac[l]=charac[l+key]+1;

			      }


}

void clsc(){

	       //	GETPIX( charax[l]+x, charay[l]+y, charac[l] );
       for(l=0;l<200;l++){



  for(c=0;c<320;c++){


    GETPIX (c,l,0);
    GETPIX (c,l,0);
     GETPIX (c,l,0);


      }}



 }

void colli(){
	    null=0;
       //	    if (targx= key-x) {
	      //	GETPIX( x+320,y*200, charac[l] );
	  if (ol == 3 | y == ytrig)
	//  if ( y == ytrig)
	   if (x == xtrig){
	    null=200;
					  co=co+1;
				       //	  re=co;
			   xtrig=xtrig+10;
       chara();
			 snd();
			      // targx=xtrig*2;

				   // system(beep);
					      //	 GETPIX(ballx[l]++ ,bally[l]++,bally[l]++  );
					      //	c=c-1;l=l-1;


}

//

}
void scoreboard(){

if (null == 200){


		  ytrig=ytrig-(tan(key)/4);
			 xtrig=xtrig-tan(key);
			 //   l=l+200;
			   }

			 null=0;

}

void bullet()    {



		 if (ol ==     3)
			    {
			    for (key=0;key<60;key++){


		       sound(1000);
			// null=0;
			delay(1);
   nosound();
			   // if (key>200+y){key=200-y;}
			GETPIX(x+3, y-key,ballx[key]  );
			GETPIX(x+3, y-key+2,0  );

			} }
	ol=0;

}

int main(){






  char kc = 0;
  char s[255];
  byte *pal;

  set_mode( VGA_256_COLOR_MODE );



  /* printf("Hello, world!\n"); */


  /* loop until ESC pressed */
  while( kc!=0X1b )


  {
//if (y!=targy){x=targx;}




if (y>190){y=190;}
if (x>310){x=310;}
if(y<10){y=10;}
 if (x<10){x=10;}
if (z>0){z=0;}
if (ytrig<30){ytrig=190;}
if (co>10){co=2;}
if (xtrig<0){xtrig=320; }
xtrig=xtrig-1;


clsc();

chara();

k=k*z;

x=x+o;
y=y+r;
colli();
//null=0;
scoreboard();
//l++;
//player();
key++;
bullet();
//co=0;
//put_pixels();       //	i=i+1;

 default_scene();

    if(kbhit()) {

	       //	printf(s, "r",s);

       kc=getch();
      if( kc == (char)0 ) {
	kc=getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */
	     r=r-1;
	 //  y=y-5;
	 // k=k+2;
	   z=z-1;
	  // o=0;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:

	       //left

      //	x=x+5;
	      r=0;
	      o=1;



	 break;
	case 0x4b:

		 r=0;
       //	x=x-5;
		o=-1;
	  break;

	case 0x50: /* down arrow */
		   o=0;
		k=k-2;
		z=z++;
		  r=1;
       //	  y=y+5;
	  //strcpy(s, "down arrow");

	   break;

		case 0x52:
		     //	 for (l=0;l<100;l++){

		     ol=3;

		      // charac[l]=0;
		       //		 }
				 break;
	default: /* other special keys */
	//    r=0;
	  //  o=0;
	 //
	  sprintf(s, "00 %02x", kc);

	}
      }


      else {
  //	sprintf(s, "%02x", kc);
       r=0;o=0;    // null=0;
      }
//     printf("Key pressed: %s\n", s);



  }


}
default_scene();
 set_mode( TEXT_MODE );

  return 0;
}

