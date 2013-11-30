enum State{
  START=0,
  SIGN=1,
  DIGIT=2,
  AFTER_DOT=3,
  AFTER_E=4,
  E_SIGN=5,
  E_DIGIT=6,
  ERROR=7,
  DOT_NO_DIGIT=8,
  SPACE=9,
};
int next_state(int x,char symbol){
    if(x==START){
        if(symbol==' ') return START;
        if(isdigit(symbol)) return DIGIT;
        if(symbol=='+'||symbol=='-') return SIGN;
        if(symbol=='.') return DOT_NO_DIGIT;
        return ERROR;
    }
    else if(x==SIGN){
        if(isdigit(symbol)) return DIGIT;
        if(symbol=='.') return DOT_NO_DIGIT;
        return ERROR;
    }else if(x==DIGIT){
        if(isdigit(symbol)) return DIGIT;
        if(symbol=='.') return AFTER_DOT;
        if(symbol=='e') return AFTER_E;
        if(symbol==' ') return SPACE;
        return ERROR;
    }else if(x==AFTER_DOT){
        if(isdigit(symbol)) return AFTER_DOT;
        if(symbol=='e') return AFTER_E;
        if(symbol==' ') return SPACE;
        return ERROR;
        
    }else if(x==AFTER_E){
        if(isdigit(symbol)) return E_DIGIT;
        if(symbol=='+' || symbol=='-') return E_SIGN;
        return ERROR;
    }else if(x==E_SIGN){
        if(isdigit(symbol)) return E_DIGIT;
        return ERROR;
    }else if(x==E_DIGIT){
        if(isdigit(symbol)) return E_DIGIT;
        if(symbol==' ') return SPACE;
        return ERROR;
    }else if(x==DOT_NO_DIGIT){
        if(isdigit(symbol)) return AFTER_DOT;
        return ERROR;
    }else if(x==SPACE){
        if(symbol==' ') return SPACE;
        return ERROR;
    }
}
bool accept(int state){
    return state==DIGIT || state==AFTER_DOT || state==E_DIGIT ||state==SPACE;
}
class Solution {
public:
    bool isNumber(const char *s) {
        int state=START;

        while(*s){
            state=next_state(state,*s);
            if(state==ERROR) return false;
            s++;
        }
    
        return accept(state);
    }
};
