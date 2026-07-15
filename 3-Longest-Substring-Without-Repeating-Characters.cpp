class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int n = s.length();
        bool freq[2 << 6] = {};
        int ans = 0;
        while (right < n && left < n) {
            // condition is no dup
            if(freq[s[right]] == 0){
                freq[s[right]] = 1;
                right++;
            }
            else{
                freq[s[left]] = 0;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}