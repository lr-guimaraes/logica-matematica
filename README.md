# logica-matematica

## Entrada
 - As proposições devem conter parenteses no inicio
 - São aceitas preposições no formato (A prep B) ou ((A prep1 B)prep C)

## Duas variaveis 
### Conjunção
    Type of the number variables between 1 and 3: 2
    Type it variable: p
    Type it variable: q
     =========================
    |  PREPOSITIONS  | INPUTS |
    |================|========|
    |Conjuction      |   ^    |
    |Dijuntion       |   v    |
    |Implication     |   >    |
    |Biconditional   |   b    |
    |Negation        |   ~    |
     ========================= 
    Type the expresson: (p^q)  
    Exit: Truth table 2^2
    ==================   
    |p  |q  |(p^q)      
    =================    
    |0  |0  |     0      
    |1  |0  |     0      
    |0  |1  |     0      
    |1  |1  |     1      
    =================    
  ### disjunção
   
    Type of the number variables between 1 and 3: 2
    Type it variable: p
    Type it variable: q
     =========================
    |  PREPOSITIONS  | INPUTS |
    |================|========|
    |Conjuction      |   ^    |
    |Dijuntion       |   v    |
    |Implication     |   >    |
    |Biconditional   |   b    |
    |Negation        |   ~    |
     ========================= 
    Type the expresson: (pvq)  
    Exit: Truth table 2^2
    ==================   
    |p  |q  |(pvq)      
    =================    
    |0  |0  |     0      
    |1  |0  |     1      
    |0  |1  |     1      
    |1  |1  |     1      
    =================    
  ### Implication
  
    Type of the number variables between 1 and 3: 2
    Type it variable: p
    Type it variable: q
     =========================
    |  PREPOSITIONS  | INPUTS |
    |================|========|
    |Conjuction      |   ^    |
    |Dijuntion       |   v    |
    |Implication     |   >    |
    |Biconditional   |   b    |
    |Negation        |   ~    |
     ========================= 
    Type the expresson: (p>q)
    Exit: Truth table 2^2
    ==================
    |p  |q  |(p>q)
    =================
    |0  |0  |     1
    |1  |0  |     0
    |0  |1  |     1
    |1  |1  |     1
    =================
    
   ### Bicondional
   
    Type of the number variables between 1 and 3: 2
    Type it variable: p
    Type it variable: q
     =========================
    |  PREPOSITIONS  | INPUTS |
    |================|========|
    |Conjuction      |   ^    |
    |Dijuntion       |   v    |
    |Implication     |   >    |
    |Biconditional   |   b    |
    |Negation        |   ~    |
     ========================= 
    Type the expresson: (pbq)
    Exit: Truth table 2^2
    ==================
    |p  |q  |(pbq)
    =================
    |0  |0  |     1
    |1  |0  |     0
    |0  |1  |     0
    |1  |1  |     1
    =================
### Tautologia 

    Type of the number variables between 1 and 3: 2
    Type it variable: p
    Type it variable: q
     =========================
    |  PREPOSITIONS  | INPUTS |
    |================|========|
    |Conjuction      |   ^    |
    |Dijuntion       |   v    |
    |Implication     |   >    |
    |Biconditional   |   b    |
    |Negation        |   ~    |
     ========================= 
    Type the expresson: ((p>q)vp)
    Exit: Truth table 2^2
    ==================
    |p  |q  |((p>q)vp)
    =================
    |0  |0  |     1
    |1  |0  |     1
    |0  |1  |     1
    |1  |1  |     1
    =================
