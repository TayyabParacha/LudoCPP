#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <ctime>
using namespace std;
int SIZE=52;
char ludo[] = {'*','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','*','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
std::map<char, int> playerOnePieces = {{'A',0},{'B',0},{'C',0},{'D',0},{'E',0},{'F',0}};
std::map<char, int> playerZeroPieces = {{'1',0},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0}};

bool passCheck = false;
int scoreZero = 0;
int scoreOne = 0;
char playerZeroFinal[] = {'>', '>', '>', '>', '>', '>'};
char playerOneFinal[] = {'<', '<', '<', '<', '<', '<'};

int winCheckOne(){
    if(playerOnePieces['A'] != -2) {
               return -1;
    }
    if(playerOnePieces['B'] != -2) {
        return -1;
    }
    if(playerOnePieces['C'] != -2) {
        return -1;
    }
    if(playerOnePieces['D'] != -2) {
        return -1;
    }
    if(playerOnePieces['E'] != -2) {
        return -1;
    }
    if(playerOnePieces['F'] != -2) {
        return -1;
    }
    return 1;
}


int winCheckZero(){
    for(int i=0;i<6;i++){
        if(playerZeroPieces['1'] != -2){
            return -1;
        }
        if(playerZeroPieces['2'] != -2){
            return -1;
        }
        if(playerZeroPieces['3'] != -2){
            return -1;
        }
        if(playerZeroPieces['4'] != -2){
            return -1;
        }
        if(playerZeroPieces['5'] != -2){
            return -1;
        }
        if(playerZeroPieces['6'] != -2){
            return -1;
        }
    }
    return 1;
}

void printSelectionZero(){
    std::map<char, int>::iterator it = playerZeroPieces.begin();
    // Iterate over the map using Iterator till end.
    while (it != playerZeroPieces.end())
    {
        // Accessing KEY from element pointed by it.
        char word = it->first;
        // Accessing VALUE from element pointed by it.
        int count = it->second;
        if(count!=-2){
            cout<<word<<",";
        }
        // Increment the Iterator to point to next entry
        it++;
    }
    cout<<"\n";

}
void printSelectionOne(){
    std::map<char, int>::iterator it = playerOnePieces.begin();
    // Iterate over the map using Iterator till end.
    while (it != playerOnePieces.end())
    {
        // Accessing KEY from element pointed by it.
        char word = it->first;
        // Accessing VALUE from element pointed by it.
        int count = it->second;
        if(count!=-2){
            cout<<word<<",";
        }
        // Increment the Iterator to point to next entry
        it++;
    }
    cout<<"\n";
}

bool checkBoardForZero(int value){
    if(playerZeroPieces['1']==value){
        return false;
    }
    if(playerZeroPieces['2']==value){
        return false;
    }
    if(playerZeroPieces['3']==value){
        return false;
    }
    if(playerZeroPieces['4']==value){
        return false;
    }
    if(playerZeroPieces['5']==value){
        return false;
    }
    if(playerZeroPieces['6']==value){
        return false;
    }
    return true;
}
bool checkBoardForOne(int value){
    if(playerOnePieces['A']==value){
        return false;
    }
    if(playerOnePieces['B']==value){
        return false;
    }
    if(playerOnePieces['C']==value){
        return false;
    }
    if(playerOnePieces['D']==value){
        return false;
    }
    if(playerOnePieces['E']==value){
        return false;
    }
    if(playerOnePieces['F']==value){
        return false;
    }
    return true;
}
void printBoard(){
    cout<<"            "<<ludo[10]<<" "<<ludo[11]<<" "<<ludo[12]<<"            "<<"\n";
    cout<<"            "<<ludo[9]<<"   "<<ludo[13]<<"            "<<"\n";
    cout<<"            "<<ludo[8]<<"   "<<ludo[14]<<"            "<<"\n";
    cout<<"            "<<ludo[7]<<"   "<<ludo[15]<<"            "<<"\n";
    cout<<"            "<<ludo[6]<<"   "<<ludo[16]<<"            "<<"\n";
    cout<<"            "<<ludo[5]<<"   "<<ludo[17]<<"            "<<"\n";
    cout<<ludo[51]<<" "<<ludo[0]<<" "<<ludo[1]<<" "<<ludo[2]<<" "<<ludo[3]<<" "<<ludo[4]<<"       "<<ludo[18]<<" "<<ludo[19]<<" "<<ludo[20]<<" "<<ludo[21]<<" "<<ludo[22]<<" "<<ludo[23]<<"\n";
    cout << ludo[50] << " " << playerZeroFinal[0] << " " << playerZeroFinal[1] << " " << playerZeroFinal[2] << " " << playerZeroFinal[3] << " " << playerZeroFinal[4] << "   " << "X" << "   " << playerOneFinal[4] << " " << playerOneFinal[3] << " " << playerOneFinal[2] << " " << playerOneFinal[1] << " " << playerOneFinal[0] << " " << ludo[24] << "\n";
    cout<<ludo[49]<<" "<<ludo[48]<<" "<<ludo[47]<<" "<<ludo[46]<<" "<<ludo[45]<<" "<<ludo[44]<<"       "<<ludo[30]<<" "<<ludo[29]<<" "<<ludo[28]<<" "<<ludo[27]<<" "<<ludo[26]<<" "<<ludo[25]<<"\n";
    cout<<"            "<<ludo[43]<<"   "<<ludo[31]<<"            "<<"\n";
    cout<<"            "<<ludo[42]<<"   "<<ludo[32]<<"            "<<"\n";
    cout<<"            "<<ludo[41]<<"   "<<ludo[33]<<"            "<<"\n";
    cout<<"            "<<ludo[40]<<"   "<<ludo[34]<<"            "<<"\n";
    cout<<"            "<<ludo[39]<<"   "<<ludo[35]<<"            "<<"\n";
    cout<<"            "<<ludo[38]<<" "<<ludo[37]<<" "<<ludo[36]<<"            "<<"\n";

}
void playerZeroTurn(int randomNumber){
    cout<<"Your roll is: "<<randomNumber<<"\n\n";
    cout<<"Player 0 score: "<<scoreZero<<"\n";
    cout<<"Player 1 score: "<<scoreOne<<"\n\n";

    //Player Zero Turn
    printSelectionZero();
    cout<<"Chose any of the above pieces :";
    char select;
    cin>>select;
    int previousValue=playerZeroPieces[select];
    int newValue=playerZeroPieces[select]+randomNumber;
    bool check=checkBoardForZero(newValue);
    if(check==false){
        cout<<"Your piece already at the new value, Your move passed\n";
    }
    else {
        if (ludo[newValue] != '0' or ludo[newValue] != '*') {
            playerOnePieces[ludo[newValue]] = 0;
        }
        if (newValue > 50) {
            int actual=newValue;
            if(actual>56){
                if (previousValue > 50) {
                    previousValue = previousValue - 50 - 1;
                    playerZeroFinal[previousValue] = '>';
                }
                else{
                    ludo[previousValue] = '0';
                }
                playerZeroPieces[select] = -2;
                scoreZero=scoreZero+1;
            }
            else{
                newValue = newValue - 50 - 1;
                playerZeroFinal[newValue] = select;
                if (previousValue > 50) {
                    previousValue = previousValue - 50 - 1;
                    playerZeroFinal[previousValue] = '>';
                }
                else{
                    ludo[previousValue] = '0';
                }
                playerZeroPieces[select] = actual;
            }
        }
        else{
            if(previousValue==0){
                if(select=='1'){
                    ludo[newValue]='1';
                    playerZeroPieces['1'] = newValue;
                }
                else if(select=='2'){
                    ludo[newValue]='2';
                    playerZeroPieces['2'] = newValue;

                }
                else if(select=='3'){
                    ludo[newValue]='3';
                    playerZeroPieces['3'] = newValue;


                }else if(select=='4'){
                    ludo[newValue]='4';
                    playerZeroPieces['4'] = newValue;

                }else if(select=='5'){
                    ludo[newValue]='5';
                    playerZeroPieces['5'] = newValue;

                }
                else if(select=='6'){
                    ludo[newValue]='6';
                    playerZeroPieces['6'] = newValue;
                }
            }
            else{
                if(previousValue==26){
                    ludo[previousValue]='*';
                }
                else{
                    ludo[previousValue]='0';
                }
                if(select=='1'){
                    ludo[newValue]='1';
                    playerZeroPieces['1'] = newValue;
                }
                else if(select=='2'){
                    ludo[newValue]='2';
                    playerZeroPieces['2'] = newValue;

                }
                else if(select=='3'){
                    ludo[newValue]='3';
                    playerZeroPieces['3'] = newValue;


                }else if(select=='4'){
                    ludo[newValue]='4';
                    playerZeroPieces['4'] = newValue;

                }else if(select=='5'){
                    ludo[newValue]='5';
                    playerZeroPieces['5'] = newValue;

                }
                else if(select=='6'){
                    ludo[newValue]='6';
                    playerZeroPieces['6'] = newValue;
                }
            }
        }
    }
}
void playerOneTurn(int randomNumber){
    cout<<"Your roll is: "<<randomNumber<<"\n\n";
    cout<<"Player 0 score: "<<scoreZero<<"\n";
    cout<<"Player 1 score: "<<scoreOne<<"\n\n";
    //Player One Turn
    printSelectionOne();
    cout<<"Chose any of the above pieces :";
    char select;
    cin>>select;
    int previousValue=playerOnePieces[select];
    int newValue;
    if(previousValue==0){
        newValue=(playerOnePieces[select]+randomNumber+26)%52;
    }
    else{
        newValue=(playerOnePieces[select]+randomNumber)%52;
    }
    if(newValue<24){
        passCheck= true;
    }
    bool check=checkBoardForOne(newValue);
    if(check==false){
        cout<<"Your piece already at the new value, Your move passed\n";
    }
    else {
        if (ludo[newValue] != '0' or ludo[newValue] != '*') {
            playerZeroPieces[ludo[newValue]] = 0;
        }
        if (passCheck==true and newValue > 24) {
            int actual=newValue;
            if(actual>30){
                if (previousValue > 24) {
                    previousValue = previousValue - 24 - 1;
                    playerOneFinal[previousValue] = '<';
                }
                else{
                    ludo[previousValue] = '0';
                }
                playerOnePieces[select] = -2;
                scoreOne=scoreOne+1;
            }
            else{
                newValue = newValue - 24 - 1;
                playerOneFinal[newValue] = select;
                if (previousValue > 24) {
                    previousValue = previousValue - 24 - 1;
                    playerOneFinal[previousValue] = '<';
                }
                else{
                    ludo[previousValue] = '0';
                }
                playerOnePieces[select] = actual;
            }
        }
        else{
            if(previousValue==0){
                if(select=='A'){
                    ludo[newValue]='A';
                    playerOnePieces['A'] = newValue;
                }
                else if(select=='B'){
                    ludo[newValue]='B';
                    playerOnePieces['B'] = newValue;

                }
                else if(select=='C'){
                    ludo[newValue]='C';
                    playerOnePieces['C'] = newValue;


                }else if(select=='D'){
                    ludo[newValue]='D';
                    playerOnePieces['D'] = newValue;

                }else if(select=='E'){
                    ludo[newValue]='E';
                    playerOnePieces['E'] = newValue;

                }
                else if(select=='F'){
                    ludo[newValue]='F';
                    playerOnePieces['F'] = newValue;
                }
            }
            else{
                if(previousValue==0){
                    ludo[previousValue]='*';
                }
                else{
                    ludo[previousValue]='0';
                }
                if(select=='A'){
                    ludo[newValue]='A';
                    playerOnePieces['A'] = newValue;
                }
                else if(select=='B'){
                    ludo[newValue]='B';
                    playerOnePieces['B'] = newValue;

                }
                else if(select=='C'){
                    ludo[newValue]='C';
                    playerOnePieces['C'] = newValue;


                }else if(select=='D'){
                    ludo[newValue]='D';
                    playerOnePieces['D'] = newValue;

                }else if(select=='E'){
                    ludo[newValue]='E';
                    playerOnePieces['E'] = newValue;

                }
                else if(select=='F'){
                    ludo[newValue]='F';
                    playerOnePieces['F'] = newValue;
                }
            }
        }
    }
}

int main() {
    printBoard();
    srand((unsigned) time(0));
    while (true) {
        if(winCheckOne()==1){
            cout<<"Player One Wins!!";
            break;
        }
        if(winCheckZero()==1){
            cout<<"Player Two Wins!!";
            break;
        }
        int randomNumber;
        randomNumber = (rand() % 6) + 1;
        playerZeroTurn(randomNumber); //Player Zero Turn
        cout<<"\n";
        printBoard();
        randomNumber = (rand() % 6) + 1;
        playerOneTurn(randomNumber); //Player One Turn
        printBoard();
    }
    return 0;
}
