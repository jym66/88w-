#include "stdio.h"

int pow(int x,int y){
    int temp = 1;
    if(y == 0){
        return 1;
    }
    for (int i = 0; i < y; ++i) {
        temp *=x;
    }
    return temp;
}
void template(FILE *fp,int num,int count,int bit []){
    fprintf(fp,"case %d: \n",num);
    int revers = 0;
    for (int i = 0,j = count -1; i <count; i++,j--) {
        revers+= bit[i] * pow(10,j);
    }
    if (count== 1){fprintf(fp," printf(\"是 %d 位数\");\n printf(\"个位数是 %d\");\n printf(\"倒过来是 %d\");\n",count,bit[0],revers);}
    if (count== 2){fprintf(fp," printf(\"是 %d 位数\");\n printf(\"个位数是 %d\");\n printf(\"十位数是 %d\");\n printf(\"倒过来是 %d\");\n",count,bit[0],bit[1],revers);}
    if (count== 3){fprintf(fp," printf(\"是 %d 位数\");\n printf(\"个位数是 %d\");\n printf(\"十位数是 %d\");\n printf(\"百位数是 %d\");\n printf(\"倒过来是 %d\");\n",count,bit[0],bit[1],bit[2],revers);}
    if (count== 4){fprintf(fp," printf(\"是 %d 位数\");\n printf(\"个位数是 %d\");\n printf(\"十位数是 %d\");\n printf(\"百位数是 %d\");\n printf(\"千位数数 %d\");\n printf(\"倒过来是 %d\");\n",count,bit[0],bit[1],bit[2],bit[3],revers);}
    if (count== 5){fprintf(fp," printf(\"是 %d 位数\");\n printf(\"个位数是 %d\");\n printf(\"十位数是 %d\");\n printf(\"百位数是 %d\");\n printf(\"千位数数 %d\");\n printf(\"万位数是 %d\");\n printf(\"倒过来是 %d\");\n",count,bit[0],bit[1],bit[2],bit[3],bit[4],revers);}
    fprintf(fp," break;\n");
}

void numRevers(int num,int *count,int bit[]){
    if(num % 10 == num){
        bit[*count] = num%10;
        ++(*count);
        return;
    }
    bit[*count] = num%10;
    ++(*count);
    numRevers(num/10,count,bit);
}
int main(){
    int count = 0;
    int bit [] = {0,0,0,0,0};
    FILE *fp;
    fp = fopen("/Users/python/downloads/88w.c","w+");
    fputs("#include \"stdio.h\"\n\n\nint main(){\nint num;\nprintf(\"请输入一个不超过五位的数\\n\");\nscanf(\"%d\",&num);\nswitch(num)\n{\n",fp);
    for (int i = 1; i < 100000; ++i) {
        numRevers(i, &count,bit);
        template(fp,i,count,bit);
        count = 0;
    }
    fputs("   }\n}",fp);


}