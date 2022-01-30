#include <stdio.h>
#include <stdlib.h>

/* Atadila Belva Ganya
18320015
Teknik Biomedis'20*/

int main()
{
    char fileName[] = "";
    unsigned char isi[12];
    FILE *fileRead;

    printf("Masukkan nama file yang ingin Anda cek: ");
    scanf("%s", fileName);
    fileRead = fopen(fileName, "r");
    while (fileRead == NULL){
        printf("\nFile tidak ditemukan.\n");
        printf("Silakan masukkan nama file yang lain: ");
        scanf("%s", fileName);
        fileRead = fopen(fileName, "r");
    }

    printf("-------------------------------------------");
    printf("\nFile ditemukan.\n");
    fread(isi, sizeof(isi),1,fileRead);
    char temp[]="";

    //hex of pdf : 25 50 44 46
    if ((isi[0]==0x25) && (isi[1]==0x50) && (isi[2]==0x44) && (isi[3]==0x46)){
        printf("File tersebut adalah file pdf.\n");
    }
    //hex of JPG : FF D8
    else if((isi[0]==0xFF) && (isi[1]==0xD8)){
        printf("File tersebut adalah file JPG.\n");
    }
    else{
        printf("Program tidak dapat mendefinisikan type dari file tersebut (bukan file pdf ataupun JPG).\n");
        printf("Silakan membuka program kembali dan coba file lainnya.\n");
    }

    fclose(fileRead);
    return 0;
}
