#include "sds.h"

zhou_sds *zhou_sds_creat(int capacity)
{
	zhou_sds *sds;

	sds = malloc(sizeof(zhou_sds));
	if (!sds)
		return NULL;
	sds->buf = malloc(sizeof((char)*capacity+1));
	if (!sds->buf)
		return NULL;
	sds->capacity = capacity;
	sds->use 	  = 0;
	sds->free	  = capacity;

	return sds;
}

int zhou_sds_destroy(zhou_sds *sds)
{
	if (sds) {
		if (sds->buf)
			free(sds->buf);
		free(sds);
	}
}

char *zhou_sdscpy_str(zhou_sds *sds, const char *str)
{
	return strcpy(sds->buf, str);
}

char *zhou_sdscon

		
