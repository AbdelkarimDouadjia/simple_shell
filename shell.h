#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/wait.h>


#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CMD_AND		2
#define CMD_NORM	0
#define CMD_CHAIN	3
#define CMD_OR		1


#define CONVERT_UNSIGNED	2
#define CONVERT_LOWERCASE	1



#define USE_STRTOK 0
#define USE_GETLINE 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

/**
** struct list_str - string structure signle (linked-list)
** @num: index of the number input
** @str: char or (String)
** @next: next case pointered (node)
*/
typedef struct list_str
{
	int num;
	char *str;
	struct list_str *next;
} list_s;

/**
 ** struct pasinfo - has to pass funct ptrs to functions as an arguement,
** allowing uniform prototype for function pointer struct
 ** @arg: an arguments string generated from getline
 ** @argv: arg generated from an array of stringd
 ** @path: the path for the same comm
 ** @argc: the count has a parameter
 ** @line_count:  failure count error
 ** @err_num: the exit()s function return error code
 ** @linecount_flag:  check the count var if on the input field line
 ** @fname:  it return the file name about a program specified
 ** @env:  environ (linked-list) has a local copy
 ** @environ:  environ (linked-list) has a custom modified copy
 ** @history:  a case on (linked-list) has a histoire
 ** @alias:  a case on (linked-list) has a alias element
 ** @env_changed:  check the environ var if on the input field line
 ** @status:  gives us a status about the final command executed
 ** @cmd_buf: check the cmd_buf var if on the input field line
 ** @cmd_buf_type:  check the cmd_buf_type var if on the input field line
 ** @readfd:  check the readfd var if on the input field line
 ** @histcount:  check the histcount var if on the input field line
 **/
typedef struct pasinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_s *env;
	list_s *history;
	list_s *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_s;
#define INFO_INIT\
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - func related and char(string) builtin
 * @type: the builtin flag commes.
 * @func: it's just a function pointered to the builtin funct
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_s *);
} bilttin_tal;

int _pufstd(char *str, int fd);
char *fedn_puht(info_s *, char *, char *);
char *chaa_rdupp(char *, int, int);

int is_comoodd(info_s *, char *);
void fin_dcomnd(info_s *);

int loophsh(char **);
void for_ocmand(info_s *);
int hsh(info_s *, char **);
int _charpiit(char);



void _epputss(char *);
int _pufiudf(char c, int fd);

char *_stceat(char *, char *);
int _stcmmp(char *, char *);
int builtinco_fins(info_s *);
char *_stcocp(char *, char *);
char *strest_wit(const char *, const char *);



int _puuchir(char);
int _stlesn(char *);
char **stoiww2(char *, char);
char *_strtprp(const char *);
char *_srtingcp(char *, char *, int);


void _puutss(char *);
char *_copncastr(char *, char *, int);
void *_reellocc(void *, unsigned int, unsigned int);


char **stoiww(char *, char *);

char *_memfilsetl(char *, char, unsigned int);
void del_frre(char **);
char *_tischr(char *, char);


int alph_is(int);
int bf_fer(void **);


int _mihelyp(info_s *);
int del_is(char, char *);
int str_oint(char *);
int is_atio(char *);

void sign_Hand(int);
void errorp_rint(info_s *, char *);

char *converr_nuum(long int, int, int);
int activitated(info_s *);
void comments_replace(char *);



int exi_mi(info_s *);
int _micded(info_s *);
int decc_print(int, int);



int reed_hihist(info_s *info);
int _mihist(info_s *);


ssize_t gis_inptu(info_s *);
int _mihelpalias(info_s *);
int _geline(info_s *, char **, size_t *);



void settin_inf(info_s *, char **);
void fee_inff(info_s *, int);
int _mievnv(info_s *);
int evv_populate_lis(info_s *);
char *_getevv(info_s *, const char *);
int _miunssotenvv(info_s *);
int _misetrevv(info_s *);




char *git_histoir_fi(info_s *inf);
int wriitc_eaphistory(info_s *inf);
int buil_ddhs_ls(info_s *inf, char *buf, int linecount);
void del_inf(info_s *);
int remun_hest(info_s *inf);


void frfee_lis(list_s **);
size_t prin_li_stt(const list_s *);
list_s *adnd_nod(list_s **, const char *, int);
int rmove_node_at_index(list_s **, unsigned int);
list_s *nodd_add_end(list_s **, const char *, int);



char **liss_to_str(list_s *);
size_t liss_lengs(const list_s *);
ssize_t gitt_index_index(list_s *, list_s *);
list_s *start_nodd_wi(list_s *, char *, char);
size_t priin_liss(const list_s *);


void chic_char(info_s *, char *, size_t *, size_t, size_t);
int is_chair(info_s *, char *, size_t *);
int chang_alia(info_s *);
int cahnge_strr(char **, char *);
int change_ver(info_s *);

int _rmounsetenvv(info_s *, char *);
char **envr_git(info_s *);
int _sinitenva(info_s *, char *, char *);

#endif
