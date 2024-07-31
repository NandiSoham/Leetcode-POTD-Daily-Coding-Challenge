// Problem Link -> https://leetcode.com/problems/filling-bookcase-shelves/description/

class Solution {
public:
    int totalBooks;
    int shelfWidth;
    int memo[1001][1001];

    int arrangeBooks(vector<vector<int>>& books, int index, int remainingWidth, int currentMaxHeight) {
        if (index >= totalBooks) {
            return currentMaxHeight;
        }

        if (memo[index][remainingWidth] != -1) {
            return memo[index][remainingWidth];
        }

        int bookWidth = books[index][0];
        int bookHeight = books[index][1];

        int keepBook = INT_MAX;
        int skipBook = INT_MAX;

        // Option 1: Keep the book on the current shelf
        if (bookWidth <= remainingWidth) {
            keepBook = arrangeBooks(books, index + 1, remainingWidth - bookWidth, max(currentMaxHeight, bookHeight));
        }

        // Option 2: Skip to the next shelf
        skipBook = currentMaxHeight + arrangeBooks(books, index + 1, shelfWidth - bookWidth, bookHeight);

        return memo[index][remainingWidth] = min(keepBook, skipBook);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(memo, -1, sizeof(memo));
        totalBooks = books.size();
        this->shelfWidth = shelfWidth;

        int remainingWidth = shelfWidth;
        return arrangeBooks(books, 0, remainingWidth, 0);
    }
};
