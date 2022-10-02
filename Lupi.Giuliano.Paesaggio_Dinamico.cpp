//AUTHOR:Giuliano Lupi
//DATE:02/12/2021
//TITLE:PAESAGGIO_DINAMICO
/*ALGORITHM:Genera un paesaggio casuale mattiniero o notturno affinché l'utente possa sempre vedere qualcosa di differente.*/
#include <winbgim.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

int main(){
	initwindow (1920,1080);
	srand(time(0));
	int n=rand()%10;
	if (n<=5){
		//TEMA GIORNO
		int erba (COLOR (0,220,0));
		int pioggia (COLOR(0,0,255));
		int fili_erba(COLOR(23,144,69));
		int terra (COLOR(0,240,0));
		int orizzonte (COLOR(0,200,0));
		int cresta_patroclo(COLOR(0,201,0));
		int cielo (COLOR(171,205,249));
		int tronco (COLOR(174,128,83));
		int legno (COLOR(194,148,103));
		int mattone (COLOR(202,142,130));
		int stucco (COLOR(242,152,148));
		int comignolo (COLOR(174,128,82));
		int foglie (COLOR(65,177,84));
		int chioma (COLOR(87,230,88));
		int sole (COLOR(230,230,0));
		int raggi (COLOR(243,159,24));
		int nuvola (COLOR(228,229,224));
		int nuvola_fill(COLOR(247,247,247));
		int oro (COLOR(205,164,52));
		int ottone (COLOR(218,165,32));
		int acciaio_inossidabile (COLOR(156,156,156));
		int serracinesca (COLOR(143,143,143));
		int asfalto (COLOR(41,49,51));
		int strisce (COLOR(255,255,255));
		int rami=100;
		int fili=50000;
		int gocce=2000;
		int uccelli=5;
		int nuvole=5;
		int temporaneo(COLOR(0,0,255));
		
		
			//ORIZZONTE
		setlinestyle(0,0,5);
		setcolor(orizzonte);
		line(0,getmaxy()/1.5,getmaxx(),getmaxy()/1.5);
		
		//TERRA
		setfillstyle(1,terra);
		floodfill(getmaxx()/2,800,orizzonte);
		
		//CIELO
		setfillstyle(1,cielo);
		floodfill(getmaxx()/2,200,orizzonte);
		
		//SOLE
		int solex=rand()%getmaxx();
		int soley=rand()%getmaxy()/3;
		setlinestyle(0,0,20);
		setcolor(raggi);
		circle(solex,soley,100);
		setfillstyle(1,sole);
		floodfill(solex,soley,raggi);
		
		//NUVOLE
		setlinestyle(0,0,5);
		for (int i=0;i<nuvole;i++){
			for(int c=0;c<5;c++){
				int nuvolax=rand()%getmaxx();
				int nuvolay=rand()%getmaxy()/3;
				int raggio=rand()%50+10;
				setcolor(temporaneo);
				circle(nuvolax,nuvolay,raggio);
				setfillstyle(1,nuvola_fill);
				floodfill(nuvolax,nuvolay,temporaneo);
				setcolor(nuvola);
				circle(nuvolax,nuvolay,raggio);
			}
			
			//floodfill(chiomax,chiomay,chioma);
		}
		
		//UCCELLI
			setlinestyle(0,0,5);
			setcolor(COLOR(0,0,0));
			for (int i=0; i<uccelli;i++){
				int uccellix=rand()%getmaxx();
				int uccelliy=rand()%getmaxy()/1.5;
				arc(uccellix,uccelliy,360,180,10);
				arc(uccellix+20,uccelliy,360,180,10);
			}
			
		//MONTAGNE
		//MONTE PATROCLO
		setlinestyle(0,0,5);
		setcolor(cresta_patroclo);
		line(getmaxx()-1300,getmaxy()/1.5,getmaxx()-900,getmaxy()-700);
		line(getmaxx()-900,getmaxy()-700,getmaxx()-750,getmaxy()/1.5);
		line(getmaxx()-1000,getmaxy()/1.5,getmaxx()-550,getmaxy()/1.5);
		line(getmaxx()-1000,getmaxy()/1.5,getmaxx()-1600,getmaxy()-1000);
		setfillstyle(1,erba);	
		floodfill(getmaxx()-760,getmaxy()/1.5-10,cresta_patroclo);
		line(getmaxx()-900,getmaxy()-700,getmaxx()-550,getmaxy()/1.5);
		setfillstyle(1,terra);	
		floodfill(getmaxx()-590,getmaxy()/1.5-10,cresta_patroclo);
		//MONTE EVEREST SENZA NEVE
		setlinestyle(0,0,5);
		setcolor(orizzonte);
		line(getmaxx()-1900,getmaxy()/1.5,getmaxx()-1600,getmaxy()-1000);
		line(getmaxx()-1600,getmaxy()-1000,getmaxx()-1300,getmaxy()/1.5);
		setfillstyle(1,erba);	
		floodfill(getmaxx()-1700,getmaxy()/1.5-10,orizzonte);
		setcolor(orizzonte);
		line(getmaxx()-1600,getmaxy()-1000,getmaxx()-1000,getmaxy()/1.5);
		setfillstyle(1,terra);	
		floodfill(getmaxx()-1100,getmaxy()/1.5-10,orizzonte);
		
		//ERBA
		setlinestyle(0,0,2);
		setcolor(fili_erba);
		for (int i=0; i<fili;i++){
			int filox=rand()%getmaxx();
			int filoy=rand()%getmaxy()+getmaxy()/1.49;
			int raggiofilo=rand()%20;
			int angolo_min_filo=rand()%1;
			int angolo_max_filo=rand()%90+10;
			arc(filox,filoy,angolo_min_filo,angolo_max_filo,raggiofilo);
		}
		
		//CASINA
		setlinestyle(0,0,5);
		setcolor (mattone);
		int casax=rand()%getmaxx()-580+1000;
		int casay=getmaxy()-230;
		rectangle(casax,casay,casax+380,casay-350);
		setfillstyle(1,stucco);
		floodfill(casax+10,casay-10,mattone);
		//GARAGE
		setcolor (mattone);
		rectangle(casax,casay,casax-320,casay-200);
		setfillstyle(1,stucco);
		floodfill(casax-20,casay-20,mattone);
		//SERRACINESCA
		setcolor(serracinesca);
		rectangle(casax-40,casay,casax-280,casay-170);
		setfillstyle(1,acciaio_inossidabile);
		floodfill(casax-120,casay-150,serracinesca);
		int serracinescayi=casay-140;
		int serracinescay=casay;
		int serracinescaxi=casax-40;
		int serracinescax=casax-280;
		line(serracinescaxi,serracinescayi,serracinescax,serracinescayi);
		for(int i=0;i<4;i++,serracinescayi+=30){
			floodfill(serracinescaxi-10,serracinescay-5,serracinesca);
			line(serracinescaxi,serracinescayi+30,serracinescax,serracinescayi+30);
			setfillstyle(1,acciaio_inossidabile);
			floodfill(serracinescaxi-10,serracinescay-5,serracinesca);
		}
		//FINESTRA
		setcolor (tronco);
		rectangle(casax+40,casay-170,casax+140,casay-270);
		line (casax+90,casay-170,casax+90, casay-270);
		line (casax+40,casay-220,casax+140, casay-220);
		setfillstyle (1,cielo);
		floodfill(casax+50,casay-180,tronco);
		floodfill(casax+50,casay-250,tronco);
		floodfill(casax+135,casay-180,tronco);
		floodfill(casax+135,casay-250,tronco);
		//PORTA
		arc(casax+280,casay-170,360,180,60);
		line(casax+220,casay-170,casax+220,casay);
		line(casax+340,casay-170,casax+340,casay);
		line(casax+220,casay,casax+340,casay);
		setfillstyle (1,legno);
		floodfill(casax+225,casay-5,tronco);
		//MANIGLIA
		setcolor(oro);
		circle(casax+320,casay-90,10);
		setfillstyle(1,ottone);
		floodfill(casax+320,casay-90,oro);
		//TETTO
		setcolor(tronco);
		setcolor(tronco);
		line(casax-20,casay-350,casax+190,casay-490);
		line(casax+400,casay-350,casax+190,casay-490);
		line(casax-20,casay-350,casax+400,casay-350);
		setfillstyle (1,legno);
		floodfill(casax+180,casay-420,tronco);
		//COMIGNOLO
		setcolor(comignolo);
		rectangle(casax+280,casay-400,casax+230,casay-500);
		setfillstyle(1,legno);
		floodfill(casax+270,casay-470,comignolo);
		
		//ALBERO
		//TRONCO
		setlinestyle(0,0,5);
		setcolor(tronco);
		int troncox=rand()%getmaxx()/5;
		int troncoy=rand()%getmaxy()/5+500;
		rectangle(troncox,troncoy-300,troncox+100,troncoy+200);
		setfillstyle(1, legno);
		floodfill(troncox+20,troncoy-1,tronco);
		//CHIOMA
		for (int i=0;i<rami;i++){
			int chiomax=rand()%troncox+troncox/11+100;
			int chiomay=rand()%troncoy/6+troncoy/5+100;
			int raggio=rand()%100+20;
			setcolor(temporaneo);
			circle(chiomax,chiomay,raggio);
			setfillstyle(1,chioma);
			floodfill(chiomax,chiomay,temporaneo);
			setcolor(foglie);
			circle(chiomax,chiomay,raggio);
		}
		
		//STRADA
		setlinestyle(0,0,10);
		setcolor(strisce);
		line(0,getmaxy()-200,getmaxx(),getmaxy());
		setfillstyle(1,asfalto);
		floodfill(1,getmaxy()-100,strisce);
		setlinestyle(1,0,10);
		line(0,getmaxy()-100,getmaxx(),getmaxy()+100);
		setlinestyle(4,0,10);	
	}
	else{
		//TEMA NOTTE
		int erba (COLOR (0,160,0));
		int pioggia (COLOR(0,0,255));
		int fili_erba(COLOR(13,124,59));
		int terra (COLOR(0,140,0));
		int orizzonte (COLOR(0,100,0));
		int cresta_patroclo(COLOR(0,101,0));
		int cielo (COLOR(101,105,149));
		int tronco (COLOR(174,128,83));
		int legno (COLOR(194,148,103));
		int mattone (COLOR(202,142,130));
		int stucco (COLOR(242,152,148));
		int comignolo (COLOR(174,128,82));
		int foglie (COLOR(55,167,74));
		int chioma (COLOR(77,220,78));
		int sole (COLOR(250,250,250));
		int raggi (COLOR(250,250,250));
		int nuvola (COLOR(128,129,124));
		int nuvola_fill(COLOR(147,147,147));
		int luce(COLOR(230,230,0));
		int oro (COLOR(195,154,42));
		int ottone (COLOR(208,155,22));
		int acciaio_inossidabile (COLOR(146,146,146));
		int serracinesca (COLOR(133,133,133));
		int asfalto (COLOR(41,49,51));
		int strisce (COLOR(255,255,255));
		int rami=100;
		int fili=50000;
		int stelle=1000;
		int uccelli=5;
		int nuvole=5;
		int temporaneo(COLOR(0,0,255));

	
		//ORIZZONTE
		setlinestyle(0,0,5);
		setcolor(orizzonte);
		line(0,getmaxy()/1.5,getmaxx(),getmaxy()/1.5);
		
		//TERRA
		setfillstyle(1,terra);
		floodfill(getmaxx()/2,800,orizzonte);
		
		//CIELO
		setfillstyle(1,cielo);
		floodfill(getmaxx()/2,200,orizzonte);
		
		//STELLE
		setlinestyle(0,0,2);
		setcolor(strisce);
		for (int i=0; i<stelle;i++){
			int stellax=rand()%getmaxx();
				int stellay=rand()%getmaxy()/1.51;
				int raggio=2;
				setcolor(temporaneo);
				circle(stellax,stellay,raggio);
				setfillstyle(1,strisce);
				floodfill(stellax,stellay,temporaneo);
				setcolor(strisce);
				circle(stellax,stellay,raggio);
		}
		
		//SOLE
		int solex=rand()%getmaxx();
		int soley=rand()%getmaxy()/3;
		setlinestyle(0,0,20);
		setcolor(raggi);
		circle(solex,soley,100);
		setfillstyle(1,sole);
		floodfill(solex,soley,raggi);
		
		//NUVOLE
		setlinestyle(0,0,5);
		for (int i=0;i<nuvole;i++){
			for(int c=0;c<5;c++){
				int nuvolax=rand()%getmaxx();
				int nuvolay=rand()%getmaxy()/3;
				int raggio=rand()%50+10;
				setcolor(temporaneo);
				circle(nuvolax,nuvolay,raggio);
				setfillstyle(1,nuvola_fill);
				floodfill(nuvolax,nuvolay,temporaneo);
				setcolor(nuvola);
				circle(nuvolax,nuvolay,raggio);
			}
		}
			
		//MONTAGNE
		//MONTE PATROCLO
		setlinestyle(0,0,5);
		setcolor(cresta_patroclo);
		line(getmaxx()-1300,getmaxy()/1.5,getmaxx()-900,getmaxy()-700);
		line(getmaxx()-900,getmaxy()-700,getmaxx()-750,getmaxy()/1.5);
		line(getmaxx()-1000,getmaxy()/1.5,getmaxx()-550,getmaxy()/1.5);
		line(getmaxx()-1000,getmaxy()/1.5,getmaxx()-1600,getmaxy()-1000);
		setfillstyle(1,terra);	
		floodfill(getmaxx()-760,getmaxy()/1.5-10,cresta_patroclo);
		line(getmaxx()-900,getmaxy()-700,getmaxx()-550,getmaxy()/1.5);
		setfillstyle(1,erba);	
		floodfill(getmaxx()-590,getmaxy()/1.5-10,cresta_patroclo);
		//MONTE EVEREST SENZA NEVE
		setlinestyle(0,0,5);
		setcolor(orizzonte);
		line(getmaxx()-1900,getmaxy()/1.5,getmaxx()-1600,getmaxy()-1000);
		line(getmaxx()-1600,getmaxy()-1000,getmaxx()-1300,getmaxy()/1.5);
		setfillstyle(1,terra);	
		floodfill(getmaxx()-1700,getmaxy()/1.5-10,orizzonte);
		setcolor(orizzonte);
		line(getmaxx()-1600,getmaxy()-1000,getmaxx()-1000,getmaxy()/1.5);
		setfillstyle(1,erba);	
		floodfill(getmaxx()-1100,getmaxy()/1.5-10,orizzonte);
		
		//ERBA
		setlinestyle(0,0,2);
		setcolor(fili_erba);
		for (int i=0; i<fili;i++){
			int filox=rand()%getmaxx();
			int filoy=rand()%getmaxy()+getmaxy()/1.49;
			int raggiofilo=rand()%20;
			int angolo_min_filo=rand()%1;
			int angolo_max_filo=rand()%90+10;
			arc(filox,filoy,angolo_min_filo,angolo_max_filo,raggiofilo);
		}
		
		//CASINA
		setlinestyle(0,0,5);
		setcolor (mattone);
		int casax=rand()%getmaxx()-580+1000;
		int casay=getmaxy()-230;
		rectangle(casax,casay,casax+380,casay-350);
		setfillstyle(1,stucco);
		floodfill(casax+10,casay-10,mattone);
		//GARAGE
		setcolor (mattone);
		rectangle(casax,casay,casax-320,casay-200);
		setfillstyle(1,stucco);
		floodfill(casax-20,casay-20,mattone);
		//SERRACINESCA
		setcolor(serracinesca);
		rectangle(casax-40,casay,casax-280,casay-170);
		setfillstyle(1,acciaio_inossidabile);
		floodfill(casax-120,casay-150,serracinesca);
		int serracinescayi=casay-140;
		int serracinescay=casay;
		int serracinescaxi=casax-40;
		int serracinescax=casax-280;
		line(serracinescaxi,serracinescayi,serracinescax,serracinescayi);
		for(int i=0;i<4;i++,serracinescayi+=30){
			floodfill(serracinescaxi-10,serracinescay-5,serracinesca);
			line(serracinescaxi,serracinescayi+30,serracinescax,serracinescayi+30);
			setfillstyle(1,acciaio_inossidabile);
			floodfill(serracinescaxi-10,serracinescay-5,serracinesca);
		}
		//FINESTRA
		setcolor (tronco);
		rectangle(casax+40,casay-170,casax+140,casay-270);
		line (casax+90,casay-170,casax+90, casay-270);
		line (casax+40,casay-220,casax+140, casay-220);
		setfillstyle (1,luce);
		floodfill(casax+50,casay-180,tronco);
		floodfill(casax+50,casay-250,tronco);
		floodfill(casax+135,casay-180,tronco);
		floodfill(casax+135,casay-250,tronco);
		//PORTA
		arc(casax+280,casay-170,360,180,60);
		line(casax+220,casay-170,casax+220,casay);
		line(casax+340,casay-170,casax+340,casay);
		line(casax+220,casay,casax+340,casay);
		setfillstyle (1,legno);
		floodfill(casax+225,casay-5,tronco);
		//MANIGLIA
		setcolor(oro);
		circle(casax+320,casay-90,10);
		setfillstyle(1,ottone);
		floodfill(casax+320,casay-90,oro);
		//TETTO
		setcolor(tronco);
		setcolor(tronco);
		line(casax-20,casay-350,casax+190,casay-490);
		line(casax+400,casay-350,casax+190,casay-490);
		line(casax-20,casay-350,casax+400,casay-350);
		setfillstyle (1,legno);
		floodfill(casax+180,casay-420,tronco);
		//COMIGNOLO
		setcolor(comignolo);
		rectangle(casax+280,casay-400,casax+230,casay-500);
		setfillstyle(1,legno);
		floodfill(casax+270,casay-470,comignolo);
		
		//ALBERO
		//TRONCO
		setlinestyle(0,0,5);
		setcolor(tronco);
		int troncox=rand()%getmaxx()/5;
		int troncoy=rand()%getmaxy()/5+500;
		rectangle(troncox,troncoy-300,troncox+100,troncoy+200);
		setfillstyle(1, legno);
		floodfill(troncox+20,troncoy-1,tronco);
		//CHIOMA
		for (int i=0;i<rami;i++){
			int chiomax=rand()%troncox+troncox/11+100;
			int chiomay=rand()%troncoy/6+troncoy/5+100;
			int raggio=rand()%100+20;
			setcolor(temporaneo);
			circle(chiomax,chiomay,raggio);
			setfillstyle(1,chioma);
			floodfill(chiomax,chiomay,temporaneo);
			setcolor(foglie);
			circle(chiomax,chiomay,raggio);
		}
		
		//STRADA
		setlinestyle(0,0,10);
		setcolor(strisce);
		line(0,getmaxy()-200,getmaxx(),getmaxy());
		setfillstyle(1,asfalto);
		floodfill(1,getmaxy()-100,strisce);
		setlinestyle(1,0,10);
		line(0,getmaxy()-100,getmaxx(),getmaxy()+100);
		setlinestyle(4,0,10);	
	}
	getch();
}
//TO DO:
/* 
*/
//TEST CASES:
//Funziona tutto correttamente anche dopo le modifiche per randomizzare il tutto.
