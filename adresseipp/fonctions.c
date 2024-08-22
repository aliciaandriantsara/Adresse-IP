#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adresseip.h"

void main_main(char *recovery_ip, int chaine)
{
    char tab_1[4];
    char tab_2[4];
    char tab_3[4];
    char tab_4[4];
    int verification=0;
    if(chaine == 1)
    {
        sscanf(recovery_ip, "ip=%[^.].%[^.].%[^.].%[^.]", tab_1, tab_2, tab_3, tab_4);
        verification=testing_adresss(tab_1, tab_2, tab_3, tab_4);
        
        type_of_adress(verification, tab_1, tab_2, tab_3, tab_4);
    }
    else
    {
        printf("                <p>Vous n'avez pas suivi l'instruction. Recommencez</p>\n");
    }
}

int chainecarac(char* recovery_ip)
{
    int chaine=0;
    int i;
    for(i=0; i<16;i++)
    {
        if(recovery_ip[i] == '.')
        {
            chaine=1;
        }
    }
    return (chaine);
}

int control_error(char *tab_1, char *tab_2, char *tab_3, char *tab_4)
{
    char *tab;
    int i;
    int *a;
    int verify=0;
    a=(int*)malloc(4*sizeof(int));
    tab=(char*)malloc(4*sizeof(char));
    a[0]=strlen(tab_1);
    a[1]=strlen(tab_2);
    a[2]=strlen(tab_3);
    a[3]=strlen(tab_4);
    for(i=0; i<4; i++)
    {
        if(a[i] > 3)
        {
            verify=1;
            printf("        <p>Vous avez faits une erreur. Recommencez</p>\n");
        }
    }
    return (verify);
}

void foot_of_body()
{
    printf("        <p>\n");
    printf("            Cliquez sur le lien suivant pour reesayer\n");
    printf("            <a href=\"adresseip.html\">Adresse IP</a>\n");
    printf("        </p>\n");
    printf("    </body>\n");
    printf("</html>\n");
}

void head_of_body()
{
    printf("    <body>\n");
    printf("        <h1>Adresse IP</h1>\n");
}


void head(char *title)
{
    printf("Content-type: text/html\n\n");
    printf("<html>\n");
    printf("    <head>\n");
    printf("        <title>%s</title>\n", title);
    printf("        <meta charset=\"utf-8\"/>\n");
    printf("        <link rel=\"stylesheet\" href=\"adresseip.css\"/>\n");
    printf("    </head>\n");
}

void type_of_adress(int verification, char *tab_1,  char *tab_2, char *tab_3, char *tab_4)
{
    int value_1=0;
    value_1=atoi(tab_1);
    int verify=0;
    verify=control_error(tab_1, tab_2, tab_3, tab_4);
    if(verify == 1)
    {
        goto QUIT;
    }
    else
    {
        if(verification == 1)
        {
            printf("            <p>Ce que vous avez entrez n'est pas un adresse IP</p>\n");
        }
        else
        {
            if (value_1 < 128)
            {
                printf("            <p>value1 : %d</p>\n", value_1);
                printf("            <p>Vous avez entrez un adresse IP de type A</p>\n");
            }
            else if(value_1 < 191)
            {
                printf("            <p>Vous avez entrez un adresse IP de type B</p>\n");
                
            }            
                
            else if(value_1 < 224)
            {
                printf("            <p>Vous avez entrez un adresse IP de type C</p>\n");

            }  
            else if(value_1 <239)
            {
                printf("            <p>Vous avez entrez un adresse IP de type D</p>\n");

            }
            else
            {
                printf("            <p>Vous avez entrez un adresse IP de type E</p>\n");

            }
        
        }
    }
QUIT:
}

int testing_adresss(char *tab_1, char *tab_2, char *tab_3, char *tab_4)
{
    int *tab;
    int i;
    int verification=0;
    tab=(int*)malloc(4*sizeof(int));
    tab[0]=atoi(tab_1);
    tab[1]=atoi(tab_2);
    tab[2]=atoi(tab_3);
    tab[3]=atoi(tab_4);
    for(i=0; i<4; i++)
    {
        if(tab[i] > 255)
        {
            verification=1;
        }
    }
    return (verification);


}
