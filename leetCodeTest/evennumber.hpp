#ifndef EVENNUMBER_HPP
#define EVENNUMBER_HPP
#include "pub.h"

//题目:给定正整数N、M，均介于1~10^9之间，N<=M，找出两者之间(含N、M)的位数为偶数的数有多少个。
#define STEP (2)
#define EVENBASE (2)
#define N (10)

// 计算整数位数
int getBits(int n){
    int count = 0;
    while (n != 0){
        n /= N;
        count++;
    }
    return count;
}

/*

得到n，m的位数
若n，m位数相同：
    为偶数，则返回 m - n + 1
    为奇数，则返回0


若n，m位数不同：
 分别判断起止区间n和m位数
  若n的位数为偶数，则 位数的末端数 - n + 1；如位数是2，则 99 - n + 1 (99 = 10^2 - 1)
  若m的位数为偶数，则 m - 位数的起始数 + 1；如位数是2，则 m - 10 + 1 (10 = 10^(2 - 1))
  其他情况，则不处理
从n的位数+1遍历到m的位数-1

*/

int totalEvenNumber(int n, int m){
    if (n > m){
        printf("error input [%d, %d]\n",n,m);
        return 0;
    }
    int even = 0;
    int bitN = getBits(n);
    int bitM = getBits(m);
    cout << "bitN=" << bitN << " bitM=" << bitM << endl;

    if (bitN == bitM){
        if (bitN % 2 == 0){
            even = m - n + 1;
            return even;
        }
        return 0;
    }

    if (bitN % EVENBASE == 0){
        even += ((int)pow(10, bitN) - 1) - n + 1; // [n,m]: m - n +1   99=100-1
        bitN++;
    }else{
        bitN++;
    }

    if (bitM % EVENBASE == 0){
        even += m - (int)pow(10, bitM - 1) + 1;
    }

    for (int i = bitN; i < bitM; i += STEP){
        even += ((int)pow(10, i) -  1) - (int)pow(10, i - 1) + 1; // m-n+1
    }

    return even;
}

#endif // EVENNUMBER_HPP
