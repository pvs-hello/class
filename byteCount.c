#include <stdio.h>
#include <string.h>
void charcount(char data[]){
    int len=strlen(data);
    char frame[32];
    frame[0]=len+1;
    for(int i=0;i<len;i++){
        frame[i+1]=data[i];
    }
    printf("character counting:%d\n",(unsigned char)frame[0]);
    for (int i = 0; i < strlen(frame); i++)
    {
        printf("%c",frame[i]);
    }
    
}

void bitstuffing(char data[]){
    char frame[256];
    char flag[]="01111110";
    int count=0;int j;
    strcpy(frame,flag);
    j=strlen(frame);
    for(int i=0;i<strlen(data);i++){
        frame[j++]=data[i];
        if(data[i]=='1'){
            count++;
            if(count==5){
                frame[j++]='0';
                count=0;
            }
        }
        else{
            count=0;
        }
    }
    strcpy(&frame[j],flag);
    printf("Bit Stuffing:%s\n",frame);
}

void bytestuffing(char data[]){
    char ESC='E';
    char FLAG='F';
    int len=strlen(data);
    char frame[32];
    int j=0;
    frame[j++]=FLAG;
    for(int i=0;i<len;i++){
        if(data[i]==FLAG || data[i]==ESC){
            frame[j++]=ESC;
        }
        frame[j++]=data[i];  
    }
    frame[j++]=FLAG;
    frame[j]='\0';
    printf("Byte Stuffing:%s\n",frame);

}

int main(){
    char data[20];
    printf("enter a string:");
    scanf("%s",&data);
    data[strcspn(data,"\n")]='\0';
    charcount(data);
    //bitstuffing(data);
    //bytestuffing(data);
    return 0;
}