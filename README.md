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

Dokładny opis funkcji wraz z kodem źródłowym:
Usuwanie słowa z bazy:
Funkcja otrzymuje adres listy oraz wyrazy które należy usunąć, następnie 
przeszukuje listę do napotkania takiego samego wyrazu i go usuwa.
void usun(Baza** head, char* wyrazpodany) 
{
Baza* current = *head;
Baza* tmp;
if (strcmp(current->slowobaza, wyrazpodany) == 0)
{
 *head = current->next;
free(current);
return;
}
while (current->next!=NULL)
{
tmp = current->next;
if (strcmp(current->next->slowobaza, wyrazpodany) == 0)
{
current->next = tmp->next;
free(tmp);
}
else
{
current = current->next;
}
}
}
Edytowanie słowa z bazy:
Funkcja otrzymuje adres listy, wyraz który mamy zamiar zmienić, oraz wyraz 
który docelowo ma go zastąpić, następnie przeszukuje listę do napotkania 
zamienianego wyrazu i zamienia go na wyraz docelowy. Jeśli wyraz docelowy 
jest już w bazie zamiana nie nastąpi, a użytkownik zostanie poinformowany o 
tym poprzez komunikat.
void edytuj(Baza** head, char* wyrazpodany, char* wyrazedycja)
{
Baza* current=*head;
 while (current != NULL)
 {
 if(strcoll(wyrazedycja,current->slowobaza)==0)
 {
 printf("wyraz jest juz w bazie\n");
 return;
}
current = current->next;
 }
 current = *head;
while (current != NULL)
{
if (strcmp(current->slowobaza, wyrazpodany) == 0)
{
strcpy(current->slowobaza , wyrazedycja);
}
else
{
current = current->next;
}
}
}
Wypisanie wszystkich słów z bazy:
Funkcja otrzymuje adres listy, następnie sprawdza czy baza nie jest pusta. Jeśli 
jest to otrzymamy komunikat informujący o tym, a jeśli zawiera jakieś słowa to 
je wyświetla na ekran.
void wypisz(Baza* head)
{
if (head == NULL) printf("Baza jest pusta\n");
else
{
Baza* current = head;
do {
 printf("%s", current->slowobaza);
 printf("\n");
 current = current->next;
} while (current != NULL);
}
}
Zapisanie edytowanej bazy do pliku:
Funkcja otrzymuje adres listy oraz pliku tekstowego, następnie zapisuje listę do 
tego pliku.
void zapiszbaza(Baza**head,FILE*file)
{
 Baza* current=*head;
while (current != NULL)
 {
 fprintf(file,"%s\n",current->slowobaza);
 current=current->next;
 }
}
Dodawanie słów do listy:
Funkcja otrzymuje adres listy oraz podany wyraz, następnie sprawdza czy to 
nie będzie pierwszy wyraz na liście, jeśli tak to wywołuje funkcje 
dodajpoczatek(), jeśli nie to sprawdza czy wyraz nie znajduje się już na liście. 
Jeśli nie to dodaje wyraz w odpowiednie miejsce na liście tak, aby zachować 
kolejność alfabetyczną.
void dodaj(Baza** head, char* wyrazpodany)
{
Baza* current = (Baza*)malloc(sizeof(Baza));
strcpy(current->slowobaza , wyrazpodany);
current->next = NULL;
if (*head == NULL)
{
dodajpoczatek(head, wyrazpodany);
 return; //head;
}
Baza* tmp = *head;
Baza* pop = NULL;
while (tmp != NULL)
{
 if(strcoll(wyrazpodany,tmp->slowobaza)==0)
 {
 printf("wyraz jest juz w bazie");
 return;
}
 if(strcoll(wyrazpodany,tmp->slowobaza)>0)
 {
 pop=tmp;
 tmp = tmp->next;
}else
 {
 if(pop==NULL)
 {
 current->next = *head;
 *head = current;
 }else
 {
 pop->next=current;
 current->next=tmp;
 }
 break;
 }
}
if(!tmp)
 {
pop->next=current;
 }
return; //head;
}
Dodanie słowa na początek listy:
Funkcja otrzymuje adres listy, oraz wyraz do dodania na początek listy.
void dodajpoczatek(Baza** head, char* wyrazpodany)
{
Baza* current;
current = (Baza*)malloc(sizeof(Baza));
strcpy(current->slowobaza, wyrazpodany);
current->next = *head;
*head = current;
return; 
}
Wypisanie słów z bazy na podstawie wzorca:
Funkcja otrzymuje adres listy i oraz wzorzec szukanego wyrazu, następnie na 
podstawie wzorca przeszukuje listę wyrazów i znajduje słowa w których te 
same litery wzorca występują na tych samych pozycjach co słów bazy. 
void wyszukaj(Baza** head, char* wyrazpodany)
{
 char slowo[50];
Baza* current=*head;
int j = 0;
int temp = 0;
int test=0;
while(current!=NULL)
{
 for (int i = 0; i < strlen(wyrazpodany); i)
 {
 if(current==NULL)
 {
 break;
 }
 if (wyrazpodany[strlen(wyrazpodany)-1]!='*')
 {
 if(strlen(current->slowobaza)>strlen(wyrazpodany))
 {
 i = 0;
 j=0;
 current = current->next;
 continue;
 }
 }
 if(strlen(current->slowobaza)<strlen(wyrazpodany))
 {
 i = 0;
 j=0;
 current = current->next;
 continue;
 }
 if (wyrazpodany[i + j] == '*') 
 { 
 strcpy(slowo,current->slowobaza);
 printf("%s\n",slowo);
 current = current->next;
 i=0;
 j=0;
 }
 if (wyrazpodany[i + j] == '?')
 {
 i++;
 if ((i+j)==strlen(wyrazpodany)) 
 {
 strcpy(slowo,current->slowobaza);
 printf("%s\n",slowo);
 current = current->next;
 i=0;
 j=0;
 }
 }else
 if (wyrazpodany[i + j] == '[') 
 {
 for (j; wyrazpodany[i+j] != ']'; j++)
 {
 if (wyrazpodany[j+i] == current->slowobaza[i])
 {
 i++;
 }
 if ((i+j)==strlen(wyrazpodany)) 
 {
 strcpy(slowo,current->slowobaza);
 current = current->next;
 i=0;
 j=0;
 }
 }
 j++;
 }else
 if (wyrazpodany[i + j] == current->slowobaza[i]) 
 {
 i++;
 if ((i+j)==strlen(wyrazpodany)) 
 {
 strcpy(slowo,current->slowobaza);
 printf("%s\n",slowo);
 current = current->next;
 i=0;
 j=0;
 }
 }else
 if ((i+j)==strlen(wyrazpodany)) 
 {
 strcpy(slowo,current->slowobaza);
 printf("%s\n",slowo);
 current = current->next;
 i=0;
 j=0;
 }else
 {
 i = 0;
 j=0;
 current = current->next;
 }
 }
}
}
Funkcja sterująca main:
Funkcja otwiera plik tekstowy Bazaslow.txt i wczytuje z niego słowa, które 
umieszcza na liście. Jeśli pliku nie uda się otworzyć otrzymamy odpowiedni 
komunikat na ekranie. Następnie na ekran wyświetla się menu użytkownika 
zachęcające użytkownika do wybrania opcji którą operację ma wykonać 
program. Program jest również zabezpieczony przed podaniem nieprawidłowej 
opcji, a jego zamknięcie następuje również poprzez stosowny wybór.
int main()
{
Baza* head;
head = NULL;
int f = 0;
int n = 10;
char wyrazpodany[50];
char wyrazedycja[50];
char zpliku[50];
FILE* file;
file=fopen( "Bazaslow.txt", "r");
if (file == NULL)
{
 printf("blad otwarcia pliku");
}
while (fscanf(file, "%s", zpliku) >0)
{
dodaj(&head, zpliku); //
}
 fclose(file);
 FILE* plik;
while (n != 0)
{
printf("\nwybierz co chcesz zrobic\n");
printf("1. Wyszukaj wyrazy pasujace do podanych znakow\n");
printf("2. Dodac nowe slowo do Bazy\n");
printf("3. Usunac wybrane slowo z Bazy\n");
printf("4. Edytowac wybrane slowo w Bazie\n");
printf("5. wypisac wszystkie slowa\n");
printf("0. Zapisac edytowana i ulozna alfabetycznie baze oraz Zakonczyc program\n");
scanf("%d", &n);
printf("\n");
switch (n)
{
case 0:
 plik=fopen( "Bazaslow.txt", "w");
 if (plik == NULL)
 {
 printf("blad otwarcia pliku");
 }
 zapiszbaza(&head,file);
return 0;
break;
 case 1:
 printf("podaj znane znaki w miejsce nieznanych wpisz '?' w przypadku kilku 
mozliwych podaj je w nawiasie kwadratowym'['']' \n");
 scanf("%s", wyrazpodany);
 wyszukaj(&head, wyrazpodany);
 break;
case 2:
printf("podaj slowo ktore chcesz dodac do Bazy \n");
scanf("%s", wyrazpodany);
dodaj(&head, wyrazpodany);
break;
 case 3:
 printf("podaj slowo ktore chcesz usunac z Bazy \n");
 scanf("%s", wyrazpodany);
 usun(&head, wyrazpodany);
 break;
 case 4:
 printf("podaj slowo ktore chcesz edytowac \n");
 scanf("%s", wyrazpodany);
 printf("podaj jak podane slowo ma wygladac po edycji \n");
 scanf("%s", wyrazedycja);
 edytuj(&head, wyrazpodany, wyrazedycja);
 printf("Jesli wyraz po edycji powinien znajdowac sie na innej pozycji w Bazie biorac 
pod uwage porzadek alfabetyczny zostanie tam umieszczonyn po zapisaniu i ponownym 
uruchomieniu programu \n");
 break;
case 5:
wypisz(head);
break;
 default:
 printf("Podaj wlasciwa opcje.\n");
 //scanf("%d", &n);
 break;
}
}
getchar();
printf("\nWcisnij \"ENTER\" aby kontynuowac\n");
 getchar();
 system("cls");
}
Lista słów:
typedef struct Baza
{
char slowobaza[50];
struct Baza* next; //nastepny element
} Baza;
Instrukcja użytkownika
Instrukcja korzystania z programu: 
Użytkownik dostaje wszystkie instrukcje podczas wywołania programu. Po 
wyświetleniu menu należy jedynie wybrać odpowiednią opcję i postępować 
zgodnie z tym co wyświetli program na ekran.
