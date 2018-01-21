/*
一根长度为n的绳子，请把绳子剪成m段，(m,n都是整数并且m,n>1)，每段
绳子的长度为k[0],k[1],k[2]...k[m].
请问k[0]*k[1]*k[2]...*k[m]最大的乘积是多少
*/

/*
动态规划法，O(n^2)的时间复杂度和O(n)的空间复杂度。
剪第一刀，有n-1种选择,剪出的第一段绳子长度可以是1,2...n-1。
因此状态方程：f(n)=max(f(i)*f(n-i)).
所以从下往上的顺序一直从f(1)得到f(n)
*/

int MaxCuttingProduct_DP(const int& len) {
  if (len < 2) return 0;
  if (len <= 3) return len - 1;  // len=2 return 1*1; len=3 return 1*2;
  vector<int> product(len + 1, 0);
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;
  int max = 0;
  for (int i = 4; i <= len; ++i) {
    max = 0;
    for (int j = 1; j <= i / 2; ++j) {
      int product = products[j] * products[i - j];
      max = std::max(max, product);
      products[i] = max;
    }
  }
  max = products[len];
  return max;
}

/*
贪婪法 时间复杂度O(1).
按照以下策略：n>=5时，尽可能多的剪长度为3的绳子；当剩下的绳子长度为4，剪成2段长度为2的绳子。
n>=5时，可以证明2(n-2)>n且3(n-3)>n
*/
int MaxCuttingProduct_Greedy(const int& len) {
  if (len < 2) return 0;
  if (len <= 3) return len - 1;  // len=2 return 1*1; len=3 return 1*2;
  // 尽量能剪成长度为3的绳子段
  int time_of_3 = len / 3;
  // 剩下长度为4，更好的办法是剪成长度为2的两段
  if (len - 3 * time_of_3 == 1) time_of_3 -= 1;
  int time_of_2 = (len - 3 * time_of_3) / 2;
  return static_cast<int>(std::pow(3, time_of_3)) *
         static_cast<int>(std::pow(2, time_of_2));
}