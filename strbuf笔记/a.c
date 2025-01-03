#ifndef _STRBUF_H
#define _STRBUF_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
struct strbuf {
    int len;
    int alloc;
    char *buf;
};

void strbuf_init(struct strbuf *sb, size_t alloc){
sb->alloc=alloc;
sb->len=0;
sb->buf=(char*)malloc(alloc);
sb->buf[sb->len]='\0';
}

void strbuf_attach(struct strbuf *sb, void *str,size_t len, size_t alloc){
sb->alloc=alloc;
sb->len=len;
sb->buf=(char*)str;
}

void strbuf_release(struct strbuf *sb){
    free(sb->buf);
    strbuf_attach(sb,NULL,0,0);
}

void strbuf_swap(struct strbuf *a, struct strbuf *b){
    struct strbuf t=*a;
    *a=*b;
    *b=t;

}
char *strbuf_detach(struct strbuf *sb, size_t *sz){

}
int strbuf_cmp(const struct strbuf *first, const struct strbuf *second){

}
void strbuf_reset(struct strbuf *sb);

void strbuf_grow(struct strbuf *sb, size_t extra){
    int remain=sb->alloc-sb->len;
    if(extra>remain)
        sb->buf=(char*)realloc(sb->alloc+=extra)
}
void strbuf_add(struct strbuf *sb, const void *data, size_t len){
    strbuf_grow(sb,len);
    sb->len=len;

}
void strbuf_addch(struct strbuf *sb, int c);
void strbuf_addstr(struct strbuf *sb, const char *s);
void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2);
void strbuf_setlen(struct strbuf *sb, size_t len);
size_t strbuf_avail(const struct strbuf *sb);
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len);

void strbuf_rtrim(struct strbuf *sb);
void strbuf_ltrim(struct strbuf *sb);
void strbuf_remove(struct strbuf *sb, size_t pos, size_t len);

ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint);
int strbuf_getline(struct strbuf *sb, FILE *fp);

struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max);
bool strbuf_begin_judge(char *target_str, const char *str, int strnlen);
char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len);
#endif

