class Solution {
public:
     int isSetBit(int &x, int bit){
        return x & (1<<bit);
    }

    int setBit(int &x, int bit){
        return x = x | (1<<bit);
    }
    int unSetBit(int &x, int bit){
        return x = x & ~(1<<bit);
    }
    int minimizeXor(int num1, int num2) {
            int x = num1;
            int currentSetBitsCount = __builtin_popcount(x);
            int requiredSetBitsCount = __builtin_popcount(num2);

            if(currentSetBitsCount<requiredSetBitsCount){
                int bit=0;
                while(currentSetBitsCount<requiredSetBitsCount){
                    if(isSetBit(x,bit)==0){
                        setBit(x,bit);
                        currentSetBitsCount++;
                    }
                    bit++;
                }
            }
            else if(currentSetBitsCount>requiredSetBitsCount){
                int bit=0;
                while(currentSetBitsCount>requiredSetBitsCount){
                    if(isSetBit(x,bit)){
                        unSetBit(x,bit);
                         currentSetBitsCount--;
                    }
                    bit++;
                }
            }
            return x;
    }
};