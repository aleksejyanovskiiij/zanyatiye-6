// zanyatie 6, zadaniye 4
#include <iostream>
#include <cctype> 
#include <string_view>

bool zadaniye_na_massive() {
    int square[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &square[i][j]);
        }
    }
    int sum_horizontal = 0;
    int sum_vertical = 0;
    for (int i = 0; i < 3; ++i) {
        int current_sum_row = 0;
        for (int j = 0; j < 3; ++j) {
            current_sum_row += square[i][j];
        }
        if (sum_horizontal == 0) { sum_horizontal = current_sum_row; }
        else if (current_sum_row != sum_horizontal) { return false; }
    }
    for (int i = 0; i < 3; ++i) {
        int current_sum_column = 0;
        for (int j = 0; j < 3; ++j) {
            current_sum_column += square[j][i];
        }
        if (sum_vertical == 0) { sum_vertical = current_sum_column; }
        else if (current_sum_column != sum_vertical) { return false; }
    }
    int sum_main_diagonal = 0;
    int sum_other_diagonal = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j)     { sum_main_diagonal  += square[i][j]; }
            if (i + j == 2) { sum_other_diagonal += square[i][j]; }
        }
    }
    return sum_main_diagonal == sum_other_diagonal;
}


int zadaniye_na_stroku(std::string_view str, int n) {
    int count = 0;
    int pos = 0;
    int len = str.length();
    while (pos < len) {
        while (pos < len && std::isspace(str[pos])) ++pos;
        if (pos >= len) break;

        int wordStart = pos;
        while (pos < len && !std::isspace(str[pos])) ++pos;
        
        if (pos - wordStart == n) ++count;
    }
    return count;
}

int main() {
    printf(zadaniye_na_massive() ? "da\n" : "net\n");
    printf("%d\n", zadaniye_na_stroku("ale da zdravstvuitye privet zemlya", 6));
    return 0;
}
