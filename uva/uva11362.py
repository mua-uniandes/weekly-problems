from sys import stdin, stdout

trie = {}

def buildTrie(s):
    for i in range(0, len(s)):
        if(trie.get(s[i]-48) == None):
            trie[s[i]-48] = s[i] - 48

def main():

main()