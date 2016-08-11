#ifndef _RULES_H_INCLUDED_
#define _RULES_H_INCLUDED_

typedef const char *(*rule_fn)(int number, int *special_numbers);

const char * default_rule(int number, int *special_numbers);
const char * multiple_rule(int number, int *special_numbers);
const char * special_word_rule(int number, int *special_numbers);

#endif // _RULES_H_INCLUDED_
