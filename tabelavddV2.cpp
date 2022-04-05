#include <iostream>
#define T 1
#define F 0

class Operation{
    private:
        char *preposition[5] = {"n","c","d","i","b"};
        //struct
    public:
        void operation();
        void conjunction();
        void disjunction();
        void implication();
        void binomial();
        void true_table();       
}

int main(){
    int i = 0, number;
    char *str[10];
    std::cout <<"Type of the number variables between 1 and 3";
    std::cin >>number;
    do{
        std::cout <<"Type it variable string: ";
        std::cin >>str[i];
        i++;
    }while(i < number);

    pushVar(str [],number);
    pushT(number);
    Operation::true_table();
    

}
void Operation::pushVar(char str [], int number){
    char *variable = new char[number];

    for(i = 0; i < number ;i++){
        variable[i] = str[i];
        cout << variable[i] <<";"; //test
    }
    cout <<end1;
}
void Operation::pushT(int coluns){
    int line = 2**coluns;
    int *cont = new int[line][coluns];

    for(i = 0; i <line; i++){
        for(j = 0, j< coluns, j++){
            cont[i][j] = ;
        }
    }
}


void Operation::operation(){
    Operation op;     
    op.conjunction();
    op.disjunction();
    op.mplication();
    op.binomial();
}

void Operation::conjunction(){
    for(i = 0; i < 4 ; i++){
        if((a[i] && b[i]) == T){
            Operation::result[i][0] = T;
        }else{
            Operation::result[i][0] =F;
        }
    }
}
void Operation::disjunction(){
    for(i = 0; i < 4 ; i++){
        if((a[i] || b[i]) == T){
            Operation::result[i][1] = T;
        }else{
            Operation::result[i][1] = F;
        }
    }
}
void Operation::implication(){
    for(i = 0; i < 4 ; i++){
        if((b[i]== T || (a[i] || b[i] == F)){
            Operation::result[i][2]= T;
        }else{
            Operation::result[i][2] = F;
        }
    }
}
void Operation::bicondicional(){
    for(i = 0; i < 4 ; i++){
        if(((a[i] && b[i]) == T || (a[i] && b[i] == F))){
            Operation::result[i][3] = T;
        }else{
            Operation::result[i][3] = F;
        }
    }
}
void Operation::negation(){
    Operation op;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(Operation::result[i][j] == T){
                Operation::Nresult[i][j] == F;
            }else{
                Operation::Nresult[i][j] == T;            
            }
        }
    }
}

void Operation::true_table(){
    Operation op;

    int i = sizeof(variable);
    

    printf(" |Conjunction | Disjunction | Implication | Binomial\n");
    printf("|"<<op.a[1]);
    printf(""<<op.b[0]);

}
