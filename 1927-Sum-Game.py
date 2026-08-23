class Solution:
    def sumGame(self, num: str) -> bool:
        half_len = len(num) // 2
        net_sum = 0
        net_symbol_cnt = 0
        tot_symbol_cnt = 0
        
        # 1. Fold string characters to calculate aggregate state differences
        for i, char in enumerate(num):
            weight = 1 if i < half_len else -1
            
            if char == '?':
                tot_symbol_cnt += 1
                net_symbol_cnt += weight
            else:
                net_sum += int(char) * weight
                
        # 2. Odd total empty spots give Alice the last turn, ensuring her victory
        if tot_symbol_cnt % 2 != 0:
            return True
            
        # 3. Bob wins only if initial sum diff is perfectly balanced by remaining spots
        return 2 * net_sum + 9 * net_symbol_cnt != 0
        