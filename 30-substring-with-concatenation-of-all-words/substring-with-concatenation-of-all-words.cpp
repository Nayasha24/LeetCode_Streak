class Solution {
public:
   

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result; // To store the resulting starting indices
    if (s.empty() || words.empty() || words[0].empty()) {
        return result; // Edge case: if s or words are empty, return empty result
    }
    
    int wordLength = words[0].length(); // Length of each word in words (all words are the same length)
    int numWords = words.size();        // Number of words in words
    int substringLength = wordLength * numWords; // Total length of the concatenated substring
    
    unordered_map<string, int> wordsCount; // Hash map to store the frequency of each word in words
    for (const string& word : words) {
        wordsCount[word]++; // Populate the wordsCount map with the frequency of each word
    }

    // We will have `wordLength` different starting points (i.e., 0, 1, ..., wordLength-1)
    for (int i = 0; i < wordLength; i++) {
        unordered_map<string, int> seenWords; // Hash map to track words seen in the current window
        int left = i; // Initialize the left pointer of the sliding window
        int count = 0; // Counter to keep track of the number of words matched in the current window
        
        // Slide the window over the string starting from index `i`
        for (int j = i; j <= static_cast<int>(s.length()) - wordLength; j += wordLength) {
            string word = s.substr(j, wordLength); // Extract a word of length `wordLength` starting from index `j`
            if (wordsCount.find(word) != wordsCount.end()) {
                seenWords[word]++; // If the word is in wordsCount, increment its count in seenWords
                count++; // Increment the count of words matched
                
                // If a word's frequency in seenWords exceeds its frequency in wordsCount
                while (seenWords[word] > wordsCount[word]) {
                    string leftWord = s.substr(left, wordLength); // Extract the word at the left pointer
                    seenWords[leftWord]--; // Decrement its count in seenWords
                    count--; // Decrement the count of words matched
                    left += wordLength; // Move the left pointer to the right
                }
                
                // If the number of words matched equals the number of words in words
                if (count == numWords) {
                    result.push_back(left); // Add the starting index to the result
                }
            } else {
                // If the word is not in wordsCount, reset the window
                seenWords.clear(); // Clear the seenWords map
                count = 0; // Reset the count of words matched
                left = j + wordLength; // Move the left pointer to the next possible starting position
            }
        }
    }

    return result; // Return the resulting starting indices
}

};