#include "mq.h"
#include "kfifo.h"

static unsigned char fifo_buffer[128];
static struct kfifo fifo;

int MQ_Init() {
  if (kfifo_init(&fifo, fifo_buffer, sizeof(fifo_buffer)) != 0) {
    return -1;
  }
  return 0;
}

int MQ_PutMessage(unsigned char msg) {
  if (kfifo_put(&fifo, msg) != 0) {
    return -1;
  }
  return 0;
}

int MQ_GetMessage(unsigned char *msg) {
  if (kfifo_get(&fifo, msg) != 0) {
    return -1;
  }
  return 0;
}
