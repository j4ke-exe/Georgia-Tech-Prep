//strcpy: Copies a string to another.
char src[] = "Hello";
char dest[6];
strcpy(dest, src);
// dest now contains "Hello"

//strcat: Concatenates (appends) one string to another.
char dest[12] = "Hello";
char src[] = " World";
strcat(dest, src);
// dest now contains "Hello World"

//strlen: Returns the length of a string (excluding the null terminator).
char str[] = "Hello";
size_t len = strlen(str);
// len is 5

//strcmp: Compares two strings lexicographically.
char str1[] = "Hello";
char str2[] = "World";
int result = strcmp(str1, str2);
// result is negative since "Hello" < "World"

//strncpy: Copies a specified number of characters from one string to another.
char src[] = "Hello";
char dest[6];
strncpy(dest, src, 3);
// dest now contains "Hel"
dest[3] = '\0';
// ensure null termination

//strncat: Concatenates a specified number of characters from one string to another.
char dest[12] = "Hello";
char src[] = " World";
strncat(dest, src, 3);
// dest now contains "Hello Wo"

//strchr: Finds the first occurrence of a character in a string.
char str[] = "Hello";
char *pos = strchr(str, 'l');
// pos points to the first 'l' in "Hello"

//strstr: Finds the first occurrence of a substring in a string.
char str[] = "Hello World";
char *pos = strstr(str, "World");
// pos points to "World" in "Hello World"
