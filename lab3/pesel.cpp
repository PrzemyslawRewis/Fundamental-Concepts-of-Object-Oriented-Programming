#include "pesel.h"

using namespace std;

const int tablica_wag[10]={1,3,7,9,1,3,7,9,1,3};
const int dni_miesiaca[12]={31,28,31,30,31,30,31,31,30,31,30,31};

bool leapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
      }

bool PeselValidator(const char* Tpesel, int PESEL[])
{
   
    if(strlen(Tpesel)==11)
    {
        for (int i=0;i<11;i++)
        {
           PESEL[i]=static_cast<int>(Tpesel[i])-48;
        }

        if(PESEL[0]*10+PESEL[1]>0&&PESEL[0]*10+PESEL[1]<99)
        {    
           
            if(getCtrlNumber(PESEL)==PESEL[10])
            {
                        int rok= getYear(PESEL);
                        if(rok>=1900&&rok<=1999)
                        {
                            if(PESEL[2]==1||PESEL[2]==0)
                            {
                                int miesiac=getMonth(PESEL);
                                if (miesiac!=2)
                                {
                                    if(getDay(PESEL)<=dni_miesiaca[miesiac-1]) 
                                        return true;
                                    else 
                                        return false;  
                                }
                                else
                                {
                                    if(leapYear(rok)==true)
                                        {if(getDay(PESEL)<=29)
                                            return true;
                                        else
                                            return false;}
                                    else 
                                    {
                                        if(getDay(PESEL)<=28)
                                            return true;
                                        else
                                            return false;
                                    }
                                              

                                }
                                
                            }
                            else
                            return false;
                        }
                        else if(rok>=2000&&rok<=2099)
                        {
                            if(PESEL[2]==2||PESEL[2]==3)
                            {
                                 int miesiac=getMonth(PESEL);
                                if (miesiac!=2)
                                {
                                    if(getDay(PESEL)<=dni_miesiaca[miesiac-1]) 
                                        return true;
                                    else 
                                        return false;  
                                }
                                else
                                {
                                    if(leapYear(rok)==true)
                                        {if(getDay(PESEL)<=29)
                                            return true;
                                        else
                                            return false;}
                                    else 
                                    {
                                        if(getDay(PESEL)<=28)
                                            return true;
                                        else
                                            return false;
                                    }
                                              

                                }
                            }
                            else
                            return false;
                        }
                        else
                        {
                            if(PESEL[2]==4||PESEL[2]==5)
                            {
                                 int miesiac=getMonth(PESEL);
                                if (miesiac!=2)
                                {
                                    if(getDay(PESEL)<=dni_miesiaca[miesiac-1]) 
                                        return true;
                                    else 
                                        return false;  
                                }
                                else
                                {
                                    if(leapYear(rok)==true)
                                        {if(getDay(PESEL)<=29)
                                            return true;
                                        else
                                            return false;}
                                    else 
                                    {
                                        if(getDay(PESEL)<=28)
                                            return true;
                                        else
                                            return false;
                                    }
                                              

                                } 
                            }
                            else
                            return false;
                        }
             }   
            else
                return false;


        }
        else
            return false;

     
    }


    else
    {
        return false;
    }

    

}
void printPesel(int PESEL[])
{
    for (int i=0 ;i<11;i++)
    {
        cout<<PESEL[i];
    }

}
int getCtrlNumber(int PESEL[])
{
    int liczba_kontrolna=0;
    for(int i =0;i<10;i++)
    {
        liczba_kontrolna+=PESEL[i]*tablica_wag[i];
    }
    int wynik=liczba_kontrolna%10;
    wynik=10-wynik;
    wynik=wynik%10;
    return wynik;
          

}
int getDay(int PESEL[])
{
    return 10*PESEL[4]+PESEL[5];


}
int getMonth(int PESEL[])
{
    int rok=getYear(PESEL);
    if(rok>=1900&&rok<=1999)
    {
        return (10*PESEL[2]+PESEL[3]);
    }
    else if(rok>=2000&&rok<=2099)
    {
        return (10*(PESEL[2]-2)+PESEL[3]);
    }
    else 
    {
        return (10*(PESEL[2]-4)+PESEL[3]);
    }
  
}
int getYear(int PESEL[])
{
    

    if(PESEL[2]==1||PESEL[2]==0)
    {
        return (1900+10*PESEL[0]+PESEL[1]);
    }
    else if (PESEL[2]==2||PESEL[2]==3)
    {
        return (2000+(10*PESEL[0])+PESEL[1]);
    }
    else 
    {
        return (2100+(10*PESEL[0])+PESEL[1]);
    }
  
}
