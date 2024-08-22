#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adresseip.h"



int main()
{
    char *title="Adressse IP";
    char recovery_ip[16];
    
    int chaine=0;
    head(title);
    head_of_body();
    strcpy(recovery_ip, getenv("QUERY_STRING"));
    chaine=chainecarac(recovery_ip);
    main_main(recovery_ip, chaine);
    foot_of_body();
    return 0;
}

