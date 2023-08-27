

// dragchase by keyvan mehrbakhsh 2022
// try too shoot before the red stick below gets to the yellow sign.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>


#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#define NUM_COLORS 256

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03
int xscroll;
int gh;
int yscroll;
int height= 320;
int width= 240;
int ff();
int life=10000;

#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9
#include "font.c"
typedef unsigned char byte;
typedef unsigned char text;
byte far *VGA=(byte far *)0xA0000000L;
byte far *GGG=(byte far *)0xA0000000L;
int x=150;
int  y=150;
int shuf;
int charx;
int chary;
int showx;
int showy;
#define SETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define GETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define PI 3.14


//#define MAX(x,y) ((x) > (y) ? (x) : (y))
//#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int i,k,c,o,z,p,s,move,t;
  int bulletl=1;
  int l=1;
  int g=1;
  int real,reat;
  int increm;
  int r;
  int ol=0;
int sc=-10;
int scxpos=180;
int targx,bullx;
int targy,bully,tempy;
int null=100;
int key,cari,carp;
int re1=1;
int re2=1;
int re3=1;
int re4=1;
int re5=1;
int re6=1;

int horiz;


int co=1;
int tri=1;
void set_mode(byte mode)
{
   union REGS regs;
  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86( VIDEO_INT, &regs, &regs );
}
int blox[]={1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,8,8,8,8,8};
int bloy[]={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5.1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};


int ballx[]={1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,8,8,8,8,8,
	     9,9,9,9,9,10,10,10,10,10,11,11,11,11,11,12,12,12,12,12,13,13,13,13,13,14,14,14,14,14};
int bally[]= {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5
	    ,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
//int charax[]={};
int charay[]={2,3,3,4,5,5,6,4,9,9,1,1,1,4,5,6,7,7,7,7,1,1,1,4,5,6,7,7,7,7,2,3,3,5,5,6,4,4,9,9,};

int roadx[1024];
int roady[1024];





  int ytrig[]={1};
  int xtrig[]={1};

//int ytrig[]={1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,8,8,8,8,8};
//int xtrig[]={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5.1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};

int mapx[]={1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4};
int mapy[]={1,2,3,3,3,3,5,5,9,9,1,1,3,4,5,6,7,7,9,9,1,1,3,4,5,6,7,7,9,9,1,2,3,3,3,3,5,5,9,9,};


int chix[]={4,4,4,4,4,1,1,1,1,1,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,1,1,1,1,1,4,4,4,4,4
	      ,	1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10
	    ,4,4,4,4,4,1,1,1,1,1,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,1,1,1,1,1,4,4,4,4,4
	      ,	1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};

int chiy[]={1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4

	     ,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10
	    ,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4
	     , 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};

int location[]={10,90,30,60,20,70};



int iconx[]={1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4
	     , 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10
	    ,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4
	     , 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};

int icony[]={4,4,4,4,4,1,1,1,1,1,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,1,1,1,1,1,4,4,4,4,4
	      ,	1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10
	    ,4,4,4,4,4,1,1,1,1,1,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,1,1,1,1,1,4,4,4,4,4
	      ,	1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};

char *ini="DBG by keyvan mehrbakhsh 2022 ";

char *go="  !GAME OVER!   final score :   ";


char score[]={'0','0','1','2','3','4','5','6','7','8','9','0'};
//char score2[]={'1','2','3','4','5','6','7','8','9','0'};




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
   for (snu=1;snu<500;snu++){
   for (int snd=1;snd<40;snd++){
   sound((1000*iconx[snd]));
   // delay(1);
//   co=co+1;
 }  }

}




void road(){


	  //	    for (int real=0;real<320;real++){

	//   for (int reat=0;reat<240;reat++){

	    //   if (showx){showx=showx+200;}



		if (showx==x)


	       if (showy==y){life=life-30;sound(horiz*10);y=y+1;}




 // }

   //}


	       }















void showroad(){

		for (int real=0;real<200;real++){

	   for (int reat=0;reat<320;reat++){

	    //   if (showx){showx=showx+200;}

	   road();

		  roadx[reat]=(real^shuf^reat)+ballx[reat&real];
		  roady[real]=(real^shuf^reat)^bally[real&real]-shuf
		  ;
		showx=+(roadx[reat]);
		showy=+(roady[real]);

	 // if (horiz=y){roady[real]=roady[real]+y;}

	      SETPIX(showx,showy+shuf,ballx[reat]);

	    if ( horiz==5){horiz=0;   }
	  //  if ( shuf==200){shuf=0;   }
	 horiz++;

  }

    }
    shuf++;






}







void default_scene_bg()
		       {


			      for (int t=0;t<40;t++){
			     for (int l=0;l<(life/1000);l++){

		 GETPIX((t/8)+40+(10*l),charay[t]+5,t);



			    }}

	    // for (int cari=0;cari<10;cari++){
	   for (int i=0;i<50;i++){


	     // GETPIX(car[(t+x)/30]+icony[(t+x)/30]+100,car[(t+y)/30]+icony[(t+y)/30]+100,iconx[1+t]);



	      GETPIX(i,i,x);
	      GETPIX((-i)+320,i,x);
	      GETPIX((-i)+320,(-i)+200,y);
	      GETPIX((i),(-i)+200,y);
			 //     }
				   }







}
void default_scene_bg2()
		       {
	    // for (int cari=0;cari<10;cari++){
	   for (int t=0;t<10;t++){



	    //  GETPIX(40+x,160+t+y*((x)),x);
	    //  GETPIX(160+x+t*2,158+y*((y)),x);
	    //   GETPIX(-160+x,160+t+y*((x)),x);
	    //  GETPIX(160+x+t*2,258+y*((y)),x);


			      }
				   }

void default_scene3()
		       {


	   for (int r=0;r<20;r++){
	   for (int g=0;g<40;g++){



	      GETPIX(blox[r],bloy[r]+(bloy[(g*50)+yscroll])+(g),sc);

				//key++;
			  // if (key==40){key==1;}

			      }
			    }

			}
void default_scene()   {
	   for (int t=0;t<300;t++){
		  increm++;
		  int i;
		 int j;
		 j=cos(increm)*((t/40)+(y/100));
		 //if (j>=10){j=0;}

		  i=sin(increm)*t/30;
		int k=i;

		     charx=(x);
		     chary=(y)
		     ;
	      GETPIX((i+1)+x,j+y,t);
	      GETPIX((i-1)+x,j+y,t);
	       GETPIX((i)+x,j+1+y,2);
		GETPIX((i)+x,j-1+y,3);
		GETPIX((i)+x,j+y,3);
		GETPIX((i+1)+x,j+1+y,3);
		GETPIX((i-1)+x,j-1+y,6);
	       GETPIX((i+1)+x,j-1+y,6);
		GETPIX((i-1)+x,j+1+y,6);








	 }









}
void caar(){




	 for (int cari=0;cari<2000;cari++){
		    for (int t=0;t<500;t++){


	 //		      GETPIX(yscroll+carp*5,yscroll+cari*5,sc);
	   //   GETPIX(xscroll+carp*10+x+sc,yscroll+cari*5+sc,sc);
	     //	   GETPIX(xscroll*cari,yscroll^tri,4+tri);
	     // GETPIX(xscroll+carp*10+x+sc,yscroll+cari*10+y,1);
	       //	      GETPIX(xscroll*carp,yscroll^tri,4+tri);
	     // GETPIX(xscroll+cari*10+x,yscroll+cari*10+y+sc,1);



			}
}}

void chara(tri)

		       {

	    for (int carp=0;carp<80;carp++){


		      //	 GETPIX ( iconx[1]+carp+100,icony[3]-sc,t);
			  GETPIX ( -sc,carp*2+20,t);
		       //	   GETPIX ( iconx[1]+carp+100,icony[3]+sc,t);
			  GETPIX ( sc,carp*2+20,t);

			GETPIX( ballx[carp
			]+xtrig[tri], bally[carp]+ytrig[tri], 3 );





			       }






	     // car[l]=charac[l+key]+2;




}



void icon(){

	       for (int carp=0;carp<40;carp++){
     //	GETPIX( iconx[carp]+xtrig+8, icony[carp]+ytrig+8, xtrig );
		     //  GETPIX( icony[carp]+xtrig-8, iconx[carp]+ytrig-8, ytrig );

		       }


}
void clsc(int opaq){


       for(l=0;l<200;l++){




  for(c=0;c<320;c++){










    GETPIX (c,l,0);






  //  GETPIX (c,l,0);
//     GETPIX (c,l,0);

       //	charac[l]=charac[l+1*y];
      }}



 }


void colli(){
	    for(real=0;real<200;real++){

	   for (reat=0;reat<320;reat++){


  }  }




}
void scoremath(){








		  }


void moving(){
	 x=x+o;
y=y+r;
	 y=y+k;
k=k*z;






}
collide(){
if(


  (x) == xtrig[tri]+5 & charay[tri]+(y)-bulletl == ytrig[tri]


)


{co++; snd();sc=sc+10;


		      re1=re1*7;
	  //   mapx[g]=mapx[g+1];
	     gh=gh+1;
	     gh=gh*2;

		   life=life+1000;
xtrig[tri]=x+y*tri;ytrig[tri]=x+y*tri;tri=tri+x;y=y+t;t=t/20;  }  }

void bullet()    {

		     for (t=0;t<40;t++){
		  if (ol==1){

			     for(bulletl=charay[t]+y;bulletl>0;bulletl--){





	      GETPIX((x),charay[t]+y-bulletl,6);


			    sound(bulletl+2000);

			 collide();

					}
			    }



}          }

int main(){




  init_font();

  char kc = 0;
  char s[255];
  byte *pal;

  set_mode( VGA_256_COLOR_MODE );

   for (l=0;l<sizeof ini*8;l++){
 put_char (ini[l],20+l*8,100,1,VGA);

	     }
 getch();

  /* printf("Hello, world!\n"); */


  /* loop until ESC pressed */
  while( kc!=0X1b )


  {


moving();
//t++;
//colli();
life=life-1;
if (y>=175){r=-(r);} if (y>=170){y=175;}
if (k>1){k=1;}
if (x>=310){o=-(o);} if (x>=310){x=310;}
//if (x>10){xtrig--;}
if (tri>=80 ){tri=1;}

if(y<=10){r=-(r); }  if(y<=10){y=10; }
 if (x<=10){o=-(o);}  if (x<=10){x=10;}
//if (z>0){z=0;}
if (ytrig[tri]>175){ytrig[tri]=10;xtrig[tri]=xtrig[x]*30-sc; sc=sc-4;}
if (co>10){co=1;}

if (icony[3]<10){icony[3]==10;}
//if (xtrig<0){xtrig=0; }


if (xscroll>=310){xscroll==10; }
yscroll++;
if (yscroll>239){yscroll=1 ;}


if (xtrig[tri]>310){xtrig[tri]=xtrig[tri]; }
if (xtrig[tri]<10){xtrig[tri]=10; }
if (ytrig[tri]<10){ytrig[tri]=10;re1=re1-1;xtrig[tri]=xtrig[tri]-20; }
if (t>=30){t==1;}





chara(tri);

scoremath();


    put_char (score[re1], 270,10,8,VGA);
     put_char (score[re2], 262,10,8,VGA);
      put_char (score[re3], 254,10,8,VGA);
       put_char (score[re4], 246,10,8,VGA);
	put_char (score[re5], 238,10,8,VGA);
	 put_char (score[re6], 230,10,8,VGA);
	    //	put_char (score[sc], 10,10,8,VGA);

		      if (re1>10){ re2=re2+1; re1=1; }

		       if (re1<1 ) { ;re1=1; }
		       if (re1<=-10 && re2==0 && re3==0 && re4==0 && re5==0 && re6==0 ){ re1==0;
	}
		      if (re2>10){re1=1; re3=re3+1; re2=1; }
			if (re2<1){ re1=10; re2=1;re3=9; }
		      if (re3>10){re2=1; re4=re4+1; re3=1; }
		       if (re3<1){ re2=10; re3=1;re4=9; }
		      if (re4>10){re3=1; re5=re5+1; re4=1; }
		       if (re4<1){ re3=10; re4=1;re5=9; }
		      if (re5>10){re4=1; re6=re6+1; re6=1; }
		       if (re5<1){ re4=10; re5=1;re6=9; }

			  if (re6<1){ re5=10; re6=1; }






    GETPIX(50+sc,190,3);
    GETPIX(50+sc,191,3);
    GETPIX(50+sc,192,3);
     GETPIX(50+sc,190,4);
    GETPIX(50+sc,191,4);
    GETPIX(50+sc,192,4);


	     //	sc=sc+5;
	  //  xtrig=320;


//null=0;

    GETPIX(150,190,6);
    GETPIX(150,191,6);
    GETPIX(150,192,6);

//      }
if (sc>-30){sc=-30;}



  default_scene_bg();
  default_scene();

      default_scene_bg2();



//ytrig[tri]++;
//icon();




showroad();
caar();

  default_scene3();
//default_scene();


bullet();

if (sc>1){key=key*100000;}
if (sc>=200){sc--;}




  chara(tri);
//  default_sc
ytrig[tri]++;
 nosound();

clsc(0);
//
//tri=10;
//y=y+k;


if (tri>=3){tri=1;}
chara(tri);


   if (x<=-(icony[3])-sc |  x>=(icony[3])+320+sc | life<=0 ) {
					for (l=0;l<sizeof go*8
					;l++  ){
 put_char (go[l],l*8,80,1,VGA);
		    put_char (score[re1], 170,100,8,VGA);
     put_char (score[re2], 162,100,8,VGA);
      put_char (score[re3], 154,100,8,VGA);
       put_char (score[re4], 146,100,8,VGA);
	put_char (score[re5], 138,100,8,VGA);
	 put_char (score[re6], 130,100,8,VGA);

		delay(100);
			       }
				y=200;

			      return 1;
				}






    if(kbhit()) {




	       //	printf(s, "r",s);
       //tri++;
       kc=getch();
      if( kc == (char)0 ) {

	kc=getch();
	/* special key handling */

	switch( kc )
	{

	case 0x48: /* up arrow */
	     r=r-1;
	 //  y=y-5;
	 // k--;
	   z=z-1;
	  // o=0;
	  //strcpy(s, "up arrow");
	ol=0;
	break;
	case 0x4d:

	       //left
	  ol=0;
      //	x=x+5;
	     // r=0;
	      o=1;



	 break;
	case 0x4b:
	     ol=0;
	       //	 r=0;
       //	x=x-5;
		o=-1;

	  break;

	case 0x50: /* down arrow */
		   o=0;
	      //	k=k++;
	      //	z=z++;
		  r=1;
       //	  y=y+5;
	  //strcpy(s, "down arrow");
	    ol=0;
	   break;

		case 0x52:
		     //	 for (l=0;l<100;l++){

		ol=1;

		      // charac[l]=0;
		       //		 }
				 break;
	default: /* other special keys */



	    ol=0;
       //	  sprintf(s, "00 %02x", kc);

	}


      }








//     printf("Key pressed: %s\n", s);



  }


}
//default_scene();
	 set_mode( TEXT_MODE );
	 }