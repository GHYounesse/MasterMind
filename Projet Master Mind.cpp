#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//-----------------------------Declarations------------------------------------------------------
int code1[5];/*le code  du joueur 1(niveau 1 et 2)*/
int code2[5];/*le code  du joueur 2(niveau 1 et 2)*/
int copie[5];/*l'outil du comparaison (niveau 1 et 2)*/
/*des variables concernant la fonction joker*/
int rang;
int chiffrejoker;
int nbr_tentative=0;/*Le nombre des tentatives*/
/* Des compteurs pour differentes conditions*/
int compteurjoker=0;/*le compteur qui assure que l'utilisateur a un seul joker*/ 
char caracterejoker;/*la caractere de votre rang choisi par vous qui est affichee par le joker */
int compteur;
int compteur2;
int compteur3;
char text[6];/*le code  du joueur 1(niveau 3)*/
char text2[6];/*le code  du joueur 2(niveau 3)*/
char copietext[6];/*l'outil du comparaison (niveau 3)*/
int n;/* la taille du les codes (niveau 3)*/
char s;/*la caractere pour le choix de jouer a nouveau*/
int compteurjeu;
char c;/*la caractere pour choisir le niveau*/
int compteurreponse;
//-----------------------------fonction intro de le jeu------------------------------------------------------------
intro()
{	
printf("\t\t\t\t  Master Mind\n");
printf("\t\t\t\tChoix du Niveau\n");
printf("Tapez 'D'ou 'd'pour Jouer NIVEAU 1(D%cbutant):tous les chiffres du codes sont distincts.\n",130);
printf("Tapez 'E'ou 'e'pour Jouer NIVEAU 2(Expert) : les chiffres du codes peuvent se r%cp%cter.\n",130,130);
printf("Tapez 'A'ou 'a'pour Jouer NIVEAU 3(Avanc%c): les codes peut %ctre une combinaison de chiffres (entre 0 et 9)et vides.\n",130,136);
}
//-----------------------------fonction saisie des codes(niveau 1 et 2)------------------------------------------------------
void saisie(int T[])
{int i;
 for ( i=0 ; i<5 ;i++) 
 {
  printf ("le chiffre du rang %d = ",i+1);
  scanf ("%d",&T[i]);
 }
 puts(" ");
 printf("Le code saisie :");
 for (i=0 ; i<5 ;i++){printf("%d",T[i]); }
 printf ("\n");	
 printf ("\n");
 for (i=0 ; i<5 ;i++){copie[i]=code1[i];}
}
//-----------------------------fonction saisie des codes(niveau 3)------------------------------------------------------
saisietext(char T[])
{	
 gets(T);
 n=strlen(T);        
 puts(" ");
 printf ("le code saisie :");
 puts(T);
 for (int i=0 ; i<6 ;i++){copietext[i]=text[i];} 		
}
//--------------------- la fonction de les regles du niveau 1*/---------------------------------------------------------
niveau()
{
		 printf ("Pouvez-vous trouver ma combinaison de 5 distincts chiffres \n");
	     printf ("[chiffres entre 0 et 9 sans r%cp%ctitions] \n",130,130);
	     printf ("En moins de 20 tentatives? \n");
	     printf ("Vous avez la possibilit%c d'utiliser votre seul joker apr%cs la tentavive 10 .[chiffres entre 0 et 9 sans r%cp%ctitions] \n",130,130,130,130);
	     printf ("Le Joker vous permet de trouver un chiffre bien plac%c d'un rang de votre choix .\n",130);	
}
//--------------------- la fonction de les regles du niveau 2----------------------------------------------------------------------
niveau2()
{
		 printf ("Pouvez-vous trouver ma combinaison de 5 chiffres \n");
	     printf ("[chiffres entre 0 et 9 ] \n");
	     printf ("En moins de 20 tentatives? \n");
	     printf ("Vous avez la possibilit%c d'utiliser votre seul joker apr%cs la tentavive 10 .[chiffres entre 0 et 9 ]. \n",130,130);
	     printf ("Le Joker vous permet de trouver un chiffre bien plac%c d'un rang de votre choix .\n",130);	
}
//--------------------- la fonction de les regles du niveau 3----------------------------------------------------------------------
niveau3()
{
		 printf ("Pouvez-vous trouver ma combinaison de taille 5 (nombres,vides). \n");
	     printf ("[chiffres (entre 0 et 9),vides ] \n");
	     printf ("En moins de 20 tentatives? \n");
	     printf ("vous avez la possibilit%c d'utiliser votre seul joker apr%cs la tentavive 10 . [chiffres (entre 0 et 9),vides ] \n",130,130);
	     printf ("Le Joker vous permet de trouver un chiffre ou caract%cr%c bien plac%c d'un rang de votre choix .\n",130,130,130);	    	
}
//------------------------------fonction bienplace (niveau 1 et 2)--------------------------------------------------------
int nb_bien_place(int T1[],int T2[])
{
	int bienplace=0;
    for(int i=0;i<5;i++)
    {
    	if(T2[i]==T1[i])
        {
        	bienplace++;
            T2[i]=-1;
        }
     }
     for(int i=0;i<5;i++) copie[i]=T2[i];
                     return bienplace;
}
//------------------------------------fonction bienplace (niveau 3)---------------------------------------------------------------
int nbbien_place(char T1[],char T2[])
{
	int bienplace=0;
    for(int i=0;i<5;i++)
    {
    	if(T2[i]==T1[i])
        {
        	bienplace++;
            T2[i]=-1;
        }
     }
     for(int i=0;i<5;i++) copietext[i]=T2[i];
                     return bienplace;
}
//----------------------------------fonction position (niveau 1 et 2)-------------------------------------------------------
int position(int valeur,int T1[])
{
 int p=-1 ;
   for(int i=0;i<5;i++)
    {
    	if(T1[i]==valeur)

         { p=i;break;}

    }
   return p;
}
//----------------------------------fonction position (niveau 3)-----------------------------------------------------------------
int position2(int valeur,char T1[])
{
 int p=-1 ;
   for(int i=0;i<5;i++)
    {
    	if(T1[i]==valeur)

         { p=i;break;}
    }
   return p;
}
//-----------------------------------fonction malplace (niveau 1 et 2)--------------------------------------------------------------
int trouver_malplace()
{
 int d=0 ;
 int malplace=0;
   for(int i=0;i<5;i++)
    {
      if (copie[i]!=(-1))
      {
      		d=position(code2[i],copie);
    		if(d!=(-1)) { copie[d]=0;}
       }
    }
    for(int i=0;i<5;i++)
    {
      if (copie[i]==0) malplace++;
    }
   return malplace;
}
//----------------------------------------fonction malplace (niveau 3)-----------------------------------------------------------
int trouver_malplace2()
{
 int d=0 ;
 int malplace=0;
   for(int i=0;i<5;i++)
    {
      if (copietext[i]!=(-1))
      {
      		d=position2(text2[i],copietext);
    		if(d!=(-1)) { copietext[d]=0;}
       }
       
    }
    for(int i=0;i<5;i++)
    {
      if (copietext[i]==0) malplace++;
    }
   return malplace;
}
//------------------------------------Fonction joker(Niveau 1 et 2)------------------------------------------------------------
f_joker()
{
	         rang=0;
	         chiffrejoker=0; 
	    	 /*boucle du Joker*/
		      if (nbr_tentative>=10 && compteurjoker==0)
	           { if(nbr_tentative==10)
	             {
				  printf("Il est possible maintenant d'utliser votre joker\n");
				  printf ("Joker! Afficher le rang du chiffre de votre choix \n");
	         	  printf ("Exemple : 2 a le rang 4 du code XXX2X \n");
	         	  printf("!!ATTENTION!! Vous perdrez 3 tentatives si le joker est activ%c\n",130);
				 }
	         	 printf("Tapez 'j' pour utiliser votre joker sinon tapez autrement:\n");
	         	 if('j'==getch())
	         	  {printf("Joker Activ%c!",130);
				   printf ("Entrez le rang d'un chiffre (entre 1 et 5): \n");
				   scanf ("%d",&rang);
				      while((rang<1) || (rang>5))
					  {if( (rang>5)|| (rang<1) )
					    {
					     printf("le rang saisie n'a pas entre 1 et 5");
				  	     printf ("Entrez le rang d'un chiffre (entre 1 et 5): \n");
				  	     scanf ("%d",&rang);	
						}
				      }
	         	  printf ("\n");
				  chiffrejoker=code1[rang-1];
	         	  printf ("\n");
	         	  printf ("Le code %c trouver : ",133);
	         	  if(rang==1)
	         	  {
				   printf("%dXXXX",chiffrejoker);
				  }
	         	  else if(rang==2)
	         	  {
				   printf("X%dXXX",chiffrejoker);
				  }
	         	  else if(rang==3)
	         	  {
				   printf("XX%dXX",chiffrejoker);
				  }
	         	  else if(rang==4)
	         	  {
				   printf("XXX%dX",chiffrejoker);
				  }
	         	  else if(rang==5)
	         	  {
				   printf("XXXX%d",chiffrejoker);
				  }
	         	  printf ("\n");
	         	  
	              nbr_tentative=nbr_tentative+3;compteurjoker=1;	         		
				 }
			    }
			    if(nbr_tentative<20)
			 {printf(" %d essaies restants\n",20-nbr_tentative);
			 }
	         
}
//-------------------------------Fonction Joker(niveau 3)----------------------------------------
f_joker2()
{
	         rang=0;
	    	 /*boucle du Joker*/
		      if (nbr_tentative>=10 && compteurjoker==0)
	           { if(nbr_tentative==10)
	             {
				  printf("Il est possible maintenant d'utliser votre joker\n");
				  printf ("Joker! Afficher le rang du chiffre de votre choix \n");
	         	  printf ("Exemple : ESPACE a le rang 4 du code XXX X \n");
	         	  printf("!!ATTENTION!! Vous perdrez 3 tentatives si le joker est activ%c\n",130);
				 }
	         	 printf("Tapez 'j' pour utiliser votre joker sinon tapez autrement:\n");
	         	 
	         	 if('j'==getch())
	         	  {printf("Joker Activ%c!",130);
				   printf ("Entrez le rang d'un chiffre (entre 1 et 5): \n");
				   scanf ("%d",&rang);
				    
				      while((rang<1) || (rang>5))
					  {if( (rang>5)|| (rang<1) )
					    {
					     printf("le rang saisie n'a pas entre 1 et 5");
				  	     printf ("Entrez le rang d'un chiffre (entre 1 et 5): \n");
				  	     scanf ("%d",&rang);	
						}  
				      }
				  
	         	  printf ("\n");
				  caracterejoker=text[rang-1];
	         	  printf ("\n");
	         	  printf ("Le code %c trouver : ",133);
	         	  if(rang==1)
	         	  {
				   printf("%cXXXX",caracterejoker);
				  }
	         	  else if(rang==2)
	         	  {
				   printf("X%cXXX",caracterejoker);
				  }
	         	  else if(rang==3)
	         	  {
				   printf("XX%cXX",caracterejoker);
				  }
	         	  else if(rang==4)
	         	  {
				   printf("XXX%cX",caracterejoker);
				  }
	         	  else if(rang==5)
	         	  {
				   printf("XXXX%c",caracterejoker);
				  }
	         	  printf ("\n");	         	  
	              nbr_tentative=nbr_tentative+3;compteurjoker=1;	         		
				 }
			    }
			 if(nbr_tentative<20)
			 {printf(" %d essaies restants\n",20-nbr_tentative);
			 }
	         
}
//----------------------------------condition 1 des codes (niveau 1 )-----------------------------------------------------
f_condition1(int T1[])
{	
	for(int i=0;i<5;i++)
		   { for(int j=0;j<5;j++)
		      {
		      	if ((i!=j)&&(T1[i]==T1[j])) 
		      	{
		      	 printf("Il y'a des chiffres qui se r%cp%ctent.\n",130,130);
		      	 printf("Rentrez votre code :\n");
	             saisie(T1);
	              compteur=1;		
				 }
			   }

		    }
}
//------------------------------condition 2 des codes  (niveau 1 et 2)-------------------------------------------------
f_condition2(int T1[])
{
	for(int i=0;i<5;i++)
			 {if((T1[i]<0) ||(T1[i]>9)) 
		      	{
				 if(( (T1[i]>9)|| (T1[i]<0)) )
				 {
					 printf(" Entrez  des chiffres entre 0 et 9.\n");
					 printf("Rentrez votre code :\n");
	                saisie(T1);
	                compteur2=1;							 	
				 }  	
				}	
			 }		
}
//---------------------------------------Condition des codes  (niveau 3)---------------------------------------------------
fcondition3(char T1[])
{ 
  if(n!=5)
  {puts("Il faut tapez une chaine de taille 5");
   saisietext(T1);
   compteur3=1;
  }		
}
//--------------------------------------------boucle <Play Again>(niveau 1 et 2)--------------------------------------------------------------------
playagain()
{
do
{compteurreponse=0;

 printf("Tu veux jouer %c nouveau ?\n",133);
 printf("Si tu veux,Tapez 'O'ou'o'\n");
 printf("Sinon,Tapez 'N'ou'n'\n");
 s=getchar();
 s=getchar();
 if((s=='O') ||(s=='o'))
 {
  compteurjeu=1;
  nbr_tentative=0;
  compteurjoker=0;
 }
 else if((s=='N') ||(s=='n'))
 {
  compteurreponse=0;
  printf("\t\t\t\t Thanks for Playing\n");
 }
 else
 {
 	compteurreponse=1;
 }
 }while(compteurreponse==1);
  s=getchar();	
}
//--------------------------------------------boucle <Play Again> (niveau 3)--------------------------------------------------------------------
playagainv3()
{
 
do
{compteurreponse=0;
 
 printf("Tu veux jouer %c nouveau ?\n",133);
 printf("Si tu veux,Tapez 'O'ou'o'\n");
 printf("Sinon,Tapez 'N'ou'n'\n");
 s=getchar();
 if((s=='O') ||(s=='o'))
 {
  compteurjeu=1;
  nbr_tentative=0;
  compteurjoker=0;
 }
 else if((s=='N') ||(s=='n'))
 {
  compteurreponse=0;
  printf("\t\t\t\t Thanks for Playing\n");
 }
 else
 {
 	compteurreponse=1;
 }
 }while(compteurreponse==1);
  s=getchar();	
}
//**************************************Debut du programme**************************************************
main()
{
int a=0,b=0;
int k=0;
do
{
 compteurjeu=0;
 intro();
 c=getchar();	
//----------------------------------------Niveau 1-------------------------------------------------------
  if((c=='D')||(c=='d'))
     {printf ("\t\t\t\t  NIVEAU 1(D%cbutant) : \n",130);
       printf ("Veuillez entrer le code %c trouver : \n",133);
       saisie(code1);
       /*les conditions du repetitions ou l'intervalle des chiffres du code1*/
        do
        {
         compteur=0;
         compteur2=0;
         f_condition1(code1);
		 f_condition2(code1);
		}while((compteur==1)||(compteur2==1));
	    niveau();
	    do 
	    {    f_joker();
	         printf ("\n");
	         if(nbr_tentative<20)
			 {
			 	printf ("Votre proposition? \n");
			    saisie(code2);
			 /*les conditions du repetitions ou l'intervalle des chiffres du code2*/
			    do
                {
                   compteur=0;
                   compteur2=0;
                   f_condition1(code2);
		           f_condition2(code2);
		        }while( (compteur==1) || (compteur2==1));
			   a=nb_bien_place(code2,copie);
			   b=trouver_malplace();
			 	
			 }
		     
		     if(a==5) 
	          {
	        	printf ("\t\t\tBravo! Vous avez trouv%c en %d tentatives \n",130,nbr_tentative+1);
	        	printf("\n");
				 break;	
	          }
		     else 
		      {if(nbr_tentative<20)
			   {
			   	printf ("bien place = %d\n",a);
	     		printf ("mal place = %d\n",b);
				} 
				
			  }
	    nbr_tentative++;	
		}	 
		while((nbr_tentative<20)&&a<5);
	     if ((nbr_tentative>=20)||(k=0))
		 {
		  printf ("\t\t\tGAME OVER GOOD LUCK NEXT TIME \n");
		  printf("\n");
		 }
		playagain();
	 }	
//-----------------------------------Niveau 2-------------------------------------------------------
else if((c=='E')||(c=='e'))
 {
  printf ("\t\t\t\t NIVEAU 2(Expert) : \n");
       printf ("Veuillez entrer le code %c trouver : \n",133);
       saisie(code1);
        do
        {
         compteur2=0;
         f_condition2(code1);
		}while(compteur2==1);
	    niveau2();
	    do 
	    {    f_joker();
	         if(nbr_tentative<20)
	         {
	         	printf ("\n");
		     printf ("Votre proposition? \n");
			 saisie(code2);
			 
			 
			 do
               {
                compteur2=0;
                f_condition2(code2);
		       }while(compteur2==1);
 		       a=nb_bien_place(code2,copie);
 		       b=trouver_malplace();
		    }
 		if(a==5) 
	        {
	        	 printf ("\t\t\tBravo! Vous avez trouve en %d tentatives \n",nbr_tentative+1);
	        	 printf("\n");
	        	 k=1;
				 break;	
			} else 
			{if(nbr_tentative<20)
			 {
			 	printf("bien place =    %d\n",a);
 	    	    printf("mal place =    %d\n",b);
			 }
						
			}
      nbr_tentative++;
    }while ((nbr_tentative<20)&&(a<5));
 	if ((nbr_tentative>=20)||(k=0))
		 {
		  printf ("\t\t\tGAME OVER GOOD LUCK NEXT TIME \n");
		  printf("\n");
		 }
 	playagain();
}
//-------------------------------------Niveau 3--------------------------------------------------------------
else if((c=='A')||(c=='a'))
{
	printf ("\t\t\t\t NIVEAU 3(Avanc%c) : \n",130);
	   /* cette  gets() ne fonctionne pas*/
	   /*sa role :etre ignoree par le programme et entrez directement dans la boucle suivante*/
	   printf ("Veuillez entrer le code %c trouver : \n",133);
        gets(text);
        saisietext(text);
        do
        {
         compteur3=0;
         fcondition3(text);
		}while(compteur3==1);    
	    niveau3();
	    do 
	    {    f_joker2();
	         if(nbr_tentative<20)
	         {
	         	
	         	
			
	         printf ("\n");
		     printf ("Votre proposition? \n");
			 saisietext(text2);
			do
            {
             compteur3=0;
             fcondition3(text2);
		     }while(compteur3==1);
 		      a=nbbien_place(text2,copietext);
 		      b=trouver_malplace2();
		    }
 		if(a==5) 
	        {
	        	 printf ("\t\t\tBravo! Vous avez trouve en %d tentatives \n",nbr_tentative+1);
	        	 printf("\n");
	        	 k=1;
				 break;	
			} else 
			{if(nbr_tentative<20)
		      {
		      	printf("bien place =    %d\n",a);
 	    	   printf("mal place =    %d\n",b);
			  }
						
			}
      nbr_tentative++;
    }while ((nbr_tentative<20)&&(a<5));
 	if ((nbr_tentative>=20)||(k=0))
		 {
		  printf ("\t\t\tGAME OVER GOOD LUCK NEXT TIME \n");
		  printf("\n");
		 }
    playagainv3();
}
	
//----------------------------------------------------------------------------------------------
else 
{
printf("il faut tapez les  touches du clavier propos%ces pour jouer le jeu\n",130);
printf("\n");
playagain();
}
}while(compteurjeu==1);
return 0;
}
	

	
	
	
	

