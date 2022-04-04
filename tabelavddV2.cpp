#include <iostream>
#include <cmath>
#include <vector>

#define T 1
#define F 0

class Operation{
    private:

    public:
        void var();
        void pushV();
        void pushA();
        void operation();
        void conjunction();
        void disjunction();
        void implication();
        void binomial();
        void true_table();       
}

int main(){

    int number, i = 0;
    char var;

    std::cout<<"Number of the variables: ";
    std::cin<<number;
    do{
        std::cout <<"Type it the variable: ";
        std::cin >>var;
        Operation::pushV(var,number)
        Operation::pushA(var);
        i++;
    }while(i<= number);
   
    Operation::true_table();
    

}


void Operation::pushV(char a,int n){    
    int i = 0;

    if(i <= n){
    Operation::variable[i] = a;
    i++;
    }else{
        std::cout <<"ERROR!!";
    }
    
}

void Operation::pushA(int n){
    int row, coluns;

    coluns = n
    row = 2**n;

    int **values = new int*[row];
    for(int i = 0; i < row; ++i) {
        values[i] = new int[coluns];
    }

    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < coluns; ++j) {
            if(coluns == 1){
                if(j == 0){
                    values[i][j] = F;
                }else{
                    values[i][j] = T;
                }
            }else if(coluns == 2){
                if()
            }
            cout << setw(2) << values[i][j] << "; ";
        }
        cout << endl
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
            Operation::result[i][1] =F;
        }
    }
}
void Operation::implication(){
    for(i = 0; i < 4 ; i++){
        if((b[i]== T || (a[i] || b[i] == F))){
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

}
