#ifndef __CSTRING_H__
#define  __CSTRING_H__

#include<string>
/*
��̬�����ַ���Ҳ�ᱨ��
*/
extern char * substring(char *str, int beginindex, int endindex, char *ret);

extern char * trim(char *str);
extern char *replace(char *str, char *oldstr, char *newstr);
extern char *replaceall(char *str, char *oldstr, char *newstr);
extern int start_with(char *str, char *start);
extern int end_with(char *str, char *end);
extern char * to_upper_case(char *str, int start, int offset);
extern char * to_lower_case(char *str, int start, int offset);
extern char * str_toupper(char *str);
extern std::string hsGetCol(const char* ASourceStr, int AColNo, char AChar);


char *removestr(char *str, int start, int num);


//UTF-8��GB2312��ת��
std::string utf8_to_anscii(std::string const & utf8);

//GB2312��UTF-8��ת��
std::string anscii_to_utf8(std::string const & gb2312);

#endif