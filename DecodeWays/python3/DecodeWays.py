class Solution:
    def __init__(self):
        self.seen = {}
    def numDecodings(self, s: str) -> int:
        if (len(s) == 0):
            return 1
        if (int(s[0]) == 0):
            return 0
        if len(s) in self.seen:
            return self.seen[len(s)]
        comb = self.numDecodings(s[1:])
        if (len(s) > 1 and int(s[0:2]) <= 26):
            comb += self.numDecodings(s[2:])
        self.seen[len(s)] = comb
        return comb
