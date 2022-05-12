#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Baza {
	char slowobaza[50];
	struct Baza* next; //nastepny element
} Baza;
void dodajpoczatek(Baza** head, char* wyrazpodany)
{
	Baza* current;
	current = (Baza*)malloc(sizeof(Baza));

	strcpy(current->slowobaza, wyrazpodany);
	current->next = *head;
	*head = current;
	return; //head;
}
/*void dodajkoniec(Baza* head, char* wyrazpodany)
{


	if (head == NULL)
	{
	    printf("asff");
		head = (Baza*)malloc(sizeof(Baza));
		(head)->slowobaza = wyrazpodany;
		(head)->next = NULL;
	}
	else
	{
		Baza* current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = (Baza*)malloc(sizeof(Baza));
		current->next->slowobaza = wyrazpodany;
		current->next->next = NULL;
	}




}*/
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
        if (wyrazpodany[i + j] == '*') //jezeli trfi na * w podanym wyrazie to wyraz pasuje do sprawdzanego
            {                              // nie wazne jakie sa dalsze pozycje wyrazu sprawdzanego
                strcpy(slowo,current->slowobaza);
                printf("%s\n",slowo);
                current = current->next;
                i=0;
                j=0;
                if(current==NULL)
            {
                break;
            }
            }else
        if (wyrazpodany[i + j] == '?')
            {
                i++;

        if ((i+j)==strlen(wyrazpodany)) //ostatni znak oznacza ze wyraz pasuje do obecnego z bazy
            {
                strcpy(slowo,current->slowobaza);
                printf("%s\n",slowo);
                current = current->next;
                i=0;
                j=0;
            }
            }else
            if (wyrazpodany[i + j] == '[') //sprawdza czy ktoras z podanych opcji pokrywa sie z odpowidajacym miejscem wyrazu sprawdzanego
            {
                for (j; wyrazpodany[j] != ']'; j++)
                {
                    if (wyrazpodany[j] == current->slowobaza[i])
                    {
                        i++;
                    }
                    if ((i+j)==strlen(wyrazpodany)) //ostatni znak oznacza ze wyraz pasuje do obecnego z bazy
                    {test++;printf("%d",test);
                    strcpy(slowo,current->slowobaza);
                    current = current->next;
                    i=0;
                    j=0;
                    }

                }
                j++;


            }else

            if (wyrazpodany[i + j] == current->slowobaza[i]) //sprawdza czy obecna litera wyrazu pokrywa sie z odpowiadajaca wyrazu z bazy
            {
                i++;
                if ((i+j)==strlen(wyrazpodany)) //ostatni znak oznacza ze wyraz pasuje do obecnego z bazy
            {
                strcpy(slowo,current->slowobaza);
                printf("%s\n",slowo);
                current = current->next;
                i=0;
                j=0;
            }

            }else
            if ((i+j)==strlen(wyrazpodany)) //ostatni znak oznacza ze wyraz pasuje do obecnego z bazy
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
void zapiszbaza(Baza**head,FILE*file)
{
    Baza* current=*head;


	while (current != NULL)
    {
        fprintf(file,"%s\n",current->slowobaza);
        current=current->next;
    }
}

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
		printf("wybierz co chcesz zrobic\n");
		printf("1. Wyszukaj wyrazy pasujace do podanych znakow\n");
		printf("2. Dodac nowe slowo do Bazy\n");
		printf("3. Usunac wybrane slowo z Bazy\n");
		printf("4. Edytowac wybrane slowo w Bazie\n");
		printf("5. wypisac wszystkie slowa\n");
		printf("0. Zapisac edytowana i ulozona alfabetycznie baze oraz Zakonczyc program\n");
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
            printf("podaj znane znaki w miejsce nieznanych wpisz '?' w przypadku kilku mozliwych podaj je w nawiasie kwadratowym'['']' \n");
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
            printf("Jesli wyraz po edycji powinien znajdowac sie na innej pozycji w Bazie biorac pod uwage porzadek alfabetyczny zostanie tam umieszczonyn po zapisaniu i ponownym uruchomieniu programu \n");
            break;
		case 5:
			wypisz(head);
			break;
        default:
            printf("Podaj wlasciwa opcje.\n");
            scanf("%d", &n);
            break;
		}
	getchar();
	printf("\nWcisnij 'ENTER' aby kontynuowac\n");
       getchar();

       system("cls");
    }
}
