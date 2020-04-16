#ifndef _MQ_H_
#define _MQ_H_

int MQ_Init();
int MQ_PutMessage(unsigned char msg);
int MQ_GetMessage(unsigned char *msg);

#endif
