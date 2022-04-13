#include <iostream>
#include <vector>
#include <math.h>
#define T 1
#define F 0

class Truth_table{
    private:
        int result[5]; //straighten
        int number;
        char variable[1];
        char expression[10]; //temporary
        std::vector< std::vector<int> > con;
        int open[5];
        int close[5];
        int operation[5];
    
    public:
        void pushVar(char []);
        void pushT();

      /*  void conjunction();
        void disjunction();
        void implication();
        void bicondicional();
        void table();
    */
        //void not();
        char getVar(int);
        void setVar(char, int);

        int getResult(int );
        void setResult(int, int);  

        int getNumber();
        void setNumber(int);  

        int getOpen(int);
        void setOpen(int, int);

        int getClose(int);
        void setClose(int, int);

        int getOp(int);
        void setOp(int, int);

        char getExpression(int);
        void setExpression(int, char);
        int getSizeExpression();

        void operation();
        void popEX();

};

int main(){
    Truth_table tt;
    int i = 0;
    int number;   
    char *expresson[5];
    bool condition = false;
    

    std::cout <<"Type of the number variables between 1 and 3: ";
    std::cin >>number; 
    
    tt.setNumber(number);

    char var[number]; 

    do{
        std::cout <<"Type it variable ", i + 1, ": ";
        std::cin >>var[i];
        i++;
    
    }while(i < number);
   
    do{
    //How do this?
    std::cout <<"Type the expresson: ";
    std::cin >>*expresson;

    for(int i = 0; i < sizeof(expresson); i++){
        std::cout <<expresson[i],",";
        tt.setExpression(i,*expresson[i]);
    }
    //check if the expression is correct
    tt.pushVar(var);
    condition = true;
    
    }while(condition == false);
 
    
    for(int i = 0; i < number; i++){
    tt.getVar(i);
    }
    std::cout <<"Exit: Truth table 2^",number;

    // tt.pushT();
    //tt.truth_table();
}

int Truth_table::getNumber(){
    return number;
    
}
void Truth_table::setNumber(int n){
    number = n;
    //std::cout <<number;
}

char Truth_table::getVar(int i){
    return variable[i];
}
void Truth_table::setVar(char x,int i){
    variable[i] = x;
}

char Truth_table::getExpression(int i){
    return expression[i];
}
int Truth_table::getSizeExpression(){

    return sizeof(expression);
}
void Truth_table::setExpression(int i, char ex){
    expression[i] = ex;
}

int Truth_table::getResult(int i){
    return result[i];
}
void Truth_table::setResult(int x,int i){
    result[i] = x;
}

int Truth_table::getOpen(int i){
    return open[i];
    
}
void Truth_table::setOpen(int i, int n){
    open[i] = n;

}
int Truth_table::getClose(int i){
    return close[i];
}
void Truth_table::setClose(int i , int n ){
    close[i] = n;
}

int Truth_table::getOp(int i){
    return operation[i];
}
void Truth_table::setOp(int i, int n){
    operation[i] = n;
}


void Truth_table::pushVar(char str[]){
 
    con.resize(pow(2, getNumber()));       
    for(int i = 0; i < getNumber(); i++){
        setVar(str[i],i);
      std::cout << variable[i] <<";"; //test
        //std::cout <<getVar(i);
    }
}

void Truth_table::pushT(){

    int line = pow(2,getNumber());
    int k = 0;

    con.resize(pow(2,getNumber()));
    for(int i = 0; i <line; i++){
        con.resize(pow(2,getNumber()));
        for(int j = 0; j < getNumber(); j++){
            if(k <= (pow(2,j))/2){
                con[i][j] = F;
            }else if((k > (pow(2,j))/2)){ 
                con[i][j] = T;
            }
            k++;
       
        k = 0;   
         }
    }
}

void Truth_table::popEX(){
    int j = 0;
    int k = 0;
    int l = 0
    ;
    for (int i = 0; i <getSizeExpression(); i++){
        if (getExpression(i) == "("){   
            setOpen(j,i);
            j++;   
         }else if(getExpression(i) == ")"){   
            setClose(k,i);
            k++;     
         }else if(getExpression(i) == ("˄" || "v" || "¬" || "→" || "↔")){
            setOp(l,i);
            l++;
         } 

    }
}

void Truth_table::operation(){

}
