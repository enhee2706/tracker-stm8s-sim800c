#ifndef _MQ_H_
#define _MQ_H_

int MQ_Init(void);
int MQ_PutMessage(unsigned char msg);
int MQ_GetMessage(unsigned char *msg);

#endif
