//
// @birth: created by Melrose on 2021/3/5
// @version: 1.0.0

// https://leetcode-cn.com/problems/implement-queue-using-stacks/
//
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//        boolean empty() 如果队列为空，返回 true ；否则，返回 false
//
//说明：
//
//你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

//

#include <stack>

class MyQueue {
 private:
    std::stack<int> mIn,mOut;

 public:
    MyQueue() {

    }

    void push(int x) {
        mIn.push(x);
    }

    int pop() {
        if (mOut.empty()){
            while (!mIn.empty()){
                mOut.push(mIn.top());
                mIn.pop();
            }
        }
        int top = mOut.top();
        mOut.pop();
        return top;
    }

    int peek() {
        if (mOut.empty()){
            while (!mIn.empty()){
                mOut.push(mIn.top());
                mIn.pop();
            }
        }
        return mOut.top();
    }

    bool empty() {
        return  mOut.empty()&&mIn.empty();
    }
};


int main() {
    auto queue = new MyQueue;

    queue->push(1);
    queue->push(2);
    queue->push(3);

    while (!queue->empty()){
        printf("%d\n",queue->pop());
    }
    return 0;
}

