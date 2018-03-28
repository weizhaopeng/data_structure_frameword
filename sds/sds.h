ifndef _SDS_H_
#define _SDS_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *字符串常量，用于存储字符串，具有更高的使用效率
 *buf:存储空间 	 	   capacity:存储空间容量
 *use:使用的空间(byte) free:剩余的空间(byte)
 */
typedef struct {
	void *buf;
	int   capacity;
	int   use;
	int   free;
} zhou_sds;

/*
 *创建sds
 */
zhou_sds *zhou_sds_creat(int capacity);

/*
 *释放sds
 */
int zhou_sds_destroy(zhou_sds *sds);

/*
 *复制字符串str到sds
 */
int zhou_sdscpy_str(zhou_sds *sds, const char *str);

/*
 *复制sds1的内容到sds2
 */
int zhou_sdscpy_sds(zhou_sds *sds1, const zhou_sds *sds2);

/*
 *比较两个sds中的字符串
 */
int zhou_sdscmp(zhou_sds *sds1, zhou_sds *sds2);

/*
 *清空字符串
 */
void zhou_sds_clear(zhou_sds *sds);

/*
 *拓展sds：当数据<=1MB时，增加为原来的二倍的容量；当数据>1MB时，增加1MB的容量
 */
int zhou_sds_expand(zhou_sds *sds);

/*
 *拓展sds的容量到新的capacity
 */
int zhou_sds_add(zhou_sds *sds, int capacity);

#endif
