#include <iostream>
#include <cstring>
#include <vector>
#define DEBUG0 if(0)
#define DEBUG1 if(1)
#define INT_MAX 100000
#define ERROR "ERROR\0"


class Token {
    public:
    char type[INT_MAX];
    int sequence_number;
    char value[INT_MAX];
    int line;
    bool terminal = false;
    void initStrings(){
        for (int i=0; i<INT_MAX-1; ++i){
            type[i]='0';
            value[i]='0';
        }
        type[INT_MAX]='\0';
        value[INT_MAX]='\0';
        return;
    }
};


class Types{
    public:
    //classes of globals tokens
    char PR[27][INT_MAX] = {
        "main\0",
        "if\0", "then\0", "else\0",
        "int\0", "real\0", "boolean\0",
        "var:\0", "f\0",
        "return\0", "function\0",
        "write\0", "read\0",
        "for\0", "to\0", "do\0", "repeat\0", "until\0", "while\0",
        
        "programa_SOL\0", "sequencia\0", "tempo\0", "fases_EPIC\0",
        "Explore\0", "Interact\0", "Present\0", "Critique\0"

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
    char DIGIT[10][3] = {"0\0","1\0","2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0"};
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


int tokenzing(int len, char* input, std::vector<Token> *tokens){
    int acc = 0;
    int acct = 0;
    int acc_line = 0;
    Types* types = new Types();
    while (acc<len){
        char word[INT_MAX];
        int acc0 = acc;
        DEBUG0{std::cout<<acc<<":ACC-input="<<input[acc]<<"\n";}
        while ((input[acc0]>=65 && input[acc0]<=90)
          || (input[acc0]>=97 && input[acc0]<=122)){
            word[acc0-acc]=input[acc0];
            acc0++;
        }
        word[acc0-acc]='\0';

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
        compareString(word,types->PR[17]) ||
        compareString(word,types->PR[18]) ||

        compareString(word,types->PR[19]) ||
        compareString(word,types->PR[20]) ||
        compareString(word,types->PR[21]) ||
        compareString(word,types->PR[22]) ||
        compareString(word,types->PR[23]) ||
        compareString(word,types->PR[24]) ||
        compareString(word,types->PR[25]) ||
        compareString(word,types->PR[26])){
            Token *token = new Token();
            DEBUG0{
                std::cout<<acc<<" - word="<<word<<"-\n";
                std::cout<<"ACCT:"<<acct<<"\n";
            }
            strcpy(token->value, word);
            DEBUG0{std::cout<<"VALOR-TOKEN-"<<token->value<<"-\n";}
            strcpy(token->type, "PR\0");
            token->sequence_number = acct;
            token->line = acc_line;
            tokens->push_back(*token);
            acct+=1;
            DEBUG0{std::cout<<"acc0="<<acc0<<"END\n";}
            word[0]='\0';
            acc=acc+(acc0-acc);
            // acc++;
        }
        else if ((input[acc]=='[') ||
                (input[acc]==']') ||
                (input[acc]=='(') ||
                (input[acc]==')') ||
                (input[acc]==';') ||
                (input[acc]=='.') ||
                (input[acc]==',')){
            Token *token = new Token();
            token->value[0] = input[acc];
            token->value[1] = '\0';
            strcpy(token->type, "DS\0");
            token->sequence_number = acct;
            token->line = acc_line;
            tokens->push_back(*token);
            acct+=1;
            //DEBUG0{std::cout<<"DSacc="<<acc<<std::endl;}
            acc++;
        }
        else if (compareString(word,types->DC[0]) ||
         compareString(word,types->DC[1])){
            Token *token = new Token();
            strcpy(token->value, word);
            strcpy(token->type, "DC\0");
            DEBUG0{std::cout<<"IS END? -"<<word<<"-\n";}
            token->sequence_number = acct;
            token->line = acc_line;
            tokens->push_back(*token);
            acct+=1;
            acc=acc+(acc0-acc);
            word[0]='\0';
        }
        else if (input[acc]==32 || input[acc]=='\t' || input[acc]=='\n'){
            if (input[acc]=='\n'){acc_line++;}
            acc++;
        }
        else if ((input[acc]=='0') ||
                 (input[acc]=='1') ||
                 (input[acc]=='2') ||
                 (input[acc]=='3') ||
                 (input[acc]=='4') ||
                 (input[acc]=='5') ||
                 (input[acc]=='6') ||
                 (input[acc]=='7') ||
                 (input[acc]=='8') ||
                 (input[acc]=='9')){
            Token *token = new Token();
            token->value[0] = input[acc];
            token->value[1] = '\0';
            strcpy(token->type, "DIGIT\0");
            token->sequence_number = acct;
            token->line = acc_line;
            tokens->push_back(*token);
            acct+=1;
            acc++;
        }
        else if (compareString(word,types->VALUES_BOLLEAN[0]) ||
                 compareString(word,types->VALUES_BOLLEAN[1]) ||
                 compareString(word,types->VALUES_BOLLEAN[2])){
            Token *token = new Token();
            strcpy(token->value, word);
            strcpy(token->type, "BOOLEAN\0");
            token->sequence_number = acct;
            token->line = acc_line;
            tokens->push_back(*token);
            acct+=1;
            acc=acc+(acc0-acc);
            word[0]='\0';
        }
        else if (input[acc]=='+' ||
                 input[acc]=='-' ||
                 input[acc]=='*' ||
                 input[acc]=='/' ||
                 (input[acc]=='/' && input[acc+1]=='/') ||
                 (input[acc]==':' && input[acc+1]=='=')){
            if ((input[acc]=='/' && input[acc+1]=='/') ||
                 (input[acc]==':' && input[acc+1]=='=')){
                Token *token = new Token();
                token->value[0] = input[acc];
                token->value[1] = input[acc+1];
                token->value[2] = '\0';
                strcpy(token->type, "MATH_OPERATOR\0");
                token->sequence_number = acct;
                token->line = acc_line;
                tokens->push_back(*token);
                acct+=1;
                acc+=2;
            }
            else{
                Token *token = new Token();
                token->value[0] = input[acc];
                token->value[1] = '\0';
                strcpy(token->type, "MATH_OPERATOR\0");
                token->sequence_number = acct;
                token->line = acc_line;
                tokens->push_back(*token);
                acct+=1;
                acc+=1;
            }
        }
        else if (input[acc]=='='||input[acc]=='>'||input[acc]=='<'||
                (input[acc]=='>'&&input[acc]=='=')||
                (input[acc]=='<'&&input[acc]=='=')||
                (input[acc]=='<'&&input[acc]=='>')){
            if ((input[acc]=='>'&&input[acc]=='=')||
                (input[acc]=='<'&&input[acc]=='=')||
                (input[acc]=='<'&&input[acc]=='>')){
                Token *token = new Token();
                token->value[0] = input[acc];
                token->value[1] = input[acc+1];
                token->value[2] = '\0';
                strcpy(token->type, "REL_OPERATOR\0");
                token->sequence_number = acct;
                token->line = acc_line;
                tokens->push_back(*token);
                acc+=2;
            }
            else{
                Token *token = new Token();
                token->value[0] = input[acc];
                token->value[1] = '\0';
                strcpy(token->type, "REL_OPERATOR\0");
                token->sequence_number = acct;
                token->line = acc_line;
                tokens->push_back(*token);
                acct+=1;
                acc+=1;
            }
        }
        else{
            Token *token = new Token();
            strcpy(token->value, word);
            strcpy(token->type, "ERROR\0");
            token->sequence_number = acct;
            token->line = acc_line;
            tokens->push_back(*token);
            acct+=1;
            word[0]='\0';
            acc=acc+(acc0-acc);
        }
    }
    return acct;
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
    
    std::cout<<"tokenzing process initialization...\n";
    std::vector<Token> tokens = std::vector<Token>();
    int len_tokens = tokenzing(lenght, result, &tokens) + 1;

    std::cout<<"LENGHT TOKENS="<<len_tokens<<std::endl;
    for (Token j : tokens){
        std::cout<<"Token="<<j.value<<"|"<<j.type<<"|"<<j.line<<"|"<<"\n";
    }

    return 0;
}