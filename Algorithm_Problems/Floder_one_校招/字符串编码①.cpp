/*[编程题] 字符串编码
给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。 
输入描述:
每个测试输入包含1个测试用例
每个测试用例输入只有一行字符串，字符串只包括大写英文字母，长度不超过10000。


输出描述:
输出编码后的字符串

输入例子:
AAAABCCDAA

输出例子:
4A1B2C1D2A
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt,i=0;
    string::iterator it=s.begin(),ed=s.end();
    while((it!=ed)){
        cnt=0;
        while(*it==*(++it)){++cnt;}
        cnt+=1;
        cout<<cnt<<*(it-1);
    }
    cout<<endl;

    return 0;
}
