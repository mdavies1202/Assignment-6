/* Michael Davies
 * 12/4/13
 * Purpose: Assignment 6
 */

//Libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//Global Variables

//Main Function Prototypes
void menu();
void program1();
void program2();
void program3();
void program4();
void program5();
void program6();
void program7();
bool repeat();

void cleanArray(int[],int);
int hex2dec(const string);   
void largeNum(int[],int);
void sumArrayEle(int[], int[], int[], int);
void getString(string&);
void countOcc(string&, int[], int);
void outputOcc(string&,int[],int);
float average(float[],int);
float stanDevi(float[],int,float);

//poker functions
void createDeck(int[],int[],int);
void printHand(int[],int[],int);
void scoreHand(int[],int[],int);
bool checkFlush(int[]);
int checkPairs(int[]);
bool checkStrt(int[]);

//Arrays
void fillArray(int[], int SIZE, int min, int max);
void printArray(int [], int size, int);
void printCharArray(char[], int SIZE, int);
void char2dec(char[], int[], int SIZE, bool);
int getArraySize(int[],int size, int value);
int arrayFind(int [], int n, int find);
void shiftArray(int[],int size);
void reverseArray(int[], int size);
void setArrayZero(int[],int size);
void bubbleSort(int[], int size, int start);
void swapElements(int&, int&);
void swapElements(char&, char&);
void randomIndex(int[],int,int,int);
void masterSort(int[],int);

int main(int argc, char** argv) {
    
    menu();
    cout<<"\nYou have completed assignmen 6.\n";
    return 0;
}
  
//main
void menu(){
    char r;
    int c;
    //menu
    do{
        r='y';
        
        cout<<"\n"
            <<"\nAssignment 6 - Arrays"
            <<"\n___________________________________________________________"
            <<"\n'1'  Adding Hex Values"
            <<"\n'2'  Removing Repeats" 
            <<"\n'3'  Adding Out of Bounds Integers"            
            <<"\n'4'  Testing Bubble Sort"            
            <<"\n'5'  Scoring a Poker Hand"           
            <<"\n'6'  Counting Occurrences"           
            <<"\n'7'  Standard Deviation";
        do{
            cout<<"\n___________________________________________________________"
                <<"\nPlease Enter the number of the program you'd like to use:  ";
            cin>>c;
        }while(c<1||c>7);
        
        switch(c){
            case 1:  program1()  ; break;
            case 2:  program2()  ; break;    
            case 3:  program3()  ; break;
            case 4:  program4()  ; break;
            case 5:  program5()  ; break;
            case 6:  program6()  ; break;
            case 7:  program7()  ; break;
        
        }
        if(c>0&&c<=7){
            cout<<"\nEnd of program. "<<c<<".\n"
                <<"Would you like to go back to the main menu [y/n]?  ";
            cin>>r;
         }
    }while(!(r=='N'||r=='n'));
}
bool repeat(){
    char r;
    cout<<"\nWould you like to make do another calculation? [y/n]?  ";
    cin>>r;
    if(r!='n'&&r!='N'){
        return 1;
    }
    else{
        return 0;
    }
}
void program1(){
    string hex;
    int dec=1;
    cout<<"\n___________________________________________________________"; 
    cout<<"\n________________  Adding Hex Numbers   ____________________";
    cout<<"\n___________________________________________________________\n";
    cout<<"This program will add two hex numbers and output the integer value.\n";
    do{ 
        cout<<"Enter Hex Number 1:   ";
        cin.ignore();
        getline(cin,hex);
        dec=hex2dec(hex);
        cout<<"Enter Hex Number 2: + ";
        getline(cin,hex);
        dec+=hex2dec(hex);
        cout<<"___________________________________________________________\n";
        cout<<"                   =  "<<dec;
    }while(repeat()); 
}
void program2(){
    const int SIZE=25;
    char array[SIZE];
    int dec[SIZE];
    cout<<"\n___________________________________________________________"; 
    cout<<"\n___________ Removing Repeats in an Array __________________";
    cout<<"\n___________________________________________________________";
    cout<<"\nThis program will delete any repeats in a random character array\n";
     do{ 
         cout<<"Random Array:  \n";
         fillArray(dec, SIZE, 97, 122);
         char2dec(array, dec, SIZE, false);
         printCharArray(array, SIZE, 5);
         char2dec(array, dec, SIZE, true);
         cout<<"\nFixed Array:  \n";
         cleanArray(dec,SIZE);       
         int size=getArraySize(dec, SIZE, 0);
         char2dec(array, dec, size, false);
         printCharArray(array, size, 5);
    }while(repeat());  
}
void program3(){
    const int SIZE=20;
    cout<<"\n___________________________________________________________"; 
    cout<<"\n__________ Summing Out of Bounds Integers _________________";
    cout<<"\n___________________________________________________________";
    cout<<"\nThis program will allow the summation of two integers outside the range of int.\n";
     do{ 
         int num1[SIZE], num2[SIZE], sum[SIZE+1];
         setArrayZero(num1,SIZE);
         setArrayZero(num2,SIZE);
         
        
         cin.ignore();
         cout<<"Only enter integers with less than 20 digits\n";
         cout<<"Number 1:  ";
         largeNum(num1, SIZE);
      
         cout<<"Number 2:  ";
         largeNum(num2, SIZE);
       
         sumArrayEle(num1, num2, sum, SIZE);
         
         //sum
         bool numStart=false;
 
         cout<<"     Sum:  ";
         for(int i=0; i<SIZE; i++){
             if(sum[i]&&!numStart){numStart=true;}
             if(numStart){cout<<sum[i];}  
         }
    }while(repeat()); 
}
void program4(){
    const int SIZE = 10;
    int unsort[SIZE], sort[SIZE];
    cout<<"\n___________________________________________________________"; 
    cout<<"\n_________ Demonstration of Bubble Sort ____________________";
    cout<<"\n___________________________________________________________";
    cout<<"\nThis program will output an array as I bubble sort the values\n";
     do{ 
         cout<<"Unsorted Array:\n";
         fillArray(unsort, SIZE,1,10);
         printArray(unsort, SIZE, 10);
         cout<<"Sorted Array:\n";
         setArrayZero(sort, SIZE);
         printArray(sort, SIZE, 10);
         for(int i=0;i<SIZE;i++){
             sort[i]=unsort[i];
             bubbleSort(sort,SIZE,i);
             printArray(sort,SIZE,10);
         }
    }while(repeat()); 
}
void program5(){
    const int SIZE=52;
    int face[SIZE];
    int suit[SIZE];
    cout<<"\n___________________________________________________________"; 
    cout<<"\n_____________ Scoring Poker Hands   _______________________";
    cout<<"\n___________________________________________________________";
    cout<<"\nThis program generates random poker hands and outputs their value.\n";
    do{
        createDeck(face, suit, SIZE);
        cout<<endl<<"Your Hand:  "<<endl;
        printHand(face,suit,5);
        scoreHand(face,suit,5);
        cout<<endl;
    }while(repeat());  
}
void program6(){
    cout<<"\n___________________________________________________________"; 
    cout<<"\n______________ Occurrences per line _______________________";
    cout<<"\n___________________________________________________________";
    cout<<"\nThis program counts the occurrences of each character in a string.\n";
     do{
         string a;
         getString(a);
         const int SIZE=a.length();
         int index[SIZE];
         setArrayZero(index,SIZE);
         countOcc(a,index,SIZE);
         outputOcc(a,index,SIZE);
         
         
    }while(repeat()); 
}
void program7(){
    int size=0;
    cout<<"\n___________________________________________________________"; 
    cout<<"\n_______________ Welcome to Standard Deviation  ____________";
    cout<<"\n___________________________________________________________";
    cout<<"\nThis program calculates standard deviation.\n";
     do{ 
         cout<<"Enter number of values:  ";
         cin>>size;
         const int SIZE=size;
         float dataSet[SIZE];
         for(int i=0;i<SIZE;i++){
             cout<<"Enter Value "<<i+1<<":  ";
             cin>>dataSet[i];
         }
         float avg = average(dataSet, SIZE);
         cout<<"Standard Deviation:  "<<stanDevi(dataSet, SIZE, avg);
    }while(repeat()); 
}

void fillArray(int a[], int size, int min, int max){
    srand(time(0));
    for(int i=0, n=0;i<size;i++){
        a[i]=rand()%(max-min)+min;
        
    }
}
void printArray(int a[], int size, int perLine){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)){
            cout<<endl;
        }
    }
}
void shiftArray(int a[],int size){

    int b[size];
    for(int i=0;i<size;i++){b[i]=0;}

    for(int i=0,j=0;i<size;i++){
        if(a[i]){b[j]=a[i];j++;}
    }

    for(int i=0;i<size;i++){
        a[i]=b[i];
    }
}
void reverseArray(int a[], int size){
    int temp[size];
    for(int i=size-1, n=0; n<size; i--,n++){
        temp[n]=a[i];
    }
    for(int i=0; i<size; i++){
        a[i]=temp[i];
    }
}
void printCharArray(char a[], int size, int perLine){
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1)){
            cout<<endl;
        }
    }
}
void char2dec(char a[], int d[], int size, bool c2d){
    if(!c2d){
        for(int i=0;i<size;i++){
            a[i]=d[i];
        }
    }
    else{
        for(int i=0;i<size;i++){
            d[i]=a[i];
        }
    }
}
int getArraySize(int a[],int size, int value){
    for(int i=0;i<size;i++){
        if(a[i]==value)
            return i;
    }
    return size;
}
void setArrayZero(int a[], int size){
    for(int i=0;i<size;i++){a[i]=0;}
}
void bubbleSort(int a[], int size, int start){
    if(start)
        for(int i=start;i>0;i--){
            if(a[i]<a[i-1])
                swapElements(a[i],a[i-1]);
        }
}
void swapElements(int &p, int &q){
    p ^= q;
    q ^= p;
    p ^= q;
}
void swapElements(char &p, char &q){
    p ^= q;
    q ^= p;
    p ^= q;
}
void randomIndex(int a[], int size, int min, int max){
    srand(time(0));
    int random;
    setArrayZero(a,size);
    for(int i=0;i<size;i++){

        do{
            random=rand()%max+min;
        }while(a[random]!=0);

        a[random]=i;   
    }
}
void masterSort(int a[],int size){
    for(int i=0;i<size;i++){
        bubbleSort(a,size,i);
    }
}


int hex2dec(const string a){
    int dec=0;
    if(a.length()>=8){
        cout<<"Overload\n\n";
        return 0;
    }

    for(int i=0, n=a.length()-1;i<a.length();i++, n--){
        if(a[i]=='0'){dec+=(0*pow(16,n));}
        else if(a[i]=='1'){dec+=(1*pow(16,n));}
        else if(a[i]=='2'){dec+=(2*pow(16,n));}     
        else if(a[i]=='3'){dec+=(3*pow(16,n));}
        else if(a[i]=='4'){dec+=(4*pow(16,n));}
        else if(a[i]=='5'){dec+=(5*pow(16,n));}
        else if(a[i]=='6'){dec+=(6*pow(16,n));}
        else if(a[i]=='7'){dec+=(7*pow(16,n));}
        else if(a[i]=='8'){dec+=(8*pow(16,n));}
        else if(a[i]=='9'){dec+=(9*pow(16,n));}
        else if(a[i]=='a'||a[i]=='A'){dec+=(10*pow(16,n));}
        else if(a[i]=='b'||a[i]=='B'){dec+=(11*pow(16,n));}
        else if(a[i]=='c'||a[i]=='C'){dec+=(12*pow(16,n));}
        else if(a[i]=='d'||a[i]=='D'){dec+=(13*pow(16,n));}
        else if(a[i]=='e'||a[i]=='E'){dec+=(14*pow(16,n));}
        else if(a[i]=='f'||a[i]=='F'){dec+=(15*pow(16,n));}     
    }
    return dec;
}
void cleanArray(int a[],int size){
    for(int i=0;i<size;i++){
        for(int n=i+1;n<size;n++){
            if(a[i]==a[n]){a[n]=0;}
        }
    }
    shiftArray(a,size);
}
void largeNum(int a[],int size){
    string temp;
    do{
        getline(cin,temp);
    }while(temp.length()>19);
    for(int i=0; i<temp.length(); i++){
 
        a[i+size-temp.length()]=temp[i]-48;
    }
}
void sumArrayEle(int a[], int b[], int s[], int size){
    setArrayZero(s,size+1);
    for(int i=size+1;i>0;i--){
        s[i]+= a[i]+b[i];
        if(s[i]>=10){
            s[i-1]= 1;
            s[i] -= 10;
        }
    }
}
void getString(string &a){
    cout<<"Enter string:  ";
    cin.ignore();
    getline(cin,a);
}
void countOcc(string &a, int index[], int size){

    for(int i=0;i<size;i++){
        for(int c=0;c<size;c++){
            if(a[i]==a[c])index[i]++;
        }
    }
 
    for(int i=0;i<size;i++){
        if(i)
            for(int c=i;c>0;c--){
                if(index[c]<index[c-1]){
                    swapElements(a[c],a[c-1]);
                    swapElements(index[c],index[c-1]);
                }
            }
    }
    
    for(int i=0;i<size;i++){
        for(int c=0;c<size;c++){
            if(index[i]==index[c]&&a[i]!=a[c]){
                for(int n=i+1;n<size;n++){
                    if(a[i]==a[n]){
                        index[i]=0;
                    }
                }
            }
        }
    }
}
void outputOcc(string &a,int index[],int size){
    cout<<"Letter  occurence\n";
    for(int i=size;i>=0;i--){
        if(index[i]==0||index[i]>20);
        else if(i==0){
            cout<<"  "<<a[i]<<"         "<<index[i]<<endl;
        }
        else if(a[i]!=a[i-1]){
            cout<<"  "<<a[i]<<"         "<<index[i]<<endl;
        }
    }
}
float average(float a[],int size){
    float average=0;
    for(int i=0;i<size;i++){
        average += a[i];
    }
    return average/size;
}
float stanDevi(float a[],int size, float aver){
    float std=0;
    for(int i=0;i<size;i++){
        std+=((a[i]-aver)*(a[i]-aver));
    }
    return sqrt(std/(size));
}


void createDeck(int face[], int suit[], int size){
    
    int index[size];
    randomIndex(index,size,0,size);
   
    for(int i=0;i<size;i++){
        face[i]=index[i]%13+1;
        suit[i]=index[i]%4;
    }
    
}
void printHand(int face[], int suit[], int size){
    for(int i=0;i<size;i++){
        switch(face[i]){
            case 1:cout<<"Ace";break;
            case 2:cout<<"Two";break;
            case 3:cout<<"Three";break;
            case 4:cout<<"Four";break;
            case 5:cout<<"Five";break;
            case 6:cout<<"Six";break;
            case 7:cout<<"Seven";break;
            case 8:cout<<"Eight";break;
            case 9:cout<<"Nine";break;
            case 10:cout<<"Ten";break;
            case 11:cout<<"Jack";break;
            case 12:cout<<"Queen";break;
            case 13:cout<<"King";break;
        }
        cout<<" of ";
        switch(suit[i]){
            case 0:cout<<"Hearts";break;
            case 1:cout<<"Spades";break;
            case 2:cout<<"Diamonds";break;
            case 3:cout<<"Clubs";break;
        }
        cout<<endl;
    }
}
void scoreHand(int face[],int suit[],int size){
    bool strt;
    bool flush = checkFlush(suit);
    int pairs = checkPairs(face);
    if(pairs==0)strt=checkStrt(face);
    
    
    if(flush&&strt)cout<<endl<<"Straight Flush!";
    else if(pairs==6)cout<<endl<<"Four of a Kind!";
    else if(pairs==4)cout<<endl<<"Full House!";
    else if(flush)cout<<endl<<"Flush!";
    else if(strt)cout<<endl<<"Straight!";
    else if(pairs==3)cout<<endl<<"Three of a Kind!";
    else if(pairs==2)cout<<endl<<"Two Pair!";
    else if(pairs==1)cout<<endl<<"One Pair!";
    else{
        cout<<endl;
        switch(face[4]){
            case 1:cout<<"Ace";break;
            case 2:cout<<"Two";break;
            case 3:cout<<"Three";break;
            case 4:cout<<"Four";break;
            case 5:cout<<"Five";break;
            case 6:cout<<"Six";break;
            case 7:cout<<"Seven";break;
            case 8:cout<<"Eight";break;
            case 9:cout<<"Nine";break;
            case 10:cout<<"Ten";break;
            case 11:cout<<"Jack";break;
            case 12:cout<<"Queen";break;
            case 13:cout<<"King";break;
        }
        cout<<" High.";
    }
    
}
bool checkFlush(int suit[]){
    if(suit[0]==suit[1]&&suit[0]==suit[2]&&suit[0]==suit[3]&&suit[0]==suit[4])
        return true;
    return false;
}
int checkPairs(int face[]){
    int pairs=0;
    for(int i=0;i<5;i++){
        for(int c=i+1;c<5;c++){
            if(face[i]==face[c]){
                pairs++;
            }
        }
    }
    return pairs;
}
bool checkStrt(int face[]){
    masterSort(face,5);
    if((face[0]+4==face[4])||face[0]==10)return true;
    return false;
}
