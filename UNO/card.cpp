#include "card.h"

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()) {
        return true;
    }
    else {
        return false;
    }
}

WildCard::WildCard(Color c, int n) {
    setColor(c);
    setNumber(n);
}

string WildCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   Wild    |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}

bool WildCard::play(Card* discard, GameState &gameState) {// parameters are only here so the code doesn't throw a tantrum
    int colorNum;
    bool doneWithColors = false;
    cout << "You chose the wild card, please choose a color: 0-RED, 1-BLUE, 2-GREEN, 3-YELLOW" << endl;
    cin >> colorNum;
    while (doneWithColors != true) {
        if (colorNum == 0) {
            color = RED;
            doneWithColors = true;
        }
        else if (colorNum == 1) {
            color = BLUE;
            doneWithColors = true;
        }
        else if (colorNum == 2) {
            color = GREEN;
            doneWithColors = true;
        }
        else if (colorNum == 3) {
            color = YELLOW;
            doneWithColors = true;
        }
        else {
            cout << "Invalid entry, please try again." << endl;
            cin >> colorNum;
        }
    }
    
    return true;
}
