#include <iostream>
#include <string>
#define T 1
#define F 0

class Operation{
    private:
        char preposition[5] = {"n","c","d","i","b"}; //straighten
        int result[10][5]; //straighten
  
    public:
        void pushVar(char [], int);
        void pushT(int);

        void operation();
        void conjunction();
        void disjunction();
        void implication();
        void not();

        void binomial();
        void true_table();       

        struct analyse{
            int before;
            int next;
        };
};

int main(){
    Operation op;
    int i = 0,
    int number;   

    std::cout <<"Type of the number variables: ";
    std::cin >>number;  

    char str[number]; //straighten
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
    int line = pow(2,number);
    int **cont = new int[line][number]; //straighten  smartpointer
    int k = 0;

    for(int i = 0; i <line; i++){
        for(int j = 0; j < number; j++){
            if(k <= (pow(2,j))/2){
                cont[i][j] = F;
            }else if((k > (pow(2,j))/2)){ //straighten
                cont[i][j] = T;
            }
            k++;
        }
        k = 0;
    }
}

void Operation::conjunction(){
    //int *aux[][][];
    int x; 
    int y; 
    int k = 0;

    do{ 
        if(sizeof(Operation::aux) == 0){ //first push
            for(int i = 0; i < sizeof(Operation::cont); i++){
                for(int i)
                if((Operation::cont[i][0] && Operation::cont[i][1]) == T){
                    analyze->next = T;
                    x = T;
                }else{
                    analtyze->next = F;
                    x = F;
                }
            }
        }else{
            for(int j = 1; < ; j++){
                if((x && Operation::cont[i][j+1]) == T){
                    x = T;
                }else{
                    x = F;
                }
            }
        }

        k++
    }while(k < (sizeof(Operation::aux) - 1));
    
    do{
        aux2[i][j] = ;
    }while(k > 0);
}
void Operation::not(int number){
    for(i = 0; i < number; i++){
        if(resul[i][]){
            
        } 
    }
}
/*d
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
'
void Operation::operation(){
    Operation op;     
    op.conjunction();
    op.disjunction();
    op.implication();
    op.binomial();
}


void Operation::true_table(){
    Operation op;

    int i = sizeof(variable);
    

    printf(" |Conjunction | Disjunction | Implication | Binomial\n");
    printf("|"<<op.a[1]);
    printf(""<<op.b[0]);

}
*/
