#include <iostream>
#include <cstring>
#include <vector>
#define DEBUG0 if(1)
#define DEBUG1 if(1)
#define INT_MAX 100000


class Token {
    public:
    char type[INT_MAX];
    int sequence_number;
    char value[INT_MAX];
};


class Types{
    public:
    //classes of globals tokens
    char PR[18][INT_MAX] = {
        "if\0", "then\0", "else\0",
        "integer\0", "real\0", "boolean\0",
        "var:\0", "f\0",
        "procedure\0", "function\0",
        "write\0", "read\0",
        "for\0", "to\0", "do\0", "repeat\0", "until\0", "while\0" 
    };
    char DS[7][3] = {
        ";\0",".\0",",\0","(\0",")\0","[\0","]\0"
    };
    char DC[2][7] = {
        "begin\0", "end\0"
    };
    char MATH_OPERATORS[6][4] = {
        "+\0","-\0","*\0","/\0","//\0",":=\0"
    };
    char REL_OPERATORS[6][4] = {
        "=\0",">\0","<\0",">=\0","<=\0","<>\0"
    };
    char VALUES_BOLLEAN[3][7] = {"true\0", "false\0", "empty\0"};
    char DIGITO[10][3] = {"0\0","1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0"};
    char DIGIT[9][3] = {"1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0"};
};


int compareString(char* str0, char* str1){
    int acc = 0;
    while (str0[acc]==str1[acc] && str0[acc]!='\0' && str1[acc]!='\0'){
        acc++;
    }
    if (str0[acc]=='\0' && str1[acc]=='\0'){
        return 1;}
    return 0;
}


int tokenzing(int len, char* input, std::vector<Token> tokens){
    int acc = 0;
    int acct = 0;
    Types* types = new Types;
    while (acc<len){
        char word[INT_MAX];
        int acc0 = acc;
        while (input[acc0]!='\0' && input[acc0]!='\t' && input[acc0]!=' '){
            word[acc0-acc]=input[acc0];
            acc0++;
        }
        DEBUG0{std::cout<<"WORD="<<word<<"\n";}
        if (compareString(word,types->PR[0]) ||
        compareString(word,types->PR[1]) ||
        compareString(word,types->PR[2]) ||
        compareString(word,types->PR[3]) ||
        compareString(word,types->PR[4]) ||
        compareString(word,types->PR[5]) ||
        compareString(word,types->PR[6]) ||
        compareString(word,types->PR[7]) ||
        compareString(word,types->PR[8]) ||
        compareString(word,types->PR[9]) ||
        compareString(word,types->PR[10]) ||
        compareString(word,types->PR[11]) ||
        compareString(word,types->PR[12]) ||
        compareString(word,types->PR[13]) ||
        compareString(word,types->PR[14]) ||
        compareString(word,types->PR[15]) ||
        compareString(word,types->PR[16]) ||
        compareString(word,types->PR[17])
        ){
            strcpy(tokens[acct].value,word);
            strcpy(tokens[acct].type,"PR\0");
            tokens[acct].sequence_number = acct;
            acct++;
        }
        acc = acc0;
        acc++;
    }
    return 1;
}


int read(char output[]){
    int acc = 0;
    do{
        output[acc]=(char)getchar();
        // DEBUG0{std::cout<<"char="<<output[acc]<<"\n";}
        acc++;
    }
    while (output[acc-1]!='\0' && output[acc-1]>=0 && output[acc-1]<=122);
    return acc-1;
}


int main(int argv, char* argc[]){
    char result[INT_MAX];
    DEBUG0{std::cout<<"AQUI-init\n";}
    int lenght = read(result);
    DEBUG0{
        for (int i=0; i<lenght; ++i){
            std::cout<<result[i];
        }
        std::cout<<"\nlenght = "<<lenght<<" - FIM\n";
    }
    std::vector<Token> tokens = std::vector<Token>();
    int error0 = tokenzing(lenght, result, tokens);
    return 0;
}