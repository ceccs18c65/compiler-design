#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isNumber(char s[10]) {
  int flag = 1, i = 0;
  for (i = 0; i < strlen(s); i++) {
    if (!isdigit(s[i]) && s[i] != '.') {
      flag = 0;
    }
  }
  return flag;
}
int isKeyword(char buffer[]) {
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto",
    "if","int","long","register","return","short","signed",
    "sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"};
  int i, flag = 0;
  for (i = 0; i < 32; ++i) {
    if (strcmp(keywords[i], buffer) == 0) {
      flag = 1;
      break;
    }
  }
  return flag;
}
int main() {
  system("clear");
  char ch, buffer[15], operators[] = "+-*/%=", symbols[] = ";:!^\"\'";
  FILE  *fp;
  int i, j = 0;

  fp = fopen("input.txt", "r");

  if (fp == NULL) {
    printf("error while opening the file\n");
    exit(0);
  }
  while ((ch = fgetc(fp)) != EOF) {
    for (i = 0; i < 6; ++i) {
      if (ch == operators[i])
        printf("%c is an operator\n", ch);
      else if (ch == symbols[i])
        printf("%c is a symbol\n", ch);
    }
    if (isalnum(ch) || ch == '.') {
      buffer[j++] = ch;
    } else if ((ch == '\n' || ch == '=' || ch == ';' || ch == '+' || ch == '-' || ch == '*'|| ch == '/' || ch == '%' || ch == '.')) {
      buffer[j] = '\0';
      j = 0;
      if (isKeyword(buffer) == 1)
        printf("%s is a keyword\n", buffer);
      else
      if (isNumber(buffer))
        printf("%s is a constant\n", buffer);
      else
        printf("%s is an identifier\n", buffer);
    }
  }
  fclose(fp);
  return 0;
}
