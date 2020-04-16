#include "mq.h"
#include "kfifo.h"

static unsigned char fifo_buffer[128];
static struct kfifo fifo;

int MQ_Init(void) {
  return kfifo_init(&fifo, fifo_buffer, sizeof(fifo_buffer));
}

int MQ_PutMessage(unsigned char msg) {
  return kfifo_put(&fifo, msg);
}

int MQ_GetMessage(unsigned char *msg) {
  return kfifo_get(&fifo, msg);
}
