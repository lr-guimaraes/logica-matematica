#include <iostream>
#define T 1
#define F 0

class Operation{
    private:
        char *preposition[5] = {"n","c","d","i","b"}; //straighten
        int result[10][0]; //straighten
  
    public:
        void pushVar(char [], int);
        void pushT(int);
        void operation();
        void conjunction();
        void disjunction();
        void implication();
        void binomial();
        void true_table();       
};

int main(){
    Operation op;
    int i = 0, number;
    char str[10]; //straighten

    std::cout <<"Type of the number variables: ";
    std::cin >>number;
    do{
        std::cout <<"Type it variable string: ";
        std::cin >>str[i];
        i++;
    }while(i < number);
    op.pushVar(str, number);
    op.pushT(number);

    op.true_table();
    

}

void Operation::pushVar(char str[], int number){
    char *variable = new char[number];

    for(int i = 0; i < number; i++){
        variable[i] = str[i];
        std::cout << variable[i] <<";"; //test
    }
    std::cout <<"\n";
}

void Operation::pushT(int number){
    int line = 2^number;
    int **cont = new int[line][number]; //straighten
    int k = 0;

    for(int i = 0; i <line; i++){
        for(int j = 0; j<  number; j++){
            if(k <= (2^j)/2){
                cont[i][j] = F;
            }else if((k > (2^j)/2)){
                cont[i][j] = T;
            }
            k++;
        }
        k = 0;
    }
}


void Operation::operation(){
    Operation op;     
    op.conjunction();
    op.disjunction();
    op.binomial();
}

void Operation::conjunction(){
    for(int i = 0; i < sizeof(Operation::cont); i++){
        if((Operation::cont[i][j] && (Operation::cont[i][j])) == T){
            Operation::result[i][0] = T;
        }else{
            Operation::result[i][0] =F;
        }
    }
}
/*
void Operation::disjunction(){
    for(int i = 0; i < sizeof(Operation::cont) ; i++){
        if((a[i] || b[i]) == T){
            Operation::result[i][1] = T;
        }else{
            Operation::result[i][1] = F;
        }
    }
}
void Operation::implication(){
    for(i = 0; i < sizeof(Operation::cont) ; i++){
        if((b[i]== T || (a[i] || b[i] == F)){
            Operation::result[i][2]= T;
        }else{
            Operation::result[i][2] = F;
        }
    }
}
void Operation::bicondicional(){
    for(i = 0; i < sizeof(Operation::cont) ; i++){
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
*/