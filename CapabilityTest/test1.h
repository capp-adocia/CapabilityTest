#pragma once
#include <string>
#include <vector>

// 原始的，用来移除小于0x20（十进制数：32）的字符（慢）
std::string remove_ctrl(std::string s) {
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result = result + s[i];
    }
    return result;
}

// 复合赋值操作避免临时字符串（快）
std::string remove_ctrl_mutating(std::string s) {
    std::string result;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
            result += s[i];
    }
    return result;
}

// 使用reserve避免不必要的内存分配（稍快）
std::string remove_ctrl_ref(const std::string& s) {
    std::string result;
    result.reserve(s.size());
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] >= 0x20)
             result.push_back(s[i]);
    }
    return result;
}

// 使用迭代器消除指针解引