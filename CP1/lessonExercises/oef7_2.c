#include <stdio.h>
#include <string.h>

#define SIZEOFNAAM 150
#define AANTALNAMEN 200

int main(){
    char naam[AANTALNAMEN][SIZEOFNAAM] ={0};
    int idxGroot=0;
    int idxKlein=0;

    for(int i=0;i<AANTALNAMEN;i++){
       strcpy(naam[i],"|");
    }

    char temp[SIZEOFNAAM] = {0};
    int counter=0;

    for(int i=0;i<AANTALNAMEN;i++){
        printf("Geef een naam of schrijf stop: ");
        fgets(temp,SIZEOFNAAM,stdin);
        if(strcmp(temp,"stop\n") ==0){
            break;
        } else{
            strcpy(naam[i],temp);
        }
        counter++;
    }

    for(int i=0;i<AANTALNAMEN-1;i++){
        for(int j=0;j<AANTALNAMEN-i-1;j++){
            if(strcmp(naam[j],naam[j+1])>0){
                strcpy(temp,naam[j]);
                strcpy(naam[j],naam[j+1]);
                strcpy(naam[j+1],temp);
            }
            }
    }

    printf("\n");
    printf("De namen lijst in alfabetische volgorde is: \n");
    for(int i=0;i<counter;i++){
        printf("%s",naam[i]);
        if(strlen(naam[i])>=strlen(naam[idxGroot])){
            idxGroot=i;
        }
        if(strlen(naam[i])<=strlen(naam[idxKlein])){
            idxKlein=i;
        }
    }

    printf("De Grootste naam is: %s",naam[idxGroot]);
    printf("De Kleinste naam is: %s",naam[idxKlein]);



    return 0;
}
