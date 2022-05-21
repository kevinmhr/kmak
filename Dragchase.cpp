// chiklate by keyvan mehrbakhsh 2022
// try too shoot before the red stick below gets to the yellow sign.


#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NUM_COLORS 256

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03
int xscroll;
int yscroll;
int height= 320;
int width= 200;
int ff();
#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char byte;

byte far *VGA=(byte far *)0xA0000000L;
int x;
int  y;
#define SETPIX(x,y,c) *(VGA+(x)+(y)+height)=c
#define GETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define TARGPIX(targx,targy,c) *(VGA+(targx)+(targy)*320)=c
#define BULLETPIX(targx,targy,c) *(VGA+(targx)+(targy)*320)=c

//#define MAX(x,y) ((x) > (y) ? (x) : (y))
//#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int i,k,l,c,o,z,p,s,move;
  int xtrig;
  int ytrig;
  int r,flat;
  int ol=0;
int sc;

int targx,bullx;
int targy,bully,tempy;
int null=100;
int key,cari,carp;
int re;
int co=1;
int tri=2;
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
int car[]={1,3,1,4,1,5,1,6,2,3,2,4,2,5,2,6,2,7,3,3
	   ,3,6,3,7,4,3,4,6,4,7,5,3,5,6,5,7,6,3,6,6,
	   6,7,7,3,7,4,7,5,7,6,8,3,8,4,8,5,8,6,9,3,
	    9,4,9,5,9,6,10,3,10,4,10,5,10,6,11,3,11,4,11,5};









int iconx[]={1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4};
int icony[]={2,3,3,4,5,5,6,4,9,9,1,1,1,4,5,6,7,7,7,7,1,1,1,4,5,6,7,7,7,7,2,3,3,5,5,6,4,4,9,9,};








int charac[]={3,3,3,3,3,3,3,3,3,3,4,2,2,2,2,2,2,2,2,4,4,2,2,2,2,2,2,2,2,4,3,3,3,3,3,3,3,3,3,3};
void put_pixels(){

 union REGS regs;
  regs.h.ah = 0x0c;
  regs.h.al = 4;
  regs.x.cx = x;
  regs.x.dx = y;
  int86( VIDEO_INT, &regs, &regs );



}



void snd()
{
  int snu;
   for (snu=10000;snu<12000;snu++){

   sound(snu);
    delay(1);
   co=co+1;
 }

}
void default_scene()
		       {
	   for (s=0;s<40;s++){


	    // TARGPIX(ball[s+l]+x,bally[s+s+s]+10+y,charac[l+s+tan(x)]);
	     GETPIX(bally[s+s+l]+x,ballx[s+l]+y,charac[co+tri]);
	     GETPIX(3+x,y,4);
	     GETPIX(7+x,2+y,4);
	     GETPIX(x,y,9);
		      charac[l]=charac[l]+2;





			      }


}
void caar(){



	 for (int carp=0;carp<40;carp++){
	 for (int cari=0;cari<80;cari++){



	      GETPIX(car[cari]+xscroll, car[carp+l],car[3] );
	       GETPIX(car[cari]+xscroll, car[carp+l]+1,car[2] );



			}
}}

void chara(tri)
		       {

	    for (int carp=0;carp<40;carp++){
	    for (int t=0;t<1000;t++){
		    // if (  x == car[cari]+xscroll && y == car[carp]+xscroll ){

			// snd();




	      //	GETPIX( car[carp]+carp, car[carp+l], 2 );
		     //	GETPIX( charax[carp]+xtrig, charax[-carp]+ytrig, 7 );
			GETPIX( charax[carp]+xtrig*tri, charax[-carp]+ytrig*tri, xtrig );
		       GETPIX( charax[carp]+xtrig/tri, charax[-carp]+ytrig/tri, ytrig );

				 }

			       }




	     // car[l]=charac[l+key]+2;




}

void clsc(){


       for(l=0;l<200;l++){



  for(c=0;c<320;c++){


    GETPIX (c,l,0);
//    GETPIX (c,l,0);
//     GETPIX (c,l,0);

       //	charac[l]=charac[l+1*y];
      }}



 }


void colli(){
		//	GETPIX( charax[carp]+xtrig, charax[-carp]+ytrig+-20+x*2, 3 );
		  //	GETPIX( charax[carp]+xtrig, charax[-carp]+ytrig+-20+x/2, 3 );
		    //	GETPIX( charax[carp]+xtrig, charax[-carp]+ytrig+-20+x*8, 6 );
		      //	GETPIX( charax[carp]+xtrig+y*4, charax[-carp]+ytrig+-20+x, 2 );





}
void scoreboard(){

if (null == 200){
	     sc=sc-20;
	   ytrig=ytrig-(tan(key)/4);xtrig=xtrig-tan(key);



		 for (l=0;l<40;l++){





	     // charac[l]=charac[l+key]+1;



			   }

	    null=0;
}
		  }
void bullet()    {



		 if (ol ==     3)
			    {

			       //	bullx=x;
			 //   bully=y;

			     for(l=0;l<200;l++){
			     // xscroll--;
			       co=co+1;
			     //  default_scene();
			       //	 caar();
			    //  for(int t=0;t<2000
			     // ;t++){



			    sound(l+2000);
			   //   co=co;





			BULLETPIX(bullx+l, bully,3  );

			//   colli();


			BULLETPIX((bullx+l)-2, bully,0  );


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
//int xx=x;int yy=y;
// xtrig=xx;
  //	     ytrig=yy;
//xtrig=xtrig*tri;
//ytrig=ytrig*tri;
//  colli();
if (y>180){y=180;}
if (k>1){k=1;}
if (x>310){x=310;}
//if (x>10){xtrig--;}
if (tri>=4){tri=2;}
//if (o==1 && x>140 ){xscroll++;}
//if (o==-1){xscroll--;}
if(y<10){y=10;}
 if (x<10){x=10;}
//if (z>0){z=0;}
if (ytrig>180){ytrig=180;}
if (co>10){co=1;}
//if (xtrig<0){xtrig=0; }

if (xtrig>310){xtrig=310; }
if (xtrig<10){xtrig=10; }
if (ytrig<10){ytrig=10; }

if (sc==400){ printf("GAME OVER");}
//if (y == ytrig && x == xtrig){ snd(); co=co+1;null=200;  }
//x++;
xscroll++;

//ytrig++;







scoreboard();

y=y+k;
k=k*z;

x=x+o;
y=y+r;
	if (xtrig==0){
		     // GETPIX(sc,190,3);

    GETPIX(50+sc,190,3);
    GETPIX(50+sc,191,3);
    GETPIX(50+sc,192,3);
     GETPIX(50+sc,190,4);
    GETPIX(50+sc,191,4);
    GETPIX(50+sc,192,4);


		sc=sc+5;
	  //  xtrig=320;


//null=0;

    GETPIX(150,190,6);
    GETPIX(150,191,6);
    GETPIX(150,192,6);

      }
//l++;
//player();
//key++;
  default_scene();
bullet();
//move=move+1;
caar();

//xscroll--;
 // tri=tri+2;



//k++;
//chara();
caar();
chara(tri);

//printf (s,"xtrig",xtrig);
clsc();
//tri++;

if( x==xtrig/2 & y==ytrig/2|
 x==xtrig*2 & y==ytrig*2|
 x==xtrig/3 & y==ytrig/3|
 x==xtrig*3 & y==ytrig*3 |
  x==xtrig/4 & y==ytrig/4|
 x==xtrig*4 & y==ytrig*4
 )

{co++; snd();delay(2);  }






  default_scene();
 nosound();
  chara(tri);




    if(kbhit()) {
	xtrig=x+tri;


ytrig=y+tri;	       //	printf(s, "r",s);
       tri=tri+1;
       kc=getch();
      if( kc == (char)0 ) {
	kc=getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */
	     r=r-1;
	 //  y=y-5;
	  k--;
	   z=z-1;
	  // o=0;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:

	       //left

      //	x=x+5;
	     // r=0;
	      o=1;



	 break;
	case 0x4b:

	       //	 r=0;
       //	x=x-5;
		o=-1;

	  break;

	case 0x50: /* down arrow */
		   o=0;
		k=k++;
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
   r=0;o=0;    	xtrig=x+tri;
ytrig=y+tri; //tri++;
// chara(tri);
   tri=tri+1;    // null=0;
      }
//     printf("Key pressed: %s\n", s);



  }


}
//default_scene();
 set_mode( TEXT_MODE );

  return 0;
}