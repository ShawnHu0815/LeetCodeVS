#include <bits/stdc++.h>
using namespace std;

// 自定义memcpy函数实现
void* my_memcpy(void* dst, const void* src, size_t n) {
    // 将void*转换为char*，以便按字节复制
    char* d = (char*)dst;
    const char* s = (const char*)src;
    
    // 逐字节复制
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    
    return dst;  // 返回目标地址
}

int main() {
    cout << "=== memcpy函数测试 ===" << endl;
    
    // 测试1：复制整型数组
    cout << "\n1. 复制整型数组：" << endl;
    int src_arr[] = {1, 2, 3, 4, 5};
    int dst_arr[5] = {0};
    
    cout << "复制前dst_arr: ";
    for (int i = 0; i < 5; i++) {
        cout << dst_arr[i] << " ";
    }
    cout << endl;
    
    my_memcpy(dst_arr, src_arr, sizeof(src_arr));
    
    cout << "复制后dst_arr: ";
    for (int i = 0; i < 5; i++) {
        cout << dst_arr[i] << " ";
    }
    cout << endl;
    
    // 测试2：复制字符串
    cout << "\n2. 复制字符串：" << endl;
    char src_str[] = "Hello World!";
    char dst_str[20] = {0};
    
    cout << "复制前dst_str: \"" << dst_str << "\"" << endl;
    
    my_memcpy(dst_str, src_str, strlen(src_str) + 1);  // +1包含'\0'
    
    cout << "复制后dst_str: \"" << dst_str << "\"" << endl;
    
    // 测试3：复制结构体
    cout << "\n3. 复制结构体：" << endl;
    struct Person {
        int age;
        char name[10];
        double height;
    };
    
    Person src_person = {25, "Alice", 165.5};
    Person dst_person = {0};
    
    cout << "复制前dst_person: age=" << dst_person.age 
         << ", name=\"" << dst_person.name 
         << "\", height=" << dst_person.height << endl;
    
    my_memcpy(&dst_person, &src_person, sizeof(Person));
    
    cout << "复制后dst_person: age=" << dst_person.age 
         << ", name=\"" << dst_person.name 
         << "\", height=" << dst_person.height << endl;
    
    // 测试4：部分复制
    cout << "\n4. 部分复制测试：" << endl;
    char long_str[] = "This is a very long string";
    char short_str[10] = {0};
    
    my_memcpy(short_str, long_str, 9);  // 只复制前9个字符
    short_str[9] = '\0';  // 手动添加结束符
    
    cout << "原字符串: \"" << long_str << "\"" << endl;
    cout << "部分复制: \"" << short_str << "\"" << endl;
    
    // 测试5：与系统memcpy对比
    cout << "\n5. 与系统memcpy对比：" << endl;
    int test_arr1[5] = {10, 20, 30, 40, 50};
    int result1[5] = {0};
    int result2[5] = {0};
    
    my_memcpy(result1, test_arr1, sizeof(test_arr1));
    memcpy(result2, test_arr1, sizeof(test_arr1));
    
    cout << "我的memcpy结果: ";
    for (int i = 0; i < 5; i++) cout << result1[i] << " ";
    cout << endl;
    
    cout << "系统memcpy结果: ";
    for (int i = 0; i < 5; i++) cout << result2[i] << " ";
    cout << endl;
    
    // 验证结果是否一致
    bool same = true;
    for (int i = 0; i < 5; i++) {
        if (result1[i] != result2[i]) {
            same = false;
            break;
        }
    }
    cout << "结果是否一致: " << (same ? "是" : "否") << endl;
    
    return 0;
}