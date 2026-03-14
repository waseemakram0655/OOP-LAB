//The properoty to derive characteristics and properties from another class
//Private is not inherited like if a private and child class is public then not inherited.
//child class
//The inheritance follows the foolowing order
//Private>Protected>Public
//private*protected=private
//protected*public=public
//              MAIN    WITHINBASECLASS    WITHINDERIVED
//PUBLIC:         Y             Y                   Y
//PRIVATE:        N             Y                   N
//PROTECTED       N             Y                   Y

//  TYPES OF INHERITANCE
//SINGLE INHERITANCE
//One derived class one parent class inheriting that
//student->human
//Firstly the constructor will be called for parent class then child class
//Destructor will be called first of child then that of parent.
//If there is function overloading then the function of the called class i.e. derived class is called but we can clarify =========through scope resolution operator===.
//like base::show();

//MULTILEVEL INHERITANCE
//There must be multiple levels of inheritance 
//grandfather->father->son
//person->employee->manager
//The access modifiers will be decided on the basis of inherited access modifiers and existing like
//public*public*private=private
//Following the same power order as mentioned above
//
//MULTIPLE INHERITANCE
//In this child inherits from multiple parents classes
//student->boy
//son->boy
//The boy inherits from both son and student parent classes
//The constructors calls first of the one which is placed first in the list whose properties are inherited first
//The destructor sequence will be reverse the constructor sequence. 

//HIERARICAL INHERITANCE:
//Multiple child classes originate from one parent class 
//
//HYBRID INHERITANCE:
//The type of inheritance by using more than one type of inheritance is hybrid.
//Like Multiple and hierarical.

//MULTIPATH INHERITANCE
//In this case due to this ambiguous naming we use virtual keyword to overcome amgiguity.
//