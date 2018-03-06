#ifndef _SDS_H_
#define _SDS_H_

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
static inline zhou_sds *sds_creat(int capacity);

/*
 *释放sds
 */
static inline int sds_destroy(zhou_sds *sds);

/*
 *插入字符串str
 */
static inline int sds_insert_str(zhou_sds *sds, char *str);


