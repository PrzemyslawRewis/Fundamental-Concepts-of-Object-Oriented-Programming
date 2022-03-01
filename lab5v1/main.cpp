/* W liście jednokierunkowej, każdy obiekt poza ostatnim wskazuje
 na kolejny element listy. Następnik dla ostatniego elementu jest 
 ustawiany na NULL (nullptr), co umożliwia sprawdzenie końca listy.

 Zadanie najłatwiej rozwiązać tworząc dwie struktury: Node (węzeł)
 oraz właściwą strukturę MyList, trzymajacą wskaźnik na pierwszy węzeł.

 W zadaniu proszę napisać listę połączoną jednokierunkowo, 
 służącą do przechowywania napisów (łańcuchów znaków).

 Napisy muszą być kopiowane do alokowanej pamięci. 
 Należy zadbać o zwolnienie pamięci przy czyszczeniu listy.

 Niektóre z funkcji nie zmieniają listy (np. print)
  i z tego powodu powinny odbierać stały wskaźnik do struktury MyList.
*/

#include "MyList.h"
#include <cstring>
#include <iostream>

int main() {
    std::cout << "--- Pierwsza lista ---" << std::endl;
    MyList testList;
    init(&testList);
    
    ////////////////////////////////////////////////
    char buffer[50];
    strcpy(buffer, "Ala");
    add(&testList, buffer);
    strcpy(buffer, "ma");
    add(&testList, buffer);
    
    add(&testList, "kota");

    const MyList* lptr = &testList;

    std::cout << lptr->head->data << std::endl;
    std::cout << lptr->head->next->data << std::endl;
    
    #ifndef BASIC
      insertAfter(&testList,"Ala","Nowak");
      std::cout << find(lptr,"Nowak")->data <<std::endl;
      insertAfter(&testList,"kota","Puszka");
      std::cout << last(lptr)->data << std::endl;
    #endif
  
    ////////////////////////////////////////////////
    std::cout << "Czy lista jest pusta? " 
              << (empty(lptr)? "TAK" : "NIE") << std::endl;
    std::cout << "Lista zawiera:" << std::endl;
    print(lptr);
    
    ////////////////////////////////////////////////
    std::cout << "\n--- Druga lista ---" << std::endl;
    MyList drugaLista;
    init(&drugaLista);
    strcpy(buffer, "Zadanie jest");
    add(&drugaLista, buffer);
    strcpy(buffer, "latwe.");
    add(&drugaLista, buffer);
    print(&drugaLista);

    ////////////////////////////////////////////////
    std::cout << "\n--- Czyszczenie ---" << std::endl;
    clear(&testList);
    std::cout << "Czy teraz lista jest pusta? " 
              << (empty(lptr)? "TAK" : "NIE") << std::endl;
              
    std::cout << "Probujemy wypisac pusta liste. " << std::endl;
    print(lptr);
    
    ////////////////////////////////////////////////
    print(&drugaLista);
    std::cout << std::endl;
    clear(&drugaLista);
    
    clear(&drugaLista);
    
}


/*oczekiwany output

--- Pierwsza lista ---
Ala
ma
Nowak	// brak w BASIC
Puszka	// brak w BASIC
Czy lista jest pusta? NIE
Lista zawiera:
Ala Nowak ma kota Puszka //Ala ma kota
--- Druga lista ---
Zadanie jest latwe. 
--- Czyszczenie ---
Czy teraz lista jest pusta? TAK
Probujemy wypisac pusta liste. 
Zadanie jest latwe. 
*/
