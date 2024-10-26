#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ���㲿��ƥ���LPS���飩
vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0; // ǰ׺����
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP�㷨ʵ��
bool kmpSearch(const string& pattern, const string& text) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    int i = 0; // text������
    int j = 0; // pattern������

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return true; // �ҵ�ƥ��
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false; // δ�ҵ�ƥ��
}

int main() {
    string presetPassword, unlockSequence;

    cout << "�������趨�Ŀ�������: ";
    cin >> presetPassword;
    cout << "�����뿪���ַ�����: ";
    cin >> unlockSequence;

    if (kmpSearch(presetPassword, unlockSequence)) {
        cout << "�����ɹ���" << endl;
    } else {
        cout << "����ʧ�ܣ�" << endl;
    }

    return 0;
}
