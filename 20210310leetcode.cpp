//
// @birth: created by Melrose on 2021/3/10
// @version: 1.0.0
//

//实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。
//
//
//示例 1：
//
//输入：s = "1 + 1"
//输出：2
//示例 2：
//
//输入：s = " 2-1 + 2 "
//输出：3
//示例 3：
//
//输入：s = "(1+(4+5+2)-3)+(6+8)"
//输出：23
// 
//
//提示：
//
//1 <= s.length <= 3 * 105
//s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
//s 表示一个有效的表达式
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/basic-calculator
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <string>
#include <stack>
using  namespace  std;


//(1+(4+5+2)-3)+(6+8)
//(1+(-4+5+2)-3)+(6+8)


//-1-(-1+1)

// -1
// 1
// -(1+1)

class Solution {
private:

public:
    int calculate(string s) {
        stack<int> symbol;
        // 初始为正号入栈
        symbol.push(1);
        int res = 0;
        // 符号
        int punctuation = 1;
        for(int i = 0; i < s.length(); i ++) {
            if (s[i] == ' '){
                continue;
            } else if (s[i] == '+') {
                // 更新符号
                punctuation = symbol.top();
            } else if (s[i] == '-') {
                // 更新符号
                punctuation = -symbol.top();
            } else if (s[i] == '(') {
                symbol.push(punctuation);
            } else if (s[i] == ')') {
                symbol.pop();
            } else {
                // 当前遍历到的数字
                long num = 0;
                while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                i --;
                res += punctuation * num;
            }
        }
        return res;

    }
};