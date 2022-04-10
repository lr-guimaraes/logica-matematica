    #include <iostream>
    #include <vector>
    #include <math.h>
    #define T 1
    #define F 0

    class Operation{
        private:
            int result[5]; //straighten
            int number;
            char variable[1];//char *variable = new char[10];//std::vector< std::vector<int> >  variable; //
            std::vector< std::vector<int> > con;
        //  int **cont = new int[pow(2,number)][number]; //straighten  smartpointer
    
        public:
            void pushVar(char []);
            void pushT();

            void operation();
            void conjunction();
            void disjunction();
            void implication();
            void bicondicional();
            void truth_table();
            //void not();
            char getVar(int);
            void setVar(char, int);

            int getResult(int );
            void setResult(int, int);  

            int getNumber();
            void setNumber(int);  

            struct analyse{
                int before;
                int next;
            };
    };

    int main(){
        Operation op;
        int i = 0;
        int number;   
        

        std::cout <<"Type of the number variables: ";
        std::cin >>number; 
        
        op.setNumber(number);
    
        char str[number]; //straighten
        do{
            std::cout <<"Type it variable string: ";
            std::cin >>str[i];
            i++;
        }while(i < number);
        op.pushVar(str);
       // op.pushT();

        //op.truth_table();
    }

    int Operation::getNumber(){
        std::cout <<number;
        return number;
       
    }
    void Operation::setNumber(int n){
        number = n;
       //std::cout <<number;
    }

    char Operation::getVar(int i){
        return variable[i];
    }
    void Operation::setVar(char x,int i){
        variable[i] = x;
    }

    int Operation::getResult(int i){
        return result[i];
    }
    void Operation::setResult(int x,int i){
        result[i] = x;
    }

    void Operation::pushVar(char str[]){
        Operation op;
        int n = op.getNumber();
   //     char *variable = new char[n];
        std::cout <<n;
        con.resize(pow(2,n));       
        for(int i = 0; i < op.getNumber(); i++){
            setVar(str[i],i);
        //    std::cout << variable[i] <<";"; //test
           //std::cout <<" \n1test2\n";
            //std::cout <<getVar(i);
        }
        std::cout <<" \n2test2\n";
    }

    void Operation::pushT(){
        Operation op;
        int n = op.getNumber();

        int line = pow(2,n);
      //  int cont[line][n]; //straighten  smartpointer
        int k = 0;

        con.resize(pow(2,n));
        for(int i = 0; i <line; i++){
            con.resize(pow(2,n));
            for(int j = 0; j < n; j++){
                if(k <= (pow(2,j))/2){
                    con[i][j] = F;

                }else if((k > (pow(2,j))/2)){ //straighten
                    con[i][j] = T;
                }
                k++;
              //  std::cout <<con[i][j];
            }
            k = 0;   
        }
        
    }

    void Operation::conjunction(){
        Operation op;
        analyse an;
        
        int n = op.getNumber();
        int line = pow(2,n);
        
        an.next = 2;
        for(int i = 0; i < line; i++){
            for(int j = 0; j < n; j++){
                an.before = con[i][j];

                if(an.next == 2){ //first analysis
                    an.next = con[i][j];
                }else{
                    if((an.before || an.next) == T){
                        an.next = T;
                    }else{
                        an.next = F;
                    }
                }
            an.next = 2; //to not go with values from the previous line
            }
            setResult(an.next,0);
        }
    } 

    void Operation::disjunction(){
        Operation op;
        analyse an;
        int n = op.getNumber();
        int line = pow(2,n);
        
        an.next = 2;
        for(int i = 0; i < line; i++){
            for(int j = 0; j < n; j++){
                an.before = op.con[i][j];

                if(an.next == 2){ //first analize
                    an.next = op.con[i][j];
                }else{
                    if((an.before == T) && (an.next == T)){
                        an.next = T;
                    }else{
                        an.next = F;
                    }
                }
            }
        setResult(an.next,1);
        }
    }
    void Operation::implication(){
        Operation op;
        analyse an;
        int n = op.getNumber();
        int line = pow(2,n);

        an.next = 2;   
        for(int i = 0; i < line; i++){
            for(int j = 0; j < n; j++){
                an.before = op.con[i][j];

                if(an.next == 2){ //first analize
                    an.next = con[i][j];
                }else{
                    if((an.before == T) && (an.next == F)){
                        an.next = F;
                    }else{
                        an.next = T;
                    }
                }
            }
        setResult(an.next,2);
        }
    }
    void Operation::bicondicional(){
        Operation op;
        analyse an;
        int n = op.getNumber(); //test
        int line = pow(2,n);

    an.next = 2;
        for(int i = 0; i < line; i++){
            for(int j = 0; j < n; j++){
                an.before = op.con[i][j];

                if(an.next == 2){ //first analize
                    an.next = op.con[i][j];
                }else{
                    if(((an.before && an.next) == T) || (an.before && an.next) == F){
                        an.next = F;
                    }else{
                        an.next = T;
                    }
                }
            }
            setResult(an.next,3);
        }   
    }

    void Operation::truth_table(){
        Operation op;     
        op.conjunction();
        op.disjunction();
        op.implication();
        op.bicondicional();

        for(int i = 0; i < op.number; i++){
            std::cout<< getVar(i);
        }
        std::cout<<" |Conjunction | Disjunction | Implication | Binomial\n";

        for(int i = 0; i <op.number + 4; i++){
            for (int j = 0; j < pow(2,op.number); j++){
                std::cout<< op.con[i][j];
            }
            std::cout << op.getResult(1);
        }
    }
