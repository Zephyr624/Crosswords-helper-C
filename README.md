# Pomocnik-krzyzowkowy-C
Program podający słowa pasujące do podanych znanych liter słowa szukanego
Opis zadania
Celem programu jest wyszukanie w bazie wyrazów, takich, które są zgodne z 
zadanym wzorcem. Przykładowo, zapis: ‘a?z??[e,i,o,u]*’ oznacza wyraz, 
którego pierwszą literą jest ‘a’, druga jest dowolna, trzecią ‘z’, czwarta i piąta 
są dowolne, szósta: ‘e’, ‘i’, ‘o’ lub ‘u’, pozostałe znaki są dowolne oraz dowolna 
może być ich ilość.

Lista dostępnych w programie słów trzymana jest w pliku tekstowym.
Istnieje możliwość wypisania wszystkich dostępnych słów, usuwanie, 
dodawanie oraz ich edycja. Słowa przechowywane są na liście w porządku 
alfabetycznym.

Opis systemu
Użyte biblioteki:
• stdio.h - definiuje podstawowe funkcje wejścia i wyjścia
• Stdlib.h - definiuje funkcje konwersji liczb, alokację pamięci
• String.h - Definiuje funkcje obsługi ciągów znaków
Użyte pliki:
Program wykorzystuje jeden plik tekstowy zawierający bazę wyrazów 
Bazaslow.txt

Funkcje:
• void dodajpoczatek(Baza** head, char* wyrazpodany)
• void wypisz(Baza* head)
• void dodaj(Baza** head, char* wyrazpodany)
• void wyszukaj(Baza** head, char* wyrazpodany)
• void usun(Baza** head, char* wyrazpodany)
• void edytuj(Baza** head, char* wyrazpodany, char* wyrazedycja)
• void zapiszbaza(Baza**head, FILE*file)
