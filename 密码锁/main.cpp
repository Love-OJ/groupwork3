#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 计算部分匹配表（LPS数组）
vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);// 初始化LPS数组，长度为模式串的长度，初始值都为0  
    int length = 0; // 前缀长度
    int i = 1;
//123
    while (i < m) {
        if (pattern[i] == pattern[length]) {// 当前字符与最长前缀后缀的下一个字符相等  
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {// 当前字符与最长前缀后缀的下一个字符不相等  
                length = lps[length - 1];
            } else {// 如果前缀长度为0，说明没有前缀后缀可以回退，只能逐个字符比较  
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP算法实现
bool kmpSearch(const string & pattern, const string & text) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    int i = 0; // text的索引
    int j = 0; // pattern的索引

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return true; // 找到匹配
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {// 如果模式串索引不为0，说明存在部分匹配，可以根据LPS数组回退  
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false; // 未找到匹配
}

int main() {
    string presetPassword, unlockSequence;
// 输入设定的开锁密码和开锁字符序列  
    cout << "请输入设定的开锁密码: ";
    cin >> presetPassword;
    cout << "请输入开锁字符序列: ";
    cin >> unlockSequence;
// 使用KMP算法在开锁字符序列中搜索设定的开锁密码  
    if (kmpSearch(presetPassword, unlockSequence)) {
        cout << "开锁成功！" << endl;
    } else {
        cout << "开锁失败！" << endl;
    }

    return 0;
}
