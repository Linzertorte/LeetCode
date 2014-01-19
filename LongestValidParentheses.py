class Solution:
    def longestValidParentheses(self, s):
        stack = []
        right=[-1 for i in xrange(len(s))]
        for i in xrange(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if len(stack)!=0:
                    right[stack[-1]]=i
                    del stack[-1]
                right[i]=-1

        #print right                                                                                                                                      
        i,j,cnt = 0,0,0
        while i<len(s):
            if right[i]!=-1:
                j=i
                leng = 0
                while j<len(s) and right[j]!=-1:
                    leng += right[j]-j+1
                    j = right[j]+1
                cnt = max(leng,cnt)
                i = j
            else:
                i += 1

        return cnt

