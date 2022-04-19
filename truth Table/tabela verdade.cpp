#include <iostream>
#include <vector>
#include <math.h>

#include<string>
#define T 1
#define F 0

class Truth_table{
    private:
        int result[5];
        int number;
        char variable[4];
        char expression[20]; //temporary
        char sequence[10];  //temporary
        int coluns;
        int p_operatiors[5];
        int **con; //criete array 2d
        int **intermediare; //calc intermediare
    public:
        void pushVar(char []); 
        void pushT();
        int getResult(int );
        void setResult(int, int);  
        void boleans();

        //operations
        void conjunction(int ,int ,int);
        void disjunction(int ,int ,int);
        void implication(int ,int ,int);
        void bicondicional(int ,int ,int);

        void conjunction(int,int);
        void disjunction(int ,int);
        void implication(int ,int);
        void bicondicional(int ,int);
        void operation(); //analize operations and variables, from the equation
        //void not();
        void table();
    //create table from the amount of variables
    
        char getVar(int);
        void setVar(char, int);
        int getNumber();
        void setNumber(int);  
        int getColuns();
        void setColuns(int);
        int getOp(int);
        void setOp(int, int);
        char getExpression(int);
        void setExpression(int, char);
        int getSizeExpression();
        void popEX();
        char getSequence(int);
        void setSequence(char,int);

        int getCon(int,int);
        void setCon(int,int,int);
        void defineCon(int,int);

        //Calc intermediare
        int getIntermediare(int,int);
        void setIntermediare(int,int,int);
        void defineIntermediare(int,int);

        //analysis if con[i][j] is true or false
        struct analyse{
                int before;
                int next;
        };
        //position variable in "char variable[4];", to analisis order of the calc
        struct vars{
            int var1;
            int var2;
        };

    
};

int main(){
    Truth_table tt;
    int cont = 0;
    int number;   
//  std::string var;
    std::string expresson;
    bool condition = false;
    
    std::cout <<"Type of the number variables between 1 and 3: ";
    std::cin >>number; 
    
    tt.setNumber(number);
    tt.setColuns(number);

    char var[number]; 

    do{
        std::cout <<"Type it variable: ";
        std::cin >>var[cont];
        tt.setVar(var[cont],cont);
        cont++;
    }while(cont < number); 

    std::cout <<"|================|========|"<<std::endl;
    std::cout <<"|  PREPOSITIONS  | INPUTS |"<<std::endl;
    std::cout <<"|================|========|"<<std::endl;
    std::cout <<"|Conjuction      |   ^    |"<<std::endl;
    std::cout <<"|dijuntion       |   v    |"<<std::endl;
    std::cout <<"|Implication     |   >    |"<<std::endl;
    std::cout <<"|biconditional   |   b    |"<<std::endl;
    std::cout <<"|================|========|"<<std::endl;

    std::cout <<"Type the expresson: ";
    std::cin >> expresson;

    for(int i = 0; i < expresson.size() ; i++){
        tt.setExpression(i,expresson[i]);
    }

    std::cout <<"Exit: Truth table 2^"<<number;

    tt.pushT();
    tt.popEX();
    tt.operation();
    tt.table();

}

int Truth_table::getNumber(){
    return number;
    
}
void Truth_table::setNumber(int n){
    number = n;
}

int Truth_table::getColuns(){
    return coluns;
}
void Truth_table::setColuns(int i){
    coluns = i;
}
// Methotes gets and seters
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
int Truth_table::getOp(int i){
    return p_operatiors[i];
}
void Truth_table::setOp(int i, int n){
    p_operatiors[i] = n;
}
char Truth_table::getSequence(int i){
    return sequence[i];
}
void Truth_table::setSequence(char j,int i){
    sequence[i] = j;
}

int Truth_table::getCon(int i ,int j){
    return con[i][j];
}

void Truth_table::defineCon(int row,int coluns){
    con = new int *[row];
    for(int i = 0; i < row;i++){
        con[i] = new int[coluns];
    }    
}
void Truth_table::setCon(int i,int j, int k){
    con[i][j] = k;
}

int Truth_table::getIntermediare(int i ,int j){
    return intermediare[i][j];
}

void Truth_table::defineIntermediare(int row,int coluns){ 
    intermediare = new int *[row];
    for(int i = 0; i < row;i++){
        intermediare[i] = new int[coluns];
    }
}
void Truth_table::setIntermediare(int i,int j, int k){
    intermediare[i][j] = k;
}

//Methotes push
void Truth_table::pushVar(char str[]){

// con.resize(pow(2, getNumber()));       
    for(int i = 0; i < getNumber(); i++){
        setVar(str[i],i);
    }
}
void Truth_table::pushT(){
//table true and false //table true and false
    int line = pow(2,getNumber());

    defineCon(line,getNumber());
    for(int i = 0; i <line; i++){
        for(int j = 0; j < getNumber(); j++){   
            if (getNumber() == 1){
                if(j/2 < 0.5){
                    setCon(j,i,F);
                }else{ 
                    setCon(j,i,T);   
                }
            }       
            else if (getNumber() == 2){
                if(j == 0){
                    if(i % 2 != 1){
                        setCon(i,j,F);
                    }else{ 
                        setCon(i,j,T);
                    }
                }else{
                    if(i/2 < 1){//if((line/2 <=0) || (line % 2 == 0)){
                        setCon(i,j,F);
                    }else{ 

                        setCon(i,j,T);
                    }
                }
            }
            else if(getNumber() == 3){
                if(j == 0){
                    if(i % 2 != 1){

                        setCon(i,j,F);
                    }else{ 
                        setCon(i,j,T);
                    }
                }else if(j == 1){
                    if((i % 4 == 2) || (i % 4 == 3)){//if((line/2 <=0) || (line % 2 == 0)){
                        setCon(i,j,T);
                    }else{ 
                        setCon(i,j,F);
                    }
                }else{
                    if(i/2 < 2){//if((line/2 <=0) || (line % 2 == 0)){
                        setCon(i,j,F);
                    }else{ 
                        setCon(i,j,T);
                    }
                }
            }
        } 
    }
}

void Truth_table::operation(){
    vars v;
    int cont_ex = 0; //couter of expression
    int k = 0; //couter of operations
    int numOp , open, close;
    int line = pow(2, getNumber());
    char operators[4] = {'^','v','>','b'};
    int op;
    char position[10];
    //number of operations
    for(int l = 0; l< getSizeExpression(); l++){

        for(int m = 0; m < 4; m++){
            if(getExpression(l) == operators[m]){
                numOp++;
            }
        }
    }
    defineIntermediare(line,numOp);
    
    while(cont_ex < getSizeExpression()){
        if(getExpression(cont_ex) == '('){
            open++;
            while(open > close){
                cont_ex++;
                for(int cont_var = 0; cont_var < getNumber(); cont_var++){
                    if(getExpression(cont_ex) == getVar(cont_var)){
                        v.var1 = cont_var;
                    }
                }
                for(int cont_open; cont_open < getSizeExpression(); cont_open++){
                    if(getExpression(cont_ex) == '('){
                        open++;
                    }
                }
                if(getExpression(cont_ex) == '('){
                    cont_ex++;
                }
                open -=1;
                cont_ex++;

                for(int i = 0; i < 4; i++){
                    if((getExpression(cont_ex) == operators[i])){
                        op = i;
                    }
                }
                cont_ex++;
                for(int cont_var = 0; cont_var < getNumber(); cont_var++){
                    if(getExpression(cont_ex) == getVar(cont_var)){
                        v.var2 = cont_var;
                        cont_ex++;
                    }
                }
                switch(op){
                    case 0:
                        conjunction(v.var1, v.var2,k);
                        k++;
                        break;
                    case 1:

                        disjunction(v.var1, v.var2,k);
                        k++;
                        break;
                    case 2:
                        implication(v.var1, v.var2,k);
                        k++;
                        break;
                    case 3:
                        bicondicional(v.var1, v.var2,k);
                        k++;
                        break;    
                    default:
                        std::cout <<"ERRO"<<std::endl;
                        break;
                }
                if(getExpression(cont_ex) == '('){
                    cont_ex++;
                }else if(getExpression(cont_ex) == ')'){

                
                    close++, cont_ex++;

                    if(open < close){
                        for(int i = 0; i < 4; i++){
                            if((getExpression(cont_ex) == operators[i])){
                            op = i;
                            }
                        }
                        cont_ex++;
                        for(int cont_var = 0; cont_var < getNumber(); cont_var++){
                            if(getExpression(cont_ex) == getVar(cont_var)){
                                v.var2 = cont_var;
                                cont_ex++;
                            }
                        }
                        switch(op){
                            case 0:
                                conjunction(v.var2,k);
                                k++;
                                break;
                            case 1:
                                disjunction(v.var2,k);
                                k++;
                                break;
                            case 2:
                                implication(v.var2,k);
                                k++;
                                break;
                            case 3:
                                bicondicional(v.var2,k);
                                k++;
                                break; 
                            default:
                                std::cout <<"ERRO"<<std::endl;
                                break;
                        }
                    }
                }
            }
            cont_ex = getSizeExpression();
        }
    }
    if (k = getColuns()){
        for(int i = 0; i < line; i++){
            for(int j = 0; j <numOp; j++){
                setResult(getIntermediare(i,j),i);
            }
        }
    }
    cont_ex = getSizeExpression();


}
void Truth_table::popEX(){
    int j = 0;
    int k = 0;
    int l = 0;

    for (int i = 0; i <getSizeExpression(); i++){
        for(int j = 0; j < getSizeExpression(); j++){
            if (getExpression(i) == getVar(j)){   
                setSequence(getVar(j),i);
            }
        }
    }
}

void Truth_table::conjunction(int x,int z,int coluns){
    analyse an;
    int line = pow(2, getNumber());

    an.next = 2;
    an.before = 2;
    //first analysis
    for(int i = 0; i < line; i++){
        if (coluns == 0){//analize if is first calc 
            an.before = getCon(i,x);
        }
        an.next = getCon(i,z);
        if((an.before && an.next) == T){ 
            setIntermediare(i,coluns,T);
        }else{
            setIntermediare(i,coluns,F);
        }
    }
    
} 
void Truth_table::conjunction(int z,int coluns){
    analyse an;
    int line = pow(2, getNumber());

    //first analysis
    for(int i = 0; i < line; i++){

        an.before = getIntermediare(i,coluns-1);
        an.next = getCon(i,z);
        if((an.before && an.next) == T){ 
            setIntermediare(i,coluns,T);
        }else{
            setIntermediare(i,coluns,F);
        }
    }
    
} 


void Truth_table::disjunction(int x,int z, int coluns){
analyse an;
    int line = pow(2, getNumber());
    
    an.next = 2;
    an.before = 2;

    //first analysis
    for(int i = 0; i < line; i++){
        if (coluns == 0){//analize if is first calc 
            an.before = getCon(i,x);
        }else{
            an.before = getIntermediare(i,coluns);
        }
        an.next = getCon(i,z);

        if((an.before || an.next) == T){
            
            setIntermediare(i,coluns,T);
        }else{
            setIntermediare(i,coluns,F);
        }
    }
} 

void Truth_table::disjunction(int z, int coluns){
    analyse an;
    int line = pow(2, getNumber());
    
    //first analysis
    for(int i = 0; i < line; i++){
       
        an.before = getIntermediare(i,coluns-1);
        an.next = getCon(i,z);
        if((an.before || an.next) == T){
            setIntermediare(i,coluns,T);
        }else{
            setIntermediare(i,coluns,F);
        }
    }
} 

void Truth_table::implication(int x,int z, int coluns){
    analyse an;
    int line = pow(2, getNumber());
    
    an.next = 2;
    an.before = 2;

    if(an.next && an.before == 2){ //first analysis
        for(int i = 0; i < line; i++){
            if (coluns == 0){//analize if is first calc 
            an.before = getCon(i,x);
        }
        an.next = getCon(i,z);

            if((an.before == T) && (an.next == F)){
                setIntermediare(i,coluns,F);
            }else{
                setIntermediare(i,coluns,T);
            }
        }
    } 
} 

void Truth_table::implication(int z, int coluns){
    analyse an;
    int line = pow(2, getNumber());
    

    if(an.next && an.before == 2){ //first analysis
        for(int i = 0; i < line; i++){

        an.before = getIntermediare(i,coluns-1);   
        an.next = getCon(i,z);

            if((an.before == T) && (an.next == F)){
                setIntermediare(i,coluns,F);
            }else{
                setIntermediare(i,coluns,T);
            }
        }
    } 
} 

void Truth_table::bicondicional(int x,int z, int coluns){
    analyse an;
    int line = pow(2, getNumber());
    
    an.next = 2;
    an.before = 2;

    if(an.next && an.before == 2){ //first analysis
        for(int i = 0; i < line; i++){
            if (coluns == 0){//analize if is first calc 
            an.before = getCon(i,x);
        }
        an.next = getCon(i,z);

            if(((an.before == T) && (an.next== T)) || ((an.before== F) && (an.next== F))){
                setIntermediare(i,coluns,T);
            }else{
                setIntermediare(i,coluns,F);
            }
        }
    } 
} 
void Truth_table::bicondicional(int z, int coluns){
    analyse an;
    int line = pow(2, getNumber());
     for(int i = 0; i < line; i++){
        an.before = getCon(i,coluns-1);
        an.next = getCon(i,z);

        if(((an.before == T) && (an.next== T)) || ((an.before== F) && (an.next== F))){
            setIntermediare(i,coluns,T);
        }else{
            setIntermediare(i,coluns,F);
        }
    }
} 

void Truth_table::table(){   
    std::cout <<std::endl;
    std::cout <<"=================="<< std::endl;
    for(int i = 0; i < getNumber(); i++){
        std::cout<<"|"<< getVar(i) << "  ";
    }
    std::cout<<"|";
    for(int i = 0; i < getSizeExpression(); i++){
        std::cout << getExpression(i);
    }
    std::cout<<"\n================="<< std::endl;
    for(int i = 0; i <pow(2,getNumber ()); i++){
        for (int j = 0; j < getNumber(); j++){
            std::cout<<"|" <<getCon(i,j)<< "  ";
        }
        std::cout<<"|     " <<getResult(i) << std::endl;
    }

    std::cout<<"=================";

}
