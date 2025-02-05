class Solution(object):
    def areAlmostEqual(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) != len(s2):  # Length mismatch
            return False  

        first_index, second_index = -1, -1
        mismatch_count = 0

        for i in range(len(s1)):
            if s1[i] != s2[i]:
                mismatch_count += 1

                if first_index == -1:
                    first_index = i
                elif second_index == -1:
                    second_index = i
                else:
                    return False  # More than two mismatches

        # If no mismatch, strings are already equal
        if mismatch_count == 0:
            return True

        # If only one mismatch, it's impossible to swap -> return False
        if mismatch_count != 2:
            return False

        # Swap characters and check if they become equal
        s1_list = list(s1)  
        s1_list[first_index], s1_list[second_index] = s1_list[second_index], s1_list[first_index]

        return "".join(s1_list) == s2
        