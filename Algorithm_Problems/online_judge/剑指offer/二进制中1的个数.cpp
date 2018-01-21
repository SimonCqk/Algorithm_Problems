/*
输入一个整数，输出该数二进制表示中1的个数。
*/

/*
错误写法：
int NumOfOneInBinary(int num){
    int count=0;
    while(num){
        if(num&1)
            ++count;
        n >>= 1;
    }
    return count;
}

不支持输入负数，因为移位后要保证还是一个负数，最高符号位会设为1
引起死循环
*/

int NumOfOneInBinary(int num){
    int count=0;
    int flag = 1;
    while(num){
       if(flag&num)
        ++count;
       flag <<= 1; // 对于一个32位的int，必须循环32次才能结束(flag才为0)
    }
    return count;
}

/*
  n&(n-1):得到的数是把原来的数的最右边的1置0
  例如：001101 & 001100 = 001100
  相当于每次消掉一个1,直到全为0
*/
int NumOfOneInBinary(int num){
    int count=0;
    while(num){
      ++count;
      num = num & (num - 1);
    }
    return count;
}