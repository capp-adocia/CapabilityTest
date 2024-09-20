#pragma once
#include <string>
#include <vector>

// 原始的，用来移除小于0x20（十进制数：32）的字符（很慢）（6246 ms）
std::string remove_ctrl(std::string s) {
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result = result + s[i];
    }
    return result;
}

// 复合赋值操作避免临时字符串（快）（1394 ms）
std::string remove_ctrl_mutating(std::string s) {
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}

// 使用reserve避免不必要的内存分配（稍快）（1120 ms）
std::string remove_ctrl_ref(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result.push_back(s[i]);
    }
    return result;
}

// 使用迭代器消除指针解引（2208 ms）
std::string remove_ctrl_iter(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it >= 0x20)
            result.push_back(*it);
    }
    return result;
}

// 使用字符数组代替字符串（极快）（6 ms）（Release版本下仅需105 微秒，0.105ms）
void remove_ctrl_cstrings(char* destp, const char* srcp, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (srcp[i] >= 0x20) {
            *destp++ = srcp[i];
        }
    }
    *destp = '\0';  // 确保目标字符串以 null 结尾
}