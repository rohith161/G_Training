#include <stdio.h>
#include <string.h>	

int main() {
    char *str = "#include <stdio.h>";
    char *reset_color = "\x1b[0m";
    char *color_code = "\x1b[1;31m"; // Red color

    // Find the position of the substring "#include" in the string
    char *pos = strstr(str, "#include");

    // Print the string up to the position of the substring
    printf("%.*s", pos - str, str);

    // Print the substring in color
    printf("%s%.*s%s", color_code, (int)strlen("#include"), pos, reset_color);

    // Print the rest of the string after the substring
    printf("%s\n", pos + strlen("#include"));

    return 0;
}
